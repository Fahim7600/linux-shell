#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "../include/parser.h" 

#define INPUT_BUFFER_SIZE 1024

// Function declarations
void initialize_shell();
void cleanup_shell();

int main() {
    char input[INPUT_BUFFER_SIZE]; 
    initialize_shell();

    
    while (1) {
        printf("sh> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");
            break; 
        }

        input[strcspn(input, "\n")] = '\0';

        
        if (strlen(input) == 0) {
            continue;
        }
        char **parsed_commands = parse_input(input);

        // Print the parsed tokens (for testing purposes)
        printf("Parsed tokens:\n");
        for (int i = 0; parsed_commands[i] != NULL; i++) {
            printf("  Token[%d]: %s\n", i, parsed_commands[i]);
        }

        free_parsed_input(parsed_commands);
    }
    cleanup_shell();

    return 0;
}

void initialize_shell() {
    printf("Shell initialized (signal handlers not implemented).\n");
}

void cleanup_shell() {
    printf("Shell cleanup (history not implemented).\n");
}