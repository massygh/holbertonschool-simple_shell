#include "shell.h"

/**
 * main - fonction
 * Return: Always 0.
 */
int main(void)
{
	char *input_line = NULL;
	char **command_arguments;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printPrompt();
		read = getline(&input_line, &len, stdin);
		if (read == -1)
		{
			if (feof(stdin))
			{
				printf("Exiting the shell.\n");
				free(input_line);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("Failed to read the command\n");
				free(input_line);
				return (1);
			}
		}
		if (input_line[0] == '\n')
		{
			continue;
		}
		command_arguments = parseInputLine(input_line);
		if (strcmp(command_arguments[0], "exit") == 0)
		{
			freeMemory(command_arguments, countTokens(input_line));
			free(input_line);
			exit(EXIT_SUCCESS);
		}
		executeCommand(command_arguments);
		freeMemory(command_arguments, countTokens(input_line));
	}
	free(input_line);
	return (0);
}
