#include <Odin/odin.hpp>

Odin::Odin::~Odin() {}

// template <class KTy, class Ty>
// void Odin::Odin::mapStatsToFile(std::map<KTy, Ty> map, std::string fileName) {
// 	std::ofstream outFile;
// 	outFile.open(fileName);
// 	outFile << "Name " << " Frequency" << std::endl;
// 	for (auto it = map.cbegin(); it != map.cend(); ++it)
// 		outFile << it->first << " : " << it->second << "\n";
// }

// std::map Odin::exportToHashmap(std::string input) {
// 	std::map<std::string, unsigned int> foodFrequency;
// }

void Odin::Odin::out() {
	std::cout << "Odin is firing" << std::endl;
}

