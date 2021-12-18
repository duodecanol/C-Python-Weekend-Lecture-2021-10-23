#pragma once
#include "projectheader.h"

int test01() {
	// Basic operations of pointer
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