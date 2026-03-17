#define _XOPEN_SOURCE 600

#include "builtin.h"
#include <time.h>
#include <stdlib.h>

builtin_cmnd* base_cmnds_ft[BASE_COMMANDS_COUNT] = { exit_cmnd, echo_cmnd, timenow_cmnd, schedtime_cmnd };
char* base_cmnds_strs[BASE_COMMANDS_COUNT] = { "exit", "echo", "timenow", "schedtime" };

// echo command: prints the next argument
void echo_cmnd(void * args) {
	char** output = (char**) args;

	printf("%s\n", *output);
}

// exit command: exits the shell
void exit_cmnd(void * args) {

	exit(EXIT_SUCCESS);
}

void timenow_cmnd(void *args) {

	time_t tm = time(NULL);
	printf("%s", ctime(&tm));
}

void schedtime_cmnd(void *args) {

	struct timespec tm;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tm);	

	double secs = (double)tm.tv_sec + (double)tm.tv_nsec / 100'000'000.0;

	printf("-- shell has executed for %f secs on a CPU --\n", secs);
}
