/* scanf example */
#include <stdio.h>
#include <limits.h>
#include <float.h>    
#include "intertypes_operations_test.h"

int intertypes_operations_print()
{
	char a = 'A'; // 65
	char d = 'd'; // 100
	int zehn = 10;
	double x = 1233.444;
	
	printf("%c\n", a + zehn);
	printf("%d\n", a + zehn);
	printf("%d\n", a + 128); // char는 -128 ~ 127
	printf("%c\n", a + 128);  // ?
	printf("===================================\n");
	printf("%lf\n", a + 2.5);
	printf("%lf\n", a + x);
	printf("===================================\n");
	printf("%d\n", INT_MAX);
	printf("%d\n", INT_MAX + d);
	printf("===================================\n");
	printf("%lld\n", LLONG_MAX);
	printf("%lld\n", LLONG_MAX + d);
	printf("===================================\n");
	printf("%llu\n", ULLONG_MAX);
	printf("%llu\n", ULLONG_MAX + d);
	long double ld = 0;
	printf("===================================\n");
	printf("%Lf\n", DBL_MAX);
	printf("%Lf\n", DBL_MAX + d);
	printf("===================================\n");
	printf("%lf\n", DBL_MIN); // double precision long // NO unsigned
	printf("%lf\n", DBL_MIN - d);
	printf("%.60Lf\n", DBL_MIN); // double precision long // NO unsigned
	printf("%Lf\n", DBL_MIN - d);

	return 0;
}

int types_investigation() {
	/* TEST 20
	연산시 피연산자의 형태는 같아야 하며 그 결과도 같은 형태가 된다.
	형태란 자료형을 말하는 것이다.
	피연산자의 자료형은 연산결과에 영향을 미치며, 
	연산결과를 저장하는 변수의 자료형도 영향을 미친다.
	또한 출력함수 printf의 identifier %d 등에 의해서도 출력값이 변화한다.

	따라서 경우에 따라 직관적인 계산치와는 완전히 다른 출력결과를 얻고 당황할 수 있다.

	*/
	
	double num1 = 245; // 245.0
	int num2 = 3.1415; // 3
	int num3 = 129; // integer [4 byte] : 
	char ch = num3;  // char [1 byte] : -128 - 127, unsigned char : 0 - 255
	// Operator '=' 는 "대입연산자"  
	// char 만큼의 공간을 갖는 변수 "ch" 에 num3의 값 129를 할당한다.
	unsigned char uch = num3;

	printf("정수 245 를 실수로 : %lf\n", num1);
	printf("실수 3.1415를 정수로 : %d\n", num2);
	printf("정수 129를 char에 저장한 값: %d\n", ch);
	printf("정수 129를 unsigned char에 저장한 값: %d\n", uch);
	//printf("%d\n", );
	//printf("%d\n", );
	printf("===================================\n");
	int result;
	double result2;

	result = 10 / 4;
	printf("result = %i\n", result); // 2
	
	result2 = 10 / 4.0; // 연산시에 10.0 / 4.0으로 바꾼다.
	printf("result = %lf\n", result2); // 2.500000
	printf("result = %d\n", result2); // 0
	printf("result = %g\n", 10 / 4);
	
	return 0;
}

int typecast() {
	/* TEST 21   Type Casting 과 연산결과
	* 자료형이 이미 결정된, 같은 type의 변수들을 나눗셈 연산한다.
	* int / int 는 int 연산한다. 
	* double / int 연산시에는 바로 계산할 수 없으므로, 컴퓨터가 자동으로 
	* 작은 사이즈의 자료형을 큰 쪽에 맞춰 임시 공간을 할당해서 값을 복사하여 연산한다.
	* 실수형의 이진 메커니즘을 확인하려면 https://www.h-schmidt.net/FloatConverter/IEEE754.html 참고.
	*/

	int num1 = 3, num2 = 4;
	double divResult;

	divResult = num1 / num2; // 결과를 예상해 보세요!
	printf("int / int 나눗셈 결과를 double 변수에 저장: %lf\n", divResult);

	divResult = (double) num1 / num2; // 결과를 예상해 보세요!
	printf("(double) int / int 나눗셈 결과를 double 변수에 저장: %lf\n", divResult);
	printf("(double) int / int 나눗셈 결과를 바로 출력: %lf\n", (double)num1 / num2);


	return 0;
}

int test_22() {
	/* TEST 22 
	* 
	*/
	printf("===================================\n");
	int history, literature, art;
	int total;
	double average;

	printf("역사, 문학, 미술 점수를 입력하세요: ");
	scanf_s("%d %d %d", &history, &literature, &art);

	total = history + literature + art;
	average = total / 3.0;
	average = (double)total / 3;

	printf("Total score is %d and the average is %lf", total, average);
	return 0;
}

int test_23() {
	/* TEST 22
	* 
	*/
	int input, change;
	int w500, w100, w50, w10;

	printf("돈을 입력하세요: ");
	scanf_s("%d", &input);
	//

	w500 = change / 500;
	change = change % 500;
	w100 = change / 100;
	change = change % 100;
	w50 = change / 50;
	change = change % 50;
	w10 = change / 10;


	return 0;
}