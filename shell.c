#include "shell.h"
#include <fcntl.h>

Status status;
char line[BUFFER_SIZE + 1];

void init() { status = ACTIVE; }

bool handle_input(char *line) { return true; }

void loop(void) {
  do {

    printf("->>>");

    fgets(line, BUFFER_SIZE, stdin);

    int fd =
        open("cartshell.log", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);

    if (!handle_input(line)) {
      exit(EXIT_FAILURE);
    }

  } while (status == ACTIVE);
}
