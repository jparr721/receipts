#ifndef THEIA_THEIA_HPP
#define THEIA_THEIA_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>
#include <map>
#include <algorithm>
#include <fstream>

namespace Theia{
	class Theia{
	public:
		Theia();
		~Theia();
		std::string removeJson(std::string, bool);
		std::string retreiveData(std::string);
		//   	template <class KTy, class Ty>
	    //   	void mapStatsToFile(std::map<KTy, Ty>, std::string);
		static void output();

	private:
		static size_t curlWriteCallback(void*, size_t, size_t, std::string*);
	};
}

#endif //THEIA_THEIA_HPP