#include "main.h"
#define INT_BUFF 20
/**
 *
 *
 */

int unsigned_int_handler(va_list list, char main_buff[], int main_count) {
	int value = va_arg(list, int);
	char buffer[INT_BUFF];
	int parse_count = 0;

	if (value < 0) {
		return (-1);
	}

	do {
		buffer[parse_count++] = '0' + (value % 10);
		value = (value / 10);
	} while (value > 0);

	for (int i = 0, j = parse_count - 1; i < j; i++, j--) {
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

int octal_handler(va_list list, char main_buff[], int main_count) {
        int value = va_arg(list, int);
        char buffer[INT_BUFF];
        int parse_count = 0;

        if (value < 0) {
                return (-1);
        }

        do {
                buffer[parse_count++] = '0' + (value % 8);
                value = (value / 8);
        } while (value > 0);

        for (int i = 0, j = parse_count - 1; i < j; i++, j--) {
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

int hexadecimal_x_handler(va_list list, char main_buff[], int main_count) {
        int value = va_arg(list, int);
        char buffer[INT_BUFF];
        int parse_count = 0;

        if (value < 0) {
                return (-1);
        }

	int var_char;
	char extra_char[] = {'a', 'b', 'c', 'd', 'e', 'f'};
        while (value > 0) {
		var_char = (value % 16);
		if (var_char > 9)
			buffer[parse_count++] = extra_char[var_char % 10];
		else
               		buffer[parse_count++] = '0' + var_char;
                value = (value / 16);
        }

        for (int i = 0, j = parse_count - 1; i < j; i++, j--) {
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

int hexadecimal_X_handler(va_list list, char main_buff[], int main_count) {
        int value = va_arg(list, int);
        char buffer[INT_BUFF];
        int parse_count = 0;

        if (value < 0) {
                return (-1);
        }   

        int var_char;
        char extra_char[] = "ABCDEF";
        while (value > 0) {
                var_char = (value % 16);
                if (var_char > 9)
                        buffer[parse_count++] = extra_char[var_char % 10];
                else
                        buffer[parse_count++] = '0' + var_char;
                value = (value / 16);
        } 

        for (int i = 0, j = parse_count - 1; i < j; i++, j--) {
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

