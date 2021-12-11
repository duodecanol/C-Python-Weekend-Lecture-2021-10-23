#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int result;
	result = add(3, 4); // 함수가 호출되어 메모리에 적재된 다음 지정된 자료형의 반환값을 반환하고 종료. 메모리에서 사라진다.
	printf("덧셈 결과 1 : %d\n", result);
	result = add(5, 8);
	printf("덧셈 결과 2 : %d\n", result);
}

