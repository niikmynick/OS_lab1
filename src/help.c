//
// Created by Никита Кобик on 27.10.2024.
//
#include <stdio.h>

#include "help.h"


void cmd_help(char **args, int argc) {
    (void)args;
    (void)argc;

    printf("Available commands:\n");
    printf("pwd             - print the current directory\n");
    printf("cd              - change directory\n");
    printf("ls              - list files in the current directory\n");
    printf("help            - show this help message\n");
    printf("echo            - print arguments to the console\n");
    printf("cat             - display the content of files\n");
    printf("emasearchint    - search for an integer in a file using EMA\n");
    printf("binsearch       - search for an integer in a file using binary search\n");
    printf("gendat          - generate random data and write it to a file\n");
    printf("exit            - exit the shell\n");
}
