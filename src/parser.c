#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

#define MAX_TOKENS 128

// Function to parse user input into commands and arguments
char **parse_input(const char *input) {
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    if (!tokens) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    char *input_copy = strdup(input); // Create a modifiable copy of the input
    if (!input_copy) {
        perror("strdup");
        free(tokens);
        exit(EXIT_FAILURE);
    }

    char *token = strtok(input_copy, " "); // Tokenize the input by spaces
    int index = 0;

    while (token != NULL) {
        tokens[index] = strdup(token); // Allocate memory for each token
        if (!tokens[index]) {
            perror("strdup");
            free(input_copy);
            free_parsed_input(tokens);
            exit(EXIT_FAILURE);
        }
        index++;

        if (index >= MAX_TOKENS - 1) {
            fprintf(stderr, "Error: Too many tokens\n");
            break;
        }

        token = strtok(NULL, " ");
    }

    tokens[index] = NULL; // Null-terminate the array of tokens
    free(input_copy);

    return tokens;
}

// Function to free the memory allocated for parsed input
void free_parsed_input(char **parsed_input) {
    if (!parsed_input) return;

    for (int i = 0; parsed_input[i] != NULL; i++) {
        free(parsed_input[i]);
    }
    free(parsed_input);
}