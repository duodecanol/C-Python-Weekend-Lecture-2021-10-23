#pragma once
#include "projectheader.h"
#include <stdlib.h>
#include <string.h>


int test20() {
	puts("=============");

	int age;
	char* greeting;

	printf("나이를 입력하세요: ");
	scanf_s("%d", &age);

	if (age > 30)
		greeting = "It is nice to meet you.";
	else
		greeting = "Hello";

	fprintf(stdout, "인사말: %s\n", greeting);

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
	/// strlen 함수를 이용하여 string의 길이를 구하고, 그 길이 값을 기준으로 
	/// 긴 문자열을 출력시키고
	/// 길이 같음 둘 다 출력시킨다.
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
	/* scanf 함수는 빈칸이 포함된 문자열은 입력할 수 없다.
	* 문자열의 입출력은 전용 함수를 사용한다.
	* 한 줄을 모두 입력	gets
	* 문자열을 모두 출력	puts
	*/
	char str[80];

	printf("문자열을 입력하세요: ");
	gets(str);
	printf("입 력 된  문 자 열: ");
	puts(str);

	return 0;
}

int test26() {
	puts("=============");
	/* 소설 이어쓰기 함수
	* 키보드로 입력받아서 엔터를 치면 지금까지 입력한 내용이 계속 더해져서 출력됨
	* '끝' 이라고 입력받으면 종료
	* ## 추가로, 텍스트 파일에 소설 쓰기를 저장하는 부분도 구현했다.
	*/

	FILE* fp = fopen("novel.txt", "a+");

	char novel[1000] = { 0, };   // initialize with zeros
	char sentence[100] = { 0, }; // initialize with zeros
	
	
	while (1) {
		printf("문자열을 입력하세요: ");
		gets(sentence);

		if (strcmp(sentence, "끝") == 0)
			break;
		if (strcmp(sentence, ";") == 0) {
			strcat(novel, "\n");
			fprintf(fp, "\r\n");
			continue;
		}

		strcat(novel, sentence); // string concatenate
		strcat(novel, " ");		 // 끝에 공백을 더해준다.

		printf("현재까지의 줄거리: \n"); // stdout 
		fprintf(fp, "%s ", sentence);  // 파일

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
	printf("이름을 입력하세요: ");
	gets(name);
	strcat(str, name);
	strcat(str, ",");

	printf("전화번호를 입력하세요: ");
	gets(tel);
	strcat(str, tel);
	strcat(str, ",");

	printf("주소를 입력하세요: ");
	gets(address);
	strcat(str, address);
	strcat(str, " ]");
	

	puts(str);

	return 0;
}


int test28() {
	/* 하나의 문자만을 전용으로 입출력하는 함수
	* 문자들을 연속으로 입출력하면 문자열의 입출력이 된다.
	* 문자 입력 함수 getchar
	* 문자 출력 함수 putchar
	*/
	char str[80];
	int ch = '_'; // for문 조건판별을 위해 값 초기화를 시킨다.
	int i;

	printf("문자열을 입력하세요: ");
	for (i = 0; ch != '\n'; i++) { // condition: ch가 개행문자 '\n' 가 아닌 한. 
		ch = getchar();
		str[i] = ch;
	}

	str[i] = '\0';

	i = 0; 
	// i 는 이미 위에서 활용하여 값이 증가된 상태이므로 0을 재할당한다.
	// 그렇게 하면 출력할 수 있다.
	printf("입 력 된   문 자 열: ");	
	for (i = 0; str[i] != '\0'; i++) {
		// condition: 여기서는 str을 출력하니까
		// str[i] 의 값이 null char가 아닌 것을 조건으로 한다.
		putchar(str[i]);
	}

	return 0;
}

int test29() {
	puts("=============");
	/* 키보드에서 입력되는 데이터는 일단 버퍼에 저장되고
	* getchar 함수는 버퍼로부터 데이터를 가져오므로, 
	* 문자열은 한번에 입력된다.
	*/
	char str[100] = { 0, };
	char ch;
	int i = 0;

	printf("문자열을 입력하세요 (종료는 Ctrl+Z): ");
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

	printf("입 력 된   문 자 열: ");
	puts(str);

	return 0;
}

int test30() {
	puts("=============");
	char str[100] = { 0, };
	char ch;
	int i = 0;

	printf("문자열을 입력하세요 (종료는 Enter): ");
	while (1) {
		ch = getchar();

		if (ch == '\n')
			break;
		str[i] = ch;
		i++;
	}
	str[i] = '\0';

	printf("입 력 된   문 자 열: ");
	puts(str);

	return 0;
}

