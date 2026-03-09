#include "builtin.h"
#include <stdlib.h>

void (*base_cmnds_ft[BASE_COMMANDS_COUNT])(void*) = { exit_cmnd, echo_cmnd };
char* base_cmnds_strs[BASE_COMMANDS_COUNT] = { "exit", "echo" };



void echo_cmnd(void * args) {

    char** output = (char**) args;

    printf("%s\n", *output);
}

void exit_cmnd(void * args) {

    exit(EXIT_SUCCESS);
}
