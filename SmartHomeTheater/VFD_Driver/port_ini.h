#pragma once

#include <pigpio.h>
#include <iostream>

#define LOW 0x0
#define HIGH 0x1
#define GRIDS 12
#define SEGMENTS 16
#define CHARDIGITS 10	//Number of character grids
#define CHARS_BEGIN 1	//"1" when characters digits starting from first grid (this + CHARDIGITS = end of char digits)

#define LEFT    0
#define RIGHT   1
#define CENTER  2
uint8_t grid_index = 0;


/*Define the wiring | Line up the ports*/
uint8_t G[GRIDS] = {1,2,3,4,5,6,7,8,9,10,11,12};
uint8_t S[SEGMENTS] = {21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};

/*Initialise Deamon*/
if (gpioInitialise() < 0) exit(1);
std::cout << "Deamon unicialised!" << std::endl;

/*Set ports mode to output*/
for (uint8_t i = 0; i < G.length; i++)
{
	gpioSetMode(G[i], PI_OUTPUT)
}
for (uint8_t i = 0; i < S.length; i++)
{
	gpioSetMode(S[i], PI_OUTPUT)
}
std::cout << "Ports initialised." << std::endl;

/*Set everythig to LOW by default*/
for (uint8_t i = 0; i < G.length; i++)
{
	gpioWrite(G[i], LOW);
}
for (uint8_t i = 0; i < S.length; i++)
{
	gpioWrite(S[i], LOW);
}
std::cout << "Ports are clear to use." << std::endl;