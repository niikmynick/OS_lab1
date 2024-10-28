//
// Created by Никита Кобик on 27.10.2024.
//
#include <stdio.h>

#include "echo.h"

void cmd_echo(char **args, int argc) {
  for (int i = 1; i < argc; i++) {
    printf("%s ", args[i]);
  }

  printf("\n");
}