#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int test07() {
	char name[80];
	char sex;
	int age;
	double height;

	printf("Input your name: ");
	scanf_s("%s", name, 80);
	printf("Input your gender: ");
	scanf_s(" %c", &sex, 1);
	printf("Input your age: ");
	scanf_s(" %d", &age);
	printf("Input your height: ");
	scanf_s(" %lf", &height);

	printf("Name: %s, Sex: %c, Age: %d, Height: %.1lf\n\a", name, sex, age, height);
	return 1;
}