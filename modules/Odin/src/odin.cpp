#include <Odin/odin.hpp>

Odin::Odin::~Odin() {}

size_t Odin::Odin::curlWriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
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

template <class KTy, class Ty>
void Odin::Odin::mapStatsToFile(std::map<KTy, Ty> map, std::string fileName) {
	std::ofstream outFile;
	outFile.open(fileName);
	outFile << "Name " << " Frequency" << std::endl;
	for (auto it = map.cbegin(); it != map.cend(); ++it)
		outFile << it->first << " : " << it->second << "\n";
}

std::map Odin::exportToHashmap(std::string input) {
	std::map<std::string, unsigned int> foodFrequency;
}

/**
* Cleans JSON formatting off of the input
**/
std::string Odin::Odin::cleanUpData(std::string input) {
	// Find location of first square bracket
	size_t position = input.find("[");

	// Delete them boys
	input.erase(0, position);

	// Next, find the brackets, quotes, etc... and delete them
	input.erase(std::remove(input.begin(), input.end(), '['), input.end());
	input.erase(std::remove(input.begin(), input.end(), ']'), input.end());
	input.erase(std::remove(input.begin(), input.end(), '{'), input.end());
	input.erase(std::remove(input.begin(), input.end(), '}'), input.end());
	input.erase(std::remove(input.begin(), input.end(), '\"'), input.end());

	// Replace the commans with spaces to clean up formatting
	std::replace(input.begin(), input.end(), ',', ' ');

	std::cout << input << std::endl;

	return "done";
}

// Send a GET request to API to retreive image
void Odin::Odin::retreiveData(std::string URL) {
	CURL *curl;
 	CURLcode res;
 	std::map<std::string, unsigned int> frequencyMap;
 
	curl_global_init(CURL_GLOBAL_DEFAULT);

	curl = curl_easy_init();
	std::string s;
	if(curl) {
	curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
			
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); // for https
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); // for https
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

	/* Perform the request, res will get the return code */ 
	res = curl_easy_perform(curl);
	/* Check for errors */ 
	if(res != CURLE_OK)
	  fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

	/* always cleanup */ 
	curl_easy_cleanup(curl);
	}
	// std::cout << s << std::endl;
	cleanUpData(s);
	std::cout << "Finished." << std::endl;

	curl_global_cleanup();
}

// Submit a post request to API link to send dat
void Odin::Odin::postData() {
	CURL *curl;
	CURLcode res;

	// Initialize environment
	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://104.236.200.91/index.php/food/types");

		// Specify the data
		// curl_easy_setopt
	}
}


int main(void) {
	Odin rm;
	rm.retreiveData("http://104.236.200.91/index.php/food/names");
	return 0;
}
