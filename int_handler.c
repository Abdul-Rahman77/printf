#include "main.h"
#define INT_BUFF 20

/**
 * int_handler - handles the %d and %i flags in the format string
 * @list: the va_list variable for the printf
 * @main_buff: represents the buffer storing all chars to be printed
 * @main_count: keeps track of all the chars to be printed
 * Return: returns the total chars to be printed
 */

int int_handler(va_list list, char main_buff[], int main_count)
{
	int value = va_arg(list, int);
	char buffer[INT_BUFF];
	int parse_count = 0;
	int i, j;
	int mini_parser = 0;
	char swap;

	if (value < 0)
	{
		buffer[parse_count++] = '-';
		value = -value;
	}

	do {
		buffer[parse_count++] = '0' + (value % 10);
		value = (value / 10);
	} while (value > 0);

	for (i = 0, j = parse_count - 1; i < j; i++, j--)
	{
		if (buffer[i] == '-')
			i++;
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
