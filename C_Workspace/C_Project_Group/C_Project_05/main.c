#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int result;
	result = add(3, 4); // �Լ��� ȣ��Ǿ� �޸𸮿� ����� ���� ������ �ڷ����� ��ȯ���� ��ȯ�ϰ� ����. �޸𸮿��� �������.
	printf("���� ��� 1 : %d\n", result);
	result = add(5, 8);
	printf("���� ��� 2 : %d\n", result);
}

