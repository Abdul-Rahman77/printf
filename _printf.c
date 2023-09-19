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

	va_start(get_list, format);
	count_char = printf_support(format, get_list, i, count_char, temp_buff);
	return (count_char);
}

/**
 * printf_support - helps reduce the lines of codes in _printf()
 * @format: the format string from _printf function
 * @get_list: the variadic list of arguments
 * @i: an iterator for the format string
 * @count_char: keeps track of the printed characters
 * @temp_buff: buffer for the chars to be printed
 * Return: the total number of characters to be printed
 */

int printf_support(const char *format, va_list get_list,
		int i, int count_char, char temp_buff[])
{
	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			if (format[i] == '%')
			{
				i++;
				count_char = check_specifier(format, i, count_char, get_list, temp_buff);
			}
			else
			{
				temp_buff[count_char] = format[i];
				count_char++;
			}
			i++;
		}
	}
	else
	{
		return (-1);
	}
	write(1, temp_buff, count_char);
	va_end(get_list);
	return (count_char);
}

int check_specifier(const char *format, int i, int count_char,
		va_list get_list, char temp_buff[])
{
	if (format[i] == 'c')
	{
		count_char = char_handler(get_list, temp_buff, count_char);
	}
	else if (format[i] == 's')
	{
		count_char = string_handler(get_list, temp_buff, count_char);
	}
	else if (format[i] == 'd' || format[i] == 'i')
	{
		count_char = int_handler(get_list, temp_buff, count_char);
	}
	else if (format[i] == 'b')
		count_char = binary_handler(get_list, temp_buff, count_char);
	else if (format[i] == 'o')
		count_char = octal_handler(get_list, temp_buff, count_char);
	else if (format[i] == 'x')
		count_char = hexadecimal_x_handler(get_list, temp_buff, count_char);
	else if (format[i] == 'X')
		count_char = hexadecimal_X_handler(get_list, temp_buff, count_char);
	return (count_char);
}
