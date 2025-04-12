#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "../include/parser.h" 
#include "../include/executor.h"
#include "../include/history.h"

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

        add_to_history(input);
        if(strcmp(input, "history") == 0) {
            display_history();
            continue;
        }



        char **parsed_commands = parse_input(input);

        execute_commands(parsed_commands);

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