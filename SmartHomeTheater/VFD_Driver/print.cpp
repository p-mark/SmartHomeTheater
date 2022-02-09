#include <print.h>
#include <display_icons.h>
#include <thread>

class VFD{
private:

ini port;
display screen;
std::thread display_thread;

bool run = true;

/*Build and project scene with preset icon states 
and given propreties: animation, text alignment*/
void Print(std::string word, uint8_t animate = OFF, uint8_t text_align = CENTER)
{while(run){
    //Starting with text
    screen.jumpGrid(CHARS_BEGIN);

    //Do we have to animate?
    (animate || (CHARDIGITS < word.length())) ? screen.writeWord_Animated(word, animate) :
        screen.writeWord_Aligned(word, text_align);

    //Handle the Icons
    for (uint8_t i = 0; i < ICON_GRIDS; i++)
        screen.writeGrid(display_icons[i]);
    }
}

public:

/*Show text / Play animaton on a new thread*/
void Show(std::string word, uint8_t animate, uint8_t text_align)
{
    flush();
    display_thread(Print, word, animate, text_align);
}

/*Stop running display*/
void flush() {
    run = false;
    if (display_thread.get_id())
        display_thread.join();
    run = true;
}
};