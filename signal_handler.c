#include "main.h"

/**
 *signal_handler- it keeps track is interactive mode
 *@m: the signal number
 *Return: nothing
 */

void signal_handler(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
