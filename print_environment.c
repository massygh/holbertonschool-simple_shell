#include "shell.h"

/**
 * @brief Print the current environment variables.
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
