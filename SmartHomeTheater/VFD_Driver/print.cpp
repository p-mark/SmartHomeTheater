#include <print.h>
#include <display_icons.h>

/*Build and project animated scene with given text_align
and preset icon states*/
void Print(std::string word, uint8_t text_align, uint8_t animation)
{
    //Starting with text
    jumpGrid(CHARS_BEGIN);
    writeWord(std::string word, text_align);

    //Handle the Icons
    for (uint8_t i = 0; i < ICON_GRIDS; i++)
        writeGrid(display_icons[i]);
}

/*Build and project the scene with given text_align
and preset icon states*/
void Print(std::string word, uint8_t text_align = CENTER)
{
    //Starting with text
    jumpGrid(CHARS_BEGIN);
    writeSentence(std::string word, text_align);

    //Handle the Icons
    for (uint8_t i = 0; i < ICON_GRIDS; i++)
        writeGrid(display_icons[i]);
}

int main() {
    Print("Tiszavirág kemping");
    return 0;
}