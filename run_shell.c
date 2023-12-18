#include "shell.h"
#include "prompt.h"

/**
 * run_shell - variable
 */

void run_shell(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			printf("Shell exiting.\n");
			break;
		}
		if (strcmp(command, "env") == 0)
		{
			print_environment();
			continue;
		}

		if (access(command, F_OK) != 0)
		{
			printf("./shell: No such file or directory\n");
			continue;
		}
		execute_command(command);
	}
	printf("Shell exiting.\n");
}
