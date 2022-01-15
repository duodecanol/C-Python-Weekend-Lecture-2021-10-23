#pragma once
#include "projectheader.h"


int test011() {
	puts("============= local variable");
	int a = 10, b = 20;

	printf("바꾸기 전  a: %5d, b: %5d\n", a, b);

	//a, b = b, a; // Python syntax
	int temp;
	temp = a;
	a = b;
	b = temp;

	printf("바꾸기 후  a: %5d, b: %5d\n", a, b);

	return 0;
}

int test012() {
	puts("============= use function ref param");
	int a = 10, b = 20;

	printf("바꾸기 전  a: %5d, b: %5d\n", a, b);

	swap(&a, &b);

	printf("바꾸기 후  a: %5d, b: %5d\n", a, b);

	return 0;
}

int test013() {
	puts("=============");
	int a = 10, b = 20;

	printf("바꾸기 전  a: %5d, b: %5d\n", a, b);
	// define scope and therefore restrict the range of the varibles declared inside
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
		printf("temp value: %5d\n", temp);
	}
	printf("바꾸기 후  a: %5d, b: %5d\n", a, b);
	//printf("temp value: %5d\n", temp);

	return 0;
}

int test02() {
	puts("=============");
	int val = 10;
	//int val = 20; 
	// 'val': redefinition; multiple initialization
	{
		int val = 20;
		{
			val++;
			{
				val++;
				{
					val++;
				}
			}
		}
		printf("val: %5d\n", val);  // 23
		// 위 경우에서처럼, 여러 구역에 같은 변수 이름이 선언되었고
		// 중첩된 내부 scope에서 변수 값을 변화시킬 경우
		// 가장 가까운 상위 scope의 변수에 작용한다.
	}
	printf("val: %5d\n", val);  // 10

	return 0;
}