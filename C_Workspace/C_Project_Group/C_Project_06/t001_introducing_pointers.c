#pragma once
#include "projectheader.h"

int test01() {
	/*
		Basic operations of pointer

	*/ 
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
	/* 역참조 (dereferenceing)을 사용하여 변수 값에 intPtr로 접근하여
	* 값을 재할당한다.
	*/
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
	/* double pointer를 이용하여 두 변수의 값을 서로 swap한다.
	*  일반적으로 교체에는 temp 변수가 하나 더 필요하다.
	* 그러나 파이썬 등 일부 언어에서는  a, b = b, a 와 같이 single-line-swap이 가능하다.
	*/
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

int test04() {
	/*
	char array가 아닌, char pointer에 String을 초기화시키고
	배열 인덱스가 아닌 포인터 주소 간격으로 접근하여 문자열을 출력시킨다.
	char 자료형은 1 byte이므로, 메모리가 1 byte 간격으로 연속되어있다.
	만약 int라면 4 byte 간격, long이라면 8 byte 간격으로 메모리 주소 역참조를 시도하면 값을 얻을 수 있다.
	*/
	char* pszData = "Test string!";

	printf("[%p] %c\n", pszData, *pszData);
	printf("[%p] %c\n", pszData + 1, *( pszData + 1 ));
	printf("[%p] %c\n", pszData + 5, *( pszData + 5 ));
	printf("[%p] %c\n", pszData + 11, *( pszData + 11 ));

	puts("=============");
	int i = 0;
	while (1) {
		if (*( pszData + i ) == '\0')
			break;
		printf("[%p] %c\n", pszData + i, *( pszData + i ));
		i++;
	}
	puts("=============");

	return 0;
}