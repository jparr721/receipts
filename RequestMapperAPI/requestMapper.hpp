#include <iostream>
#include <stdio.h>
#include <curl/curl.h>
#include <string>

class RequestMapper {
	public:
		void retreiveData(std::string);
		void postData();
};
