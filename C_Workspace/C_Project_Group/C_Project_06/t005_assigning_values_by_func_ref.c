#pragma once
#include "projectheader.h"

void assign(int* ip) {
	// �Լ��� �޸𸮿� �ִ� ������ �����̴�.
	// �Լ��� ȣ��� �����Ѵ�.
	*ip = 100;
}

/// <summary>
/// swap values of two variables.
/// </summary>
/// <param name="a">int variable</param>
/// <param name="b">int variable</param>
void exchange(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int test06() {
	puts("=============");

	int cheoli = 0;
	assign(&cheoli);
	printf("�Լ��� ȣ��� �Ŀ� cheoli�� ����� ��: %d\n", cheoli);

	return 0;
}

int test07() {
	puts("=============");

	int cheoli = 10, metel = 20;
	exchange(&cheoli, &metel);
	printf("�Լ��� ȣ��� ���� cheoli: %d, metel: %d\n", cheoli, metel);

	return 0;
}
