#include <stdlib.h>
#include <stdio.h>
#include <curl/curl.h>
#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <Theia/theia.hpp>

namespace Theia {
	// Theia() {}
	// ~Theia() {}

	void output() {
		std::cout << "Does it work?" << std::endl;
	}

	/**
	* Private helper method to write the curl data to a variable

	* @param void* contents - This value is inserted by the curl request
	* @param size_t size - Request size
	* @param size_t nmemb - Allocated memory
	* @param std::string s - The string the data is mapped to
	* (and allocated space for)
	*/
	size_t curlWriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
		size_t newLength = size*nmemb;
		size_t oldLength = s->size();
		try {
			s->resize(oldLength + newLength);
		} catch (std::bad_alloc &e) {
			// Temporary error
			std::cout << "ERROR: Bad memory allocation" << std::endl;
			return 0;
		}

		std::copy((char*)contents, (char*)contents+newLength, s->begin()+oldLength);
		return size*nmemb;
	}

	/**
	* Removes JSON formatting from data retreived via CURL
	*
	* @param unformattedString - The unformatted JSON string
	* @param printout - boolean which will print the formatted
	* string to the console if true.
	*/
	std::string removeJson(std::string unformattedString, bool printout) {
		size_t startOfJson = 0;

		if (unformattedString.empty()) {
			return "ERROR: String is empty";
		}
		// Remove excess text up to first square bracket if in array format
		if (unformattedString.find_first_of('[') != 0) {
			startOfJson = unformattedString.find_first_of('[');

			// Erase everything up to this point
			unformattedString.erase(0, startOfJson);
		// If not displayed in Array format
		} else {
			startOfJson = unformattedString.find_first_of('{');

			// Once again, erase to the first squggle
			unformattedString.erase(0, startOfJson);
		}

		// Remove all sorts of excess formatting from the JSON object
		unformattedString.erase(std::remove(unformattedString.begin(), unformattedString.end(), '['), unformattedString.end());
		unformattedString.erase(std::remove(unformattedString.begin(), unformattedString.end(), ']'), unformattedString.end());
		unformattedString.erase(std::remove(unformattedString.begin(), unformattedString.end(), '{'), unformattedString.end());
		unformattedString.erase(std::remove(unformattedString.begin(), unformattedString.end(), '}'), unformattedString.end());
		unformattedString.erase(std::remove(unformattedString.begin(), unformattedString.end(), '\"'), unformattedString.end());

		// Replace the commas with spaces, it looks cleaner
		std::replace(unformattedString.begin(), unformattedString.end(), ',', ' ');

		if (printout) {
			std::cout << unformattedString << std::endl;
			return unformattedString;
		} else {
			return unformattedString;
		}
	}

	/**
	* Sends a curl GET request to the API and
	* returns it as a string.
	*
	* This code features one parameter
	* @param URL - Takes the API route to be processed
	* @return - This returns the data from the API as
	* 			a string
	*/
	std::string retreiveData(std::string URL) {
		CURL *curl;
	 	CURLcode res;

		curl_global_init(CURL_GLOBAL_DEFAULT);

		curl = curl_easy_init();
		std::string response;
		if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());

			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); // for https
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); // for https
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if(res != CURLE_OK)
		  fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

		/* always cleanup */
		curl_easy_cleanup(curl);
		}

		curl_global_cleanup();
		return response;
	}

	/**
	* Count occurances of all words, will be used for prediction
	*
	* @param input String input to be processed
	*/
	void countOccurences(std::string input) {
		std::map <std::string, unsigned int> totalOccurances;

		// Remove the JSON formatting, we just want the words.

	}

	void mapStatsToFile(std::string input) {
		std::ofstream data_file ("user_data");

		data_file << input << std::endl;

		data_file.close();
	}
}
