#include "shell.h"

/**
* freeDP - free alloc memory
* @args: pointer to pointer - array of strings
* Return: void
*/
void freeDP(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
	{
		free(args[i]);
	}

	free(args);
}
/**
* freeMemory - free alloc memory
* @tokens: pointer to pointer - array of strings
* @count_token: number of tokens - size of the array
* Return: void
*/
void freeMemory(char **tokens, size_t count_token)
{
	while (count_token > 0)
	{
		free(tokens[--count_token]);
	}
	free(tokens);
}
