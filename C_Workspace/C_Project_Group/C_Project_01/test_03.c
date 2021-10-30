#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test_03() {
	printf("100+200");
	printf("\n");
	printf("%d", 100 + 200);
	printf("\n");
	int age;
	printf("나이를 입력하세요:   ");	scanf("%d", &age);
	printf("나의 나이는 %d세 이다\n", age);
	printf("The sum of %d and %d is %d", 10, 10, 20);
}