#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sched.h>

// contnr run <file>

void run(char* curr, char *file) {
    char *args[] = {curr, "child", file, NULL};
    execvp("/proc/self/exe", args);
}

void child(char *file) {
    char *args[] = {file, NULL};
    execvp(file, args);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "usage: %s run <file>", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "run") == 0) {
        run(argv[1], argv[2]);
    } else if (strcmp(argv[1], "child") == 0) {
        child(argv[2]);
    } else {
        fprintf(stderr, "unknown command: %s", argv[1]);
        exit(1);
    }
}