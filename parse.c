#include "shell.h"
/**
* parseLine - splits a string into words (tokens)
* @line: the string to be splitted
* Return: an array of strings (each word of the line string) or NULL
*/
char **parseLine(char *line)
{
	char *copy_line = NULL, *token = NULL;
	char *delimiters = " \t\r\n\a";
	char **tokens = NULL;
	int count_token = 0, i = 0;
	copy_line = strdup(line);
	if (!copy_line)
		return (NULL);
	token = strtok(copy_line, delimiters);
	while (token)
	{
		count_token++;
		token = strtok(NULL, delimiters);
	}
	free(copy_line);
	count_token++;
	tokens = malloc(sizeof(char *) * count_token);
	if (!tokens)
		return (NULL);
	copy_line = strdup(line);
	if (!copy_line)
	{	free(tokens);
		return (NULL);
	}
	token = strtok(copy_line, delimiters);
	while (token)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			free(tokens);
			free(copy_line);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delimiters);
	}
	tokens[i] = NULL;
	free(copy_line);
	return (tokens);
}
