#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void go_test() {

}

int test_04() {
	printf("My age is :  %d\n", 29);
	printf("%d is my point", 100);// 100 is my point
	printf("Good\tMorning\r\neverybody\n");
	printf("Good\tMorning\r\neverybody\r\n");
	return 0;
}


int multiply(int a, int b) {
	printf("%d * %d = %d\n", a, b, a * b);
	return 0;
}

int test_05() {
	printf("4 * 5 = %d\n", 4 * 5);
	printf("7 * 9 = %d\n", 7 * 9);
	multiply(12, 12);
	return 0;
}


int test_07() {
	int height;
	int weight;
	int cha;
	height = 168;
	weight = 46;
	cha = height - weight;
	printf("    Ű : %d cm\n", height);
	printf("������ : %d kg\n", weight);
	printf("Ű���� �����Ը� �� ���� %d �Դϴ�.\n", cha);
	return 0;
}

int test_08() {
	int num, num2;
	printf("������ �ϳ��� �Է��Ͻþ��~~:   ");
	scanf_s("%d", &num);
	printf("Decimal: %012d, Octal: %09o, Hexadecimal: %#X\n", num, num, num);

	printf("������ �� ���� �Է��Ͻþ��~~:   ");
	scanf_s("%d %d", &num, &num2);
	printf("�Է¹��� �������� %d, %d�Դϴ�.\n", num, num2);
	return 0;
}

int test_09() {
	int bonbong, bonus, total;
	double tax, real_income;

	bonbong = 150;
	bonus = 60;

	total = bonbong + bonus;
	tax = total * 0.08; 
	real_income = total - tax;

	printf("����: %d\t���ʽ�: %d\t�ѱ޿�: %d\n", bonbong, bonus, total);
	printf("����: %6.3lf\t�Ǽ��Ծ�: %.2lf\n", tax, real_income);
	printf("%-8d\n%+8d", 11, -44);
	return 0;
}

int test_10() { // ������ ���
	double base_fee = 660;
	double rate_kw = 88.5;
	double tax, fee, total;
	double usage;
	
	printf(" ���� ��뷮�� �Է��ϼ��� (Kw) : ");
	scanf_s("%lf", &usage);

	fee = base_fee + (usage * rate_kw);
	tax = fee * 0.09;
	total = fee + tax;
	
	printf(" ���� ������� %.3lf�� �Դϴ�.\n", total);
	return 0;
}

/* scanf �ڷ��� ���߱�
*  
* double	>	lf	> 64bit	!! double complies with the IEC 60559:1989 (IEEE 754) standard for binary floating - point arithmetic. 
* float		>	f	> 32bit 
* 
* 
*/

int test_11() {
	// ASCII �ڵ� ǥ
	printf("������ �����: %d\n", 65);
	printf("������� ���ڷ�: %c\n", 65);
	printf("���ڸ� ���ڷ�: %d\n", 'A'); // ���ͷ� 'A'�� ��½ÿ� %d�� �ϸ� ���ڷ� ��µȴ�.
	return 0;
}

int test_12() {
	// assign CHAR
	char ch = 'A';
	const char *xx = "������";  /// const�� �ڷ����� ��� �����Ǵ°�????
	
	printf("ch:%c\n", ch);
	printf("literal int size: %d byte (8 bit)\n", sizeof(7));
	printf("literal double size: %d byte\n", sizeof(42321513547.654516517));
	printf("literal char size: %d byte\n", sizeof('A'));
	printf("assigned char size: %d byte\n", sizeof(ch));

	return 0;
}