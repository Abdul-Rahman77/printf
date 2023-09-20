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

	va_start(get_list, format);
	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			if (format[i] == '%')
			{
				i++;
				check_specifier(format, &i, &count_char, get_list, 0);
			}
			else
			{
				count_char += _putchar(format[i]);
			}
			i++;
		}
	}
	else
	{
		return (-1);
	}
	va_end(get_list);
	return (count_char);
}


/**
 * char_handler - can handle any character
 * @list: naming the variadic function
 * @count_char: countes the characters
 *
 * Return: the characters
 */
int char_handler(va_list list, int *count_char)
{
	char character = va_arg(list, int);

	*count_char += _putchar(character);
	return (*count_char);
}


/**
 * string_handler - handles the %X flag in the format string
 * @list: the va_list variable for the printf
 * @count_char: keeps track of all the chars to be printed
 * Return: returns the total chars to be printed
 */


int string_handler(va_list list, int *count_char)
{
	char *str = va_arg(list, char*);

	*count_char += _puts(str);
	return (*count_char);
}

