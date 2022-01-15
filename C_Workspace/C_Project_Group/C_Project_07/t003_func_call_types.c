#pragma once
#include "projectheader.h"


int test03() {
	puts("=============");
	int a = 10;
	a = add_ten_v(a);  // 값을 전달하는 방식 call by value
	printf("  a: %5d\n", a);

	return 0;
}

int test04() {
	puts("=============");
	int a = 50;
	add_ten_r(&a);  // 주소를 전달하는 방식 call by reference
	printf("  a: %5d\n", a);

	return 0;
}

