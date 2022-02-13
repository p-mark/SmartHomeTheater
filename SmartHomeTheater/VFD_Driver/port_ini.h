#pragma once							/*User definded port properties*/
/*********************************************************************************************************************/
#define GRIDS 12		//Used grids
#define SEGMENTS 16		//Used segments
#define CHARDIGITS 10	//Number of digit/character grids
#define CHARS_BEGIN 0	//"0" when characters digits starting from first grid
/*********************************************************************************************************************/

#define ICON_GRIDS		(GRIDS - CHARDIGITS)
#define ICONS			(ICON_GRIDS * SEGMENTS)

#include <pigpio.h>
#include <iostream>
#include <display_icons.h>

#define LOW		0x0
#define HIGH	0x1
#define ON		1
#define OFF		0
#define LEFT    0
#define RIGHT   1
#define CENTER  2

namespace VFD_Driver {
	class Port {public:
							/*User definded ports*/
/*********************************************************************************************************************/

		/*Define the wiring | Line up the ports*/
		static uint8_t G[GRIDS] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	
/*
*												 --a1--	  --a2--
*											   |  \		|	  /	 |
*											  f|   \h	|i	 /j	 |b
*											   |    \	|	/	 |
*												 --g1--	  --g2--
*											   |    /	|	\	 |
*											  e|   /m	|l	 \k	 |c
*											   |  /		|	  \	 |
*												 --d1--	  --d2--
*/
	
//									   a1,a2,b, c, d1,d2,e, f, g1,g2,h, i, j, k, l, m 
		static uint8_t S[SEGMENTS] = { 21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36 };
/*********************************************************************************************************************/

		/*Unique icons light status list*/
		bool display_icons[ICON_GRIDS][SEGMENTS];

		static void initialise()
	};
}