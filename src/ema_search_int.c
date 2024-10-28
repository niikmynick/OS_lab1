//
// Created by Никита Кобик on 27.10.2024.
//
#include <stdio.h>
#include <stdlib.h>

#include "ema_search_int.h"

void cmd_ema_search_int(char **args, int argc) {
  if (argc < 3) {
    fprintf(stderr, "Usage: ema-search-int <filename> <target>\n");
    return;
  }

  const char *filename = args[1];

  const int target = (int)strtol(args[2], nullptr, 10);

  FILE *file = fopen(filename, "rb");

  if (!file) {
    perror("fopen");
    return;
  }

  int found = 0;

  int buffer[1024];

  size_t read_count;

  while ((read_count = fread(buffer, sizeof(int), sizeof(buffer) / sizeof(int),
                             file)) > 0) {

    for (size_t i = 0; i < read_count; i++) {

      if (buffer[i] == target) {
        printf("Found %d in file.\n", target);
        found = 1;
        break;
      }
    }

    if (found) {
      break;
    }
  }

  if (!found) {
    printf("Element %d not found in file.\n", target);
  }

  fclose(file);
}