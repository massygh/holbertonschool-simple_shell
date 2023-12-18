#include "shell.h"

/**
 * freeMemory - fonctions
 * @tokens: variable
 * @count_token: variable 2
 */

void freeMemory(char **tokens, size_t count_token)
{
	while (count_token > 0)
	{
		free(tokens[--count_token]);
	}
	free(tokens);
}
