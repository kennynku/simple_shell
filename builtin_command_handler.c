#include "main.h"

/**
* execute_builtin - handles execution of builtin functions
* @command: tokenized commands
* @line: input read from stdin
*
* Return: 1 if executed, 0 if not
*/
int execute_builtin(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_compare_strings(*command, builtin.env) == 0)
	{
		print_env_var();
		return (1);
	}
	else if (_compare_strings(*command, builtin.exit) == 0)
	{
		exit_command_handler(command, line);
		return (1);
	}
	return (0);
}
