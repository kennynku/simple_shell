#include "shell.h"

/**
* read_command - reads the user entered command
*
* Return: pointer to command
*/
char *read_command(void)
{
	char *line = NULL;
	char *command = NULL;
	char *ptr = NULL;
	size_t len = 0;
	ssize_t linesize = 0;
	char ptrlen = 0;

	while ((linesize = getline(&line, &len, stdin)) != -1)
	{
		if (!command)
			command = malloc(linesize + 1);
		else
		{
			ptr = realloc(command, linesize + ptrlen + 1);
			if (ptr)
				command = ptr;
			else
				free(command), command = NULL;
		}
		if (!command)
		{
			perror("Error: ");
			return (NULL);
		}

		strcpy(command + ptrlen, line);
			if (line[linesize - 1] == '\n')
		{
			if (linesize == 1 || line[linesize - 2] != '\\')
				free(line);
				return (command);
			command[ptrlen + linesize - 2] = '\0';
			linesize -= 2;
			prompt2();
		}
		ptrlen += linesize;
	}#include "shell.h"

/**
* print_env - prints the environment string to stdout
*
* Return: 0
*/
int print_env(void)
{
	int x;

	for (x = 0; environ[x] != NULL; x++)
	{
		write(STDOUT_FILENO, environ[x], strlen(environ[x]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

	return (command);
}
