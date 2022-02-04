#include <print.h>
#include <display_icons.h>


class VFD{
private:

ini port;
display screen;

public:
bool run = true;

/*Build and project scene with preset icon states 
and given propreties: animation, text alignment*/
void Print(std::string word, uint8_t animate = OFF, uint8_t text_align = CENTER)
{while(unchanged){
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
};
