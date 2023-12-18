#include "shell.h"
#include "prompt.h"

extern char **environ; // Ajoutez cette ligne pour déclarer environ

void run_shell()
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
			char *env_var = *environ;

			while (env_var)
			{
				printf("%s\n", env_var);
				env_var = *(environ++);
			}

			continue;
		}

		if (access(command, F_OK) != 0)
		{
			printf("./shell: No such file or directory\n");
			continue;
		}

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			// Tokenize the command to handle arguments
			char *args[MAX_ARGUMENTS];
			int i = 0;
			char *token = strtok(command, " ");

			while (token != NULL && i < MAX_ARGUMENTS - 1)
			{
				args[i++] = token;
				token = strtok(NULL, " ");
			}

			args[i] = NULL;

			if (execve(args[0], args, environ) == -1)
			{
				perror("Error executing command");
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
	}

	printf("Shell exiting.\n");
}
