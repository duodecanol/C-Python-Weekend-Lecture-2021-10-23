#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int test_13() {
	char blood_type;
	// �����Է��Ҵ�� %c��ȯ
	// AB�� ����
	printf("�������� �Է��ϼ���: ");
	scanf_s("%c", &blood_type, sizeof(blood_type));

	printf("����� �������� %c�� �Դϴ�.\n", blood_type);
	return 0;
}

int test_14() {
	// ���� ����
	char ch = 'A';
	printf("ch: %c\n", ch);
	printf("ch size: %d\n", sizeof(ch));				 // 1 byte = 8 bit
	printf("literal INT size: %d\n", sizeof(7));		 // 4 byte = 32 bit
	printf("literal DOUBLE size: %d\n", sizeof(44.123)); // 8 byte = 64 bit
	printf("literal CHAR size: %d\n", sizeof('B'));		 // 4 byte = 32 bit
	printf("\n");

	char ch1 = 'C', ch2 = 67; // 1byte
	int ch3 = 'Z', ch4 = 90;  // 4byte  
	// ���ڵ� �ᱹ ���������� ���������� ���� ������ 1~128�� ��� ���� ������ �ʿ�� ���� �ʾҴ�. �׷��� int ��ſ� ���� �ڷ����� ���� ���̴�.
	printf("%c %c\n", ch1, ch2);
	printf("%d %d\n", ch1, ch2);
	printf("%c %c\n", ch3, ch4);
	printf("%d %d\n", ch3, ch4);

	return 0;
}

int understanding_char() {
	/*
	  ASCII ���� 65������ 126������ ����ϸ鼭 ���� / ���� / Hexadecimal ���� ������ ���غ���.
	  ���μ��� ���� ������ �÷� ����� �ɰ��� ������ش�.
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

	printf("�� ��ȣ�� �Է��ϼ���:  ");
	scanf_s("%c", &number, sizeof(number));
	printf("Ÿ���� �Է��ϼ���:  ");
	scanf_s("%lf", &batting_avg);
	//
	printf("���̸� �Է��ϼ���:  ");
	scanf_s("%d", &age);

	printf("%c �� ������ Ÿ���� %lf �̰� ���̴� %d �� �Դϴ�.\n", number, batting_avg, age);

	return 0;
}

int test_16() {
	/* �迭 ������ ����
	*  String ����� ���ڿ��� double quote�� ��� ó��
	*  String ����� �������� Char ������� ���� ->  an array of chars
	*  String ���������� �ι��� \0��
	*  Null character�� '\0' ���� ǥ��. ASCII Code value: 0
	*/
	double masks[80];  // delcare an array size of 80 * 8 byte

	char subway[80]; // delcare an array size of 80 * 1 byte
	
	printf("�� �̸��� �Է��ϼ��� (�⺻): ");
	scanf_s("%s", subway, 50); // arg3 => array size 80������ �̹� �Է¿����� 50������ ����ϰڴ�.
	// string scan�ÿ��� &�� ������ �ʴ´�. (������ ����)
	// ������ �Է½ÿ� ������ ������ �ű⼭ �Է��� ����ȴ�.
	printf("�̹��� ������ ���� %s���Դϴ�.\n", subway);	

	printf("�� �̸��� �Է��ϼ��� (������ �ƴ϶� ���๮�ڷ� scan ����): ");
	scanf_s("%[^\n]s", subway, 50); // arg3 => array size 80������ �̹� �Է¿����� 50������ ����ϰڴ�.
	// �������� ���� ��ĵ ���Ḧ ���� ���� %s �� [^\n]�� �߰�:    Windows��׷��� �ȳ�����. \r\n����?
	// Regex [^\n] = character that is NOT a line break '\n'
	printf("�̹��� ������ ���� %s���Դϴ�.\n", subway);

	printf("�� �̸��� �Է��ϼ��� (Ư�� ���ڷ� �����ϱ� @): ");
	scanf_s("%[^\@]s", subway, 50); // arg3 => array size 80������ �̹� �Է¿����� 50������ ����ϰڴ�.
	// �̹����� @�� �־��.
	printf("�̹��� ������ ���� %s���Դϴ�.\n", subway);

	return 0;
}
int test_17() {
	printf("---------------\n");
	printf("%s %s %s\n", "��  ��", "�����а�", "�г�");
	printf("%s %s %d\n", "�赿��", "���ڰ���", 3);
	printf("---------------\n");

	printf("%-8s %14s %5s\n", "��  ��", "�����а�", "�г�");
	printf("%-8s %14s %5d\n", "�赿��", "���ڰ���", 3);
	printf("%-8s %14s %+5d\n", "������", "��ǻ�Ͱ���", 2);
	printf("%-8s %14s %5d\n", "�Ѽ���", "�̼�������", 4);

	// %8s : �ʵ� ���� 8ĭ Ȯ���ϰ� right justify
	// %-8s : �ʵ� ���� 8ĭ Ȯ���ϰ� Left justify
	// %+5d : ����� ��쿡�� �����ȣ�� ���̵��� �Ѵ�. [������]
	return 0;
}
int test_18() {
	char number;
	double batting_avg;
	int age;
	char name[80], position[80];
	
	printf("�� ��ȣ�� �Է��ϼ���:  ");
	scanf_s("%c", &number, 1);
	printf("Ÿ���� �Է��ϼ���:  ");
	scanf_s("%lf", &batting_avg);	
	printf("���̸� �Է��ϼ���:  ");
	scanf_s("%d", &age);
	printf("�̸��� �Է��ϼ���:  ");
	scanf_s("%s", name, 13);
	printf("�������� �Է��ϼ���:  ");
	scanf_s("%s", position, sizeof(position));

	printf("���ȣ %c �� ������ Ÿ���� %04.5lf �̰� ���̴� %d �� �Դϴ�.\n�̸��� %s �̰�, �������� %s �Դϴ�.", 
		number, batting_avg, age, name, position);
	return 0;
}
int test_19() {
	return 0;
}