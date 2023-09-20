#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
void print_string(char *str);
int _strlen(char *str);
int char_handler(va_list list, int *count_char);
int string_handler(va_list list, int *count_char);
int int_handler(va_list list, int *count_char);
int binary_handler(va_list list, int *count_char);
int unsigned_int_handler(unsigned int value);
int octal_handler(unsigned int value);
int hexadecimal_x_handler(unsigned int value);
int hexadecimal_X_handler(unsigned int value);
int check_specifier(const char *format, int *i, int *count_char,
		va_list get_list, unsigned int value);
#endif
