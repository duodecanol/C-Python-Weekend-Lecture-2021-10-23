#pragma once
#include "projectheader.h"
#include <stdlib.h>


int test16() {
	puts("=============");

	printf("       주소값을 출력 : %p\n", "dream");
	printf("첫 번째 문자를  출력 : %c\n", *"dream");
	printf("두 번째 문자를  출력 : %c\n", *("dream" + 1));
	printf("세 번째 문자를  출력 : %c\n", *("dream" + 2));
	printf("네 번째 문자를  출력 : %c\n", *("dream" + 3));
	printf("오 번째 문자를  출력 : %c\n", "dream"[4]); // 문자열은 char의 배열.
	printf("육 번째 문자를  출력 : %d\n", "dream"[5]);

	return 0;
}


int test17() {
	puts("=============");

	char* name;
	name = "Hong Gildong";

	printf("이름: %s\n", name);
	printf("1: %c\n", *name);
	printf("3: %c\n", *(name + 2) );
	printf("6: %c\n", name[5]);

	return 0;
}


int test18() {
	puts("=============");

	char* fruit = "Strawberry";

	while (*fruit != '\0') {
		printf("%s\n", fruit);
		fruit++;
	}

	return 0;
}

int test19() {
	puts("=============");

	char str1[] = "My String"; 
	// 배열명은 문자열을 가리키는 주소값이긴 하지만 변수는 아니다. 값 변경이 불가능하다.
	// 따라서, 배열명은 배열의 1st elem을 가리키는 constant pointer라고 할 수 있다.
	// https://stackoverflow.com/questions/2351544/is-array-name-a-constant-pointer-in-c
	char* str2 = "Your String";

	printf("   str1 in array string: %s\n", str1);
	printf("   str1[0] in stack memory: %p\n", str1);	
			   
	printf("   str2 in char pointer: %s\n", str2);
	printf("   str2[0] in heap memory: %p\n", str2);
	

	// str1 = "Your String"; // 배열명에 다시 할당: Compile Error
	// ** 배열 선언된 문자열의 전체 값을 바꾸는 것은 불가능하다.
	str2 = "Our String";
	// ** 포인터 선언된 문자열의 전체 값을 바꾸는 것이 가능하다.
	printf("%s\n", str2);

	str1[0] = 'X';
	// ** 그런데 배열 선언된 문자열은 indexing으로 각 문자를 하나씩 바꿀 수 있다.
	// 
	// ** 반대로 포인터 선언된 문자열은 문자 하나식 접근하여 dereferencing으로 재할당이 불가능하다.
	//str2[0] = 'X';     [C0000005] code for an access violation. 	
	//*(str2 + 1) = 'X'; [C0000005] code for an access violation.
	printf("%s\n", str1);
	printf("%s\n", str2);

	// 이번에는 String을 char pointer로 선언하되, malloc으로 공간만 잡아놓자.
	char* str3 = malloc(10);
	*(str3 + 0) = 'H';
	*(str3 + 1) = 'e';
	*(str3 + 2) = 'l';
	*(str3 + 3) = 'l';
	*(str3 + 4) = 'o';
	*(str3 + 5) = '\0';

	printf("   str3: %s\n", str3);
	printf("   str3[0] malloc in heap memory: %p\n", str3);	

	// 이 경우에는 변경이 가능하다. 배열의 컨셉과 비슷하다고 생각하자.
	*(str3 + 0) = 'X';
	printf("%s\n", str3);

	free(str3);

	return 0;
}