#include "shell.h"

/**
 * emptyLine - check for a line with only spaces
 * @line: the line to check -> input from user
 * Return: 0 if not empty, 1 if line is filled with spaces or tabs
 */
int emptyLine(char *line)
{
	int only_spaces = true;
	size_t len_line = strlen(line) - 1;
	size_t i;

	for (i = 0; i < len_line; i++)
	{
		if (line[i] != TAB && line[i] != SPACE)
		{
			only_spaces = false;
			break;
		}
	}
	return (only_spaces);
}
