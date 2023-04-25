#include "main.h"

/**
* exit_command_handler - handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
* Return: no return
*/
void exit_command_handler(char **command, char *line)
{
	free(line);
	free_input_buffer(command);
	exit(0);
}
