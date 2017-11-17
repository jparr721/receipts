#include <iostream>
#include <stdio.h>
#include <curl/curl.h>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>

class RequestMapper {
	public:
		void retreiveData(std::string);
		void postData();
    	static  size_t curlWriteCallback(void*, size_t, size_t, std::string*);
    	std::string cleanUpData(std::string);
    	std::map exportToHashmap(std::string);

    	template <class KTy, class Ty>
    	void mapStatsToFile(std::map<KTy, Ty>, std::string);
};
