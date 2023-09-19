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
