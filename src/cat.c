//
// Created by Никита Кобик on 27.10.2024.
//
#include <stdio.h>

#include "cat.h"


void cmd_cat(char **args, int argc) {
    if (argc < 2) {
        fprintf(stderr, "cat: missing argument\n");
        return;
    }

    FILE *file = fopen(args[1], "r");
    if (!file) {
        perror("cat");
        return;
    }

    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    fclose(file);
}