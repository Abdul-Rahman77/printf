#include "main.h"
#define INT_BUFF 20

/**
 * unsigned_int_handler - handles the %b flag in the format string
 * octal_handler - handles the %o flag in the format string
 * hexadecimal_x_handler - handles the %x flag in the format string
 * hexadecimal_X_handler - handles the %X flag in the format string
 * @list: the va_list variable for the printf
 * @main_buff: represents the buffer storing all chars to be printed
 * @main_count: keeps track of all the chars to be printed
 * Return: returns the total chars to be printed
 */

int unsigned_int_handler(va_list list, char main_buff[], int main_count)
{
	int value = va_arg(list, int);
	char buffer[INT_BUFF];
	int parse_count = 0;
	int i, j;
	int mini_parser = 0;
	char swap;

	if (value < 0)
		return (-1);

	do {
		buffer[parse_count++] = '0' + (value % 10);
		value = (value / 10);
	} while (value > 0);

	for (i = 0, j = parse_count - 1; i < j; i++, j--)
	{
		swap = buffer[i];

		buffer[i] = buffer[j];
		buffer[j] = swap;
	}
	buffer[parse_count] = '\0';

	while (buffer[mini_parser] != '\0')
	{
		main_buff[main_count + mini_parser] = buffer[mini_parser];
		mini_parser++;
	}
	main_count += parse_count;
	return (main_count);

}

/**
 * octal_handler - handles the %o flag in the format string
 * @list: the va_list variable for the printf
 * @main_buff: represents the buffer storing all chars to be printed
 * @main_count: keeps track of all the chars to be printed
 * Return: returns the total chars to be printed
 */


int octal_handler(va_list list, char main_buff[], int main_count)
{
	int value = va_arg(list, int);
	char buffer[INT_BUFF];
	int parse_count = 0;
	int i, j;
        int mini_parser = 0;
        char swap;

	if (value < 0)
		return (-1);

	do {
		buffer[parse_count++] = '0' + (value % 8);
		value = (value / 8);
	} while (value > 0);

	for (i = 0, j = parse_count - 1; i < j; i++, j--)
	{
		swap = buffer[i];

		buffer[i] = buffer[j];
		buffer[j] = swap;
	}
	buffer[parse_count] = '\0';

	while (buffer[mini_parser] != '\0')
	{
		main_buff[main_count + mini_parser] = buffer[mini_parser];
		mini_parser++;
	}
	main_count += parse_count;
	return (main_count);

}

/**
 * hexadecimal_x_handler - handles the %x flag in the format string
 * @list: the va_list variable for the printf
 * @main_buff: represents the buffer storing all chars to be printed
 * @main_count: keeps track of all the chars to be printed
 * Return: returns the total chars to be printed
 */


int hexadecimal_x_handler(va_list list, char main_buff[], int main_count)
{
	int value = va_arg(list, int);
	char buffer[INT_BUFF];
	int parse_count = 0;
	int i, j;
        int mini_parser = 0;
        char swap;
	int var_char;
	char extra_char[] = "abcdef";

	if (value < 0)
		return (-1);

	while (value > 0)
	{
		var_char = (value % 16);
		if (var_char > 9)
			buffer[parse_count++] = extra_char[var_char % 10];
		else
			buffer[parse_count++] = '0' + var_char;
		value = (value / 16);
	}

	for (i = 0, j = parse_count - 1; i < j; i++, j--)
	{
		swap = buffer[i];

		buffer[i] = buffer[j];
		buffer[j] = swap;
	}
	buffer[parse_count] = '\0';

	while (buffer[mini_parser] != '\0')
	{
		main_buff[main_count + mini_parser] = buffer[mini_parser];
		mini_parser++;
	}
	main_count += parse_count;
	return (main_count);

}

/**
 * hexadecimal_X_handler - handles the %X flag in the format string
 * @list: the va_list variable for the printf
 * @main_buff: represents the buffer storing all chars to be printed
 * @main_count: keeps track of all the chars to be printed
 * Return: returns the total chars to be printed
 */


int hexadecimal_X_handler(va_list list, char main_buff[], int main_count)
{
	int value = va_arg(list, int);
	char buffer[INT_BUFF];
	int parse_count = 0;
	int i, j;
        int mini_parser = 0;
        char swap;
	int var_char;
	char extra_char[] = "ABCDEF";

	if (value < 0)
		return (-1);

	while (value > 0)
	{
		var_char = (value % 16);
		if (var_char > 9)
			buffer[parse_count++] = extra_char[var_char % 10];
		else
			buffer[parse_count++] = '0' + var_char;
		value = (value / 16);
	}
	for (i = 0, j = parse_count - 1; i < j; i++, j--)
	{
		swap = buffer[i];

		buffer[i] = buffer[j];
		buffer[j] = swap;
	}
	buffer[parse_count] = '\0';

	while (buffer[mini_parser] != '\0')
	{
		main_buff[main_count + mini_parser] = buffer[mini_parser];
		mini_parser++;
	}
	main_count += parse_count;
	return (main_count);
}
