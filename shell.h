#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
#define BUFSIZE 1024
#define SPACE ' '
#define TAB '\t'

int countTokens(char *line);
void printPrompt(void);
void freeMemory(char **tokens, size_t count_token);
char **parseInputLine(char *line);
void executeCommand(char **args);
char *getPath(char *file);
char *getEnv(char *name);

#endif
