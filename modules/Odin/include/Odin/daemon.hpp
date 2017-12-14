#include <string>


namespace Odin {
	class Daemon {
	public:
	private:
		int read_conf_file(int);
		int test_conf_file(std::string);
		void handle_signal(int);
		void print_usage();
	};
}