#include "shell.h"

/**
* read_command - intepretes the comment entered by the user
*
* Return: returns a pointer to the entered command
*/
char *read_command(void)
{
	char *line = NULL;
	char *command = NULL;
	char *ptr = NULL;
	size_t len = 0;
	ssize_t linesize = 0;
	char ptrlen = 0;
	/**
	 *  reads user's input using the command getli
	 *  store number of charcter in len
	 *  continues as long as line iss not equal to -1
	 */
	while ((linesize = getline(&line, &len, stdin)) != -1)
	{
		/**
		 *  if command is null allocate allocate linesize + 1
		 *  else alocate comand linesize + 1
		 *  +1 represents newline
		 */
		if (!command)
			command = malloc(linesize + 1);
		else
		{
			ptr = realloc(command, linesize + ptrlen + 1);
			if (ptr)
				command = ptr;
			else
			{
				/** 
				 * if memory allocation doesnt work,
				 *  free the command (assign null value)
				*/
				free(command);
				command = NULL;
			}
		}

		if (!command)
		{
			perror("Error: ");
			return (NULL);
		}

		strcpy(command + ptrlen, line);

		/** 
		 * Checks if last line is a newline
		 *  displays prompt2
		 *  allows for input of multi-line character
		*/
		if (line[linesize - 1] == '\n')
		{
			if (linesize == 1 || line[linesize - 2] != '\\')
				return (command);
			/* dont touch it */
			command[ptrlen + linesize - 2] = '\0';
			linesize -= 2;
			prompt2();
		}

		ptrlen += linesize;
	}

	return (command);
}
