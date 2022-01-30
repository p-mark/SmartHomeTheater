#include <port_ini.h>

#define ICON_GRIDS		(GRIDS - CHARDIGITS)
#define ICONS			(ICON_GRIDS * SEGMENTS)
#define ON				1
#define OFF				0

/*List of special icons*/
//This list have to be manually updated to every specific type of displays
#define SPEAKER_CENTER		display_icons[0][0]
#define SPEAKER_FRONT_RIGHT display_icons[0][1]
#define SPEAKER_RIGH		display_icons[0][2]
#define SPEAKER_BACK_RIGHT	display_icons[0][3]
#define SPEAKER_FRONT_LEFT	display_icons[0][4]
#define SPEAKER_LEFT		display_icons[0][5]
#define SPEAKER_BACK_LEFT	display_icons[0][6]
#define SPEAKER_SUB			display_icons[0][7]
#define DolbyDigital		display_icons[0][8]
#define DolbyPL				display_icons[0][9]
#define DTS					display_icons[0][10]
#define NEO					display_icons[0][11]
#define DVD					display_icons[0][12]
#define CD					display_icons[0][13]
#define MP3					display_icons[0][14]

/*Unique icons light status list
* OFF by default	*/
bool display_icons[ICON_GRIDS][SEGMENTS];

//Fill up the list with default
for (uint8_t i = 0; i < ICON_GRIDS; i++)
	for (uint8_t i = 0; i < SEGMENTS; i++)
		display_icons[ICON_GRIDS][SEGMENTS] = OFF;