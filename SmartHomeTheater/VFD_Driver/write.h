#pragma once

#include <port_ini.h>
#include <charset.h>
#include <timer.h>

namespace VFD_Driver {
	class Write {
	public:
		void jumpGrid(uint8_t index);
		void stepGrid();
		void Grid(bool character[SEGMENTS]);
		void Word(std::string word);

		void Word_Aligned(std::string word, uint8_t text_align);
		void Word_Animated(std::string word, uint8_t animation);

		timer Timer;
	private:
		Port port;
		uint8_t grid_index = 0;

		void Char(char c);
	};
}