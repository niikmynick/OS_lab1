//
// Created by Никита Кобик on 25.10.2024.
//
#ifndef UTILS_H

#define MAX_ARGS 128
#define MAX_COMMAND_LEN 1024
#define PATH_LEN 1024

// represents command with its name and handler
typedef struct {
  const char *name;
  void (*func)(char **args, int argc);
} Command;

void print_prompt();
void execute_command(char *input, const Command *commands);
int parse_input(char *input, char **args);

#endif
