#ifndef HISTORY_H
#define HISTORY_H

// Function to initialize the history
void initialize_history();

// Function to add a command to the history
void add_to_history(const char *command);

// Function to display the history
void display_history();

// Function to clean up history resources
void cleanup_history();

#endif // HISTORY_H