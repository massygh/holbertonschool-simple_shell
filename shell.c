#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * main - Entry point of the shell
 * Return: EXIT_SUCCESS on success, otherwise EXIT_FAILURE
 */
int main(void)
{
	char buffer[BUFFER_SIZE];

	while (1)
	{
		display_prompt();

		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("Error forking process");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execlp(buffer, buffer, NULL) == -1)
			{
				fprintf(stderr, "./shell: No such file or directory\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);
		}
	}

	return EXIT_SUCCESS;
}

