#include "shell.h"
#include "prompt.h"

/**
 * run_shell - variable
 */

void run_shell(void)
{
	char *user_input = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_prompt();

		read = getline(&user_input, &len, stdin);

		if (read == -1)
		{
			if (feof(stdin))
			{
				if (isatty(STDIN_FILENO))
					printf("\n");
				break;
			}
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}

		user_input[strcspn(user_input, "\n")] = '\0';

		if (strcmp(user_input, "exit") == 0)
		{
			free(user_input);
			exit(EXIT_SUCCESS);
		}

		execute_command(user_input);
	}

	free(user_input);
}
