#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/builtins.h"

void handle_cd(const char *path) {
    if (path == NULL || strlen(path) == 0) {
        path = getenv("HOME"); // Default to the home directory if no path is provided
    }

    if (chdir(path) != 0) {
        perror("cd");
    }
}