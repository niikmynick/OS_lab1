//
// Created by Никита Кобик on 27.10.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bin_search.h"
#include "ema_search_int.h"
#include "start_bench.h"

void cmd_start_bench(char **args, int argc) {
  if (argc < 4) {
    fprintf(
        stderr,
        "Usage: startbench <bench-name> <filename> <target> [-c <count>]\n");
    return;
  }

  const char *bench_name = args[1];

  int count = 1;

  for (int i = 4; i < argc; i++) {
    if (strcmp(args[i], "-c") == 0) {
      if (i + 1 >= argc) {
        fprintf(stderr, "Usage: startbench <bench-name> <filename> <target> "
                        "[-c <count>]\n");
        return;
      }

      count = (int)strtol(args[i + 1], NULL, 10);

      if (count <= 0) {
        fprintf(stderr, "Count must be a positive integer.\n");
        return;
      }

      i++;
    }
  }

  char **new_args = args + 1;

  if (strcmp(bench_name, "emasearchint") == 0) {
    for (int i = 0; i < count; i++) {
      cmd_ema_search_int(new_args, argc);
    }
  } else if (strcmp(bench_name, "binsearch") == 0) {
    for (int i = 0; i < count; i++) {
      cmd_bin_search(new_args, argc);
    }
  } else {
    fprintf(stderr, "Unknown benchmark: %s\n", bench_name);
  }
}