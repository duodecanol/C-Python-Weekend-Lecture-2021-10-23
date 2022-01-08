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

int test08() {
	puts("=============");

	int arr[5] = { 10, 20, 30, 40, 50 };
	int* ap = &arr[0];

	printf("%p\n", ap);
	printf("%d\n", *ap);
	printf("%p\n", ap + 1);
	printf("%d\n", *(ap + 1));
	
	printf("%ld\n", ((long)(ap + 1) - (long)ap));


	return 0;
}

int test08_long() {
	puts("=============");

	long long arr[5] = { 10, 20, 30, 40, 50 };
	long long* ap = &arr[0];

	for (int i = 0; i < 5; i++) {
		printf(" addr of elem #%d: %12p\n", i, ap + i);
		printf("value of elem #%d: %16lld\n", i, *(ap + i));
	}

	printf("Memory size of each elem: %ld\n", ((long)(ap + 1) - (long)ap));

	return 0;
}

int ex11_1() {
	/* ���� �迭�� ��հ��� ���Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	* ��, �迭 ��Ҹ� ������ ���� �迭�� �������� ���ϴ� ������ ǥ���� ����ϸ�,
	* ����� �Ҽ��� ���� ��°�ڸ����� ����Ͻÿ�.
	*/
	puts("=============");

	double arr[] = { 1.5, 20.1, 16.4, 2.3, 3.5 };
	double* ap = &arr; // �迭���� �̿��� ������ ǥ��
	double sum = 0;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		//sum = sum + *(ap + i);
		sum = sum + *(arr + i); // �迭������ ��ü�� �������̴�.
		//sum = sum + *(&arr + i); // ����. �׷��� �����ͺ��� �Ҵ��ϰ� ���� ������ �������� �ʴ´�.
	}

	double avg = sum / (sizeof(arr) / sizeof(arr[0]));

	//printf("%lf\n", sum);                                                                           
	printf("double �迭�� ���: %0.2lf\n", avg);

	return 0;
}