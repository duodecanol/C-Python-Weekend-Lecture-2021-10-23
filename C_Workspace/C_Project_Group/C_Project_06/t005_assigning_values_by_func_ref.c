#pragma once
#include "projectheader.h"

int man;

void assignGlobal() {
	// Global variable�� �����Ͽ� ���� ����.
	man = 1000;
}

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

int test05() {
	puts("============= test05");

	man = 0;
	assignGlobal();
	printf("�Լ��� ȣ��� �Ŀ� man�� ����� ��: %d\n", man);

	return 0;
}


int test06() {
	puts("============= test06");

	int cheoli = 0;
	assign(&cheoli);
	printf("�Լ��� ȣ��� �Ŀ� cheoli�� ����� ��: %d\n", cheoli);

	return 0;
}

int test07() {
	puts("============= test07");

	int cheoli = 100, metel = 20;
	printf("�Լ��� ȣ��Ǳ� ���� cheoli: %d, metel: %d\n", cheoli, metel);
	exchange(&cheoli, &metel);
	printf("�Լ��� ȣ���   ���� cheoli: %d, metel: %d\n", cheoli, metel);

	return 0;
}
