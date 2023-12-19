#include "shell.h"

/**
 * getPath - search for the file in the PATH
 * @file: the file to search for in the PATH
 * Description: search for the and send the absolute path to the file if found
 * Return: the file path if found, or NULL
 */
char *getPath(char *file)
{
	char *path = NULL;          /* to store the path */
	char *file_path = NULL;     /* to store the file path */
	char *path_env = getEnv("PATH"); /* get the PATH environ variable */

	if (!path_env) /* if getEnv fails or path is NULL */
		return (NULL);

	path = strdup(path_env); /* duplicate the PATH env variable and store it */
	if (!path) /* if strdup (duplicate) fails */
		return (NULL);

	path = strtok(path, ":"); /* split the PATH env variable using ':' */
	while (path) /* loop through the PATH as long as it's not NULL */
	{
		/* allocate memory for the file path */
		/* size of the path + size of the file + '/' + '\0' */
		file_path = malloc(sizeof(char) * (strlen(path) + strlen(file) + 2));
		/* concatenate the path with the file name using sprintf and / to separate */
		sprintf(file_path, "%s/%s", path, file);

		/* check if the file exists and is executable */
		struct stat file_info;

		if (file_path != NULL && stat(file_path, &file_info) == 0
				&& S_ISREG(file_info.st_mode) && (file_info.st_mode & S_IXUSR))
		{
			free(path);       /* free the path */
			return (file_path); /* return the file path */
		}

		free(file_path); /* free the file path if file not found or not executable */
		path = strtok(NULL, ":"); /* get the next path */
	}

	free(path); /* free the path */
	return (NULL); /* return NULL if file not found or not executable */
}
