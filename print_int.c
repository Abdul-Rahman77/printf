#include <unistd.h>

void print_int(int num) {
	write(1, &num, sizeof(int));
}

int main(void) {
	print_int(4);
	return (0);
}
