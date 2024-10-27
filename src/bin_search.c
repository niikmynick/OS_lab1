#include <stdio.h>
#include <stdlib.h>

#include "bin_search.h"


void cmd_bin_search(char **args, int argc) {
    if (argc < 3) {
        fprintf(stderr, "Usage: bin-search <filename> <target>\n");
        return;
    }

    const char *filename = args[1];
    const int target = (int) strtol(args[2], nullptr, 10);

    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        return;
    }

    int left = 0, right = -1;
    fseek(file, 0, SEEK_END);
    right = ftell(file) / sizeof(int) - 1;

    int found = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int value;
        fseek(file, mid * sizeof(int), SEEK_SET);
        fread(&value, sizeof(int), 1, file);

        if (value == target) {
            printf("Found %d at position %d.\n", target, mid);
            found = 1;
            break;
        } else if (value < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("Element %d not found in file.\n", target);
    }

    fclose(file);
}

