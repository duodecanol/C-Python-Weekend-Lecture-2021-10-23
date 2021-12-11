#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
/*  va_list, va_start, va_arg, va_end�� ���ǵ� ��� ����
* 
*   va_list:	���� ���� ���. ���� ������ �޸� �ּҸ� �����ϴ� �������Դϴ�.
*   va_start:	���� ���ڸ� ������ �� �ֵ��� �����͸� �����մϴ�.
*   va_arg:		���� ���� �����Ϳ��� Ư�� �ڷ��� ũ�⸸ŭ ���� �����ɴϴ�.
*   va_end:		���� ���� ó���� ������ �� �����͸� NULL�� �ʱ�ȭ�մϴ�.
* 
* 
* 
*/


// 66.1 ���� ���� �Լ� �����
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
	printNumbers(1, 10);                // �μ� ���� 1��
	printNumbers(2, 10, 20);            // �μ� ���� 2��
	printNumbers(3, 10, 20, 30);        // �μ� ���� 3��
	printNumbers(4, 10, 20, 30, 40);    // �μ� ���� 4��

	return 0;
}