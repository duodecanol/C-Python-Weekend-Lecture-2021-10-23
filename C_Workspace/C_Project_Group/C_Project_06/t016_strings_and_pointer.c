#pragma once
#include "projectheader.h"

int test16() {
	puts("=============");

	printf("       �ּҰ��� ��� : %p\n", "dream");
	printf("ù ��° ���ڸ�  ��� : %c\n", *"dream");
	printf("�� ��° ���ڸ�  ��� : %c\n", *("dream" + 1));
	printf("�� ��° ���ڸ�  ��� : %c\n", *("dream" + 2));
	printf("�� ��° ���ڸ�  ��� : %c\n", *("dream" + 3));
	printf("�� ��° ���ڸ�  ��� : %c\n", "dream"[4]); // ���ڿ��� char�� �迭.
	printf("�� ��° ���ڸ�  ��� : %d\n", "dream"[5]);

	return 0;
}