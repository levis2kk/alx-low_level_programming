#include "main.h"
#include <stdlib.h>

/**
 * create_file - creates a file
 * @filename: filename.
 * @text_content: content writed in the file.
 *
 * Return: 1 if it success. otherwise -1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;
	int w;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	while (text_content[len] != '\0')
	{
		len++;
	}
	
	w = write(fd, text_content, len);

	if (w == -1)
		return (-1);

	close(fd);

	return (1);
}
