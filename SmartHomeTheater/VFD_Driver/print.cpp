#include <print.h>
#include <display_icons.h>

/*Build and project scene with preset icon states 
and given propreties: animation, text alignment*/
void Print(std::string word, uint8_t animate = OFF, uint8_t text_align = CENTER)
{
    //Starting with text
    jumpGrid(CHARS_BEGIN);
    //Do we have to animate?
    (animate || (CHARDIGITS < word.length)) ? writeWord_Animated(word, animate) : writeWord_Aligned(word, text_align);

    //Handle the Icons
    for (uint8_t i = 0; i < ICON_GRIDS; i++)
        writeGrid(display_icons[i]);
}