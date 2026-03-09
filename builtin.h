#ifndef _BUILTIN_H
#define _BUILTIN_H

#include <stdlib.h>
#include <stdio.h>

#define BASE_COMMANDS_COUNT (2)

typedef enum _base_cmnd_t {
    EXIT = 0,
    ECHO = 1,
} base_cmnd_t;

void echo_cmnd(void * args);
void exit_cmnd(void * args);

extern void (*base_cmnds_ft[BASE_COMMANDS_COUNT])(void*);
extern char* base_cmnds_strs[BASE_COMMANDS_COUNT];

#endif
