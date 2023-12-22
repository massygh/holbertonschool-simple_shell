#include "main.h"

/**
 * token_input - tokenize the input
 *
 * @input: the stdin put by input
 *
 * Return: No return, void function
 */

void token_input(char *input)
{
	char *split = NULL;
	char *tokens[1024] = {NULL};
	int index = 0;

	// Tokenize the input string using space as a delimiter
	split = strtok(input, " ");

	// Loop through the tokens
	while (split)
	{
		// If the token has non-zero length, store it in the tokens array
		if (strlen(split) > 0)
		{
			tokens[index] = split;
			index += 1;
		}

		// Move to the next token
		split = strtok(NULL, " ");
	}

	// Check if the first token is NULL (empty input)
	if (tokens[0] == NULL)
	{
		return;
	}

	// Check if the command is "env"
	if (strcmp(tokens[0], "env") == 0)
	{
		// Call the print_env function to print environment variables
		print_env();
		return;
	}

	// Check if the command is "exit" without any arguments
	if (strcmp(tokens[0], "exit") == 0 && tokens[1] == NULL)
	{
		// Free memory and exit the shell
		free(tokens[0]);
		exit(0);
	}

	// Duplicate the first token (command) for later use
	split = strdup(tokens[0]);

	// Get the full path to the command
	tokens[0] = _getpath(tokens[0]);

	// Check if the path is found
	if (tokens[0] != NULL)
	{
		// Free duplicated token, execute the command, and free memory
		free(split);
		executable(tokens, input);
		free(tokens[0]);
		return;
	}

	// If the path is not found, print an error and exit
	fprintf(stderr, "./hsh: 1: %s: not found\n", split);
	free(split);
	exit(127);
}
