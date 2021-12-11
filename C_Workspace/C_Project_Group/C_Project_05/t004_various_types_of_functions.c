#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>

int Add(int num1, int num2) {
	return num1 + num2;
}

/// <summary>
/// ���ϴ� ��ŭ�� ������ ���ڸ� �Է��Ͽ� �հ踦 ���Ѵ�.
/// </summary>
/// <param name="howMany">�� ���� ���ڸ� �Է��� ������?</param>
/// <param name="...">�հ��� ���ڵ�</param>
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
	printf("���� ��� ���: %d\n", num);
}

int ReadNum(void) {
	int num;
	scanf_s("%d", &num);
	return num;
}

void HowToUseThisProg(void) {
	printf("�� ���� ������ �Է��Ͻø� ���� ����� ��µ˴ϴ�.\n");
	printf("��! �׷� �� ���� ������ �Է��ϼ���\n");
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