#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void handle_elf_error(int code, const char *message, int elf);
void check_elf_and_print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_combined_info(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void close_elf(int elf);

#endif
