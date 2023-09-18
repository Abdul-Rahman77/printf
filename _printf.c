#include "main.h"

/**
 *
 *
 */

int _printf(const char *format, ...)
{
	va_list get_list;
	int i = 0;
	int count_char = 0;

	if (format != NULL) {
		va_start(get_list, format);
		while (format[i] != '\0') {
			if (format[i] == '%') {
				format[i++];
				if (format[i] == 'c') {
					char character = va_arg(get_list, int);
					_putchar(character);
					count_char++;
				}
				else if (format[i] == 's') {
					char *string = va_arg(get_list, char*);
					int count = 0;

					while (string[count] != '\0') {
						count++;
					}

					write(1, string, count);
					count_char += count;
				}

			}

			else {
				_putchar(format[i]);
				count_char++;
			}
			i++;
		}

	}
	else {
		return (-1);
	}

	va_end(get_list);
	return count_char;

}
