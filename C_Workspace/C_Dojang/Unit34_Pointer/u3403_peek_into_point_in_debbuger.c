#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//34.3 디버거에서 포인터 확인하기
//https://dojang.io/mod/page/view.php?id=805

int dereferenceAssign() {
	int* intPtr;
	int num = 699;

	intPtr = &num;

	*intPtr = 20;

	printf("    * intPtr: %d\n", *intPtr);
	printf("        num : %d\n", num);

	return 0;
}