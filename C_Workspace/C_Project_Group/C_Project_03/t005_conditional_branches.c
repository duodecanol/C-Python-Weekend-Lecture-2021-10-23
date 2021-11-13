#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test05() {

	if (63 / 9 > 4) {
		printf("Yes");
	}
	printf("No");
}

void test06() {
	int nData = 10, nNewData = 20;
	short x; char ch[] = "Hello";

	if (nNewData = nData) { // 대입연산이 성공했기 때문에 ??
		puts("Success");
	}
	else {
		puts("Failed");
	}

	if (x = nData) {
		puts("Success");
	}
	else {
		puts("Failed");
	}


}

void test07() {
	int nData = 10;

	if (nData == 20); { // Semicolon break 참/거짓에 상관없이 아래 블럭이 실행되고 만다.
		puts("Success");
	}
}

void test08() {
	int num;
	printf("Input an integer: ");
	scanf_s("%d", &num);
	if (num < 0)
		printf("The Input value is less than zero.\n");
	if (num > 0)
		printf("The Input value is greater than zero\n");
	if (num == 0)
		printf("The Input value is zero\n");
	puts("\n\n");
	puts("                            This is the end of the program.");
}

void test09() {
	int nInput = 0;

	scanf_s("%d", &nInput);

	if (nInput >= 10) {

	}
	else {

	}
}