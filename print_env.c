#include "main.h"

/**
 * print_env - Print the environment variables.
 *
 * This function prints the environment variables to the standard output.
 * Each environment variable is printed on a new line.
 *
 * Return: no return, void function
 */

void print_env(void)
{
	char **env;

	// Loop through the environment variables
	for (env = environ; *env != NULL; env++)
	{
		// Print each environment variable on a new line
		printf("%s\n", *env);
	}
}
