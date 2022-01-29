#include <print.h>
#include <display_icons.h>

/*Build and project scene with given propreties:
text_align or animation, and preset icon states*/
void Print(std::string word, uint8_t text_align = CENTER, uint8_t animate = OFF)
{
    //Starting with text
    jumpGrid(CHARS_BEGIN);
    (animate || CHARDIGITS < word.length) ? writeWord(word, animate) : writeWord(word, text_align);

    //Handle the Icons
    for (uint8_t i = 0; i < ICON_GRIDS; i++)
        writeGrid(display_icons[i]);
}