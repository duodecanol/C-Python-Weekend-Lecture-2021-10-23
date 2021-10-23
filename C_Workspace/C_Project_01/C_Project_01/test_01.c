#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	printf("Hello, World!\n");

	int aa = 200;
	float bb = 15666.3148121333;
	printf("%d\n", aa);
	printf("%5.3f\n", aa);
	printf("%5.3f\n", 6375.0);
	printf("%.3f\n", bb);
	printf("Radix friends %d  %x  %o  %#x  %#o\n", 128, 128, 128, 128, 128);
	return 0;
}