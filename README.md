# Simple Shell Project

## Overview

This project aims to create a simple shell that emulates the basic functionalities of the Unix shell. The shell is designed to execute commands, manage processes, and handle I/O redirection.

## Project Tasks

### 0. README, man, AUTHORS
- **Files:**
    - `README.md`: Overview, compilation, testing, and submission details.
    - `man_1_simple_shell`: Manual page for the shell.
    - `AUTHORS`: List of contributors.

### 1. Betty would be proud
- **Description:** Write code that passes the Betty checks.
- **Files:**
    - Code files to be written following Betty style.

### 2. Simple shell 0.1
- **Description:** Write a UNIX command line interpreter.
- **Usage:** `simple_shell`
- **Features:**
    - Display a prompt and wait for the user to type a command.
    - The prompt is displayed again after each command execution.
    - Command lines are simple, no advanced features.
    - Handle errors and "end of file" condition.
    - Executable not found results in an error message.

### 3. Simple shell 0.2
- **Description:** Enhance the shell to handle command lines with arguments.

### 4. Simple shell 0.3
- **Description:** Extend the shell to handle the PATH and avoid unnecessary `fork` calls.
- **Examples:**
    ```bash
    $ ./shell_0.3
    :) /bin/ls
    :) ls
    :) ls -l /tmp
    ```

### 5. Simple shell 0.4
- **Description:** Implement the `exit` built-in that exits the shell.
- **Usage:** `exit`

### 6. Simple shell 1.0
- **Description:** Implement the `env` built-in that prints the current environment.
- **Example:**
    ```bash
    $ ./simple_shell
    $ env
    USER=julien
    LANGUAGE=en_US
    ...
    ```

## Requirements

### General
- **Allowed Editors:** vi, vim, emacs
- **Compilation:** `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
- **Coding Style:** Code should use the Betty style and be checked using `betty-style.pl` and `betty-doc.pl`.
- **Memory Management:** Ensure no memory leaks.
- **Functions per File:** No more than 5 functions per file.
- **Header Files:** Include guards in header files.
- **System Calls:** Use system calls only when necessary.

### GitHub
- One project repository per group.
- Avoid cloning/forking a project repository with the same name before the second deadline to prevent a 0% score.

## Compilation and Testing

### Compilation
```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Testing
Interactive Mode
bash
Copy code
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
Non-Interactive Mode
bash
Copy code
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
Additional Information
Output: Same as /bin/sh.
Error Format:
bash
Copy code
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
Documentation: Detailed comments in code.
