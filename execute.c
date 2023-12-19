#include "shell.h" /**
 * execute - execute the command
 * @args: array of arguments -> command and arguments
 * Return: 0 in success or EXIT_FAILIURE
 */
int execute(char **args)
{
	char *path_cmd = NULL;
	pid_t child_pid;
	int child_status;

	if (strcmp(args[0], "env") == 0)
	{
		while (*environ)
			printf("%s\n", *environ++);
		return (0);
	}
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
			chdir(getenv("HOME"));
		else if (chdir(args[1]) != 0)
			perror("cd");
		return (0);
	}
	if (strcmp(args[0], "exit") == 0)
	{	freeDP(args);
		free(path_cmd);
		exit(0);
	}
	path_cmd = getPath(args[0]);
	if (path_cmd == NULL)
		return (-1);
	child_pid = fork();
	if (child_pid == -1)
	{	perror("Error ; fork failed");
		free(path_cmd);
		return (-1);
	}
	else if (child_pid == 0)
	{
		if (execve(path_cmd, args, environ) == -1)
			perror("Error ; execve failed");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(child_pid, &child_status, 0);
	free(path_cmd);
	return (0);
}
