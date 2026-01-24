#define _XOPEN_SOURCE 700

#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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


int shell_task() {

	char *ln = nullptr;

	size_t args_cap = ARGS_BUFF_SIZE;
	[[maybe_unused]]size_t args_sz = 0;

	char **args = malloc(sizeof(char*) * args_cap);

	if (args == nullptr) {
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
		char *split_ln = strdup(ln);
		args_sz = split_line(&args, &args_cap, split_ln);
		
		free(ln);
		free(split_ln);
		free(args);
	}

	return 0;
}


int main(int argc, char *argv[]) {

	
	shell_task();
	

	return EXIT_SUCCESS;
}
