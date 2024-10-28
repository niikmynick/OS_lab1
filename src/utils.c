//
// Created by Никита Кобик on 25.10.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "utils.h"

int parse_input(char *input, char **args) {
  int argc = 0;

  char *token = strtok(input, " ");

  while (token != NULL && argc < MAX_ARGS - 1) {
    args[argc++] = token;
    token = strtok(nullptr, " ");
  }

  args[argc] = nullptr;

  return argc;
}

void print_prompt() {
  char cwd[PATH_LEN];

  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("shell %s > ", cwd);

  } else {
    // fallback if the current directory cannot be retrieved
    perror("getcwd");
    printf("shell > ");
  }
}

void execute_command(char *input, const Command *commands) {
  char *args[MAX_ARGS];
  const int argc = parse_input(input, args);

  if (argc == 0) {
    return;
  }

  const pid_t pid = fork();
  int status;

  switch (pid) {
  case -1:
    perror("fork failed");
    return;

  case 0: // child process
    for (int i = 0; commands[i].name != NULL; i++) {
      if (strcmp(args[0], commands[i].name) == 0) {
        if (commands[i].func != NULL) {
          const clock_t start_time = clock();

          commands[i].func(args, argc);

          const clock_t end_time = clock();
          printf("Execution time: %.2fms\n",
                 ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000);

        } else {
          // handle exit command
          exit(EXIT_SUCCESS);
        }
        exit(EXIT_SUCCESS);
      }
    }

    // command not found
    fprintf(stderr, "Command not found: %s\n", args[0]);
    exit(EXIT_FAILURE);

  default: // parent process
    waitpid(pid, &status, 0);

    if (status == -1) {
      perror("waitpid failed");
    }
    break;
  }
}