#include "shell.h"

/**
 * print_environment - fonctions
 */

void print_environment(void)

{
    char **env_var = environ;

    while (*env_var != NULL)
    {
        printf("%s\n", *env_var);
        env_var++;
    }
}
