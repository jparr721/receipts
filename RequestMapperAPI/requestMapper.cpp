#include "requestMapper.hpp"

// Send a GET request to API to retreive image
void RequestMapper::retreiveData(std::string url) {
	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://104.236.200.91/index.php/food");
		res = curl_easy_perform(curl);

		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
}

// Submit a post request to API link to send data
void RequestMapper::postData() {
	
}


int main(void) {
	RequestMapper rm;
	rm.retreiveData("sample");
	return 0;
}
