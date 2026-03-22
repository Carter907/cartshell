#ifndef _BUILTIN_H
#define _BUILTIN_H

#include <stdio.h>
#include <stdlib.h>

#define BASE_COMMANDS_COUNT (2)

typedef enum _base_cmnd_t {
  EXIT = 0,
  SCHED_TM = 1,
} base_cmnd_t;

void exit_cmnd(void *args);
void schedtime_cmnd(void *args);

typedef void builtin_cmnd(void *);

extern builtin_cmnd *base_cmnds_ft[BASE_COMMANDS_COUNT];
extern char *base_cmnds_strs[BASE_COMMANDS_COUNT];

#endif
