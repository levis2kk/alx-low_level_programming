#include <fcntl.h>
#include <string.h>
#include "main.h"

/**
 * main - Copies the content of one file to another file.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 * Return: 0 on success, otherwise an error code.
 */
int main(int argc, char *argv[])
{
	int source_fd, target_fd, read_bytes, written_bytes;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	source_fd = open(argv[1], O_RDONLY);
	if (source_fd == -1)
		exit(98);

	target_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (target_fd == -1)
		exit(99);

	while ((read_bytes = read(source_fd, buf, sizeof(buf))) > 0)
	{
		written_bytes = write(target_fd, buf, read_bytes);
		if (written_bytes != read_bytes || written_bytes == -1)
			exit(99);
	}

	if (read_bytes == -1)
		exit(98);

	if (close(source_fd) == -1 || close(target_fd) == -1)
		exit(100);

	return (0);
}
