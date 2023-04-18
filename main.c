#include "shell.h"

/**
* main - Prompt appears for user to input a command, reads it and excecutes it.
* Return: 0
*/

int main(void)
{
	char *command;

	while (1)
	{
		/* prompts the user to enter a command */
		prompt1();

		/* reads the inputted command and stores it in the command var*/
		command = read_command();

		/* if command is empty exit*/
		if (!command)
			exit(EXIT_SUCCESS);

		/* skip iteration if user enters a newline or command is null*/
		if (command[0] == '\0' || strcmp(command, "\n") == 0)
		{
			free(command);
			continue;
		}

		/* if entered command is exit, exit the funtion*/
		if (strcmp(command, "exit\n") == 0)
		{
			free(command);
			break;
		}

		/* prints back the entered command into the shell */
		printf("%s\n", command);

		/* frees command to prevent memory leak*/
		free(command);
	}
	return (0);
}
