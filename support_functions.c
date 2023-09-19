#include <unistd.h>

/**
 * _putchar - prints a character to the standard output
 * @c: The character to be passed
 * Return: returns the character passed to the stdout
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - countes the string length
 * @str: The string to be counted
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
