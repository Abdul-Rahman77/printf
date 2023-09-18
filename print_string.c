#include "main.h"

void print_string(char *str)
{
	write(1, str, _strlen(str));
}
