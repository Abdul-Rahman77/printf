#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
void print_string(char *str);
int _strlen(char *str);
int char_handler(va_list list, char buff[], int i);
int string_handler(va_list list, char buff[], int i);
int int_handler(va_list list, char main_buff[], int i);
int binary_handler(va_list list, char main_buff[], int i);
int octal_handler(va_list list, char main_buff[], int i);
int hexadecimal_x_handler(va_list list, char main_buff[], int i);
int hexadecimal_X_handler(va_list list, char main_buff[], int i);
#endif
