#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 34.2 ������ ������ ����ϱ�
// https://dojang.io/mod/page/view.php?id=276

/*  �����͸� ������ �� *�� "�� ������ �����ʹ�"��� �˷��ִ� �����̰�, 
    �����Ϳ� ����� �� *�� "�������� �޸� �ּҸ� �������ϰڴ�"��� ���Դϴ�.
*/

int test3402()
{
    int* numPtr;      // ������ ���� ����
    int num1 = 10;    // ������ ������ �����ϰ� 10 ����

    numPtr = &num1;   // num1�� �޸� �ּҸ� ������ ������ ����

    printf("*numPtr:  %d\n", *numPtr);    // 10: ������ �����ڷ� num1�� �޸� �ּҿ� �����Ͽ� ���� ������

    return 0;
}

int referenceWarning() {
    int* numPtr;
    int num1 = 10;

    numPtr = num1;   // ������ ���, numPtr�� int ���������̰� num1�� int���̶� �ڷ����� ��ġ���� ����
    // warning C4047: '=': 'int *' differs in levels of indirection from 'int'

    *numPtr = num1;  // *numPtr�� int���̰� num1�� int���̶� �ڷ����� ��ġ��
    return 0;
}