#include "unitheader.h"
#include <stdlib.h>
#include <string.h>

int memory_alloc() {
	/*
	35.1 �޸� �Ҵ��ϱ�
	https://dojang.io/mod/page/view.php?id=285
	�Ϲ����� variable�� stack�� �����ȴ�.		�޸� �ڵ� ����
	malloc���� �Ҵ��ϸ� heap ������ ����Ѵ�.	�޸� ���� ����

	�ٽ����� : https://dojang.io/mod/page/view.php?id=605
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