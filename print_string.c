#include "main.h"

/**
 * print_string - prints a string to the stdout
 * @str: the string to be printed
 */

void print_string(char *str)
{
	write(1, str, _strlen(str));
}
