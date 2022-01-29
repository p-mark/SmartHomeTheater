/*List of special icons*/
//This list have to be manually updated to every specific type of displays

#include <port_ini.h>

#define ICON_GRIDS		(GRIDS - CHARS)
#define ICONS			(ICON_GRIDS * SEGMENTS)
#define ON				1
#define OFF				0

/*Unique icons light status*/
bool display_icons[ICON_GRIDS][SEGMENTS] = {
OFF,	//SPEAKER_CENTER		
OFF,	//SPEAKER_FRONT_RIGHT 
OFF,	//SPEAKER_RIGH		
OFF,	//SPEAKER_BACK_RIGHT	
OFF,	//SPEAKER_FRONT_LEFT	
OFF,	//SPEAKER_LEFT		
OFF,	//SPEAKER_BACK_LEFT	
OFF,	//SPEAKER_SUB			
OFF,	//DolbyDigital		
OFF,	//DolbyPL				
OFF,	//DTS					
OFF,	//NEO					
OFF,	//DVD					
OFF,	//CD					
OFF		//MP3					
};