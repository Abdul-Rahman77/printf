#include "main.h"

/**
 * check_specifier - checks for specifiers after the %
 * @format: the format string to be printed
 * @i: the format iterator
 * @count_char: keeps track of the printed output
 * @get_list: the variable for the list of arguments
 * @value: unsigned integer to be which will be initialized 0
 * Return: the total number of chars printed
 */

int check_specifier(const char *format, int *i, int *count_char,
		va_list get_list, unsigned int value)
{
	if (format[*i] == 'c')
		(*count_char) = char_handler(get_list, count_char);
	else if (format[*i] == 's')
		(*count_char) = string_handler(get_list, count_char);
	else if (format[*i] == '%')
		(*count_char) += _putchar('%');
	else if (format[*i] == 'd' || format[*i] == 'i')
		(*count_char) = int_handler(get_list, count_char);
	else if (format[*i] == 'u')
	{
		value = va_arg(get_list, int);
		(*count_char) += unsigned_int_handler(value);
	}
	else if (format[*i] == 'b')
		(*count_char) = binary_handler(get_list, count_char);
	else if (format[*i] == 'o')
	{
		value = va_arg(get_list, int);
		(*count_char) += octal_handler(value);
	}
	else if (format[*i] == 'x')
	{
		value = va_arg(get_list, int);
		(*count_char) = hexadecimal_x_handler(value);
	}
	else if (format[*i] == 'X')
	{
		value = va_arg(get_list, int);
		(*count_char) = hexadecimal_X_handler(value);
	}
	else
		(*count_char) += _puts("%" + format[*i]);
	return (*count_char);
}
