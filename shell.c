#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int main(void)
{
	char input[100];
	while (1)
	{
		display_prompt();
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';  // Supprimer le saut de ligne

		if (strcmp(input, "exit") == 0)
		{
			exit_shell();
		}
		else if (strcmp(input, "env") == 0)
		{
			env_shell();
		}
		else
		{
			execute_command(input);
		}
	}
	return (0);
}
