#pragma once
#include "projectheader.h"

int test01() {
	/*
		Basic operations of pointer

	*/ 
	int a;
	a = 10;
	int* ap; // ������ ����(�ּҸ� �����ϰ� �� �ش�Ǵ� �ּҸ� ����Ų��)
	ap = &a;
	printf("a ������ ���� �ּ� : %p\n", &a);
	printf("ap ������ ���� �� : %p\n", ap); // a ������ ���� �ּ�
	printf("ap ������ ���� �ּ� : %p\n", &ap);
	printf("ap ������ ������ �� : %d\n", *ap);

	*ap = 20;
	puts("\t\t*ap = 20;");
	printf("a ������ �� ���: %d\n", a);
	puts("=============");
	return 0;
}

int test02() {
	/* ������ (dereferenceing)�� ����Ͽ� ���� ���� intPtr�� �����Ͽ�
	* ���� ���Ҵ��Ѵ�.
	*/
	int num1 = 100;
	int num2 = 100;
	int* numPtr;

	numPtr = &num1;
	*numPtr += 30;
	numPtr = &num2;
	*numPtr -= 30;

	printf("num1: %d, num2: %d\n", num1, num2);
	puts("=============");
	return 0;
}

int test03() {
	/* double pointer�� �̿��Ͽ� �� ������ ���� ���� swap�Ѵ�.
	*  �Ϲ������� ��ü���� temp ������ �ϳ� �� �ʿ��ϴ�.
	* �׷��� ���̽� �� �Ϻ� ������  a, b = b, a �� ���� single-line-swap�� �����ϴ�.
	*/
	double a = 1.3;
	double b = 1.7;
	double* ap;
	double* bp;

	double temp;

	ap = &a;
	bp = &b;
	printf("�ٲٱ� ���� a,b ��:�� %.1lf, %.1lf\n", a, b);

	temp = *ap;
	*ap = *bp;
	*bp = temp;

	printf("�ٲ� ���� a,b ��:�� %.1lf, %.1lf\n", a, b);
	puts("=============");

	return 0;

}

int test04() {
	/*
	char array�� �ƴ�, char pointer�� String�� �ʱ�ȭ��Ű��
	�迭 �ε����� �ƴ� ������ �ּ� �������� �����Ͽ� ���ڿ��� ��½�Ų��.
	char �ڷ����� 1 byte�̹Ƿ�, �޸𸮰� 1 byte �������� ���ӵǾ��ִ�.
	���� int��� 4 byte ����, long�̶�� 8 byte �������� �޸� �ּ� �������� �õ��ϸ� ���� ���� �� �ִ�.
	*/
	char* pszData = "Test string!";

	printf("[%p] %c\n", pszData, *pszData);
	printf("[%p] %c\n", pszData + 1, *( pszData + 1 ));
	printf("[%p] %c\n", pszData + 5, *( pszData + 5 ));
	printf("[%p] %c\n", pszData + 11, *( pszData + 11 ));

	puts("=============");
	int i = 0;
	while (1) {
		if (*( pszData + i ) == '\0')
			break;
		printf("[%p] %c\n", pszData + i, *( pszData + i ));
		i++;
	}
	puts("=============");

	return 0;
}