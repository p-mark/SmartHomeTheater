#include <ui.cpp>

namespace VFD_Driver {
    int main()
    {
        UI ui;

        ui.scene.output.initialise();

        //Icon debug
#define OUTPUT ui.scene.output
        OUTPUT.SPEAKER_SUB = ON;
        OUTPUT.SPEAKER_FRONT_RIGHT = ON;
        OUTPUT.SPEAKER_FRONT_LEFT = ON;

        ui.eventLoop();
    }
}