#include "main.h"
#define INT_BUFF 20
/**
 *
 *
 */

int int_handler(va_list list, char main_buff[], int main_count) {
	int value = va_arg(list, int);
	char buffer[INT_BUFF];
	int parse_count = 0;

	if (value < 0) {
		buffer[parse_count++] = '-';
		value = -value;
	}

	do {
		buffer[parse_count++] = '0' + (value % 10);
		value = (value / 10);
	} while (value > 0);

	for (int i = 0, j = parse_count - 1; i < j; i++, j--) {
		if (buffer[i] == '-')
			i++;
		char swap = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = swap;
	}
	buffer[parse_count] = '\0';

	int mini_parser = 0;
	while (buffer[mini_parser] != '\0') {
		main_buff[main_count + mini_parser] = buffer[mini_parser];
		mini_parser++;
	}
	main_count += parse_count;
	return (main_count);

}
