#include "main.h"

/**
	* print_magic_class - Print ELF magic numbers and class
	* @e_ident: ELF identification array
	*/
void print_magic_class(unsigned char e_ident[])
{
	int i;

	write(1, "  Magic:   ", 12);
	for (i = 0; i < EI_NIDENT; i++)
	{
	dprintf(1, "%02x", e_ident[i]);
	if (i < EI_NIDENT - 1)
	write(1, " ", 1);
	}

	write(1, "\n  Class:                             ", 38);
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASS32:
	write(1, "ELF32\n", 6);
	break;
	case ELFCLASS64:
	write(1, "ELF64\n", 6);
	break;
	default:
	dprintf(1, "<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
	* print_version_data - Print ELF version and data encoding
	* @e_ident: ELF identification array
	*/
void print_version_data(unsigned char e_ident[])
{
	write(1, "  Version:                           ", 38);
	dprintf(1, "%d (current)\n", e_ident[EI_VERSION]);

	write(1, "  Data:                              ", 38);
	switch (e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
	write(1, "2's complement, little endian\n", 30);
	break;
	case ELFDATA2MSB:
	write(1, "2's complement, big endian\n", 27);
	break;
	default:
	dprintf(1, "<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
	* print_osabi - Print ELF OS/ABI
	* @e_ident: ELF identification array
	*/
void print_osabi(unsigned char e_ident[])
{
	write(1, "  OS/ABI:                            ", 38);
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
	write(1, "UNIX - System V\n", 16);
	break;
	default:
	dprintf(1, "<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
	* elf_header_info - Display ELF header information
	* @elf_header: ELF header structure
	*/
void elf_header_info(Elf64_Ehdr elf_header)
{
	write(1, "ELF Header:\n", 12);
	print_magic_class(elf_header.e_ident);
	print_version_data(elf_header.e_ident);
	print_osabi(elf_header.e_ident);
}

/**
	* main - Entry point
	* @ac: Argument count
	* @av: Argument vector
	* Return: 0 on success, 98 on failure
	*/
int main(int ac, char **av)
{
	int fd;
	Elf64_Ehdr elf_header;

	if (ac != 2)
	{
	dprintf(2, "Usage: %s elf_filename\n", av[0]);
	exit(98);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
	dprintf(2, "Error: Can't open file %s\n", av[1]);
	exit(98);
	}

	if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
	{
	dprintf(2, "Error: Can't read from file %s\n", av[1]);
	close(fd);
	exit(98);
	}

	elf_header_info(elf_header);

	close(fd);
	return (0);
}
