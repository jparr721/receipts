#include "network_library/boost/network/protocol/http/client.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout<< "Usage: " << argv[0] << " [url]" << std::endl;
		return 1;
	}

	boost::network::http::client client;
	boost::network::http::client::request request(argv[1]);
	request << header("Connection", "close");
	boost::network::http::client::response response = client.get(request);
	std::cout << body(response) << std::endl;

	return 0;
}
