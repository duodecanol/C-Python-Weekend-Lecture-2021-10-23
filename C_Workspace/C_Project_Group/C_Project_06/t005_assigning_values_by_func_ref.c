#pragma once
#include "projectheader.h"

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

int test06() {
	puts("=============");

	int cheoli = 0;
	assign(&cheoli);
	printf("함수가 호출된 후에 cheoli에 저장된 값: %d\n", cheoli);

	return 0;
}

int test07() {
	puts("=============");

	int cheoli = 10, metel = 20;
	exchange(&cheoli, &metel);
	printf("함수가 호출된 후의 cheoli: %d, metel: %d\n", cheoli, metel);

	return 0;
}
