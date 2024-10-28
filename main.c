#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bin_search.h"
#include "cat.h"
#include "cd.h"
#include "echo.h"
#include "ema_search_int.h"
#include "generate_data.h"
#include "help.h"
#include "ls.h"
#include "pwd.h"
#include "start_bench.h"
#include "utils.h"

// map command names to their handlers
Command commands[] = {
    {"exit", NULL},
    {"pwd", cmd_pwd},
    {"cd", cmd_cd_wrapper}, // wrapped cd command to handle arguments
    {"ls", cmd_ls},
    {"help", cmd_help},
    {"echo", cmd_echo},
    {"cat", cmd_cat},
    {"emasearchint", cmd_ema_search_int},
    {"binsearch", cmd_bin_search},
    {"gendat", cmd_generate_data},
    {"startbench", cmd_start_bench},
    {NULL, NULL} // sentinel value for the end of the array
};

int main() {
  char input[MAX_COMMAND_LEN];

  while (1) {
    print_prompt();

    if (fgets(input, sizeof(input), stdin) == NULL) {
      // EOF handler
      break;
    }

    input[strcspn(input, "\n")] = '\0';

    if (strlen(input) == 0) {
      continue;
    }

    execute_command(input, commands);
  }

  return EXIT_SUCCESS;
}
