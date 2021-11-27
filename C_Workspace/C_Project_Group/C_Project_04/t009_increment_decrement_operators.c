#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**
*                Increment/Decrement Operators 
*                                      ���� ������ p.142
*
*/

int test09() {
	int nData = 10;

	// Increment/Decrement Operators
	nData--;
	--nData;
	nData++;
	++nData;

	printf("nData: %d\n", nData);
	printf("++nData: %d\n", ++nData); // Increase nData by 1 and then print
	printf("nData++: %d\n", nData++); // Print nData and then increase it by 1
	printf("nData: %d\n", nData);

	return 1;
}

int test10() {
	int a = 0, b = 0;

	++a; b++; // A single line operation irrelavant whther prefix or postfix
	printf("a=%d, b=%d\n", a, b);

	b = a++; // Assign a to b and then increase a
	printf("a=%d, b=%d\n", a, b);

	b = ++a; // Increase a and then assign it to b
	printf("a=%d, b=%d\n", a, b);

	printf("a=%d, b=%d\n", a++, b++); // Same case as the previous one: print then increase
	printf("a=%d, b=%d\n", a, b);     // Check the variables

	printf("a=%d, b=%d\n", ++a, ++b);
	printf("a=%d, b=%d\n", a, b);

	printf("a=%d, b=%d\n", --a, b--);
	printf("a=%d, b=%d\n", a, b);

	printf("a=%d, b=%d\n", a--, --b);
	printf("a=%d, b=%d\n", a, b);
	printf("===================================\n");
	return 1;
}

int test11() {
	int nData = 10;
	int nNewData = 20;
	int nResult = 0;

	printf("%d\n", ++nData);
	printf("%d\n", nData++);

	nResult = ++nData + nNewData;
	printf("%d\n", nResult);
	printf("%d\n", nNewData);
	printf("===================================\n");
	return 1;
}


/***
* while ���� ������������ ��� ��
* 
* ���� 1. ����� �Է¹����� �� ���ڸ�ŭ *�� ��µǴ� ���α׷��� �ۼ��Ͻÿ�. 
		  while ���� ���� �����ڸ� ����Ͻÿ�.
* ���� 2. �߰��� �� �ٿ� 5���� ��µǵ��� �ٲپ� ���ÿ�.
*              ex7_3.c
*/
int ex7_3() {
	unsigned int nInput;   // �Է°��� ����� ����
	unsigned int nInput2;
	unsigned int lowerBound = 0;

	scanf_s("%d", &nInput); nInput2 = nInput;

	while (nInput > 0) {
		printf("%c", '*');
		nInput--;
	}
	printf("\n");
	printf("===================================\n");	

	while (nInput2 != lowerBound) {
		if ((lowerBound % 5) == 0) printf("\n");
		lowerBound++;
		printf("%c", '*');
	}
	printf("\n");
	printf("===================================\n");
}
