#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//34.5 void ������ �����ϱ�
//
//https://dojang.io/mod/page/view.php?id=278

int voidpointer() {
	/**
	* �⺻������ C ���� �ڷ����� �ٸ� �����ͳ��� �޸� �ּҸ� �����ϸ� ������ ���(warning)�� �߻��մϴ�.
	* ������ void �����ʹ� �ڷ����� �������� ���� Ư�� ������ 
	* � �ڷ������� �� �����͵� ��� ������ �� �ֽ��ϴ�. 
	* �ݴ�� �پ��� �ڷ������� �� �����Ϳ��� void �����͸� ������ ���� �ֽ��ϴ�.
	* �̷� Ư�� ������ void �����ʹ� ���� �����Ͷ�� �մϴ�.
	*/
	int num1 = 10;
	char c1 = 'a';
	int* numPtr1 = &num1;
	char* cPtr1 = &c1;

	void* vPtr; // Here is a void pointer

	// ������ �ڷ����� �޶� ������ ��� �߻����� ����
	vPtr = numPtr1;    // void �����Ϳ� int ������ ����
	vPtr = cPtr1;      // void �����Ϳ� char ������ ����

	// ������ �ڷ����� �޶� ������ ��� �߻����� ����
	numPtr1 = vPtr;    // int �����Ϳ� void ������ ����
	cPtr1 = vPtr;      // char �����Ϳ� void ������ ����

	// an 'implicit' type change takes place when it comes to a void pointer.

	/* 
	��, void �����ʹ� �ڷ����� �������� �ʾ����Ƿ�
	���� �������ų� ������ ũ�⵵ �������� �ʾҽ��ϴ�. 
	���� void �����ʹ� �������� �� �� �����ϴ�. */
	vPtr = &num1;
	//printf("%d", *vPtr); // Dereferencing is invalid for a void pointer
	// ERROR: C2100 illegal indirection

	return 0;
}

/* 
		58.3 void ������ ��ȯ�ϱ�

		https://dojang.io/mod/page/view.php?id=495
*/
int type_conversion_void_pointer()
{
	int num1 = 10;
	float num2 = 3.5f;
	char c1 = 'a';
	void* ptr;

	ptr = &num1;    // num1�� �޸� �ּҸ� void ������ ptr�� ����
	// printf("%d\n", *ptr);         // ������ ����
	printf("%d\n", *(int*)ptr);     // 10: void �����͸� int �����ͷ� ��ȯ�� �� ������

	ptr = &num2;    // num2�� �޸� �ּҸ� void ������ ptr�� ����
	// printf("%f\n", *ptr);         // ������ ����
	printf("%f\n", *(float*)ptr);   // 3.500000: void �����͸� float �����ͷ� ��ȯ�� �� ������

	ptr = &c1;      // c1�� �޸� �ּҸ� void ������ ptr�� ����
	// printf("%c\n", *ptr);         // ������ ����
	printf("%c\n", *(char*)ptr);    // a: void �����͸� char �����ͷ� ��ȯ�� �� ������

	return 0;
}