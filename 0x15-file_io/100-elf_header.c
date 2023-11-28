#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int  main(int __attribute__((__unused__)) argc, char *argv[])
{
    Elf64_Ehdr *header;
    int o, r;

    o = open(argv[1], O_RDONLY);
    if (o == -1)
    {
        handle_elf_error(98, "Can't read file", -1);
    }

    header = malloc(sizeof(Elf64_Ehdr));
    if (header == NULL)
    {
        handle_elf_error(98, "Can't read file", o);
    }

    r = read(o, header, sizeof(Elf64_Ehdr));
    if (r == -1)
    {
        free(header);
        handle_elf_error(98, "No such file", o);
    }

    check_elf_and_print_class(header->e_ident);
    printf("ELF Header:\n");
    print_magic(header->e_ident);
    print_data(header->e_ident);
    print_combined_info(header->e_ident);
    print_osabi(header->e_ident);
    print_type(header->e_type, header->e_ident);

    free(header);
    close_elf(o);
    return (0);
}

void handle_elf_error(int code, const char *message, int elf)
{
    dprintf(STDERR_FILENO, "Error: %s\n", message);
    if (elf != -1)
    {
        if (close(elf) == -1)
        {
            dprintf(STDERR_FILENO,
                    "Error: Can't close fd %d\n", elf);
            exit(98);
        }
    }
    exit(code);
}

void check_elf_and_print_class(unsigned char *e_ident)
{
    int index;

    for (index = 0; index < 4; index++)
    {
        if (e_ident[index] != 127 &&
            e_ident[index] != 'E' &&
            e_ident[index] != 'L' &&
            e_ident[index] != 'F')
        {
            handle_elf_error(98, "Not an ELF file", -1);
        }
    }

    printf(" Class: ");

    switch (e_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

void print_magic(unsigned char *e_ident)
{
    int index;

    printf(" Magic: ");

    for (index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", e_ident[index]);

        if (index == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

