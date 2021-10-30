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
	printf("    키 : %d cm\n", height);
	printf("몸무게 : %d kg\n", weight);
	printf("키에서 몸무게를 뺀 값은 %d 입니다.\n", cha);
	return 0;
}

int test_08() {
	int num, num2;
	printf("정수값 하나를 입력하시어요~~:   ");
	scanf_s("%d", &num);
	printf("Decimal: %012d, Octal: %09o, Hexadecimal: %#X\n", num, num, num);

	printf("정수값 두 개를 입력하시어요~~:   ");
	scanf_s("%d %d", &num, &num2);
	printf("입력받은 정수값은 %d, %d입니다.\n", num, num2);
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

	printf("본봉: %d\t보너스: %d\t총급여: %d\n", bonbong, bonus, total);
	printf("세금: %6.3lf\t실수입액: %.2lf\n", tax, real_income);
	printf("%-8d\n%+8d", 11, -44);
	return 0;
}

int test_10() { // 전기요금 계산
	double base_fee = 660;
	double rate_kw = 88.5;
	double tax, fee, total;
	double usage;
	
	printf(" 전기 사용량을 입력하세요 (Kw) : ");
	scanf_s("%lf", &usage);

	fee = base_fee + (usage * rate_kw);
	tax = fee * 0.09;
	total = fee + tax;
	
	printf(" 전기 사용요금은 %.3lf원 입니다.\n", total);
	return 0;
}

/* scanf 자료형 맞추기
*  
* double	>	lf	> 64bit	!! double complies with the IEC 60559:1989 (IEEE 754) standard for binary floating - point arithmetic. 
* float		>	f	> 32bit 
* 
* 
*/

int test_11() {
	// ASCII 코드 표
	printf("정수형 상수값: %d\n", 65);
	printf("상수값을 문자로: %c\n", 65);
	printf("문자를 숫자로: %d\n", 'A'); // 리터럴 'A'를 출력시에 %d로 하면 숫자로 출력된다.
	return 0;
}

int test_12() {
	// assign CHAR
	char ch = 'A';
	const char *xx = "ㄴㄸㅆ";  /// const의 자료형은 어떻게 결정되는가????
	
	printf("ch:%c\n", ch);
	printf("literal int size: %d byte (8 bit)\n", sizeof(7));
	printf("literal double size: %d byte\n", sizeof(42321513547.654516517));
	printf("literal char size: %d byte\n", sizeof('A'));
	printf("assigned char size: %d byte\n", sizeof(ch));

	return 0;
}