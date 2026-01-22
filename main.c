#define _XOPEN_SOURCE 700

#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void read_line(char **ln) {
	size_t ln_s;

	if (getline(ln, &ln_s, stdin) == -1) {
		if (feof(stdin)) {
			exit(EXIT_SUCCESS);
		}
		perror("read_line()");
		exit(EXIT_FAILURE);
	}
}

int shell_task() {

	char *ln;
	
	while (true) {

		printf("> ");
		read_line(&ln);
		
		printf("%s", ln);

		free(ln);
	}

	return 0;
}



int main(int argc, char *argv[]) {

	
	shell_task();
	

	return EXIT_SUCCESS;
}
