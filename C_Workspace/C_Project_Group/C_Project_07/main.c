#pragma once
#include "projectheader.h"

void swap(int*, int*);
int add_ten_v(int);
void add_ten_r(int*);

int main() {

	// ���������� ������ ���ѵǴ� ��� Ž��
	test011();
	test012();
	test013();

	test02();

	// �Լ��� �Ű�����
	// Call by Value and Reference
	test03();
	test04();


	return 0;
}

void swap(int* a, int* b) { // �ּҸ� �����ϴ� ��� call by reference
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
