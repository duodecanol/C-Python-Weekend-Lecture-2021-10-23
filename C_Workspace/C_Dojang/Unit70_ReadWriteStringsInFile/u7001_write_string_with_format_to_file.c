#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* 70.1 ������ �����Ͽ� ���Ͽ� ���ڿ� ����
*  https://dojang.io/mod/page/view.php?id=607
* 
	FILE *�������̸� = fopen(���ϸ�, ���ϸ��);
		FILE *fopen(char const *_FileName, char const *_Mode);
		�����ϸ� ���� �����͸� ��ȯ, �����ϸ� NULL�� ��ȯ
	fprintf(����������, ����, ��1, ��2, ...);
		int fprintf(FILE * const _Stream, char const * const _Format, ...);
		�����ϸ� �� ���ڿ��� ���̸� ��ȯ, �����ϸ� ������ ��ȯ
	fclose(����������);
		int fclose(FILE *_stream);
		�����ϸ� 0�� ��ȯ, �����ϸ� EOF(-1)�� ��ȯ
*/

void file_write_format() {
	FILE* fp = fopen("hello.txt", "w");

	fprintf(fp, "%s %d\n", "Hello", 100);
	fprintf(stdout, "%s %d\n", "Hello", 100); //ȭ��(stdout)�� ���ڿ� ���

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

	fscanf(stdin, "%s %d", str1, &n1);    // ������ �����Ͽ� ǥ�� �Է�(stdin)���� ���ڿ� �б�
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
	* fwrite(����, ����ũ��, ����Ƚ��, ����������);
	* size_t fwrite(void const *_Buffer, size_t _ElementSize, size_t _ElementCount, FILE *_Stream);
	* ������ ���� Ƚ���� ��ȯ, �����ϸ� ������ ���� Ƚ������ ���� ���� ��ȯ
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

	// ���� �տ��� buffer�� 0(NULL)���� �ʱ�ȭ���� �ʰ� fread�� ������ ������ 
	// �������� ������ �Բ� ���
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