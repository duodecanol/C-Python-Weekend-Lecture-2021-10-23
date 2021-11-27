#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**
*                Increment/Decrement Operators 
*                                      증감 연산자 p.142
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
* while 문과 증감연산자의 사용 예
* 
* 문제 1. 양수를 입력받으면 그 숫자만큼 *이 출력되는 프로그램을 작성하시오. 
		  while 문과 증감 연산자를 사용하시오.
* 문제 2. 추가로 한 줄에 5개씩 출력되도록 바꾸어 보시오.
*              ex7_3.c
*/
int ex7_3() {
	unsigned int nInput;   // 입력값은 양수만 가능
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
