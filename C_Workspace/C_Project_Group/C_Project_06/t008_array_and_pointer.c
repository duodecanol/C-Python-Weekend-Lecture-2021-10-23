#pragma once
#include "projectheader.h"

int test08() {
	puts("============= int ");

	int arr[5] = { 10, 20, 30, 40, 50 };
	int* ap = &arr[0];

	for (int i = 0; i < 5; i++) {
		printf(" addr of elem #%d: %p\n", i, ap + i);
		printf("value of elem #%d: %12d\n", i, *(ap + i));
	}

	printf("Memory size of each elem: %ld\n", ((long)(ap + 1) - (long)ap));

	return 0;
}

int test08_long() {
	puts("============= long long ");

	long long arr[5] = { 10, 20, 30, 40, 50 };
	long long* ap = &arr[0];

	for (int i = 0; i < 5; i++) {
		printf(" addr of elem #%d: %p\n", i, ap + i);
		printf("value of elem #%d: %12lld\n", i, *(ap + i));
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
		sum = sum + *(arr + i); //TODO: 배열변수명 자체가 포인터이다.
		//sum = sum + *(&arr + i); // 에러. 그런데 포인터변수 할당하고 나서 연산은 오류나지 않는다.
	}

	double avg = sum / (sizeof(arr) / sizeof(arr[0]));

	//printf("%lf\n", sum);                                                                           
	printf("double 배열의 평균: %0.2lf\n", avg);

	return 0;
}

int test10() {
	puts("=============");

	int arr[5] = { 10, 20, 30, 40, 50 };
	int* ap = arr;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%5d", *ap);
		ap++; //FIXME: get next elem by shifting addr 
	}
	puts("");
	return 0;
}

void arr_prn(int* ap) {
	for (int i = 0; i < sizeof(ap) / sizeof(ap[0]); i++) {
		printf("%5d", ap[i]);
		//ap++;
	}
	puts("");
}

int test11() {
	puts("=============");

	int arr[5] = { 10, 20, 30, 40, 50 };

	arr_prn(arr);

	return 0;
}

