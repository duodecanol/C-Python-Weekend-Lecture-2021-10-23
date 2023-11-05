#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int test10() {
	/* ������ ���ڸ� ���� ������ ������ �迭�� �����ϰ� �ʱ�ȭ�Ѵ�.
	*  ����� �Է��� �޾� �ش� ���ڰ� �迭 �ȿ� �� �� �ִ��� Ȯ���ϰ� ����Ѵ�.
	*/
	int arr[] = { 2,8,14,3,4,45,26,12,54,8,9,0,14,52,62,345,76,3,17,16,15,14,13,
				87,334,13,543,76,3,5,22,24,25,26,72,878,90,34,20,1,3,12,11,10,6,7,
				69,16,15,4,12,3,14,5,2,12,14,9,8,5,3,18,18,20,4,5,4,3,2 };

	int i;
	int size;
	int n;
	int count = 0;

	puts("ã�⸦ ���ϴ� ���ڸ� �Է��ϼ��� (1~20): ");
	scanf_s("%d", &n);

	size = sizeof(arr) / sizeof(arr[ 0 ]);
	for (i = 0; i < sizeof(arr) / sizeof(int); i++) {
		//printf("%d, ", arr[ i ]);
		if (arr[ i ] == n)
			count++;
	}
	printf("���� %d�� �迭�� %d�� �ֽ��ϴ�.\n", n, count);

	return 0;
}

int test11() {
	char word[ 50 ];
	word[0] = 'L';
	word[1] = 'O';
	word[2] = 'V';
	word[3] = 'E';
	word[4] = '��';

	printf("%s\n", word);
	/* ���� �迭�� �������� \0�� ������ ����� ���ڿ��� ���� �� �� ����.
	* >  LOVE����������������������������������������������������u`?��
	*     ���� ���� ���� ���ڿ��� ��µȴ�.	
	*/
	word[5] = '\0';
	printf("%s\n", word);
}

int test12()
{
	char word[ 50 ];
	int i;

	puts("�ܾ �Է��ϼ���:");
	scanf_s("%[^\n]s", word, 50);
	// scanf�Լ��� ���ڿ� �Է��� ������ �ι��� �ڵ����� ä���ش�.

	i = 0;

	while (word[ i ] != '\0') {
		i++;
	}
	printf("%s�ܾ��� ���̴� %d�� �Դϴ�. \n", word, i);

	return 0;
}

int test13() {
	char str[ 50 ] = "I like C programming";
	printf("String: %s\n", str);

	str[ 8 ] = '\0';
	printf("String: %s\n", str);
	
	str[ 6 ] = '\0';
	printf("String: %s\n", str);
	
	str[ 1 ] = '\0';
	printf("String: %s\n", str);


	return 0;
}

int test14() {
	/*
		0xcccccccc (3435973836) - �ʱ�ȭ ���� ���� ��������. (stack)
		0xcdcdcdcd (3452816845) - �ʱ�ȭ���� ���� ���� �Ҵ�� �޸�. (malloc)
		0xdddddddd (3722304989) - ������ free�� �޸�.
		0xfeeefeee (4277075694) - ������ free�� �޸�.
		0xfdfdfdfd (4261281277) - ���� �Ҵ�� �޸��� �ʰ�����(�Ҵ�� �޸��� ���� ��)*/
	int num;  //    -858993460  0xcccc cccc
	int* numPtr = &num;

	int arr1[ 5 ] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,3,4,5,6,7 }; // �����Ϸ��� ���� ũ�� �ڵ� ���
	int arr3[ 5 ] = { 1,2 }; // ���ڸ��� 0�� ���ִ�. {1,2,0,0,0}
	int arr4[ 5 ];
	arr4[0] = 1;
	arr4[1] = 2;			// ������ 3�ڸ����� -858993460 (0xcccccccc)
	/*
	arr1  { 1, 2, 3, 4, 5 }
	arr2  { 1, 2, 3, 4, 5, 6, 7 }
	arr3  { 1, 2, 0, 0, 0 }
	arr4  { 1, 2, -858993460, -858993460, -858993460 }
	*/

	printf("�迭 arr1�� ũ��: %d\n", sizeof(arr1));
	printf("�迭 arr2�� ũ��: %d\n", sizeof(arr2));
	printf("�迭 arr3�� ũ��: %d\n", sizeof(arr3));
	printf("�迭 arr4�� ũ��: %d\n", sizeof(arr4));
	
	puts(""); puts("arr1");
	for (int i = 0; i < sizeof(arr1) / sizeof(int); i++)
		printf("%d, ", arr1[ i ]);
	puts(""); puts("arr2");
	for(int i = 0; i < sizeof(arr2)/sizeof(int);i++)
		printf("%d, ", arr2[ i ]);
	puts(""); puts("arr3");
	for(int i = 0; i < sizeof(arr3)/sizeof(int);i++)
		printf("%d, ", arr3[ i ]);
	puts(""); puts("arr4");
	for(int i = 0; i < sizeof(arr4)/sizeof(int);i++)
		printf("%d, ", arr4[ i ]);

	char str1[ 10 ] = "hello"; // ������ 5ĭ�� '\0'���� ä����
	char str2[] = "hello"; // �� ���� '\0'�� ��
	char str3[ 10 ]; // ������ �ټ�ĭ�� cc�� ä����
	str3[0] = 'h';
	str3[1] = 'e';
	str3[2] = 'l';
	str3[3] = 'l';
	str3[4] = 'o';
	/*
	str1  { 'h', 'e', 'l', 'l', 'o', '\0', '\0', '\0', '\0', '\0' }
	str2  {	'h', 'e', 'l', 'l', 'o', '\0' }
	str3  {	'h', 'e', 'l', 'l', '-52', '-52', '-52', '-52', '-52' }  (-52 = cc)
	*/
	puts(""); puts("str1");
	for (int i = 0; i < sizeof(str1) / sizeof(char); i++) printf("'%d', ", str1[ i ]);
	puts(""); puts("str2");
	for (int i = 0; i < sizeof(str2) / sizeof(char); i++) printf("'%d', ", str2[ i ]);
	puts(""); puts("str3");
	for (int i = 0; i < sizeof(str3) / sizeof(char); i++) printf("%02x, ", str3[ i ]);

	puts("arr1");
	puts("arr1");
}

int test15() {
	char str[] = "Good Morning!";
	// ���ڿ� ������ null ('\0')�� �ڵ����� ����, �迭�� ���̴� 14
	printf("�迭 str�� ũ��� : %d\n", sizeof(str));
	printf("�� ���� ������ ���: %c\n", str[ 13 ]);
	printf("�� ���� ������ ���: %d\n", str[ 13 ]);
	printf("�� ���� hexadecimal�� ���: %x\n", str[ 13 ]);
	printf("���� ���� ������ ���: %d\n", str[ 4 ]); // 32
	return 0;
}

int test16() {
	char str1[] = "There is no royal road to learning C.";
	char str2[ 80 ];

	int i; int size;

	size = sizeof(str1) / sizeof(str1[ 0 ]);

	for (i = 0; i < size; i++) {
		str2[ i ] = str1[ i ];
	}

	printf("����� ���ڿ� : %s\n", str2);
	
	return 0;
}