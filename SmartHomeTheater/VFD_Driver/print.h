#pragma once

#include <port_ini.h>
#include <charset.h>

class display{
/*Select grid. Case of owerflow back to "0"*/
public: void jumpGrid(uint8_t index) {
    gpioWrite(G[grid_index], LOW);
    grid_index = index;	if (grid_index >= GRIDS) grid_index = 0;
    gpioWrite(G[grid_index], HIGH);
}

/*Select next grid*/
static void stepGrid() {
	gpioWrite(G[grid_index], LOW);
	grid_index++;	if (grid_index == GRIDS) grid_index = 0;
	gpioWrite(G[grid_index], HIGH);
}

/*Print the character/icon defined by array of segments*/
void writeGrid(bool character[SEGMENTS])
{
	for (uint8_t i = 0; i < SEGMENTS; i++)
		gpioWrite(S[i], character[i]);
}

private:
/*Transition betwen char and grid*/
void writeChar(char c) {
	c -= 33;
    (c < 96) ? writeGrid(DIGIT[c]) : writeGrid(DIGIT[95]);	
}

/*Print a string if there is space*/
void writeWord(std::string word){
	if (word.length() > CHARDIGITS) exit(1);

	for (uint8_t i = 0; i < word.length(); i++)
	{
		writeChar(word[i]);
		stepGrid();
	}
}

public:
/*Print aligned text*/
void writeWord_Aligned(std::string word, uint8_t text_align)
{
    uint8_t space_lenght = CHARDIGITS - word.length();

    //Fill in the characters
    switch (text_align) {
    case LEFT:
    {
        writeWord(word);
        for (uint8_t i = 0; i < space_lenght; i++)
            stepGrid();
        break;
    }
    case RIGHT:
    {
        for (uint8_t i = 0; i < space_lenght; i++)
            stepGrid();
        writeWord(word);
        break;
    }
    case CENTER:
    {
        std::string space = "";
        for (uint8_t i = 0; i < (space_lenght / 2); i++)
            space += " ";
        writeWord(space + word + space);
        if(space_lenght % 2 != 0)
            stepGrid();
        break;
    }
    default:
        std::string space = "";
        for (uint8_t i = 0; i < (space_lenght / 2); i++)
            space += " ";
        writeWord(space + "E:Align" + space);
        if (space_lenght % 2 != 0)
            stepGrid();
        break;
    }
}

/*Have to cut the wordBuffer to projectable size,
    * then write out the slice,
    * and repeatedly with shifting through the array*/                           //String shifteléssel jobb lenne
void writeWord_Animated(std::string word, uint8_t animation){
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

        writeWord(projectonBuffer);
        projectonBuffer.clear();
    }
}
};
