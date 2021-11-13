#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern void test11() {
	double weight, height;
	double bmi;

	printf("Input your body weight (Kg): ");
	scanf_s("%lf", &weight);
	printf("Input your body height (cm): ");
	scanf_s(" %lf", &height);
	bmi = weight / ((height / 100) * (height / 100));

	printf("Your body weight is: %lf and\n Your body height is: %lf.\nThus, the BMI of your body is: %.3lf.\n", weight, height, bmi);

	// if (20 <= bmi < 25) 처럼 하면 엉뚱한 결과가 나옴.
	// if ((20 <= bmi) < 25) 의 결과가 나오며, 최종적으로는 if (1 < 25)를 계산하게 됨.
	if (bmi <= 18.5)
		puts("Underweight.");
	else if (bmi <= 23)
		puts("Normal.");
	else if (bmi <= 25)
		puts("Overweight");
	else
		puts("Obesity.");
}

extern void test12() {
	// 6세 이하의 어린이, 70세 이상의 어른들은 무료 입장
	int age;
	printf("나이를 입력하세요 :  ");
	scanf_s("%d", &age);
	if (age <= 6 || age >= 70) {
		printf(" 무료 입장입니다. \n");
		if (age <= 6)    puts("6세 이하 어린이 무료");
		if (age >= 70)   puts("70세 이상 노인 무료");
	}
	else {
		printf(" 입장료는 3,000원 입니다. \n");
	}
}

extern void test13() {
	double weight, height;
	double bmi;

	printf("Input your body weight (Kg): ");
	scanf_s("%lf", &weight);
	printf("Input your body height (cm): ");
	scanf_s(" %lf", &height);
	bmi = weight / ((height / 100) * (height / 100));

	printf("Your body weight is: %lf and\n  Your body height is: %lf.\n  Thus, the BMI of your body is: %.3lf.\n", weight, height, bmi);

	// if (20 <= bmi < 25) 처럼 하면 엉뚱한 결과가 나옴.
	// if ((20 <= bmi) < 25) 의 결과가 나오며, 최종적으로는 if (1 < 25)를 계산하게 됨.
	if (bmi >= 20.0 && bmi < 25.0) {
		puts("표준체중입니다.");
	}
	else if (bmi < 20.0) {
		puts("저체중입니다.");
	}
	else if (bmi >= 25.0) {
		if (bmi >= 32.0)
			puts("비만입니다.");
		else
			puts("과체중입니다.");
	}
	else {
		puts("????????????");
	}
}

extern void test14() {
	int nInput = 0;
	char chCredit = 'x';
	printf("Input your credit SCORE: ");
	scanf_s("%d", &nInput);

	if (nInput >= 90)
		chCredit = 'A';
	else if (nInput >= 80)
		chCredit = 'B';
	else if (nInput >= 70)
		chCredit = 'C';
	else if (nInput >= 60)
		chCredit = 'D';
	else
		chCredit = 'F';

	printf("Your credit evaluation: %c\n", chCredit);
}

// swith / case statement
extern void test15() {
	int lot;

	printf("당첨번호를입력하세요: ");
	scanf("%d", &lot);

	switch (lot){
		case 1:
			printf("김서방");		    break;
		case 2:
			printf("홍가네");			break;
		case 3:
			printf("안산댁");			break;
		default:
			printf("당첨자가 없습니다");
			break;
	}
}

extern void test16() {
	char sel;
	printf("M 오전, A 오후, E 저녁\n");
	printf(" 입력:  ");
	scanf_s("%c", &sel);

	switch (sel) {
		case 'M': // 실수, 문자열 안된다.
			printf("Morning\n"); // Int, Char, Enum만 가능
			break;
		case 'A':
			printf("Afternoon\n");
			break;
		case 'E':
			printf("Evening\n");
			break;
		default:
			break;
	}
}

// 컴파일 실패
/*extern void test16_1() {
	char sel[20];
	printf("Switch Case 문자열 테스트");
	scanf_s("%s", sel, sizeof(sel));

	char babo[] = "바보";
	char apple[] = "사과";

	switch (sel) {
		case babo:
			printf("Morning\n");
			break;
		case apple:
			printf("Morning\n");
			break;
		default:
			break;
	}
}

// 컴파일 실패
extern void test16_2() {
	double sel = 16.34;
	double c1 = 55.3;
	double c2 = 41.4334;
	double c3 = sel;
	switch (sel)
	{
	case c1:
		printf("Morning\n");
		break;
	case c2:
		printf("Morning\n");
		break;
	case c3:
		printf("Morning\n");
		break;
	default:
		break;
	}
}*/

extern void test17() {
	int nInput = 0;
	char chCredit = 'x';
	printf("Input your credit SCORE: ");
	scanf_s("%d", &nInput);

	switch (nInput / 10) {
		case 10:
		case 9:
			chCredit = 'A'; break;
		case 8:
			chCredit = 'B'; break;
		case 7:
			chCredit = 'C'; break;
		case 6:
			chCredit = 'D'; break;
		default:
			chCredit = 'F'; break;
			break;
	}

	printf("Your credit evaluation: %c\n", chCredit);

}