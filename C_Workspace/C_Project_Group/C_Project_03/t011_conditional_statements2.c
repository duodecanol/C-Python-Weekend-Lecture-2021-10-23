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

	// if (20 <= bmi < 25) ó�� �ϸ� ������ ����� ����.
	// if ((20 <= bmi) < 25) �� ����� ������, ���������δ� if (1 < 25)�� ����ϰ� ��.
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
	// 6�� ������ ���, 70�� �̻��� ����� ���� ����
	int age;
	printf("���̸� �Է��ϼ��� :  ");
	scanf_s("%d", &age);
	if (age <= 6 || age >= 70) {
		printf(" ���� �����Դϴ�. \n");
		if (age <= 6)    puts("6�� ���� ��� ����");
		if (age >= 70)   puts("70�� �̻� ���� ����");
	}
	else {
		printf(" ������ 3,000�� �Դϴ�. \n");
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

	// if (20 <= bmi < 25) ó�� �ϸ� ������ ����� ����.
	// if ((20 <= bmi) < 25) �� ����� ������, ���������δ� if (1 < 25)�� ����ϰ� ��.
	if (bmi >= 20.0 && bmi < 25.0) {
		puts("ǥ��ü���Դϴ�.");
	}
	else if (bmi < 20.0) {
		puts("��ü���Դϴ�.");
	}
	else if (bmi >= 25.0) {
		if (bmi >= 32.0)
			puts("���Դϴ�.");
		else
			puts("��ü���Դϴ�.");
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

	printf("��÷��ȣ���Է��ϼ���: ");
	scanf("%d", &lot);

	switch (lot){
		case 1:
			printf("�輭��");		    break;
		case 2:
			printf("ȫ����");			break;
		case 3:
			printf("�Ȼ��");			break;
		default:
			printf("��÷�ڰ� �����ϴ�");
			break;
	}
}

extern void test16() {
	char sel;
	printf("M ����, A ����, E ����\n");
	printf(" �Է�:  ");
	scanf_s("%c", &sel);

	switch (sel) {
		case 'M': // �Ǽ�, ���ڿ� �ȵȴ�.
			printf("Morning\n"); // Int, Char, Enum�� ����
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

// ������ ����
/*extern void test16_1() {
	char sel[20];
	printf("Switch Case ���ڿ� �׽�Ʈ");
	scanf_s("%s", sel, sizeof(sel));

	char babo[] = "�ٺ�";
	char apple[] = "���";

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

// ������ ����
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