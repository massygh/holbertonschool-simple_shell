#include "main.h"

/**
 * _getpath- function that finds the path to execute command
 *
 * @command: command enter by user in input
 *
 * Return: command if command has '/', result of concat with PATH
 * or NULL if nothing is found
 */

char *_getpath(char *command)
{
	int i = 0;
	char *token = NULL;
	char *cache;
	char *result = NULL;

	// If command has a '/', return a duplicate of the command
	if (strchr(command, '/') != NULL)
		return (strdup(command));

	// Loop through environment variables
	while (environ[i])
	{
		// Create a copy of the environment variable for manipulation
		cache = strdup(environ[i]);
		token = strtok(cache, "=");

		// Check if the environment variable is PATH
		if (strcmp(token, "PATH") == 0)
		{
			// Get the value of PATH
			token = strtok(NULL, "=");
			token = strtok(token, ":");

			// Loop through directories in PATH
			while (token)
			{
				// Allocate memory for the result path
				result = malloc(strlen(token) + strlen(command) + 2);

				// Check if memory allocation is successful
				if (result == NULL)
				{
					perror("Malloc is NULL");
					return (NULL);
				}

				// Concatenate directory path and command
				sprintf(result, "%s/%s", token, command);

				// Check if the concatenated path is executable
				if (access(result, X_OK) == 0)
				{
					free(cache);  // Free allocated memory
					return (result);
				}

				// Free memory allocated for the result path
				free(result);

				// Move to the next directory in PATH
				token = strtok(NULL, ":");
			}
		}

		// Free memory allocated for the environment variable copy
		free(cache);
		i++;
	}

	// Free memory allocated for the command (if it's not part of PATH)
	free(command);

	// Return NULL if the command is not found in any directory in PATH
	return (NULL);
}
