#pragma once
#include "projectheader.h"

int man;

void assignGlobal() {
	// Global variable에 접근하여 값을 변경.
	man = 1000;
}

void assign(int* ip) {
	// 함수는 메모리에 있는 별도의 공간이다.
	// 함수는 호출시 동작한다.
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
	printf("함수가 호출된 후에 man에 저장된 값: %d\n", man);

	return 0;
}


int test06() {
	puts("============= test06");

	int cheoli = 0;
	assign(&cheoli);
	printf("함수가 호출된 후에 cheoli에 저장된 값: %d\n", cheoli);

	return 0;
}

int test07() {
	puts("============= test07");

	int cheoli = 100, metel = 20;
	printf("함수가 호출되기 전의 cheoli: %d, metel: %d\n", cheoli, metel);
	exchange(&cheoli, &metel);
	printf("함수가 호출된   후의 cheoli: %d, metel: %d\n", cheoli, metel);

	return 0;
}
