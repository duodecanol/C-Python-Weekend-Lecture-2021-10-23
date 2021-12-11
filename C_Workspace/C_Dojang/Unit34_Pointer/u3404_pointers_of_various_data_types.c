#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pointerTypes () {
	
	long double* ldPtr; // More than 8 byte ??
	long long* llPtr;	// 8 byte (long long, double, )
	float* flPtr;		// 4 byte (int, long, float)
	short* shPtr;		// 2 byte
	char* cPtr;			// 1 byte

	long double ldn = 4.65213999234000123E-5L;
	long long lln = 10;
	float fln = 3.5f;
	short shn = 100;
	char c = 'a';

	ldPtr = &ldn; // %Lf
	llPtr = &lln; // %lld
	flPtr = &fln; // %f
	shPtr = &shn; // %d
	cPtr = &c;    // %c

	puts("다양한 자료형의 포인터 변수들");
	printf("    ldPtr [0x%p] | size (%d) | val: %30.30Lf\n", ldPtr, sizeof(*ldPtr), *ldPtr);
	printf("    llPtr [0x%p] | size (%d) | val: %lld\n", llPtr, sizeof(*llPtr), *llPtr);
	printf("    flPtr [0x%p] | size (%d) | val: %f\n", flPtr, sizeof(*flPtr), *flPtr);
	printf("    shPtr [0x%p] | size (%d) | val: %d\n", shPtr, sizeof(*shPtr), *shPtr);
	printf("     cPtr [0x%p] | size (%d) | val: %c\n", cPtr, sizeof(*cPtr), *cPtr);

	return 0;
}

//int constAndPointer() {
//	const int in = 10;
//	const int* intPtr;
//
//	// 참조하는 변수가 const이면 변경 불가.
//	intPtr = &in;
//	*intPtr = 20;
//
//	// Pointer 자체가 const이면 변경 불가.
//	int num1 = 10;
//	int num2 = 20;
//	int* const nPtr = &num1;
//
//	nPtr = &num2;
//
//	// const int를 참조하는 pointer가 const
//	const int n1 = 10;
//	const int n2 = 20;
//	const int* const intconPtr = &num1;
//
//	*inconPtr = 30; // 역참조 값 변경 불가
//	inconPtr = &num2; // 메모리 주소 변경 불가
//
//	return 0;
//}

