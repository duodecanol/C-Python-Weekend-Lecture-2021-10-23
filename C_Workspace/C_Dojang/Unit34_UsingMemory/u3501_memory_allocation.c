#include "unitheader.h"
#include <stdlib.h>
#include <string.h>

int memory_alloc() {
	/*
	35.1 메모리 할당하기
	https://dojang.io/mod/page/view.php?id=285
	일반적인 variable은 stack에 생성된다.		메모리 자동 해제
	malloc으로 할당하면 heap 영역을 사용한다.	메모리 수동 해제

	핵심정리 : https://dojang.io/mod/page/view.php?id=605
	*/
	int num = 20;
	int* numPtr;

	numPtr = &num;

	int* numPtr2;

	numPtr2 = malloc(sizeof(int));

	printf("0x%p\n", numPtr);
	printf("0x%p\n", numPtr2);

	free(numPtr2);

	return 0;
}

int memory_dereferencing() {
	int* numPtr;

	numPtr = malloc(sizeof(int));

	*numPtr = 10;

	printf("%\d\n", *numPtr);

	free(numPtr);
			
	return 0;
}

int memory_set() {
	long long* numPtr = malloc(sizeof(long long));

	memset(numPtr, 0xFF27, sizeof(long long));

	printf("0x%llx\n", *numPtr);

	free(numPtr);
	return 0;
}

int null_pointer() {
	int* numPtr1 = NULL;
	printf("%p\n", numPtr1);
	if (numPtr1 == NULL)
		numPtr1 = malloc(sizeof(int));
	printf("%x\n", *numPtr1);
	*numPtr1 = 66;
	printf("%d\n", *numPtr1);
	return 0;
}