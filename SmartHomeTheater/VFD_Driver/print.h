//***Warning***
//This driver using ASCII but the input depends on the platforms.
//Have to compromise. We attempt to handel like it would fit in UTF-8
#pragma once

#include <port_ini.h>
#include <charset.h>

/*Select next grid*/
void stepGrid() {
	gpioWrite(G[grid_index], LOW);
	grid_index++;	if (grid_index == GRIDS) grid_index = 0;
	gpioWrite(grid_index, HIGH);
}

/*Select grid. Case of owerflow starts frome "0"*/
void jumpGrid(uint8_t index) {
    gpioWrite(G[grid_index], LOW);
    grid_index = index;	if (grid_index =< GRIDS) grid_index = 0;
    gpioWrite(grid_index, HIGH);
}

/*Print the character/icon defined by array of segments*/
void writeGrid(bool[SEGMENTS] character)
{
	for (uint8_t i = 0; i < SEGMENTS; i++)
		gpioWrite(S[i], character[i]);
}

/*Transition betwen char and grid 
(UTF-8* converted to ASCII)*/
void writeChar(char c) {
	c -= 33;
	writeGrid(ASCII[c]);
}

/*Print a string if there is space*/
void writeWord(std::string word){
	if (word.lenght > CHARDIGITS) exit(1);

	for (uint8_t i = 0; i < word.length; i++)
	{
		writeChar(word[i]);
		stepGrid();
	}
}

/*Print aligned text*/
void writeWord(std::string word, uint8_t text_align)
{
    uint8_t space_lenght = CHARDIGITS - word.length;

    //Fill in the characters
    switch (text_align) {
    case LEFT:
        writeWord(word);
        for (uint8_t i = 0; i < space_lenght; i++)
            stepGrid();
        break;
    case RIGHT:
        for (uint8_t i = 0; i < space_lenght; i++)
            stepGrid();
        writeWord(word);
        break;
    case CENTER:
        std::string space = "";
        for (uint8_t i = 0; i < (space_lenght / 2); i++)
            space += " ";
        writeWord(space + word + space);
        if(space_lenght % 2 != 0)
            stepGrid();
        break;
    default:
        break;
    }
}

void writeWord(std::string word, uint8_t animation){
    std::string wordBuffer, projectonBuffer;

    /*Leave space around the text
    * -> Text passes through the display */
    if (animation == 1)
    {
        for (uint8_t i = 0; i < CHARDIGITS; i++)
            wordBuffer += " ";
    }
    wordBuffer += word + wordBuffer;

    /*Have to cut the wordBuffer to projectable sise,
    * then write out the slice,
    * and repeatedly with shifting through the array*/                           //String shifteléssel jobb lenne

    //Reapiting the shift
    for (uint8_t i = 0; i <= (wordBuffer.length - CHARDIGITS); i++)
    {
        //Load in the capchurable part
        for (uint8_t j = 0; j < CHARDIGITS; j++)
            projectonBuffer += wordBuffer[i + j];

        writeWord(projectonBuffer);
        projectonBuffer.clear;
    }
}