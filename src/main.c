#define _XOPEN_SOURCE 700

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "builtin.h"

#define ARGS_BUFF_SIZE (256)
#define DELIM_WHITESPACE (" \t\r\n")

#define LINE_BUFF_SIZE (64)

const char *SHELL_PROMPT_STR = "carsh->";

int read_line(char **ln) {

  size_t ln_sz = 0;
  size_t buff_cap = LINE_BUFF_SIZE;

  *ln = malloc(sizeof(char) * LINE_BUFF_SIZE);

  int next_char;

  while ((next_char = getchar()) != EOF) {

    char ch = (char)next_char;
    (*ln)[ln_sz++] = ch;

    if (ln_sz == buff_cap) {
      buff_cap *= 2;
      *ln = realloc(*ln, sizeof(char) * buff_cap);
    };

    if (next_char == '\n')
      break;
  };

  if (feof(stdin)) {
    free(*ln);
    return -1;
  }

  (*ln)[ln_sz] = '\0';

  return 0;
}

size_t split_line(char ***split_ln, size_t *split_ln_sz, char *ln) {

  if (*split_ln == nullptr) {
    *split_ln = malloc(sizeof(char *) * ARGS_BUFF_SIZE);
  }

  size_t pos = 0;
  char *tok = strtok(ln, DELIM_WHITESPACE);

  do {

    (*split_ln)[pos] = tok;
    pos++;

    if (pos == *split_ln_sz) {

      (*split_ln_sz) *= 2;
      *split_ln = realloc(*split_ln, sizeof(char *) * (*split_ln_sz));

      if (*split_ln == nullptr) {
        perror("realloc()");
        exit(EXIT_FAILURE);
      }
    }

    tok = strtok(nullptr, DELIM_WHITESPACE);

  } while (tok != nullptr);

  (*split_ln)[pos] = (char *)NULL;

  return pos;
}

void launch_command(char **args) {

  pid_t pid = fork();
  switch (pid) {
  case 0:
		size_t path_len = strlen("/usr/bin/") + strlen(*args) + 1;
    char *path = malloc(path_len);
		if (path == NULL) {
			perror("malloc");
			_exit(EXIT_FAILURE);
		}
    snprintf(path, path_len, "/usr/bin/%s", *args);
    if (execvp(path, (args)) == -1) {
      perror("execvp");
      _exit(EXIT_FAILURE);
    }
    break;
  default:
    wait(NULL);
    break;
  case -1:
    perror("fork");
    _exit(EXIT_FAILURE);
    break;
  }
}

void handle_command(char **split_ln) {

  for (int i = 0; i < BASE_COMMANDS_COUNT; i++) {

    if (strcmp(split_ln[0], base_cmnds_strs[i]) == 0) {
      base_cmnds_ft[i]((void *)(split_ln + 1));
      return;
    }
  }
  launch_command(split_ln);
}

int shell_task() {

  char *ln = nullptr;

  size_t cmnd_cap = ARGS_BUFF_SIZE;
  [[maybe_unused]] size_t cmnd_size = 0;

  char **cmnd_split = malloc(sizeof(char *) * cmnd_cap);

  if (cmnd_split == nullptr) {
    perror("malloc()");
    exit(EXIT_FAILURE);
  }

  while (true) {

    printf("%s ", SHELL_PROMPT_STR);
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
