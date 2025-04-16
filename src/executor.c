#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "../include/executor.h"
#include "../include/signal_handler.h"
#include "../include/parser.h"

extern volatile pid_t child_pid; 

void execute_commands(Command *cmd) {
    if (cmd->args[0] == NULL) {
        return;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return;
    }

    if (pid == 0) {
        // Child process

        // Handle input redirection
        if (cmd->input_file) {
            int fd = open(cmd->input_file, O_RDONLY);
            if (fd < 0) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDIN_FILENO);
            close(fd);
        }

        // Handle output redirection
        if (cmd->output_file) {
            int fd;
            if (cmd->append) {
                fd = open(cmd->output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
            } else {
                fd = open(cmd->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            }
            if (fd < 0) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
        }

        // Execute the command
        if (execvp(cmd->args[0], cmd->args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        child_pid = pid;
        int status;
        waitpid(pid, &status, 0);
        child_pid = -1;
    }
}