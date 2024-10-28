//
// Created by Никита Кобик on 27.10.2024.
//

#include <stdio.h>
#include <unistd.h>

#include "pwd.h"

void cmd_pwd(char **args, int argc) {
  (void)args;
  (void)argc;

  char cwd[1024];

  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("%s\n", cwd);

  } else {
    perror("getcwd");
  }
}