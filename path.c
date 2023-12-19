#include "shell.h"
/**
 * getPath - search for the file in the PATH
 * @file: the file to search for in the PATH
 * Return: the file path if found, or NULL
 */
char *getPath(char *file)
{
	char *path = NULL;
	char *file_path = NULL;
	char *path_env = NULL;
	struct stat file_info;
	int i;
	char *token = strtok(path_env, ":");

	for (i = 0; file[i] != '\0'; i++)
	{
		if (file[i] == '/' || file[i] == '.')
		{
			if (stat(file, &file_info) == 0)
				return (strdup(file));
			return (NULL);
		}
	}
	path = getEnv("PATH");
	if (!path)
		return (NULL);
	path_env = strdup(path);
	if (path_env == NULL)
		return (NULL);
	while (token)
	{
		file_path = malloc(strlen(token) + strlen(file) + 2);
		if (file_path == NULL)
		{	free(path_env);
			return (NULL);
		}
		sprintf(file_path, "%s/%s", token, file);
		if (stat(file_path, &file_info) == 0)
		{	free(path_env);
			return (file_path);
		}
		free(file_path);
		token = strtok(NULL, ":");
	}
	free(path_env);
	return (NULL);
}
