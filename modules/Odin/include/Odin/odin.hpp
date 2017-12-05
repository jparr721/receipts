#ifndef ODIN_ODIN_HPP
#define ODIN_ODIN_HPP

#include <iostream>
#include <stdio.h>
#include <curl/curl.h>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <Theia/theia.hpp>

namespace Odin {
	class Odin {
		public:
			~Odin();
			static void out();
	};
}

#endif //ODIN_ODIN_HPP