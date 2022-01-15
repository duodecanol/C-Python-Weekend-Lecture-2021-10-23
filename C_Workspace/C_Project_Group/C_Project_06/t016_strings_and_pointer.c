#pragma once
#include "projectheader.h"
#include <stdlib.h>


int test16() {
	puts("=============");

	printf("       �ּҰ��� ��� : %p\n", "dream");
	printf("ù ��° ���ڸ�  ��� : %c\n", *"dream");
	printf("�� ��° ���ڸ�  ��� : %c\n", *("dream" + 1));
	printf("�� ��° ���ڸ�  ��� : %c\n", *("dream" + 2));
	printf("�� ��° ���ڸ�  ��� : %c\n", *("dream" + 3));
	printf("�� ��° ���ڸ�  ��� : %c\n", "dream"[4]); // ���ڿ��� char�� �迭.
	printf("�� ��° ���ڸ�  ��� : %d\n", "dream"[5]);

	return 0;
}


int test17() {
	puts("=============");

	char* name;
	name = "Hong Gildong";

	printf("�̸�: %s\n", name);
	printf("1: %c\n", *name);
	printf("3: %c\n", *(name + 2) );
	printf("6: %c\n", name[5]);

	return 0;
}


int test18() {
	puts("=============");

	char* fruit = "Strawberry";

	while (*fruit != '\0') {
		printf("%s\n", fruit);
		fruit++;
	}

	return 0;
}

int test19() {
	puts("=============");

	char str1[] = "My String"; 
	// �迭���� ���ڿ��� ����Ű�� �ּҰ��̱� ������ ������ �ƴϴ�. �� ������ �Ұ����ϴ�.
	// ����, �迭���� �迭�� 1st elem�� ����Ű�� constant pointer��� �� �� �ִ�.
	// https://stackoverflow.com/questions/2351544/is-array-name-a-constant-pointer-in-c
	char* str2 = "Your String";

	printf("   str1 in array string: %s\n", str1);
	printf("   str1[0] in stack memory: %p\n", str1);	
			   
	printf("   str2 in char pointer: %s\n", str2);
	printf("   str2[0] in heap memory: %p\n", str2);
	

	// str1 = "Your String"; // �迭�� �ٽ� �Ҵ�: Compile Error
	// ** �迭 ����� ���ڿ��� ��ü ���� �ٲٴ� ���� �Ұ����ϴ�.
	str2 = "Our String";
	// ** ������ ����� ���ڿ��� ��ü ���� �ٲٴ� ���� �����ϴ�.
	printf("%s\n", str2);

	str1[0] = 'X';
	// ** �׷��� �迭 ����� ���ڿ��� indexing���� �� ���ڸ� �ϳ��� �ٲ� �� �ִ�.
	// 
	// ** �ݴ�� ������ ����� ���ڿ��� ���� �ϳ��� �����Ͽ� dereferencing���� ���Ҵ��� �Ұ����ϴ�.
	//str2[0] = 'X';     [C0000005] code for an access violation. 	
	//*(str2 + 1) = 'X'; [C0000005] code for an access violation.
	printf("%s\n", str1);
	printf("%s\n", str2);

	// �̹����� String�� char pointer�� �����ϵ�, malloc���� ������ ��Ƴ���.
	char* str3 = malloc(10);
	*(str3 + 0) = 'H';
	*(str3 + 1) = 'e';
	*(str3 + 2) = 'l';
	*(str3 + 3) = 'l';
	*(str3 + 4) = 'o';
	*(str3 + 5) = '\0';

	printf("   str3: %s\n", str3);
	printf("   str3[0] malloc in heap memory: %p\n", str3);	

	// �� ��쿡�� ������ �����ϴ�. �迭�� ������ ����ϴٰ� ��������.
	*(str3 + 0) = 'X';
	printf("%s\n", str3);

	free(str3);

	return 0;
}