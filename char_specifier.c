#include "main.h"

int char_handler(va_list list, char buff[], int i) {
	char character = va_arg(list, int);
	buff[i] = character;
	i++;
	return (i);
}
