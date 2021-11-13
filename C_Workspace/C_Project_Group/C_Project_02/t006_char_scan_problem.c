#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int test_06() {
	char ch1, ch2;
	printf("첫번째 문자를 입력하세요: ");
	scanf_s("%c", &ch1, 1);
	printf("두번째 문자를 입력하세요: ");
	scanf_s(" %c", &ch2, 1);

	printf("첫번째 문자: %c\n", ch1);
	printf("두번째 문자: %c\n", ch2);
	return 1;
}