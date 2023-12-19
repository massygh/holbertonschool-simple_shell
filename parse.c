#include "shell.h"
/**
 * parseLine - splits a string into words (tokens)
 * @line: the string to be splitted
 * Return: an array of strings (each word of the line string) or NULL
 */
char **parseLine(char *line)
{
	char *copy_line = NULL, *token = NULL; /* copy of the line -> input of users*/
	char *delimiters = " \t\r\n\a"; /* delimiters of the line */
	char **tokens = NULL; /* store the array of words */
	int count_token = 0, i = 0; /* count the number of words and index */

	copy_line = strdup(line);
	if (!copy_line) /* if strdup fails */
		return (NULL);  /* Count the number of words in the line using delimiters */
	token = strtok(copy_line, delimiters);
	while (token)
	{
		count_token++; /* increment the number of words */
		token = strtok(NULL, delimiters); /* get the next word */
	}
	free(copy_line); /* free the copy of the line */
	count_token++; /* increment the number of words for the NULL sign */
	tokens = malloc(sizeof(char *) * count_token);
	if (!tokens) /* if malloc fails */
		return (NULL); /* Duplicate the line again and split it into words */
	copy_line = strdup(line);
	if (!copy_line) /* if strdup fails */
	{
		free(tokens);
		return (NULL);
	} /* Split the line into words and store them in tokens */
	token = strtok(copy_line, delimiters);
	while (token)
	{
		tokens[i] = strdup(token);
		if (!tokens[i]) /* if strdup fails */
		{
			free(tokens);
			free(copy_line);
			return (NULL);
		} i++;
		token = strtok(NULL, delimiters);
	}
	tokens[i] = NULL; /* Null-terminate the array of tokens */
	free(copy_line); /* free the copy of the line */
	return (tokens);
}
