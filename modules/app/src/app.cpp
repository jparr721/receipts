#include <iostream>
#include <Theia/theia.hpp>
#include <Odin/odin.hpp>

int main(int argc, char* argv[]) {
	std::cout << "Main App Firing" << std::endl;
	Theia::Theia::output();
	Odin::Odin::out();
	return EXIT_SUCCESS;
}