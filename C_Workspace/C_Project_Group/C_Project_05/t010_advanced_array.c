#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int test10() {
	/* 임의의 숫자를 갖는 임의의 길이의 배열을 선언하고 초기화한다.
	*  사용자 입력을 받아 해당 숫자가 배열 안에 몇 개 있는지 확인하고 출력한다.
	*/
	int arr[] = { 2,8,14,3,4,45,26,12,54,8,9,0,14,52,62,345,76,3,17,16,15,14,13,
				87,334,13,543,76,3,5,22,24,25,26,72,878,90,34,20,1,3,12,11,10,6,7,
				69,16,15,4,12,3,14,5,2,12,14,9,8,5,3,18,18,20,4,5,4,3,2 };

	int i;
	int size;
	int n;
	int count = 0;

	puts("찾기를 원하는 숫자를 입력하세요 (1~20): ");
	scanf_s("%d", &n);

	size = sizeof(arr) / sizeof(arr[ 0 ]);
	for (i = 0; i < sizeof(arr) / sizeof(int); i++) {
		//printf("%d, ", arr[ i ]);
		if (arr[ i ] == n)
			count++;
	}
	printf("숫자 %d는 배열에 %d개 있습니다.\n", n, count);

	return 0;
}

int test11() {
	char word[ 50 ];
	word[0] = 'L';
	word[1] = 'O';
	word[2] = 'V';
	word[3] = 'E';
	word[4] = '♥';

	printf("%s\n", word);
	/* 문자 배열의 마지막에 \0이 없으면 저장된 문자열의 끝을 알 수 없다.
	* >  LOVE앍儆儆儆儆儆儆儆儆儆儆儆儆儆儆儆儆儆儆儆儆儆儆儆儆儆u`?煦
	*     따라서 위와 같은 문자열이 출력된다.	
	*/
	word[5] = '\0';
	printf("%s\n", word);
}

int test12()
{
	char word[ 50 ];
	int i;

	puts("단어를 입력하세요:");
	scanf_s("%[^\n]s", word, 50);
	// scanf함수는 문자열 입력을 받으면 널문자 자동으로 채워준다.

	i = 0;

	while (word[ i ] != '\0') {
		i++;
	}
	printf("%s단어의 길이는 %d자 입니다. \n", word, i);

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
		0xcccccccc (3435973836) - 초기화 되지 않은 지역변수. (stack)
		0xcdcdcdcd (3452816845) - 초기화되지 않은 힙에 할당된 메모리. (malloc)
		0xdddddddd (3722304989) - 힙에서 free된 메모리.
		0xfeeefeee (4277075694) - 힙에서 free된 메모리.
		0xfdfdfdfd (4261281277) - 힙에 할당된 메모리의 초과범위(할당된 메모리의 양쪽 끝)*/
	int num;  //    -858993460  0xcccc cccc
	int* numPtr = &num;

	int arr1[ 5 ] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,3,4,5,6,7 }; // 컴파일러에 의해 크기 자동 계산
	int arr3[ 5 ] = { 1,2 }; // 빈자리에 0이 들어가있다. {1,2,0,0,0}
	int arr4[ 5 ];
	arr4[0] = 1;
	arr4[1] = 2;			// 나머지 3자리에는 -858993460 (0xcccccccc)
	/*
	arr1  { 1, 2, 3, 4, 5 }
	arr2  { 1, 2, 3, 4, 5, 6, 7 }
	arr3  { 1, 2, 0, 0, 0 }
	arr4  { 1, 2, -858993460, -858993460, -858993460 }
	*/

	printf("배열 arr1의 크기: %d\n", sizeof(arr1));
	printf("배열 arr2의 크기: %d\n", sizeof(arr2));
	printf("배열 arr3의 크기: %d\n", sizeof(arr3));
	printf("배열 arr4의 크기: %d\n", sizeof(arr4));
	
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

	char str1[ 10 ] = "hello"; // 나머지 5칸은 '\0'으로 채워짐
	char str2[] = "hello"; // 맨 끝에 '\0'이 들어감
	char str3[ 10 ]; // 나머지 다섯칸은 cc로 채워짐
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
	// 문자열 끝에는 null ('\0')이 자동으로 삽입, 배열의 길이는 14
	printf("배열 str의 크기는 : %d\n", sizeof(str));
	printf("널 문자 문자형 출력: %c\n", str[ 13 ]);
	printf("널 문자 정수형 출력: %d\n", str[ 13 ]);
	printf("널 문자 hexadecimal형 출력: %x\n", str[ 13 ]);
	printf("공백 문자 정수형 출력: %d\n", str[ 4 ]); // 32
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

	printf("복사된 문자열 : %s\n", str2);
	
	return 0;
}