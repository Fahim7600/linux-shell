#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/history.h"

#define MAX_HISTORY 100 // Maximum number of commands to store

static char *history[MAX_HISTORY]; // Array to store command history
static int history_count = 0;      // Number of commands in history

void initialize_history() {
    // Initialize the history array
    for (int i = 0; i < MAX_HISTORY; i++) {
        history[i] = NULL;
    }
}

void add_to_history(const char *command) {
    if (history_count == MAX_HISTORY) {
        // If history is full, free the oldest command and shift the rest
        free(history[0]);
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }
        history_count--;
    }

    // Add the new command to history
    history[history_count] = strdup(command);
    if (!history[history_count]) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }
    history_count++;
}

void display_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d %s\n", i + 1, history[i]);
    }
}

void cleanup_history() {
    // Free all allocated memory for history
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }
}