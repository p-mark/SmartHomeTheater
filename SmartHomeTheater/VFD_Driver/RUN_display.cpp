#include <ui.cpp>

namespace VFD_Driver {
    int main()
    {
        UI ui;

        ui.output.initialise();
        ui.output.SPEAKER_SUB = ON;
        ui.output.SPEAKER_FRONT_RIGHT = ON;
        ui.output.SPEAKER_FRONT_LEFT = ON;

        ui.eventLoop();
    }
}