#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int test_13() {
	char blood_type;
	// 문자입력할대는 %c변환
	// AB형 제외
	printf("혈액형을 입력하세요: ");
	scanf_s("%c", &blood_type, sizeof(blood_type));

	printf("당신의 혈액형은 %c형 입니다.\n", blood_type);
	return 0;
}

int test_14() {
	// 문자 저장
	char ch = 'A';
	printf("ch: %c\n", ch);
	printf("ch size: %d\n", sizeof(ch));				 // 1 byte = 8 bit
	printf("literal INT size: %d\n", sizeof(7));		 // 4 byte = 32 bit
	printf("literal DOUBLE size: %d\n", sizeof(44.123)); // 8 byte = 64 bit
	printf("literal CHAR size: %d\n", sizeof('B'));		 // 4 byte = 32 bit
	printf("\n");

	char ch1 = 'C', ch2 = 67; // 1byte
	int ch3 = 'Z', ch4 = 90;  // 4byte  
	// 문자도 결국 숫자형으로 저장하지만 값의 범위가 1~128로 적어서 많은 공간을 필요로 하지 않았다. 그래서 int 대신에 따로 자료형을 만든 것이다.
	printf("%c %c\n", ch1, ch2);
	printf("%d %d\n", ch1, ch2);
	printf("%c %c\n", ch3, ch4);
	printf("%d %d\n", ch3, ch4);

	return 0;
}

int understanding_char() {
	/*
	  ASCII 문자 65번부터 126번까지 출력하면서 문자 / 숫자 / Hexadecimal 값을 눈으로 비교해본다.
	  시인성을 위해 지정한 컬럼 수대로 쪼개서 출력해준다.
	*/
	
	printf("---------------\n");
	int begin = 65, end = 126, col = 3; 
	int step = (int) ceil ((end - begin + 1) / col) + 1;
	//printf("%d\n", step);

	for (int i = begin; i < begin + step; i++) {		
		for (int j = i; j <= end; j += step) {
			printf(" | %c :: %3d :: 0x%X | ", j, j, j);
		}		
		printf("\n");
	}
	printf("---------------\n");
	return 0;
}

int test_15() {
	char number;
	double batting_avg;
	int age;

	printf("등 번호를 입력하세요:  ");
	scanf_s("%c", &number, sizeof(number));
	printf("타율을 입력하세요:  ");
	scanf_s("%lf", &batting_avg);
	//
	printf("나이를 입력하세요:  ");
	scanf_s("%d", &age);

	printf("%c 번 선수의 타율은 %lf 이고 나이는 %d 살 입니다.\n", number, batting_avg, age);

	return 0;
}

int test_16() {
	/* 배열 개념의 이해
	*  String 상수는 문자열을 double quote로 묶어서 처리
	*  String 상수는 연속적인 Char 상수들의 집합 ->  an array of chars
	*  String 마지막에는 널문자 \0ㅍ
	*  Null character는 '\0' 으로 표현. ASCII Code value: 0
	*/
	double masks[80];  // delcare an array size of 80 * 8 byte

	char subway[80]; // delcare an array size of 80 * 1 byte
	
	printf("역 이름을 입력하세요 (기본): ");
	scanf_s("%s", subway, 50); // arg3 => array size 80이지만 이번 입력에서는 50까지만 사용하겠다.
	// string scan시에는 &를 붙이지 않는다. (포인터 개념)
	// 데이터 입력시에 공백이 들어오면 거기서 입력이 종료된다.
	printf("이번에 정차할 역은 %s역입니다.\n", subway);	

	printf("역 이름을 입력하세요 (공백이 아니라 개행문자로 scan 종료): ");
	scanf_s("%[^\n]s", subway, 50); // arg3 => array size 80이지만 이번 입력에서는 50까지만 사용하겠다.
	// 공백으로 인한 스캔 종료를 막기 위해 %s 에 [^\n]을 추가:    Windows라그런지 안끝난다. \r\n인지?
	// Regex [^\n] = character that is NOT a line break '\n'
	printf("이번에 정차할 역은 %s역입니다.\n", subway);

	printf("역 이름을 입력하세요 (특정 문자로 종료하기 @): ");
	scanf_s("%[^\@]s", subway, 50); // arg3 => array size 80이지만 이번 입력에서는 50까지만 사용하겠다.
	// 이번에는 @를 넣어본다.
	printf("이번에 정차할 역은 %s역입니다.\n", subway);

	return 0;
}
int test_17() {
	printf("---------------\n");
	printf("%s %s %s\n", "이  름", "전공학과", "학년");
	printf("%s %s %d\n", "김동수", "전자공학", 3);
	printf("---------------\n");

	printf("%-8s %14s %5s\n", "이  름", "전공학과", "학년");
	printf("%-8s %14s %5d\n", "김동수", "전자공학", 3);
	printf("%-8s %14s %+5d\n", "이을수", "컴퓨터공학", 2);
	printf("%-8s %14s %5d\n", "한선영", "미술교육학", 4);

	// %8s : 필드 폭을 8칸 확보하고 right justify
	// %-8s : 필드 폭을 8칸 확보하고 Left justify
	// %+5d : 양수인 경우에도 양수부호를 보이도록 한다. [숫자형]
	return 0;
}
int test_18() {
	char number;
	double batting_avg;
	int age;
	char name[80], position[80];
	
	printf("등 번호를 입력하세요:  ");
	scanf_s("%c", &number, 1);
	printf("타율을 입력하세요:  ");
	scanf_s("%lf", &batting_avg);	
	printf("나이를 입력하세요:  ");
	scanf_s("%d", &age);
	printf("이름을 입력하세요:  ");
	scanf_s("%s", name, 13);
	printf("포지션을 입력하세요:  ");
	scanf_s("%s", position, sizeof(position));

	printf("등번호 %c 번 선수의 타율은 %04.5lf 이고 나이는 %d 살 입니다.\n이름은 %s 이고, 포지션은 %s 입니다.", 
		number, batting_avg, age, name, position);
	return 0;
}
int test_19() {
	return 0;
}