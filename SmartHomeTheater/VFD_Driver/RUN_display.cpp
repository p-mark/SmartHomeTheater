#include <thread>
#include <ui.h>

UI ui;
    
int main() 
{
    ini::initialise();
    
    SPEAKER_SUB = ON;
    std::string input = "";
    std::cout << "print --help for more information" << std::endl;

    while (true)
    {
        std::cin >> input;

        if ((input == "e") || (input == "exit"))
        {
            ui.flush();
            return 0;
        }
        else if (input.find("--help"))
        {
            ui.help();
        }
        else if (input.find("print "))
        {
            ui.print(input);
        }
        else{std::cout << "Cannot recognise your command :( Maybe try --help";}
    }
}
