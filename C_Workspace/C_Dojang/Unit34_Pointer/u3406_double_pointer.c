#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
34.6 ���� ������ ����ϱ�
https://dojang.io/mod/page/view.php?id=279


�����͵� �����δ� �����̱� ������ �޸� �ּҸ� ���� �� �ֽ��ϴ�. 
������ �������� �޸� �ּҴ� �Ϲ� �����Ϳ� ������ �� ����, 
int **numPtr2;ó�� ���� �����Ϳ� �����ؾ� �մϴ�. 
int **numPtr2;�� ����� ������ pointer to pointer to int�� �˴ϴ�(numPtr2 �� numPtr1 �� num1).

���⼭ ���� ������ numPtr2�� ������ ���󰡼� ���� ���� ���������� 
**numPtr2ó�� ���� �տ� ������ �����ڸ� �� �� ����ϸ� �˴ϴ�. 
��, �������� �� �� �ϹǷ� numPtr2 �� numPtr1 �� num1�� ���� ����� �ǰ� num1�� ���� ������ �� �ֽ��ϴ�.

*/
int doublePointerExample() {
	int* numPtr;
	int** numPtrPtr;
	int num = 10;

	numPtr = &num;
	numPtrPtr = &numPtr;

	printf("    **numPtrPtr at [0x%p] : %d\n", &numPtrPtr, **numPtrPtr);
	return 0;
}