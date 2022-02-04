#include <iostream>
#include <print.cpp>

VFD Display;

std::thread display_thread(Print, "Hello Word!");

/*Basic user interface for terminal control*/
class UI {
	/*Prints help for commands*/
	void help() {
		std::cout << 'print "message"\tWrites out the message to the display\n';
		std::cout << '\t-a\tAnimate\n';
		std::cout << '\t-c\tCenter\n';
		std::cout << '\t-l\tLeft\n';
		std::cout << '\t-r\tRight\n';
		std::cout << '\t-c\tCenter\n';
		std::cout << 'exit\tExit\n';
		std::cout << '\te\tAlias exit\n';
	}
	
	/*Stop running display*/
	void flush() {
		Display.run = false;
		display_thread.join();
		Display.run = true;
	}

	/*Handle user command*/
	void print(std::string input)
	{
		unsigned begin = input.find('"');
		unsigned end = input.find_last_of('"');
		std::string message = input.substr(begin, end - begin);
		input.erase(begin, end - begin + 1);

		if(input.find(" -a "))
		{
			if (input.find(" -c "))
			{
				flush();
				std::thread display_thread(Print,message,ON, CENTER);
			}
			else if (input.find(" -l "))
			{
				flush();
				std::thread display_thread(Print,message,ON,LEFT,);
			}
			else if (input.find(" -r "))
			{
				flush();
				std::thread display_thread(Print,message, ON, RIGHT,);
			}
		}
		else if (input.find(" -c "))
		{
			flush();
			std::thread display_thread(Print,message, OFF, CENTER);
		}
		else if(input.find(" -l "))
		{
			flush();
			std::thread display_thread(Print,message, OFF, LEFT);
		}
		else if (input.find(" -r "))
		{
			flush();
			std::thread display_thread(Print,message, OFF, RIGHT);
		}
	}
};