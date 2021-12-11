#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc, free

int type_conversion_pointer()
{
	int* numPtr = malloc(sizeof(int));  // 4 byte
	char* cPtr;							// 1 byte
	
	*numPtr = 0x12345678;
	/*    12 34 56 78
	    Little Endian
		| 78 56 34 12 | <- numPtr
		  ��
	    cPtr (only have one byte)
	*/

	cPtr = (char*)numPtr; // Type cast intpointer to charpointer.

	printf("0x%x\n", *cPtr);

	free(numPtr);

	return 0;
}

int type_conversion_pointer_invalid_value() 
{
	short* numPtr1 = malloc(sizeof(short));    // 2����Ʈ��ŭ �޸� �Ҵ�
	int* numPtr2;

	*numPtr1 = 0x1234;

	numPtr2 = (int*)numPtr1;    // short ������ numPtr1�� int �����ͷ� ��ȯ. �޸� �ּҸ� �����

	printf("0x%x\n", *numPtr2);    // 0xfdfd1234: ���� �޸𸮸� ħ���Ͽ� ���� ������
								   // 0xfdfd�� ��Ȳ�� ���� ���� �޶��� �� ����

	free(numPtr1);    // ���� �޸� ����

	return 0;
}


int type_conversion_pointer_dereference()
{
	int* numPtr = malloc(sizeof(int));    // 4����Ʈ��ŭ �޸� �Ҵ�
	char* cPtr;

	*numPtr = 0x12345678;

	printf("0x%x\n", *(char*)numPtr);    // 0x78: numPtr1�� char �����ͷ� ��ȯ�� �� ������

	free(numPtr);    // ���� �޸� ����

	return 0;
}
