#include "shell.h"

/**
 * getEnv - gets an environ variable
 * @name: name of the environ variable to get
 * Description: the function loops through the environ variable
 * Return: Environ variable value or NULL if not found
 */

char *getEnv(char *name)
{
	int i;
	int len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (environ[i] + len + 1);
		}
	}

	return (NULL);
}
