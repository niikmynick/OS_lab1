//
// Created by Никита Кобик on 28.10.2024.
//

#include "execute.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cmd_execute(char **args, int argc) {
  if (argc < 2) {
    fprintf(stderr, "Usage: execute <command> [args...]\n");
    return;
  }

  // total length of the command string
  size_t length = 0;
  for (int i = 1; i < argc; i++) {
    length += strlen(args[i]) + 1;
  }

  // memory for the string
  char *command = (char *)malloc(length);
  if (command == NULL) {
    perror("malloc");
    return;
  }

  command[0] = '\0';
  for (int i = 1; i < argc; i++) {
    strcat(command, args[i]);
    if (i < argc - 1) {
      strcat(command, " ");
    }
  }

  const int result = system(command);
  if (result == -1) {
    perror("system");
  }

  free(command);
}