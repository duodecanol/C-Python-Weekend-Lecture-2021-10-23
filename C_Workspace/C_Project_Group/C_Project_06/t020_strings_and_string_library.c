#pragma once
#include "projectheader.h"
#include <stdlib.h>
#include <string.h>


int test20() {
	puts("=============");

	int age;
	char* greeting;

	printf("���̸� �Է��ϼ���: ");
	scanf_s("%d", &age);

	if (age > 30)
		greeting = "It is nice to meet you.";
	else
		greeting = "Hello";

	fprintf(stdout, "�λ縻: %s\n", greeting);

	return 0;
}

int test21() {
	puts("=============");

	char* str = "watermelon";
	int i = 0;

	fprintf(stdout, "%s\n", str);

	while (str[i] != '\0') {
		if (i % 2 == 0)
			printf("%c", str[i]);
		else
			printf(" ");
		i++;
	}

	puts("");
	return 0;
}

/// <summary>
/// copy str2 -> str1
/// https://www.geeksforgeeks.org/c-program-copy-string-without-using-strcpy-function/
/// </summary>
/// <param name="str1">variable to receive characters</param>
/// <param name="str2">variable to copy from</param>
void my_strcpy(char* str1, char* str2) {
	int i;

	for (i = 0; str2[i] != '\0'; ++i) {
		str1[i] = str2[i];
	}
	str1[i] = '\0';
}

void str_swap_hardcoding(char* str1, char* str2) {
	char temp[30];

	my_strcpy(temp, str1);
	my_strcpy(str1, str2);
	my_strcpy(str2, temp);
}

void str_swap_use_std(char* str1, char* str2) {
	char temp[30];

	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

int test22() {
	puts("=============");

	char str1[20] = "apple";
	char str2[20] = "banana";
	char temp[20];

	printf("str1: %10s | str2: %10s\n", str1, str2);
	printf("temp: %s\n", temp);

	str_swap_hardcoding(str1, str2);
	//str_swap_use_std(*ss, *pp);

	printf("str1: %10s | str2: %10s\n", str1, str2);

	return	0;
}

int test23() {
	/// <summary>
	/// strlen �Լ��� �̿��Ͽ� string�� ���̸� ���ϰ�, �� ���� ���� �������� 
	/// �� ���ڿ��� ��½�Ű��
	/// ���� ���� �� �� ��½�Ų��.
	/// </summary>
	/// <returns></returns>
	puts("=============");

	char str1[80] = "Long time no see!";
	char str2[80] = "What's up?";

	long str1_leng = strlen(str1);
	long str2_leng = strlen(str2);

	printf("str1 length: %ld, str2 length: %ld\n", str1_leng, str2_leng);

	if (strlen(str1) > strlen(str2))
		printf("%s\n", str1);
	else if (strlen(str1) < strlen(str2))
		printf("%s\n", str1);
	else
		printf("str1: %10s | str2: %10s\n", str1, str2);

	return 0;
}

int test24() {
	puts("=============");

	char str1[20] = "apple";
	char str2[20] = "banana";
	char temp[20];

	printf("str1: %10s | str2: %10s\n", str1, str2);

	int res;
	res = strcmp(str1, str2); //string compare
	if (res < 0) {
		strcpy(temp, str1);
		strcpy(str1, str2);
		strcpy(str2, temp);
	}

	printf("str1: %10s | str2: %10s\n", str1, str2);

	return 0;
}

int test25() {
	puts("=============");
	/* scanf �Լ��� ��ĭ�� ���Ե� ���ڿ��� �Է��� �� ����.
	* ���ڿ��� ������� ���� �Լ��� ����Ѵ�.
	* �� ���� ��� �Է�	gets
	* ���ڿ��� ��� ���	puts
	*/
	char str[80];

	printf("���ڿ��� �Է��ϼ���: ");
	gets(str);
	printf("�� �� ��  �� �� ��: ");
	puts(str);

	return 0;
}

int test26() {
	puts("=============");
	/* �Ҽ� �̾�� �Լ�
	* Ű����� �Է¹޾Ƽ� ���͸� ġ�� ���ݱ��� �Է��� ������ ��� �������� ��µ�
	* '��' �̶�� �Է¹����� ����
	* ## �߰���, �ؽ�Ʈ ���Ͽ� �Ҽ� ���⸦ �����ϴ� �κе� �����ߴ�.
	*/

	FILE* fp = fopen("novel.txt", "a+");

	char novel[1000] = { 0, };   // initialize with zeros
	char sentence[100] = { 0, }; // initialize with zeros
	
	
	while (1) {
		printf("���ڿ��� �Է��ϼ���: ");
		gets(sentence);

		if (strcmp(sentence, "��") == 0)
			break;
		if (strcmp(sentence, ";") == 0) {
			strcat(novel, "\n");
			fprintf(fp, "\r\n");
			continue;
		}

		strcat(novel, sentence); // string concatenate
		strcat(novel, " ");		 // ���� ������ �����ش�.

		printf("��������� �ٰŸ�: \n"); // stdout 
		fprintf(fp, "%s ", sentence);  // ����

		puts(novel);
		puts("");
	}

	fclose(fp);

	return 0;
}

int test27() {
	puts("=============");

	char name[10];
	char tel[20];
	char address[50];
	char str[80] = { 0, };
	
	strcat(str, "[ ");
	printf("�̸��� �Է��ϼ���: ");
	gets(name);
	strcat(str, name);
	strcat(str, ",");

	printf("��ȭ��ȣ�� �Է��ϼ���: ");
	gets(tel);
	strcat(str, tel);
	strcat(str, ",");

	printf("�ּҸ� �Է��ϼ���: ");
	gets(address);
	strcat(str, address);
	strcat(str, " ]");
	

	puts(str);

	return 0;
}


int test28() {
	/* �ϳ��� ���ڸ��� �������� ������ϴ� �Լ�
	* ���ڵ��� �������� ������ϸ� ���ڿ��� ������� �ȴ�.
	* ���� �Է� �Լ� getchar
	* ���� ��� �Լ� putchar
	*/
	char str[80];
	int ch = '_'; // for�� �����Ǻ��� ���� �� �ʱ�ȭ�� ��Ų��.
	int i;

	printf("���ڿ��� �Է��ϼ���: ");
	for (i = 0; ch != '\n'; i++) { // condition: ch�� ���๮�� '\n' �� �ƴ� ��. 
		ch = getchar();
		str[i] = ch;
	}

	str[i] = '\0';

	i = 0; 
	// i �� �̹� ������ Ȱ���Ͽ� ���� ������ �����̹Ƿ� 0�� ���Ҵ��Ѵ�.
	// �׷��� �ϸ� ����� �� �ִ�.
	printf("�� �� ��   �� �� ��: ");	
	for (i = 0; str[i] != '\0'; i++) {
		// condition: ���⼭�� str�� ����ϴϱ�
		// str[i] �� ���� null char�� �ƴ� ���� �������� �Ѵ�.
		putchar(str[i]);
	}

	return 0;
}

int test29() {
	puts("=============");
	/* Ű���忡�� �ԷµǴ� �����ʹ� �ϴ� ���ۿ� ����ǰ�
	* getchar �Լ��� ���۷κ��� �����͸� �������Ƿ�, 
	* ���ڿ��� �ѹ��� �Էµȴ�.
	*/
	char str[100] = { 0, };
	char ch;
	int i = 0;

	printf("���ڿ��� �Է��ϼ��� (����� Ctrl+Z): ");
	while (1) {
		ch = getchar();
		// https://docs.microsoft.com/ko-kr/windows/console/ctrl-c-and-ctrl-break-signals
		// EOF
		if (ch == EOF)  // Ctrl + Z ==> EOF(-1)
			break;
		str[i] = ch;
		i++;
	}
	str[i] = '\0';

	printf("�� �� ��   �� �� ��: ");
	puts(str);

	return 0;
}

int test30() {
	puts("=============");
	char str[100] = { 0, };
	char ch;
	int i = 0;

	printf("���ڿ��� �Է��ϼ��� (����� Enter): ");
	while (1) {
		ch = getchar();

		if (ch == '\n')
			break;
		str[i] = ch;
		i++;
	}
	str[i] = '\0';

	printf("�� �� ��   �� �� ��: ");
	puts(str);

	return 0;
}

