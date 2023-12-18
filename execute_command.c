#include "shell.h"

/**
 * execute_command - variable
 * @command: The command to execute.
 */

void execute_command(const char *command)
{
	char *command_copy = strdup(command);
	int status;
	char *args[MAX_ARGUMENTS];
	char *full_path;
	char full_command[256];

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		free(command_copy);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		create_arguments(command_copy, args);

		full_path = "/bin/";
		snprintf(full_command, sizeof(full_command), "%s%s", full_path, args[0]);

		if (execve(full_command, args, environ) == -1)
		{
			perror("Error executing command");
			free(command_copy);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			printf("Child process exited with status %d\n", WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status))
		{
			printf("Child process terminated by signal %d\n", WTERMSIG(status));
		}
	}
	free(command_copy);
}
