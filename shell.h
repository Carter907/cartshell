#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

typedef enum lp_status {
  ACTIVE = 0,
  PAUSE = 1,

} Status;

void loop(void);
bool handle_input(char *line);

#endif
