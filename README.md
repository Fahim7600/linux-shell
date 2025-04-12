
# Linux Shell

A brief description of what this project does and who it's for

Core Features
Command Prompt

1. Display a prompt (e.g., sh>) and read user input.
Command Execution

2. Parse and execute basic Linux commands (e.g., ls, pwd, echo).
Use fork() and exec() system calls.
Input and Output Redirection

3. Support input redirection (<).
Support output redirection (> for overwrite and >> for append).
Command Piping

4. Support piping (|) for chaining commands.
Allow multiple pipes (e.g., command1 | command2 | command3).
Multiple Commands

5. Support multiple commands separated by a semicolon (;).
Execute commands sequentially.
Conditional Execution

6. Support logical AND (&&) for conditional execution of commands.
Advanced Features
Command History

7. Maintain a history of executed commands.
Allow users to view history (e.g., history command).
Optionally, allow re-execution of commands from history (e.g., !<command_number>).
Signal Handling

8. Handle CTRL+C (SIGINT) to terminate the currently running command without exiting the shell.
Prevent the shell itself from being terminated by CTRL+C.
Error Handling

9. Display appropriate error messages for invalid commands or syntax errors.
Handle cases like missing files for redirection or invalid pipes.
Change Directory

10. Implement a built-in cd command to change the current working directory.
Exit Command

11. Implement a built-in exit command to terminate the shell.
Optional Features (Bonus)
Environment Variables

12. Support setting and accessing environment variables (e.g., export VAR=value and $VAR).
Background Execution

13. Support running commands in the background using & (e.g., command &).
Tab Completion

14. Implement basic tab completion for commands and file paths.
Custom Aliases

15. Allow users to define and use custom aliases for commands (e.g., alias ll='ls -l').
Job Control

14. Support job control commands like jobs, fg, and bg.
Shell Scripting

13. Allow execution of shell scripts (e.g., ./script.sh).