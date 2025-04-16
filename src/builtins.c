#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/builtins.h"

void handle_cd(const char *path) {
    if (path == NULL || strlen(path) == 0) {
        // Default to the home directory if no path is provided
        path = getenv("HOME");
    }

    if (chdir(path) != 0) {
        // Print an error message if chdir fails
        perror("cd");
    }
}