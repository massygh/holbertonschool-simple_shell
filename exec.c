#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		// Child process
		if (execve(command, NULL, NULL) == -1) {
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		// Parent process
		wait(NULL); // Wait for the child process to finish
	}
}
