#pragma once
#include "projectheader.h"

int test01() {
	// Basic operations of pointer
	int a;
	a = 10;
	int* ap; // 포인터 변수(주소를 저장하고 그 해당되는 주소를 가리킨다)
	ap = &a;
	printf("a 변수의 시작 주소 : %p\n", &a);
	printf("ap 포인터 변수 값 : %p\n", ap); // a 변수의 시작 주소
	printf("ap 포인터 시작 주소 : %p\n", &ap);
	printf("ap 포인터 역참조 값 : %d\n", *ap);

	*ap = 20;
	puts("\t\t*ap = 20;");
	printf("a 변수의 값 출력: %d\n", a);
	puts("=============");
	return 0;
}	

int test02() {
	int num1 = 100;
	int num2 = 100;
	int* numPtr;

	numPtr = &num1;
	*numPtr += 30;
	numPtr = &num2;
	*numPtr -= 30;

	printf("num1: %d, num2: %d\n", num1, num2);
	puts("=============");
	return 0;
}

int test03() {
	double a = 1.3;
	double b = 1.7;
	double* ap;
	double* bp;

	double temp;

	ap = &a;
	bp = &b;
	printf("바꾸기 전의 a,b 값:ㅣ %.1lf, %.1lf\n", a, b);

	temp = *ap;
	*ap = *bp;
	*bp = temp;

	printf("바꾼 후의 a,b 값:ㅣ %.1lf, %.1lf\n", a, b);
	puts("=============");

	return 0;

}