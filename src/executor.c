#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../include/executor.h"
#include "../include/signal_handler.h"

extern volatile pid_t child_pid; 

void execute_commands(char **parsed_commands) {
    if (parsed_commands[0] == NULL) {
        return;
    }

    pid_t pid = fork(); 

    if (pid < 0) {
        perror("fork");
        return;
    }

    if (pid == 0) {
        // Child process
        if (execvp(parsed_commands[0], parsed_commands) == -1) {
            perror("execvp");
        }
        exit(EXIT_FAILURE); 
    } else {
        
        child_pid = pid; 
        int status;
        waitpid(pid, &status, 0); 
        child_pid = -1; 
    }
}