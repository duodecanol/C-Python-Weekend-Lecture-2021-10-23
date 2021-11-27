#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int test12() {
	int n = 45;
	for (; ;) {  // ���ѷ��� infinite loop
		printf("%d\n", ++n);
	}
	printf("%d\n", n);

	return 0;
}

int test13() {

	for (int i = 0; i < 5; i++) { // (�ʱ�ȭ; ��;  ����)
		printf("%dth\n", i);
	}

	return 0;
}

int test14() {
	int summ; // Uninitialized
	int sum = 0;

	for (int i = 1; i <= 10; i++) { // (�ʱ�ȭ; ��;  ����)
		sum += i;
		//summ = summ + i; // Use Uninit variable. Causes compile ERROR
	}
	printf("1~10�� ����: %d\n", sum);

	return 0;
}

int test15() {
	int total = 0;
	int i;
	int num;

	printf("0���� num������ ����, num��?  ");
	scanf_s("%d", &num);

	for (i = 0; i <= num; i++)
		total += i;

	printf("0���� %d���� �������: %d\n", num, total);

	return 0;
}

/*
* Ű����κ��� �ټ� ���� ���̸� �Է¹޾Ƽ� ��� ���̸� ����ϴ�
* ���α׷��� for ���� ����Ͽ� �ۼ��Ͻÿ�. 
* �Ҽ��� ���� ù° �ڸ����� ����Ͻÿ�.
**/
int ex7_4_1() {
	unsigned int ages[5]; // 5���� ���� ����
	unsigned int sumAge = 0;
	double averageAge;

	for (int i = 0; i < 5; i++) {
		printf("%d. ���̸� �Է��ϼ���: ", i+1);
		scanf_s(" %d", &ages[i]);
	}
	for (int j = 0; j < 5; j++) {
		sumAge += ages[j];
	}

	averageAge = sumAge / 5;
	printf("�ټ����� ��� ���̴� %.1lf �Դϴ�.\n", averageAge);
	return 0;
}
/**
* �� ���η��ε� ��� ���� ����ڰ� ����.
**/
int ex7_4_2() {
	int n; // ��� �� ����
	printf("�� ���� ���̸� �Է¹��� ���ΰ���?: ");
	scanf_s("%d", &n);
	if (n < 1) return; // 0�����̸� ���α׷� ����

	unsigned int * ages; // ���� ���� �迭 �����Ҵ�
	ages = (unsigned int *)malloc(sizeof(unsigned int) * n);
	//�����Ҵ� ����
	if (ages == NULL) {
		printf("malloc error");
		exit(1);
	}

	unsigned int sumAge = 0; // ���� �հ�
	double averageAge;       // ���� ���

	printf("%d���� ���̸� �Է��մϴ�.\n ", n);
	for (int i = 0; i < n; i++) {
		printf("%d. ���̸� �Է��ϼ���: ", i + 1);		
		scanf_s(" %d", &ages[i]);
	}

	for (int j = 0; j < n; j++) {
		sumAge += ages[j];
	}

	averageAge = sumAge / n;
	printf("%d���� ��� ���̴� %.1lf �Դϴ�.\n", n, averageAge);
	printf("%d���� ���� �հ�� %d �Դϴ�.\n", n, sumAge);
	
	free(ages); // �޸� ����
	return 0;
}

/**
* ������ 7���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
* ��, for ���� ����Ͽ� �� �ٿ� �� ���� ����Ͻÿ�.
*/
int ex7_4_3() {
	
	int base = 7;
	for (int i = 1; i < 10; i++) {
		printf("%d * %d = %2d", base, i, base * i);
		if (i % 3 == 0)
			printf("\n");
		else
			printf("\t");
	}

	return 0;
}

int test18() {
	int n, i, sum = 0;
	printf("Input a positive integer: ");
	scanf_s("%d", &n);

	while (n > 0) {
		for (i = 1; i <= n; i++)
			sum += i;

		printf("1���� %d������ ����:  %d\n", n, sum);
		printf("Input a positive interger: ");
		scanf_s("%d", &n);
	}
}

int test19() {
	int x, y;

	for (y = 0; y < 5; y++) {
		for (x = 0; x < 4; x++) {
			printf("*\t");
		}
		printf("\n");
	}
}

int test20() {
	int x, y;

	for (y = 1; y <= 25; y++) {
		for (x = 1; x <= y; x++) {
			printf("* ");
		}
		printf("\n");
	}
}

int test21() {
	int x, y, w;
	int z = 30;

	for (y = 1; y <= z; y++) {
		if (y > (z / 2))  // y:13 z/2:12.5
			w = z - y;
		else
			w = y;
		for (x = 1; x <= w; x++) {
			printf("* ");
		}
		printf("\n");
	}
}

int test22() {
	int x, y, w;
	int z = 30;

	for (y = z; y > 0; y--) {
		if (y <= (z / 2))  
			w = z - y;
		else
			w = y;
		for (x = 1; x <= w; x++) {
			printf("* ");
		}
		printf("\n");
	}
}