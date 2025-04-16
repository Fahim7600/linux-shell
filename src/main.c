#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "../include/parser.h" 
#include "../include/executor.h"
#include "../include/history.h"
#include "../include/builtins.h"
#include "../include/signal_handler.h"

#define INPUT_BUFFER_SIZE 1024

extern volatile sig_atomic_t sigint_received; 


void initialize_shell();
void cleanup_shell();
void initialize_history();

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

        if (strcmp(input, "history") == 0) {
            display_history(); // Display the command history
            continue;
        }

        if (strncmp(input, "cd", 2) == 0) {
            char *path = input + 3; // Extract the path after "cd "
            handle_cd(path);        // Call the function to change the directory
            continue;
        }

        if (strcmp(input, "exit") == 0) {
            cleanup_shell();
            exit(0);
        }

        Command *cmd = parse_input(input);
        execute_commands(cmd);
        free_command(cmd);
    }

    cleanup_shell();
    return 0;
}

void cleanup_shell() {
    printf("Shell cleanup.\n");
}

void initialize_shell() {
    setup_signal_handlers(); // Set up signal handlers
    printf("Shell initialized (signal handlers set up).\n");
}