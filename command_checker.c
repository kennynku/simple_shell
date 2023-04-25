#include "main.h"
/**
 *command_checker- checks to see weather its a built in function
 *@cmd: tokenized user input
 *@buf: line drived fromgetline function
 *Return: 1 if cmd excuted 0 if cmd is not executed
 */
int command_checker(char **cmd, char *buf)
{
	if (execute_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}
