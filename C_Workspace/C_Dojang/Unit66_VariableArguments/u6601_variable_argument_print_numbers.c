#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
/*  va_list, va_start, va_arg, va_end가 정의된 헤더 파일
* 
*   va_list:	가변 인자 목록. 가변 인자의 메모리 주소를 저장하는 포인터입니다.
*   va_start:	가변 인자를 가져올 수 있도록 포인터를 설정합니다.
*   va_arg:		가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져옵니다.
*   va_end:		가변 인자 처리가 끝났을 때 포인터를 NULL로 초기화합니다.
* 
* 
* 
*/


// 66.1 가변 인자 함수 만들기
// https://dojang.io/mod/page/view.php?id=577

void printNumbers(int args, ...) {
	va_list argsPtr; // variable arguments list pointer

	va_start(argsPtr, args); // link the args to the pointer

	for (int i = 0; i < args; i++) {
		int num = va_arg(argsPtr, int);
		printf("%d  ", num);
	}

	va_end(argsPtr); // Set the pointer NULL
	printf("\n");
}

int test6601() {
	printNumbers(1, 10);                // 인수 개수 1개
	printNumbers(2, 10, 20);            // 인수 개수 2개
	printNumbers(3, 10, 20, 30);        // 인수 개수 3개
	printNumbers(4, 10, 20, 30, 40);    // 인수 개수 4개

	return 0;
}