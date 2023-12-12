# Simple Shell Project

## Overview
This project involves creating a simple shell that mimics the basic functionalities of the Unix shell. The shell is designed to execute commands, manage processes, and handle I/O redirection.

## Project Tasks
1. **README, man, AUTHORS**
    - **Files:**
        - `README.md`: Overview, compilation, testing, and submission details.
        - `man_1_simple_shell`: Manual page for the shell.
        - `AUTHORS`: List of contributors.

2. **Shell Implementation**
    - **Files:**
        - `shell.c`: Main logic for the shell, including command execution and process management.

## Requirements
- **Editors:** vi, vim, emacs
- **Compilation:** `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
- **Style:** Follow the Betty style. Use `betty-style.pl` and `betty-doc.pl` for style checks.
- **Memory:** No memory leaks.
- **Functions per File:** Limit to 5 functions per file.
- **Headers:** Include guards in header files.

## Allowed Functions and System Calls
- See list in the original prompt.

## Compilation and Testing
- **Compilation:** `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
- **Interactive Mode:**
    ```
    $ ./hsh
    ($) /bin/ls
    hsh main.c shell.c
    ($)
    ($) exit
    $
    ```
- **Non-Interactive Mode:**
    ```
    $ echo "/bin/ls" | ./hsh
    hsh main.c shell.c test_ls_2
    ```

## Submission
- **GitHub Repository:** [holbertonschool-simple_shell](https://github.com/your-username/holbertonschool-simple_shell)

## Additional Information
- **Output:** Same as /bin/sh.
- **Error Format:**
    ```
    $ echo "qwerty" | ./hsh
    ./hsh: 1: qwerty: not found
    ```
- **Documentation:** Detailed comments in code.
- **Collaboration:** Encouraged, but each student should have their own GitHub repository.
