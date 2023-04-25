#include "main.h"

/**
* print_env_var - prints the environment string to stdout
*
* Return: 0
*/
void print_env_var(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _sting_length(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
