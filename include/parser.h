#ifndef PARSER_H
#define PARSER_H

// Function to parse user input into commands and arguments
char **parse_input(const char *input);

// Function to free the memory allocated for parsed input
void free_parsed_input(char **parsed_input);

#endif // PARSER_H