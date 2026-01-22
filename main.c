#define _XOPEN_SOURCE 700

#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define ARGS_BUFF_SIZE 256
#define DELIM_WHITESPACE (" \t\r\n")


void read_line(char **ln) {

	size_t ln_sz = 0;

	char* target = nullptr;

	if (getline(&target, &ln_sz, stdin) != -1) {
		*ln = target;	
		return;
	}

	if (feof(stdin)) 
		exit(EXIT_SUCCESS);
	
	perror("read_line()");
	exit(EXIT_FAILURE);
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
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		
		tok = strtok(nullptr, DELIM_WHITESPACE);
		
	} while (tok != nullptr);

	return pos;
}


int shell_task() {

	char *ln;

	size_t args_cap = ARGS_BUFF_SIZE;
	size_t args_sz;

	char **args = malloc(sizeof(char*) * args_cap);

	if (args == nullptr) {
		perror("malloc()");
		exit(EXIT_FAILURE);
	}
	
	while (true) {

		printf("> ");
		read_line(&ln);
		char *split_ln = strdup(ln);
		args_sz = split_line(&args, &args_cap, split_ln);
		
		printf("line %s", ln);
		printf("size %ld\n", args_sz);

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
