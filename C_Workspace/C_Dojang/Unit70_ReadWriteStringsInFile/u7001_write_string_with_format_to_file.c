#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* 70.1 서식을 지정하여 파일에 문자열 쓰기
*  https://dojang.io/mod/page/view.php?id=607
* 
	FILE *포인터이름 = fopen(파일명, 파일모드);
		FILE *fopen(char const *_FileName, char const *_Mode);
		성공하면 파일 포인터를 반환, 실패하면 NULL을 반환
	fprintf(파일포인터, 서식, 값1, 값2, ...);
		int fprintf(FILE * const _Stream, char const * const _Format, ...);
		성공하면 쓴 문자열의 길이를 반환, 실패하면 음수를 반환
	fclose(파일포인터);
		int fclose(FILE *_stream);
		성공하면 0을 반환, 실패하면 EOF(-1)를 반환
*/

void file_write_format() {
	FILE* fp = fopen("hello.txt", "w");

	fprintf(fp, "%s %d\n", "Hello", 100);
	fprintf(stdout, "%s %d\n", "Hello", 100); //화면(stdout)에 문자열 출력

	fprintf(fp, "%c %x\n", 102, 4096);
	fprintf(stdout, "%c %x\n", 102, 4096);

	fclose(fp);
}

void file_read_format() {

	FILE* fp = fopen("hello.txt", "r");

	char str1[10]; int n1;
	fscanf(fp, "%s %d\n", str1, &n1);
	printf("%s %d\n", str1, n1);

	char c; int n2;
	fscanf(fp, "%c %x\n", &c, &n2);
	printf("%c %d\n", c, n2);

	fscanf(stdin, "%s %d", str1, &n1);    // 서식을 지정하여 표준 입력(stdin)에서 문자열 읽기
	printf("%s %d\n", str1, n1);


	fclose(fp);
}

void file_put_string() {
	FILE* fp = fopen("hello_puts.txt", "w");

	fputs("Hello, this is my first puts txt file!!!", fp);
	fputs("Hello, this is my first puts txt file!!!", stdout);

	fclose(fp);
}

void file_write_string() {
	/* 
	* fwrite(버퍼, 쓰기크기, 쓰기횟수, 파일포인터);
	* size_t fwrite(void const *_Buffer, size_t _ElementSize, size_t _ElementCount, FILE *_Stream);
	* 성공한 쓰기 횟수를 반환, 실패하면 지정된 쓰기 횟수보다 작은 값을 반환
	*/
	char* s1 = "Hello world! This is my first write txt file!!!";

	FILE* fp = fopen("hello_write.txt", "w+");

	fwrite(s1, strlen(s1), 1, fp); //TODO: Why _ElementCount requires 1????
	fwrite(s1, strlen(s1), 1, stdout);

	fclose(fp);
}

void file_get_string() {

	char buffer[100];

	FILE* fp = fopen("hello_puts.txt", "r");

	fgets(buffer, sizeof(buffer), fp);

	printf("%s\n", buffer);

	fclose(fp);
}

void file_read_string() {

	// 만약 앞에서 buffer를 0(NULL)으로 초기화하지 않고 fread로 파일을 읽으면 
	// 쓸데없는 값들이 함께 출력
	char buffer[100] = { 0, };

	FILE* fp = fopen("hello_write.txt", "r");

	//fread(buffer, sizeof(buffer), 1, fp);
	fread(buffer, 1, 25, fp); //TODO: Observe how the result stdout changes by adjusting _ElementCount

	printf("%s\n", buffer);

	fclose(fp);
}



void judge_file_put_string() {

	char* str = "This speech caused a remarkable sensation among the party.";

	FILE* fp = fopen("words.txt", "w");

	fputs(str, fp);
	fputs(str, stdout);

	fclose(fp);
}

void judge_file_read_string() {

	char* buffer = malloc(100);
	memset(buffer, 0, 100);

	FILE* fp = fopen("words.txt", "r");

	//TODO:
	fread(buffer, 100, 1, fp);

	printf("%s\n", buffer);

	fclose(fp);

	free(buffer);
}


//TODO: NEXT  -- https://dojang.io/mod/page/view.php?id=616