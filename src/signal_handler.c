#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/signal_handler.h"

volatile sig_atomic_t sigint_received = 0; // Flag to track SIGINT
volatile pid_t child_pid = -1;             // Track the child process PID

// Signal handler for SIGINT (CTRL+C)
void sigint_handler(int sig) {
    if (child_pid > 0) {
        // Forward SIGINT to the child process
        kill(child_pid, SIGINT);
    } else {
        // Set the flag if no child process is running
        sigint_received = 1;
    }
}

// Function to set up signal handlers
void setup_signal_handlers() {
    struct sigaction sa;

    // Set up the SIGINT handler
    sa.sa_handler = sigint_handler; // Use the custom handler
    sigemptyset(&sa.sa_mask);       // No signals are blocked
    sa.sa_flags = SA_RESTART;       // Restart interrupted system calls
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    // Ignore SIGTSTP (CTRL+Z)
    signal(SIGTSTP, SIG_IGN);
}