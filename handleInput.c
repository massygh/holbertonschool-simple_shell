#include "shell.h"

/**
 * emptyLine - check for a line with only spaces
 * @line: the line to check -> input from user
 * Return: 0 if not empty, 1 if line is filled with spaces or tabs
 */
int emptyLine(char *line)
{
	/* intialize only_spaces to true */
	int only_spaces = true;
	/* get the length of the line */
	size_t len_line = strlen(line) - 1;
	/* initialize i for loop */
	size_t i;

	/* loop through the line */
	for (i = 0; i < len_line; i++)
	{
		/* if the line[i] is not a space or tab */
		if (line[i] != TAB && line[i] != SPACE)
		{
			/* set only_spaces to false */
			only_spaces = false;
			break; /* break out of the loop */
		}
	}
	/* return only_spaces as 1 if true, 0 if false */
	return (only_spaces);
}
