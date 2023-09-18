#include "main.h"
#define INT_BUFF 20
/**
 * binary_handler - handles the %b flag in the format string
 * @list: the va_list variable for the printf
 * @main_buff: represents the buffer storing all chars to be printed
 * @main_count: keeps track of all the chars to be printed
 * Return: returns the total chars to be printed
 */

int binary_handler(va_list list, char main_buff[], int main_count)
{
	int value = va_arg(list, int);
	char buffer[INT_BUFF];
	int parse_count = 0;

	if (value == 0)
	{
		main_buff[main_count] = '0';
		main_count++;
		return (main_count);
	}
	else if (value < 0)
	{
		return (-1);
	}

	do {
		buffer[parse_count++] = '0' + (value % 2);
		value = (value / 2);
	} while (value > 0);

	for (int i = 0, j = parse_count - 1; i < j; i++, j--)
	{
		char swap = buffer[i];

		buffer[i] = buffer[j];
		buffer[j] = swap;
	}
	buffer[parse_count] = '\0';

	int mini_parser = 0;

	while (buffer[mini_parser] != '\0')
	{
		main_buff[main_count + mini_parser] = buffer[mini_parser];
		mini_parser++;
	}
	main_count += parse_count;
	return (main_count);

}
