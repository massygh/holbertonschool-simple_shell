#ifndef SHELL_H
#define SHELL_H

/* ----------Libraries---------- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* ----------Macros---------- */
extern char **environ;
#define BUFSIZE 1024
#define SPACE ' '
#define TAB '\t'

int printPrompt(void);
char *readLine(void);
char **parseLine(char *line);
int emptyLine(char *line);
int execute(char **args);
char *getEnv(char *name);
char *getPath(char *file);
void freeDP(char **args);
void freeMemory(char **tokens, size_t count);
int countTokens(char *line);

#endif
