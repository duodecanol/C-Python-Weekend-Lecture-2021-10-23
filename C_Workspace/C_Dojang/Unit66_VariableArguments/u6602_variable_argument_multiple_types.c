#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>

// 66.2 자료형이 다른 가변 인자 함수 만들기
// https://dojang.io/mod/page/view.php?id=578

void printValues(char* types, ...) {
	va_list argsPtr;
	int i = 0;

	va_start(argsPtr, types);

	while (types[ i ] != '\0') {

		printf("￣￣");
		switch (types[ i ]) {
		case 'i':
			printf("%d ", va_arg(argsPtr, int));
			break;
		case 'd':
			printf("%lf ", va_arg(argsPtr, double));
			break;
		case 'c':
			printf("%c ", va_arg(argsPtr, char));
			break;
		case 's':
			printf("%s ", va_arg(argsPtr, char *));
			break;
		default:
			break;
		}
		
		i++;
	}
	va_end(argsPtr);

	printf("\n");
}

int test6602() {
	printValues("i", 10);
	printValues("ci", 'a', 10);
	printValues("dci", 1004.33243, 'k', 10);
	printValues("sicd", "Hello Warudo!", 232, 'z', 66699.33423);
}