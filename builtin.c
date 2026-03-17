#include "builtin.h"
#include <stdlib.h>

void (*base_cmnds_ft[BASE_COMMANDS_COUNT])(void*) = { exit_cmnd, echo_cmnd }; // function table for builtin commands
char* base_cmnds_strs[BASE_COMMANDS_COUNT] = { "exit", "echo" }; // command strings (map)

// echo command: prints the next argument
void echo_cmnd(void * args) {

    char** output = (char**) args;

    printf("%s\n", *output);
}

// exit command: exits the shell
void exit_cmnd(void * args) {

    exit(EXIT_SUCCESS);
}
