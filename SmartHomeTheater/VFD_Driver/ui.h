#include <iostream>
#include <scene.cpp>

namespace VFD_Driver {
	class UI {
	public:
		void help();
		void print(std::string input);
		void eventLoop();

		Port output;
	private:
		Scene scene;
	};
}