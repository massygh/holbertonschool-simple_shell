#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

extern char **environ;

void run_shell(void);
void execute_command(const char *command);
void print_environment(void);
void print_prompt(void);

#endif /* SHELL_H */
