#include "main.h"
/**
 * _printf - prints a formatted string to the stdout
 * @format: the format string to be printed
 * Return: the total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list get_list;
	int i = 0;
	int count_char = 0;
	char temp_buff[BUFFER_SIZE];
	int index_of_buffer = 0;

	va_start(get_list, format);
	count_char = printf_support(format, get_list, i, count_char, temp_buff);
	return (count_char);
}
