#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64


int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1) {
        printf("shell> ");
        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }

        input[strcspn(input, "\n")] = 0;

        int argc = 0;

        char *token = strtok(input, " ");
        while (token != NULL && argc < MAX_ARGS - 1) {
            args[argc++] = token;
            token = strtok(nullptr, " ");
        }
        args[argc] = nullptr;

        if (argc == 0) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);

        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            continue;
        }

        if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        }

        int status;
        waitpid(pid, &status, 0);

        clock_gettime(CLOCK_MONOTONIC, &end);

        double real_time = (end.tv_sec - start.tv_sec) +
                           (end.tv_nsec - start.tv_nsec) * 1e-9;
        printf("Real time: %.6f seconds\n", real_time);

    }

    return 0;
}
