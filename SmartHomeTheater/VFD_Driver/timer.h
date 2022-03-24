#include <iostream>
#include <chrono>
#include <thread>
#include <port_ini.h>

namespace VFD_Driver
{
    class timer
    {public:
        int16_t WORD_TIME = 1000 / REFRESH_RATE;        //milisec/word
        int16_t GRID_TIME = WORD_TIME * 1000 / GRIDS;   //microsec/grid


        //Let time for the grid to emit light
        void wait_grid()
        {
            std::this_thread::sleep_for(std::chrono::microseconds(GRID_TIME));
        }
    };
}