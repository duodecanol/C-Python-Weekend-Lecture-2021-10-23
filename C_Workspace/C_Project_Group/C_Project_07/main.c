#pragma once
#include "projectheader.h"

void swap(int*, int*);
int add_ten_v(int);
void add_ten_r(int*);

int main() {

	// 지역변수의 범위가 제한되는 경우 탐구
	test011();
	test012();
	test013();

	test02();

	// 함수의 매개변수
	// Call by Value and Reference
	test03();
	test04();


	return 0;
}

void swap(int* a, int* b) { // 주소를 전달하는 방식 call by reference
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int add_ten_v(int b) {
	b += 10;
	return b;
}

void add_ten_r(int* b) {
	*b += 10;
}
