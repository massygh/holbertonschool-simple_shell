#include "shell.h"

/**
 * @brief Execute the given command in a child process.
 * @param command: The command to execute.
 */

void execute_command(const char *command)
{
	char *command_copy = strdup(command);
	int status;
	char *args[MAX_ARGUMENTS];
	int i = 0;
	char *token = strtok(command_copy, " ");

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		free(command_copy);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		while (token != NULL && i < MAX_ARGUMENTS - 1)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		// Ajoutez le chemin complet ici
		char *full_path = "/bin/";  // Vous pouvez ajuster le chemin en fonction de votre système
		char full_command[256];
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
