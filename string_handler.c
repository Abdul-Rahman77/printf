#include "main.h"

int string_handler(va_list list, char buff[], int i)
{
	char *str = va_arg(list, char*);
	char count = 0;

	while (str[count] != '\0')
	{
		buff[i + count] = str[count];
		count++;
	}
	i += count;
	return (i);
}
