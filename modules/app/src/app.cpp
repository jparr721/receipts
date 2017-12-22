#include <iostream>
#include <Theia/theia.hpp>
#include <Odin/odin.hpp>

int main(int argc, char* argv[]) {
	Theia::Theia theia;
	Odin::Odin odin;
	std::cout << "Main App Firing" << std::endl;
	theia.output();
	odin.out();
	return EXIT_SUCCESS;
}
