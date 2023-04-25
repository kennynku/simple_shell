#include "main.h"

/**
* free_input_buffer - frees buffers
* @buf: buffer to be freed
*
* Return: no return
*/
void free_input_buffer(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}
