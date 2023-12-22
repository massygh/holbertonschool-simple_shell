#include "main.h"

/**
 * main - Entry point
 *
 *
 * Return: 0 to sucess
 */

int main(void)
{
	char *input = NULL;
	size_t len_input = 0;
	ssize_t read = 0;

	// Infinite loop for the shell
	while (1)
	{
		// Print prompt if running interactively
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		// Read input from the user
		read = getline(&input, &len_input, stdin);

		// Check for end-of-file (Ctrl+D) to exit the shell
		if (read == EOF)
		{
			free(input);  // Free allocated memory
			exit(0);      // Exit the shell
		}

		// Remove newline character from the input if present
		if (read > 0 && input[read - 1] == '\n')
		{
			input[read - 1] = '\0';
		}

		// Process the input by tokenizing it
		token_input(input);
	}

	// Free allocated memory (This part is never reached in the infinite loop)
	free(input);
	return (0);
}
