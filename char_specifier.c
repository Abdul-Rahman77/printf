#include "main.h"
/**
 * char_handler - can handle any character
 * @list:naiming the variadic function
 * @buff:any empty array to store the characters
 * @i:countes the characters
 *
 * Return:the characters
 */
int char_handler(va_list list, char buff[], int i)
{
	char character = va_arg(list, int);

	buff[i] = character;
	i++;
	return (i);
}
