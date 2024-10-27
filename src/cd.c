//
// Created by Никита Кобик on 27.10.2024.
//
#include <stdio.h>
#include <unistd.h>

#include "cd.h"

static void cmd_cd(const char *path) {
    if (chdir(path) != 0) {
        perror("cd");
    }
}

// removes getting the argument from a command handler
void cmd_cd_wrapper(char **args, int argc) {
    if (argc > 1) {
        cmd_cd(args[1]);

    } else {
        printf("cd: missing argument\n");
    }
}