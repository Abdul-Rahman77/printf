#include "main.h"

/**
 * _put - prints a sring to the stdout
 * @str: the string to be printed
 * Return: the length of the character printed
 */

int _puts(char *str)
{
	write (1, str, _strlen(str));
	return (_strlen(str));
}
