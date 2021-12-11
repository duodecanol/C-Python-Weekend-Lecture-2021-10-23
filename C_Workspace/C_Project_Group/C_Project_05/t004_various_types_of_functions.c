#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>

int Add(int num1, int num2) {
	return num1 + num2;
}

/// <summary>
/// 원하는 만큼의 갯수의 숫자를 입력하여 합계를 구한다.
/// </summary>
/// <param name="howMany">몇 개의 숫자를 입력할 것인지?</param>
/// <param name="...">합계할 숫자들</param>
/// <returns>sum of numbers</returns>
int Sum(int howMany, ...) {
	va_list argsPtr;
	int sum = 0;

	va_start(argsPtr, howMany);
	for (int i = 0; i < howMany; i++) {
		int num = va_arg(argsPtr, int);
		sum += num;
		//printf("%d  ", num);
	}
	va_end(argsPtr);
	//printf("\n");

	return sum;
}

void ShowAddResult(int num) {
	printf("덧셈 결과 출력: %d\n", num);
}

int ReadNum(void) {
	int num;
	scanf_s("%d", &num);
	return num;
}

void HowToUseThisProg(void) {
	printf("두 개의 정수를 입력하시면 덧셈 결과가 출력됩니다.\n");
	printf("자! 그럼 두 개의 정수를 입력하세요\n");
}

int test04() {
	int a, b, added;
	HowToUseThisProg();

	a = ReadNum();
	b = ReadNum();
	added = Add(a, b);

	ShowAddResult(added);

	return 0;
}