#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
34.9 연습문제: 포인터와 주소 연산자 사용하기

https://dojang.io/mod/page/view.php?id=282

*/

int u3409_quiz() {
	int* numPtr;
	int num1 = 10;
	int num2 = 20;

	numPtr = &num1; //
	printf("%d\n", *numPtr);

	numPtr = &num2; //
	printf("%d\n", *numPtr);

	return 0;
}