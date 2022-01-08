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
	/* 다음 배열의 평균값을 구하여 출력하는 프로그램을 작성하시오.
	* 단, 배열 요소를 참조할 때는 배열명에 정수값을 더하는 포인터 표현을 사용하며,
	* 평균은 소수점 이하 둘째자리까지 출력하시오.
	*/
	puts("=============");

	double arr[] = { 1.5, 20.1, 16.4, 2.3, 3.5 };
	double* ap = &arr; // 배열명을 이용한 포인터 표현
	double sum = 0;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		//sum = sum + *(ap + i);
		sum = sum + *(arr + i); // 배열변수명 자체가 포인터이다.
		//sum = sum + *(&arr + i); // 에러. 그런데 포인터변수 할당하고 나서 연산은 오류나지 않는다.
	}

	double avg = sum / (sizeof(arr) / sizeof(arr[0]));

	//printf("%lf\n", sum);                                                                           
	printf("double 배열의 평균: %0.2lf\n", avg);

	return 0;
}