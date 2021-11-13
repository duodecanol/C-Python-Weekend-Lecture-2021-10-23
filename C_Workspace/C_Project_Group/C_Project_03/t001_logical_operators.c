#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int test01() {
	// Select clause

	printf("If the result of the operation is TRUE: %d\n", 20 > 10);
	printf("If the result of the operation is FALSE: %d\n", 20 < 10);

	return 1;
}

int test02() {
	// relational expression
	printf("Relational Expressions\n");
	printf("[<] Less than: %d\n", 11 < 22);
	printf("[>] Greater than: %d\n", 6 > 4);
	printf("[<=] Less than or equal to: %d\n", 22 <= 22);
	printf("[>=] Greater than or equal to: %d\n", 63 >= 2);
	
	// equality expression
	printf("Equality Expressions\n");
	printf("[==] Equal to: %d\n", 2 == 2);
	printf("[!=] Not equal to : %d\n", 1 != 0);
	return 1;
}

int test03() {
	int a = 10;

	printf("Logical Operations\n");
	printf("Logical multiplication : %d\n", (a > 5) && (a <= 15)); // True AND True
	printf("Logical sum : %d\n", (a != 10) || (a == 20));  // False OR False
	printf("Logical negation : %d\n", !((a > 5) > 0));  // NOT True
	printf("When an operand is constant : %d\n", 3.4 && (a > 0)); // 3.4 AND 1
	// 논리연산에서 0을 제외한 모든 수는 참
	return 1;
}

int test04() {
	int nData = 10, nNewData = 20;
	int x = 0, y = 0;

	printf("Logical Operation Examples\n");
	printf("%d\n", !nData && nNewData);
	printf("%d\n", !(nData && x));
	printf("%d\n", !nData || x);
	printf("%d\n", x || !y);
	printf("%d\n", ! (x && !y));

	return 1;
}

void bit_operators() {
	short i = 0xAB00; // 1010 1011 0000 0000 
	short j = 0xABCD; // 1010 1011 1100 1101
	short n;

	printf("Bit Operators\n");
	printf("%hX & %hX = %hX\n", i, j, i & j);
	printf("%hX | %hX = %hX\n", i, j, i | j);
	printf("%hX ^ %hX = %04hX\n", i, j, i ^ j);
	
	printf("\n");
}