#include <write.h>

namespace VFD_Driver 
{
    /*Select grid. In case of owerflow back to "0"*/
    void Write::jumpGrid(uint8_t index)
    {
        gpioWrite(port.G[grid_index], LOW);
        grid_index = index;	if (grid_index >= GRIDS) grid_index = 0;
        gpioWrite(port.G[grid_index], HIGH);
    }
    
    /*Select next grid*/
    void Write::stepGrid()
    {
        gpioWrite(port.G[grid_index], LOW);
        grid_index++;	if (grid_index == GRIDS) grid_index = 0;
        gpioWrite(port.G[grid_index], HIGH);
    }

    /*Print the character/icon defined by array of segments*/
    void Write::Grid(bool character[SEGMENTS]) {
        for (uint8_t i = 0; i < SEGMENTS; i++)
            gpioWrite(port.S[i], character[i]);
        Timer.wait_grid();
    }

    /*Transition betwen char and grid*/
    void Write::Char(char c) {
        c -= 33;
        (c < 96) ? Write::Grid(DIGIT[c]) : Write::Grid(DIGIT[96]);
    }

    /*Print a string if there is space*/
    void Write::Word(std::string word)
    {
        if (word.length() > CHARDIGITS) exit(1);

        //Repeat writing out the word to fill 1 sec
        for (size_t i = 0; i < REFRESH_RATE; i++)
        {   
            //Write out the chars one-by-one
            for (uint8_t i = 0; i < word.length(); i++)
            {
                Write::Char(word[i]);
                Write::stepGrid();
            }
        }
    }

    /*Print aligned text*/
    void Write::Word_Aligned(std::string word, uint8_t text_align)
    {
        uint8_t space_lenght = CHARDIGITS - word.length();

        //Fill in the characters
        switch (text_align) {
        case LEFT:
        {
            Write::Word(word);
            for (uint8_t i = 0; i < space_lenght; i++)
                Write::stepGrid();
            break;
        }
        case RIGHT:
        {
            for (uint8_t i = 0; i < space_lenght; i++)
                Write::stepGrid();
            Write::Word(word);
            break;
        }
        case CENTER:
        {
            std::string space = "";
            for (uint8_t i = 0; i < (space_lenght / 2); i++)
                space += " ";
            Write::Word(space + word + space);
            if (space_lenght % 2 != 0)
                Write::stepGrid();
            break;
        }
        default:
            std::string space = "";
            for (uint8_t i = 0; i < (space_lenght / 2); i++)
                space += " ";
            Write::Word(space + "E:Align" + space);
            if (space_lenght % 2 != 0)
                Write::stepGrid();
            break;
        }
    }

    /*Have to cut the wordBuffer to projectable size,
        * then write out the slice,
        * and repeatedly with shifting through the array*/
    void Write::Word_Animated(std::string word, uint8_t animation) {
        std::string wordBuffer, projectonBuffer;

        /*Leave space around the text
        * -> Text passes through the display */
        if (animation == 1)
            for (uint8_t i = 0; i < CHARDIGITS; i++)
                wordBuffer += " ";
        wordBuffer += word + wordBuffer;

        //Reapiting with shifting
        for (uint8_t i = 0; i <= (wordBuffer.length() - CHARDIGITS); i++)
        {
            //Fill the projectonBuffer with the capchurable part
            for (uint8_t j = 0; j < CHARDIGITS; j++)
                projectonBuffer += wordBuffer[i + j];

            Write::Word(projectonBuffer);
            projectonBuffer.clear();
        }
    }
}