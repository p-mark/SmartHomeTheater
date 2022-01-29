#include <pigpio.h>
#include <iostream>

#define LOW 0x0
#define HIGH 0x1
#define GRIDS 12
#define SEGMENTS 16
#define CHARS 10		//Number of character grids
#define CHARS_BEGIN 1	//"1" when characters digits starting from first grid (this + CHARS = end of char digits)
uint8_t g = 0;

/*Define the wiring*/
uint8_t G[GRIDS] = {1,2,3,4,5,6,7,8,9,10,11,12};
uint8_t S[SEGMENTS] = {21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};

/*Initialise Deamon*/
if (gpioInitialise() < 0) exit(1);
std::cout << "Deamon inicialised!" << std::endl;

/*Set ports mode to output*/
for (uint8_t i = 0; i < G.length; i++)
{
	gpioSetMode(G[i], PI_OUTPUT)
}
for (uint8_t i = 0; i < S.length; i++)
{
	gpioSetMode(S[i], PI_OUTPUT)
}

/*Set everythig to LOW by default*/
for (uint8_t i = 0; i < G.length; i++)
{
	gpioWrite(G[i], LOW);
}
for (uint8_t i = 0; i < S.length; i++)
{
	gpioWrite(S[i], LOW);
}