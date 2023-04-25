#include "main.h"

/**
* path_tester - checks whether path is valid
* @path: tokenized path
* @command: user entered command
*
* Return: path appended with command on success
* NULL on failure
*/
char *path_tester(char **path, char *command)
{
	int i = 0;
	char *output;

	while (path[i])
	{
		output = append_path_utility(path[i], command);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}
