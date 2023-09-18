#include "main.h"

/**
 * main - prints to the stdout
 * Return: 0 always
 */

int main(void)
{
	char *name = "Musah";
	int age = 23;
	int bigInt = 1024;

	_printf("He is %s, my partner for printf and he is %d", name, age);
	_putchar('\n');
	_printf("Hexadecimal = [%X], Decimal = [%d]", bigInt, bigInt);
}
