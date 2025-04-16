# Linux Shell

A custom Linux shell implementation for executing commands, handling redirection, piping, and more. This project is designed for educational purposes and demonstrates how a basic shell works internally.

---

## Features

### Core Features
1. **Command Prompt**:
   - Displays a prompt (e.g., `sh>`) and reads user input.

2. **Command Execution**:
   - Supports basic Linux commands (e.g., `ls`, `pwd`, `echo`) using `fork()` and `exec()` system calls.

3. **Input and Output Redirection**:
   - Input redirection (`<`) to read input from a file.
   - Output redirection (`>`) to overwrite a file.
   - Append redirection (`>>`) to append output to a file.

4. **Command History**:
   - Maintains a history of executed commands.
   - Allows users to view history using the `history` command.

5. **Change Directory**:
   - Implements a built-in `cd` command to change the current working directory.

6. **Exit Command**:
   - Implements a built-in `exit` command to terminate the shell.

7. **Signal Handling**:
   - Handles `CTRL+C` (SIGINT) to terminate the currently running command without exiting the shell.
   - Prevents the shell itself from being terminated by `CTRL+C`.

8. **Error Handling**:
   - Displays appropriate error messages for invalid commands or syntax errors.
   - Handles cases like missing files for redirection or invalid pipes.

---

## How to Run

### Prerequisites
- A Linux-based operating system.
- GCC compiler installed.

### Steps to Run
1. Clone the repository or download the source code.
2. Navigate to the project directory:
   ```bash
   cd /path/to/linux-shell


### Build the shell
3. Compile the source code:
   ```bash
    make
    ```
4. Run the shell:
    ```bash
    ./shell
    ```

### Alternative way to run (optional)
5. ```bash
    gcc -o shell src/main.c src/parser.c src/executor.c src/history.c src/signal_handler.c src/builtins.c -Iinclude
    ```

6. Run the shell:
    ```bash
    ./shell
    ```

    