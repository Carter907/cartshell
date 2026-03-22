#define _XOPEN_SOURCE 700

#include "builtin.h"
#include <stdlib.h>
#include <time.h>

builtin_cmnd *base_cmnds_ft[BASE_COMMANDS_COUNT] = {
    exit_cmnd, schedtime_cmnd};

char *base_cmnds_strs[BASE_COMMANDS_COUNT] = {"exit",
                                              "schedtime"};

// exit command: exits the shell
void exit_cmnd(void *args) { exit(EXIT_SUCCESS); }

void schedtime_cmnd(void *args) {

  struct timespec tm;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tm);

  double secs = (double)tm.tv_sec + (double)tm.tv_nsec / 100'000'000.0;

  printf("-- shell has executed for %f secs on a CPU --\n", secs);
}
