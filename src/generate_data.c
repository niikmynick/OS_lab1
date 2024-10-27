//
// Created by Никита Кобик on 27.10.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "generate_data.h"


static int compare_ints(const void *a, const void *b) {
    return (*(const int *)a - *(const int *)b);
}


void cmd_generate_data(char **args, int argc) {
    if ((argc < 4) || (argc > 5)) {
        fprintf(stderr, "Usage: generate-data <filename> <number_of_elements> <max_value> [--sorted]\n");
        return;
    }

    const char *filename = args[1];

    const int num_elements = (int) strtol(args[2], nullptr, 10);
    const int max_value = (int) strtol(args[3], nullptr, 10);

    const int sorted = (argc == 5 && strcmp(args[4], "--sorted") == 0);

    int *data = (int *) malloc(num_elements * sizeof(int));
    if (!data) {
        perror("malloc");
        return;
    }

    srand((unsigned int)clock());

    printf("\r<");
    fflush(stdout);

    for (int i = 0; i < num_elements; i++) {
        // print status bar like <====================> 100% where only 10 bars =
        if (i % (num_elements / 10) == 0) {
            printf("=");
            fflush(stdout);
        }

        data[i] = rand() % max_value;
    }
    printf("> 100%%\n");
    fflush(stdout);

    if (sorted) {
        qsort(data, num_elements, sizeof(int), compare_ints);
    }

    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        free(data);
        return;
    }

    fwrite(data, sizeof(int), num_elements, file);
    fclose(file);
    free(data);
    printf("Generated %d random numbers into %s%s.\n", num_elements, filename, sorted ? " (sorted)" : "");
}
