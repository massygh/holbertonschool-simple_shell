#include "shell.h"

/**
* freeDP - free alloc memory
* @args: pointer to pointer - array of strings
* Description: free the memory allocated for the array of strings (tokens)
* Return: void
*/
void freeDP(char **args)
{
	int i; /* index for loop */

	/* Go through the array of tokens */
	for (i = 0; args[i]; i++)
	{
		/* Free each token in the array */
		free(args[i]);
	}

	free(args); /* free the array */
}
/**
* freeMemory - free alloc memory
* @tokens: pointer to pointer - array of strings
* @count_token: number of tokens - size of the array
* Description: free the memory allocated for the array of strings (tokens)
* Return: void
*/
void freeMemory(char **tokens, size_t count_token)
{
	/* Go through the array tokens */
	while (count_token > 0)
	{
		/* Free each token in the array */
		free(tokens[--count_token]);
	}
	/* Free the array */
	free(tokens);
}
