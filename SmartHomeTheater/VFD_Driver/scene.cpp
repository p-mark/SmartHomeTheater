#include <scene.h>

namespace VFD_Driver
{
    /*Show text / Play animaton on a new thread*/
    void Scene::Print(std::string word, uint8_t animate, uint8_t text_align)
    {
        Scene::Flush();
        display_thread(Show, word, animate, text_align);
    }

    /*Stop running display*/
    void Scene::Flush() {
        if (display_thread.joinable()) {
            run = false;
            display_thread.join();
            run = true;
        }
    }

    /*Build and project scene with preset icon states
    and given propreties: animation, text alignment*/
    void Scene::Show(std::string word, uint8_t animate = OFF, uint8_t text_align = CENTER)
    {
        while (run) {
            //Starting with text
            Display.jumpGrid(CHARS_BEGIN);

            //Do we have to animate?
            (animate || (CHARDIGITS < word.length())) ? Display.Word_Animated(word, animate) :
                Display.Word_Aligned(word, text_align);

            //Handle the Icons
            for (uint8_t i = 0; i < ICON_GRIDS; i++)
                Display.Grid(display_icons[i]);
        }
    }
}