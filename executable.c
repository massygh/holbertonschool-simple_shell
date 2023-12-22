#include "main.h"

/**
 * executable - Execute a file if it has executable permissions
 *
 * @argv: Path to the executable file
 * @input: Input put by the user of this shell
 *
 * Return: no return, void function
 */

void executable(char *argv[], char *input)
{
	int status;
	int status_exit;
	pid_t child;


	if (access(argv[0], X_OK) != 0)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		free(argv[0]);
		exit(127);
	}
	// Create a child process
	child = fork();

	if (child == -1)
	{
		perror("Fail Fork\n");
		exit(0);
	}
	else if (child == 0)
	{
		// Replace the child process image with the new command
		execve(argv[0], argv, environ);
		free(argv[0]);
		exit(0);
	}
	else
	{
		// Code executed in the parent process

		wait(&status);
		if (WIFEXITED(status))
		{
			// Retrieve the exit status of the child process
			status_exit = WEXITSTATUS(status);
			if (status_exit != 0)
			{
				free(argv[0]);
				free(input);
				exit(2);
			}
		}
	}
}
