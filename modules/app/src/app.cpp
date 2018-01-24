#include <iostream>
#include <Theia/theia.hpp>

int main(int argc, char* argv[]) {
	Theia::Theia theia;
	std::cout << "Main App Firing" << std::endl;
	theia.output();
	return EXIT_SUCCESS;
}
