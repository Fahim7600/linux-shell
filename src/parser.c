#include "../include/parser.h" // Use the definition from parser.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Command *parse_input(const char *input) {
    Command *cmd = malloc(sizeof(Command));
    if (!cmd) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    cmd->args = malloc(MAX_TOKENS * sizeof(char *));
    cmd->input_file = NULL;
    cmd->output_file = NULL;
    cmd->append = 0;

    char *input_copy = strdup(input);
    char *token = strtok(input_copy, " ");
    int index = 0;

    while (token != NULL) {
        if (strcmp(token, ">") == 0) {
            token = strtok(NULL, " ");
            cmd->output_file = strdup(token);
        } else if (strcmp(token, ">>") == 0) {
            token = strtok(NULL, " ");
            cmd->output_file = strdup(token);
            cmd->append = 1;
        } else if (strcmp(token, "<") == 0) {
            token = strtok(NULL, " ");
            cmd->input_file = strdup(token);
        } else {
            cmd->args[index++] = strdup(token);
        }
        token = strtok(NULL, " ");
    }

    cmd->args[index] = NULL;
    free(input_copy);
    return cmd;
}

void free_command(Command *cmd) {
    if (!cmd) return;
    for (int i = 0; cmd->args[i] != NULL; i++) {
        free(cmd->args[i]);
    }
    free(cmd->args);
    if (cmd->input_file) free(cmd->input_file);
    if (cmd->output_file) free(cmd->output_file);
    free(cmd);
}