//***Warning***
//This driver using ASCII but the input depends on the platforms.
//Have to compromise. We attempt to handel like it would fit in UTF-8

#include <port_ini.h>
#include <charset.h>

/*Select next grid*/
void stepGrid() {
	gpioWrite(G[g], LOW);
	g++;	if (g == GRIDS) g = 0;
	gpioWrite(g, HIGH);
}

/*Select grid. Case of owerflow starts frome "0"*/
void jumpGrid(uint8_t index) {
    gpioWrite(G[g], LOW);
    g = index;	if (g =< GRIDS) g = 0;
    gpioWrite(g, HIGH);
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
	if (word.lenght > CHARS) exit(1);

	for (uint8_t i = 0; i < word.length; i++)
	{
		writeChar(word[i]);
		stepGrid();
	}
}

#define LEFT    0
#define RIGHT   1
#define CENTER  2

/*Print aligned text*/
void writeWord(std::string word, uint8_t text_align)
{
    uint8_t space_lenght = CHARS - word.length;

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