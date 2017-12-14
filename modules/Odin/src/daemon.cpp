#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <uninstd.h>
#include <syslog.h>
#include <signal.h>
#include <Odin/daemon.hpp>

int pid_file_descriptor = -1;
/**
* Read from the configuration file or 
* reload the settings.
*/
int Odin::Daemon::read_conf_file(int reload) {
	FILE *conf_file = NULL;

	// Starts at -1
	int status = -1;

	if (conf_file_name == NULL) return 0;

	conf_file = fopen(conf_file_name, "r");

	if (conf_file == NULL) {
		std::syslog(LOG_ERR, "Can't open config file: %s, error: %s", 
			conf_file_name, strerror(errno));

		return -1;
	}

	status = fscanf(conf_file, "%d", &delay);

	if (status > 0) {
		if (reload == 1) {
			syslog(LOG_INFO, "Reloaded configuration file %s of %s", 
				conf_file_name, 
				app_name);
		} else {
			syslog(LOG_INFO, "Configuration of %s read from file %s", 
				app_name,
				conf_file_name);
		}
	}

	fclose(conf_file);

	return status;
}

void Odin::Daemon::handle_signal(int signum) {
	switch(signum) {
		case SIGINT:
			std::fprintf(Odin::system_log, "Debug: stopping daemon process...\n");

			std::signal(SIGINT, SIG_DFL);
			break;
		case SIGHUP:
			fprintf(Odin::system_log, "Debug: reloading system daemon config file...\n");
			// Reload configurations
			read_conf_file(1);
		case SIGTERM:
			fprintf(Odin::system_log, "Debug: term signal sent, exiting....\n");
			exit(1);
	}
}

void Odin::Daemon::print_usage() {
	std::cout << "\n Usage: "<< app_name <<" [OPTIONS]\n" std::endl;
	std::cout << "Options:\n" std::endl;
	std::cout << " -h --help		Print the help screen" std::endl;
}