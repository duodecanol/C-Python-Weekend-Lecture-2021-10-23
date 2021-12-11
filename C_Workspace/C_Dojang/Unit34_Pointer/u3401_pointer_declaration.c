#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 34.1 ������ ���� �����ϱ�
// https://dojang.io/mod/page/view.php?id=275

int pointerDeclar() {
	int* numPtr;      // ������ ���� ����
	int num1 = 10;    // int�� ������ �����ϰ� 10 ����

	numPtr = &num1;   // num1�� �޸� �ּҸ� ������ ������ ����

	printf("������ ���� numPtr�� ��:  %p\n", numPtr);    
							// 0055FC24: ������ ���� numPtr�� �� ���
						    // ��ǻ�͸���, ������ ������ �޶���
	printf("���� num1�� �޸� �ּ� ���:  %p\n", &num1);
							// 0055FC24: ���� num1�� �޸� �ּ� ���
						    // ��ǻ�͸���, ������ ������ �޶���
	return 0;
}



int test3401(int argc, char* argv[])
{
	int* numPtr;    // Pointer variable declaration
	int num = 10;   // Declare int variable and initialize with the value of 10


	numPtr = &num;  // Assign the memory address of `num` to the pointer variable
	printf("%p\n", numPtr);
	printf("%p\n", &num);

	puts("intPtr/charPtr�� ũ��: 32bit system�� 4 byte, 64bit system�� 8 byte");
	printf("%lu\n", sizeof(numPtr)); // 64bit system intPtr : 8 byte
	printf("%lu\n", sizeof(char*)); // 64bit system charPtr : 8 byte

	// ������ dereference operator *
	puts("������ �� ���캸��");
	printf("*numPtr:  %d\n", *numPtr); // 10: ������ �����ڷ� �޸� �ּҿ� �����Ͽ� ���� ������.
	printf("*&num: %d\n", *&num);   // 10: ������ �޸� �ּҸ� ���� ����,  �������Ͽ� ���� ������.

	// ������ �����ڸ� �̿��Ͽ� ������ ������ ������ ���� �Ҵ��Ѵ�.
	puts("�������� �̿��� ���� �Ҵ�.");
	*numPtr = 20;
	printf("%d\n", *numPtr);    // 20: ������ �����ڷ� �޸� �ּҿ� �����Ͽ� ���� ������.
	printf("%d\n", num);        // 20: ���� num ���� �ٲ�

	numPtr = num;

	*numPtr = num;

	return 0;
}