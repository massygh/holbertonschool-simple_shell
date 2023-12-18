#include "shell.h"

void create_arguments(char *command, char *args[MAX_ARGUMENTS])
{
	int i = 0;
	char *token = strtok(command, " ");

	while (token != NULL && i < MAX_ARGUMENTS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;
}
