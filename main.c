
#include <fcntl.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

typedef enum lp_status {
  ACTIVE = 0,
  PAUSE = 1,

} Status;

void loop(void) {
  char *line;
  char **args;
  Status status;

  do {

  } while (status == ACTIVE);
}

int main(int argc, char *argv[]) {

  int opt;
  int hello_flag = 0;
  int bye_flag = 0;

  // Command-line option parsing
  while ((opt = getopt(argc, argv, "hb")) != -1) {
    switch (opt) {
    case 'h':
      hello_flag = 1;
      break;
    case 'b':
      bye_flag = 1;
      break;
    default:
      fprintf(stderr, "Usage: %s [-hb] file\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  if (hello_flag) {
    printf("Hello!\n");
  }
  if (bye_flag) {
    printf("Bye\n");
  }

  exit(EXIT_SUCCESS);
}
