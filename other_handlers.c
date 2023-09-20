#include "main.h"
#define INT_BUFF 20

/**
 * unsigned_int_handler - handles the %b flag in the format string
 * @value: unsigned int to be printed
 * Return: returns the total chars to be printed
 */

int unsigned_int_handler(unsigned int value)
{
	char buffer[INT_BUFF];
	int parse_count = 0;
	int count_char = 0;

	if (value == 0)
	{
		count_char += _putchar('0');
		return (count_char);
	}

	while (value > 0)
	{
		buffer[parse_count++] = '0' + (value % 10);
		value = (value / 10);
	}

	count_char += parse_count;

	while (--parse_count >= 0)
	{
		_putchar(buffer[parse_count]);
	}
	return (count_char);

}


/**
 * octal_handler - handles the %o flag in the format string
 * @value: unsigned int to be printed
 * Return: returns the total chars to be printed
 */


int octal_handler(unsigned int value)
{
	char buffer[INT_BUFF];
	int parse_count = 0;
	int count_char = 0;

	if (value == 0)
	{
		count_char += _putchar('0');
		return (count_char);
	}
	while (value > 0)
	{
		buffer[parse_count++] = '0' + (value % 8);
		value = (value / 8);
	}
	count_char += parse_count;
	while (--parse_count >= 0)
	{
		_putchar(buffer[parse_count]);
	}
	return (count_char);
}

/**
 * hexadecimal_x_handler - handles the %x flag in the format string
 * @value: unsigned int to be printed
 * Return: returns the total chars to be printed
 */


int hexadecimal_x_handler(unsigned int value)
{
	char buffer[INT_BUFF];
	int parse_count = 0;
	int i;
	int count_char = 0;
	int var_char;
	char extra_char[] = "abcdef";

	if (value == 0)
	{
		count_char += _putchar('0');
		return (count_char);
	}

	while (value > 0)
	{
		var_char = (value % 16);
		if (var_char > 9)
			buffer[parse_count++] = extra_char[var_char % 10];
		else
			buffer[parse_count++] = '0' + var_char;
		value = (value / 16);
	}

	for (i = parse_count - 1; i >= 0; i--)
	{
		count_char += _putchar(buffer[i]);
	}
	return (count_char);

}

/**
 * hexadecimal_x_handler - handles the %x flag in the format string
 * @value: unsigned int to be printed
 * Return: returns the total chars to be printed
 */


int hexadecimal_X_handler(unsigned int value)
{
	char buffer[INT_BUFF];
	int parse_count = 0;
	int i;
	int count_char = 0;
	int var_char;
	char extra_char[] = "ABCDEF";

	if (value == 0)
	{
		count_char += _putchar('0');
		return (count_char);
	}

	while (value > 0)
	{
		var_char = (value % 16);
		if (var_char > 9)
			buffer[parse_count++] = extra_char[var_char % 10];
		else
			buffer[parse_count++] = '0' + var_char;
		value = (value / 16);
	}

	for (i = parse_count - 1; i >= 0; i--)
	{
		count_char += _putchar(buffer[i]);
	}
	return (count_char);

}

