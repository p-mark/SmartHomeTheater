#pragma once

#include <pigpio.h>
#include <iostream>
#include <display_icons.h>

#define LOW 0x0
#define HIGH 0x1
#define GRIDS 12
#define SEGMENTS 16
#define CHARDIGITS 10	//Number of character grids
#define CHARS_BEGIN 1	//"1" when characters digits starting from first grid (this + CHARDIGITS = end of char digits)

#define ICON_GRIDS		(GRIDS - CHARDIGITS)
#define ICONS			(ICON_GRIDS * SEGMENTS)
#define ON				1
#define OFF				0

#define LEFT    0
#define RIGHT   1
#define CENTER  2

/*Define the wiring | Line up the ports*/
static uint8_t G[GRIDS] = {1,2,3,4,5,6,7,8,9,10,11,12};
static uint8_t S[SEGMENTS] = {21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};

/*Unique icons light status list*/
bool display_icons[ICON_GRIDS][SEGMENTS];

uint8_t grid_index = 0;

class  ini{
public:
static void initialise(){
/*Initialise Deamon*/
if (gpioInitialise() < 0) exit(1);
std::cout << "Deamon unicialised!" << std::endl;

/*Set ports mode to output*/
for (uint8_t i = 0; i < GRIDS; i++)
	gpioSetMode(G[i], PI_OUTPUT);
	
for (uint8_t i = 0; i < SEGMENTS; i++)
	gpioSetMode(S[i], PI_OUTPUT);
	
std::cout << "Ports initialised." << std::endl;

/*Set everythig to LOW by default*/
for (uint8_t i = 0; i < GRIDS; i++)
	gpioWrite(G[i], LOW);
	
for (uint8_t i = 0; i < SEGMENTS; i++)
	gpioWrite(S[i], LOW);


/*Fill up the icon list with default*/
for (uint8_t i = 0; i < ICON_GRIDS; i++)
	for (uint8_t i = 0; i < SEGMENTS; i++)
		display_icons[ICON_GRIDS][SEGMENTS] = OFF;
		
std::cout << "Ports are clear to use." << std::endl;
}
};
