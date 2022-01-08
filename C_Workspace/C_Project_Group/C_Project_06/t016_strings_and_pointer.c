#pragma once
#include "projectheader.h"

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