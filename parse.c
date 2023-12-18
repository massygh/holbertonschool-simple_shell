#include "shell.h"

/**
 * countTokens - splits a string into words (tokens)
 * @line: the string to be splitted
 * Return: an array of strings (each word of the line string) or NULL
 */
int countTokens(char *line)
{
	char *copy_line = strdup(line);
	char *token = strtok(copy_line, " \t\r\n\a");
	int count = 0;

	while (token)
	{
		count++;
		token = strtok(NULL, " \t\r\n\a");
	}

	free(copy_line);
	return (count);
}

/**
 * parseLine - splits a string into words (tokens)
 * @line: the string to be splitted
 * Return: an array of strings (each word of the line string) or NULL
 */
char **parseLine(char *line)
{
	char *copy_line = strdup(line);
	char *token = strtok(copy_line, " \t\r\n\a");
	int count = countTokens(line);
	int i = 0;

	char **tokens = malloc(sizeof(char *) * (count + 1));

	if (!tokens)
	{
		free(copy_line);
		return (NULL);
	}

	while (token)
	{
		tokens[i] = strdup(token);

		if (!tokens[i])
		{
			freeMemory(tokens, i);
			free(copy_line);
			return (NULL);
		}
		i++;
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[i] = NULL;
	free(copy_line);
	return (tokens);
}
