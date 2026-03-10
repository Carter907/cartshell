#define _GNU_SOURCE

#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "builtin.h"

#define ARGS_BUFF_SIZE 256
#define DELIM_WHITESPACE (" \t\r\n")


int read_line(char **ln) {

	size_t ln_sz = 0;
	char* targ = nullptr;

	if (getline(&targ, &ln_sz, stdin) != -1) {
		*ln = targ;		
		return 0;
	}

	if (feof(stdin)) 
		exit(EXIT_SUCCESS);
	
	return -1;
}


size_t split_line(char ***split_ln, size_t *split_ln_sz, char *ln) {

  if (*split_ln == nullptr) {
		*split_ln = malloc(sizeof(char*) * ARGS_BUFF_SIZE);
  }

	size_t pos = 0;	
	char* tok = strtok(ln, DELIM_WHITESPACE);
		
	do {
	
		(*split_ln)[pos] = tok;
		pos++;

		if (pos == *split_ln_sz) {

			(*split_ln_sz) *= 2;
			*split_ln = realloc(*split_ln, sizeof(char*) * (*split_ln_sz));			

			if (*split_ln == nullptr) {
				perror("realloc()");
				exit(EXIT_FAILURE);
			}
		}
		
		tok = strtok(nullptr, DELIM_WHITESPACE);
		
	} while (tok != nullptr);

	return pos;
}

void handle_command(char **split_ln) {

    for (int i = 0; i < BASE_COMMANDS_COUNT; i++) {
            
        if (strcmp(split_ln[0], base_cmnds_strs[i]) == 0) {
            base_cmnds_ft[i]((void*)(split_ln + 1)); 
        }
    }
}

int shell_task() {

	char *ln = nullptr;

	size_t cmnd_cap = ARGS_BUFF_SIZE;
	[[maybe_unused]]size_t cmnd_size = 0;

	char **cmnd_split = malloc(sizeof(char*) * cmnd_cap);

	if (cmnd_split == nullptr) {
		perror("malloc()");
		exit(EXIT_FAILURE);
	}
	
	while (true) {

		printf("> ");
		int rt = read_line(&ln);

		if (rt == -1) {
			perror("readline()");
			exit(EXIT_FAILURE);
		}

		char *input_ln = strdup(ln);

		cmnd_size = split_line(&cmnd_split, &cmnd_cap, input_ln);

    handle_command(cmnd_split); 
		
		free(ln);
    ln = nullptr;
		free(input_ln);
    input_ln = nullptr;
		free(cmnd_split);
    cmnd_split = nullptr;
	}
 
	return 0;
}


int main(int argc, char *argv[]) {

	shell_task();

	return EXIT_SUCCESS;
}
