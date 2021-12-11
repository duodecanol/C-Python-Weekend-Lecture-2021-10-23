#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//34.5 void 포인터 선언하기
//
//https://dojang.io/mod/page/view.php?id=278

int voidpointer() {
	/**
	* 기본적으로 C 언어는 자료형이 다른 포인터끼리 메모리 주소를 저장하면 컴파일 경고(warning)가 발생합니다.
	* 하지만 void 포인터는 자료형이 정해지지 않은 특성 때문에 
	* 어떤 자료형으로 된 포인터든 모두 저장할 수 있습니다. 
	* 반대로 다양한 자료형으로 된 포인터에도 void 포인터를 저장할 수도 있습니다.
	* 이런 특성 때문에 void 포인터는 범용 포인터라고 합니다.
	*/
	int num1 = 10;
	char c1 = 'a';
	int* numPtr1 = &num1;
	char* cPtr1 = &c1;

	void* vPtr; // Here is a void pointer

	// 포인터 자료형이 달라도 컴파일 경고가 발생하지 않음
	vPtr = numPtr1;    // void 포인터에 int 포인터 저장
	vPtr = cPtr1;      // void 포인터에 char 포인터 저장

	// 포인터 자료형이 달라도 컴파일 경고가 발생하지 않음
	numPtr1 = vPtr;    // int 포인터에 void 포인터 저장
	cPtr1 = vPtr;      // char 포인터에 void 포인터 저장

	// an 'implicit' type change takes place when it comes to a void pointer.

	/* 
	단, void 포인터는 자료형이 정해지지 않았으므로
	값을 가져오거나 저장할 크기도 정해지지 않았습니다. 
	따라서 void 포인터는 역참조를 할 수 없습니다. */
	vPtr = &num1;
	//printf("%d", *vPtr); // Dereferencing is invalid for a void pointer
	// ERROR: C2100 illegal indirection

	return 0;
}