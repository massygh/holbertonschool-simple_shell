#include "main.h"

/**
 * executable - Execute a file if it has executable permissions
 *
 * @argv: Path to the executable file
 * @input: Input put by the user of this shell
 *
 * Return: no return, void function
 */

void executeCommand(char *argv[], char *input) {
	int status;
	int exitStatus;
	pid_t childProcessID;

	// Check if the specified command is executable
	if (access(argv[0], X_OK) != 0) {
		// If the command is not executable, print an error and exit
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		free(argv[0]);  // Clean up memory
		exit(127);      // Exit with an error status
	}
<<<<<<< HEAD

	// Create a new process
	childProcessID = fork();

	// Check if the process creation was successful
	if (childProcessID == -1) {
		perror("Fork Failed\n");  // Print an error if the process creation fails
		exit(0);                 // Exit with an error status
	} else if (childProcessID == 0) {
		// Code for the child process

		// Execute the specified command in the child process
		execve(argv[0], argv, environ);

		// If execution fails, print an error and exit
		perror("Execve Failed");
		free(argv[0]);  // Clean up memory
		exit(0);        // Exit with an error status
	} else {
		// Code for the parent process

		// Wait for the child process to finish
		wait(&status);

		// Check if the child process exited normally
		if (WIFEXITED(status)) {
			// Retrieve the exit status of the child process
			exitStatus = WEXITSTATUS(status);

			// If the exit status is non-zero, clean up memory and exit with an error status
			// if (exitStatus != 0) {
			free(argv[0]);  // Clean up memory
			free(input);    // Clean up memory (if applicable)
			exit(2);        // Exit with an error status
		}
=======
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
>>>>>>> a5d7b373f5f2a038cd117c14e56b1146800466d3
		}
	}
}
