#include "main.h"

/**
 *
 */

int check_specifier(const char *format, int *i, int *count_char,
                va_list get_list)
{
	unsigned int value;

        if (format[*i] == 'c')
        {
                *count_char = char_handler(get_list, count_char);
        }
        else if (format[*i] == 's')
        {
                *count_char = string_handler(get_list, count_char);
        }
	else if (format[*i] == '%')
	{
		*count_char += _putchar('%');
	}
        else if (format[*i] == 'd' || format[*i] == 'i')
        {
                *count_char = int_handler(get_list, count_char);
        }
	else if (format[*i] == 'u')
	{
		value = va_arg(get_list, int);
		*count_char += unsigned_int_handler(value);
	}
        else if (format[*i] == 'b')
	{
                *count_char = binary_handler(get_list, count_char);
	}
        else if (format[*i] == 'o')
	{
		value = va_arg(get_list, int);
                *count_char += octal_handler(value);
	}
        else if (format[*i] == 'x')
	{
		value = va_arg(get_list, int);
                *count_char = hexadecimal_x_handler(value);
	}
        else if (format[*i] == 'X')
	{
		value = va_arg(get_list, int);
                *count_char = hexadecimal_X_handler(value);
	}
        return (*count_char);
}
