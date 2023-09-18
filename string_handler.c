#include "main.h"

/**
 * string_handler - handles the %X flag in the format string
 * @list: the va_list variable for the printf
 * @buff: represents the buffer storing all chars to be printed
 * @i: keeps track of all the chars to be printed
 * Return: returns the total chars to be printed
 */


int string_handler(va_list list, char buff[], int i)
{
	char *str = va_arg(list, char*);
	int count = 0;

	while (str[count] != '\0')
	{
		buff[i + count] = str[count];
		count++;
	}
	i += count;
	return (i);
}
