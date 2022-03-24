#include <thread>
#include <write.cpp>

namespace VFD_Driver {
    class Scene {
    public:
        void Print(std::string word, uint8_t animate, uint8_t text_align);
        void Flush();

        Write Display;
        Port output;

        std::thread display_thread;

        bool run = true;

        void Show(std::string word, uint8_t animate, uint8_t text_align);
    };
}