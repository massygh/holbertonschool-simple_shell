#include "shell.h"

/**
 * readLine - read a line from stdin
 * Description:
 * Use getline function to get the input user from stdin
 * Getline will dynamically allocate memory and update input_line
 * Getline return the number of characters read and store it in nb_char_line
 * Return: the line on success or NULL on failure
 */
char *readLine(void)
{
	char *input_line = NULL;
	size_t size_line = 0;
	ssize_t read;

	read = getline(&input_line, &size_line, stdin);

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
			return (NULL);
		}
	}
	return (input_line);
}
