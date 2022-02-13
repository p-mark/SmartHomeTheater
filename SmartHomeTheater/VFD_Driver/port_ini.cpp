#include <port_ini.h>
namespace VFD_Driver {
	void Port::initialise()
	{
		/*Initialise Deamon*/
		if (gpioInitialise() < 0) exit(1);
		std::cout << "Deamon icialised!" << std::endl;

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


		/*Fill up the icon light status list to set them OFF*/
		for (uint8_t i = 0; i < ICON_GRIDS; i++)
			for (uint8_t i = 0; i < SEGMENTS; i++)
				display_icons[ICON_GRIDS][SEGMENTS] = OFF;

		std::cout << "Ports are clear to use." << std::endl;
	}
}