#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

void exit_shell()
{
	printf("Exiting shell.\n");
	exit(EXIT_SUCCESS);
}

void env_shell()
{
	extern char **environ;
	for (char **env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
