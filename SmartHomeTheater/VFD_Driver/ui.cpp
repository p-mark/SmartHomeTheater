#include <ui.h>

/*Basic user interface for terminal control*/
namespace VFD_Driver {

	/*Prints help for commands*/
	void UI::help() {
		std::cout << "print \"message\"\tWrites out the message to the display\n";
		std::cout << "\t-a\tAnimate\n";
		std::cout << "\t-c\tCenter\n";
		std::cout << "\t-l\tLeft\n";
		std::cout << "\t-r\tRight\n";
		std::cout << "\t-c\tCenter\n";
		std::cout << "clear\tClears the display\n";
		std::cout << "exit\tExit\n";
		std::cout << "\te\tAlias exit\n";
	}

	/*Handle print command*/
	void UI::print(std::string input)
	{
		unsigned begin = input.find('"');
		unsigned end = input.find_last_of('"');
		std::string message = input.substr(begin, end - begin);
		input.erase(begin, end - begin + 1);

		if (input.find(" -a "))
		{
			if (input.find(" -c "))
			{
				scene.Print(message, ON, CENTER);
			}
			else if (input.find(" -l "))
			{
				scene.Print(message, ON, LEFT);
			}
			else if (input.find(" -r "))
			{
				scene.Print(message, ON, RIGHT);
			}
		}
		else if (input.find(" -c "))
		{
			scene.Print(message, OFF, CENTER);
		}
		else if (input.find(" -l "))
		{
			scene.Print(message, OFF, LEFT);
		}
		else if (input.find(" -r "))
		{
			scene.Print(message, OFF, RIGHT);
		}
	}

	/*Handle user input*/
	void UI::eventLoop()
	{
		std::cout << "print --help for more information" << std::endl;

		while (true)
		{
			std::cin >> input;


			if (input.find("print "))
				print(input);

			else if ((input == "e") || (input == "exit"))
			{
				scene.Flush();
				return 0;
			}
			else if (input.find("--help"))
				help();

			else if (input == "clear")
				scene.Flush();

			else { std::cout << "Cannot recognise your command :( Maybe try --help"; }
		}
	}
}