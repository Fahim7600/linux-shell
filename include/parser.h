#ifndef PARSER_H
#define PARSER_H

#define MAX_TOKENS 128

typedef struct {
    char **args;       // Command and arguments
    char *input_file;  // Input redirection file
    char *output_file; // Output redirection file
    int append;        // Flag for append mode (1 if >> is used)
} Command;

// Function to parse user input into a Command structure
Command *parse_input(const char *input);

// Function to free a Command structure
void free_command(Command *cmd);

#endif // PARSER_H