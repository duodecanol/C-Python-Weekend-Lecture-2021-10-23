#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int test_06() {
	char ch1, ch2;
	printf("ù��° ���ڸ� �Է��ϼ���: ");
	scanf_s("%c", &ch1, 1);
	printf("�ι�° ���ڸ� �Է��ϼ���: ");
	scanf_s(" %c", &ch2, 1);

	printf("ù��° ����: %c\n", ch1);
	printf("�ι�° ����: %c\n", ch2);
	return 1;
}