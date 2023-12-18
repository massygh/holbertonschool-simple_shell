#include "shell.h"

/**
 * @brief Execute the given command in a child process.
 * 
 * @param command The command to execute.
 */
void execute_command(const char *command)
{
	// Créer une copie modifiable de la commande
	char *command_copy = strdup(command);

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		free(command_copy);  // Libérer la mémoire allouée
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		// Tokenize the command to handle arguments
		char *args[MAX_ARGUMENTS];
		int i = 0;
		char *token = strtok(command_copy, " ");

		while (token != NULL && i < MAX_ARGUMENTS - 1)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}

		args[i] = NULL;

		if (execve(args[0], args, environ) == -1)
		{
			perror("Error executing command");
			free(command_copy);  // Libérer la mémoire allouée
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;
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

	// Libérer la mémoire allouée pour la copie de la commande
	free(command_copy);
}
