#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int test12() {
	int n = 45;
	for (; ;) {  // 무한루프 infinite loop
		printf("%d\n", ++n);
	}
	printf("%d\n", n);

	return 0;
}

int test13() {

	for (int i = 0; i < 5; i++) { // (초기화; 비교;  증가)
		printf("%dth\n", i);
	}

	return 0;
}

int test14() {
	int summ; // Uninitialized
	int sum = 0;

	for (int i = 1; i <= 10; i++) { // (초기화; 비교;  증가)
		sum += i;
		//summ = summ + i; // Use Uninit variable. Causes compile ERROR
	}
	printf("1~10의 합은: %d\n", sum);

	return 0;
}

int test15() {
	int total = 0;
	int i;
	int num;

	printf("0부터 num까지의 덧셈, num은?  ");
	scanf_s("%d", &num);

	for (i = 0; i <= num; i++)
		total += i;

	printf("0부터 %d까지 덧셈결과: %d\n", num, total);

	return 0;
}

/*
* 키보드로부터 다섯 명의 나이를 입력받아서 평균 나이를 출력하는
* 프로그램을 for 문을 사용하여 작성하시오.
* 소수점 이하 첫째 자리까지 출력하시오.
**/
int ex7_4_1() {
	unsigned int ages[ 5 ]; // 5명의 나이 저장
	unsigned int sumAge = 0;
	double averageAge;

	for (int i = 0; i < 5; i++) {
		printf("%d. 나이를 입력하세요: ", i + 1);
		scanf_s(" %d", &ages[ i ]);
	}
	for (int j = 0; j < 5; j++) {
		sumAge += ages[ j ];
	}

	averageAge = sumAge / 5;
	printf("다섯명의 평균 나이는 %.1lf 입니다.\n", averageAge);
	return 0;
}
/**
* 위 프로램인데 사람 수를 사용자가 지정.
**/
int ex7_4_2() {
	int n; // 사람 수 지정
	printf("몇 명의 나이를 입력받을 것인가요?: ");
	scanf_s("%d", &n);
	if (n < 1) return; // 0이하이면 프로그램 종료

	unsigned int* ages; // 나이 저장 배열 동적할당
	ages = (unsigned int*)malloc(sizeof(unsigned int) * n);
	//동적할당 실패
	if (ages == NULL) {
		printf("malloc error");
		exit(1);
	}

	unsigned int sumAge = 0; // 나이 합계
	double averageAge;       // 나이 평균

	printf("%d명의 나이를 입력합니다.\n ", n);
	for (int i = 0; i < n; i++) {
		printf("%d. 나이를 입력하세요: ", i + 1);
		scanf_s(" %d", &ages[ i ]);
	}

	for (int j = 0; j < n; j++) {
		sumAge += ages[ j ];
	}

	averageAge = sumAge / n;
	printf("%d명의 평균 나이는 %.1lf 입니다.\n", n, averageAge);
	printf("%d명의 나이 합계는 %d 입니다.\n", n, sumAge);

	free(ages); // 메모리 해제
	return 0;
}

/**
* 구구단 7단을 출력하는 프로그램을 작성하시오.
* 단, for 문을 사용하여 한 줄에 세 개씩 출력하시오.
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

		printf("1부터 %d까지의 합은:  %d\n", n, sum);
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
	// 올라갔다가 내려온다
	int x, y, w;
	int z = 30;

	for (y = 1; y <= z; y++) {
		if (y > ( z / 2 ))  // y:13 z/2:12.5
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
	// Max -> Avg -> Max
	int x, y, w;
	int z = 30;

	for (y = z; y > 0; y--) {
		if (y <= ( z / 2 ))
			w = z - y;
		else
			w = y;
		for (x = 1; x <= w; x++) {
			printf("* ");
		}
		printf("\n");
	}
}

int ex7_5_2() {
	/* 구구단 중 2단, 5단, 8단을 출력,
	*  각 단은 세로로 출력되어서 3 컬럼이 됨.
	*/
	int n[ 3 ] = { 2, 5, 8 };

	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < sizeof(n) / sizeof(int); j++) {
			printf("%d * %d = %2d     ", n[ j ], i, n[ j ] * i);
		}
		printf("\n");
	}
	return 0;
}


int printCustomMultiplicationTable() {
	/*   사용자가 입력한 숫자에 따라 출력 ?
	*
	*/
	int inputSize = 0;
	int input;
	int num[ SIZE ];

	printf("입력받은 숫자의 1~9 곱하기를 출력합니다.\n");
	printf("숫자 갯수는 %d개 이하로 제한됩니다.\n", SIZE);
	printf("입력받는 숫자의 크기는 2자리로 제한됩니다.\n");
	printf("그만 입력하려면 0 또는 그 미만의 수를 입력하세요.\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d번째 숫자 입력: ", i);
		scanf_s("%d", &input);
		if (input <= 0)
			break;
		if (input >= 100) {
			printf("입력한 숫자의 크기가 2자리를 넘습니다: %d  ", input);
			input = input % 100;
			printf("입력한 숫자는 2자리까지만 이용합니다: %d\n", input);
		}
		num[ i ] = input;
		inputSize++;
	}

	for (int k = 1; k < 10; k++) {
		for (int j = 0; j < inputSize; j++) {
			printf("%2d * %2d = %2d     ", num[ j ], k, num[ j ] * k);
		}
		printf("\n");
	}

	return 0;
}

int test23() {
	// uninitialized local variable 'sum' used
	int sum = 0; // 누적되는 변수는 반드시 초기화 필요.
	int n;

	while (1) {
		printf("0 또는 양수값을 입력하세요(음수이면 입력종료): ");
		scanf_s("%d", &n);
		if (n < 0) // 입력값이 음수이면 반복문을 exit
			break;
		sum += n;
	}
	printf("그 동안 누적된 값: %d\n", sum);
	return 0;
}