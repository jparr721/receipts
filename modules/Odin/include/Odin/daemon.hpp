#include <stdio.h>
#include <stdlib.h>
#include <uninstd.h>
#include <syslog.h>
#include <signal.h>
#include <string>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

static int runing;
static int delay;
static int counter;
static std::string conf_file_name;
static std::string pid_file_name;
static int pid_fd;
static std::string application_name;
static FILE system_log;

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