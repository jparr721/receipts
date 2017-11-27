#ifndef ODIN_ODIN_HPP
#define ODIN_ODIN_HPP

#include <iostream>
#include <stdio.h>
#include <curl/curl.h>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>

namespace Odin {
	class Odin {
		public:
			~Odin();
			
			// void retreiveData(std::string);
			// void postData();
	  //   	static  size_t curlWriteCallback(void*, size_t, size_t, std::string*);
	  //   	std::string cleanUpData(std::string);
	  //   	std::map exportToHashmap(std::string);

	  //   	template <class KTy, class Ty>
	  //   	void mapStatsToFile(std::map<KTy, Ty>, std::string);
	};
}

#endif //ODIN_ODIN_HPP