#include "shell.h"

/**
 * print_environment - fonctions
 */
void print_environment(void)
{
	char *env_var = *environ;

	while (env_var)
	{
		printf("%s\n", env_var);
		env_var = *(environ++);
	}
}
