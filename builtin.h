#ifndef _BUILTIN_H
#define _BUILTIN_H

#include <stdlib.h>
#include <stdio.h>

#define BASE_COMMANDS_COUNT (4)

typedef enum _base_cmnd_t {
    EXIT = 0,
    ECHO = 1,
		NOW_TM = 2,
		SCHED_TM = 3,
} base_cmnd_t;

void echo_cmnd(void *args);
void exit_cmnd(void *args);
void timenow_cmnd(void *args);
void schedtime_cmnd(void *args);


extern void (*base_cmnds_ft[BASE_COMMANDS_COUNT])(void*);
extern char* base_cmnds_strs[BASE_COMMANDS_COUNT];

#endif
