#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 34.1 포인터 변수 선언하기
// https://dojang.io/mod/page/view.php?id=275

int pointerDeclar() {
	int* numPtr;      // 포인터 변수 선언
	int num1 = 10;    // int형 변수를 선언하고 10 저장

	numPtr = &num1;   // num1의 메모리 주소를 포인터 변수에 저장

	printf("포인터 변수 numPtr의 값:  %p\n", numPtr);    
							// 0055FC24: 포인터 변수 numPtr의 값 출력
						    // 컴퓨터마다, 실행할 때마다 달라짐
	printf("변수 num1의 메모리 주소 출력:  %p\n", &num1);
							// 0055FC24: 변수 num1의 메모리 주소 출력
						    // 컴퓨터마다, 실행할 때마다 달라짐
	return 0;
}



int test3401(int argc, char* argv[])
{
	int* numPtr;    // Pointer variable declaration
	int num = 10;   // Declare int variable and initialize with the value of 10


	numPtr = &num;  // Assign the memory address of `num` to the pointer variable
	printf("%p\n", numPtr);
	printf("%p\n", &num);

	puts("intPtr/charPtr의 크기: 32bit system은 4 byte, 64bit system은 8 byte");
	printf("%lu\n", sizeof(numPtr)); // 64bit system intPtr : 8 byte
	printf("%lu\n", sizeof(char*)); // 64bit system charPtr : 8 byte

	// 역참조 dereference operator *
	puts("역참조 값 살펴보기");
	printf("*numPtr:  %d\n", *numPtr); // 10: 역참조 연산자로 메모리 주소에 접근하여 값을 가져옴.
	printf("*&num: %d\n", *&num);   // 10: 변수의 메모리 주소를 얻은 다음,  역참조하여 값을 가져옴.

	// 역참조 연산자를 이용하여 포인터 변수를 가지고 값을 할당한다.
	puts("역참조를 이용한 변수 할당.");
	*numPtr = 20;
	printf("%d\n", *numPtr);    // 20: 역참조 연산자로 메모리 주소에 접근하여 값을 가져옴.
	printf("%d\n", num);        // 20: 실제 num 값이 바뀜

	numPtr = num;

	*numPtr = num;

	return 0;
}