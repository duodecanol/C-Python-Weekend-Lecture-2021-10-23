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
	printf("%d\n", a + 128); // char�� -128 ~ 127
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
	����� �ǿ������� ���´� ���ƾ� �ϸ� �� ����� ���� ���°� �ȴ�.
	���¶� �ڷ����� ���ϴ� ���̴�.
	�ǿ������� �ڷ����� �������� ������ ��ġ��, 
	�������� �����ϴ� ������ �ڷ����� ������ ��ģ��.
	���� ����Լ� printf�� identifier %d � ���ؼ��� ��°��� ��ȭ�Ѵ�.

	���� ��쿡 ���� �������� ���ġ�ʹ� ������ �ٸ� ��°���� ��� ��Ȳ�� �� �ִ�.

	*/
	
	double num1 = 245; // 245.0
	int num2 = 3.1415; // 3
	int num3 = 129; // integer [4 byte] : 
	char ch = num3;  // char [1 byte] : -128 - 127, unsigned char : 0 - 255
	// Operator '=' �� "���Կ�����"  
	// char ��ŭ�� ������ ���� ���� "ch" �� num3�� �� 129�� �Ҵ��Ѵ�.
	unsigned char uch = num3;

	printf("���� 245 �� �Ǽ��� : %lf\n", num1);
	printf("�Ǽ� 3.1415�� ������ : %d\n", num2);
	printf("���� 129�� char�� ������ ��: %d\n", ch);
	printf("���� 129�� unsigned char�� ������ ��: %d\n", uch);
	//printf("%d\n", );
	//printf("%d\n", );
	printf("===================================\n");
	int result;
	double result2;

	result = 10 / 4;
	printf("result = %i\n", result); // 2
	
	result2 = 10 / 4.0; // ����ÿ� 10.0 / 4.0���� �ٲ۴�.
	printf("result = %lf\n", result2); // 2.500000
	printf("result = %d\n", result2); // 0
	printf("result = %g\n", 10 / 4);
	
	return 0;
}

int typecast() {
	/* TEST 21   Type Casting �� ������
	* �ڷ����� �̹� ������, ���� type�� �������� ������ �����Ѵ�.
	* int / int �� int �����Ѵ�. 
	* double / int ����ÿ��� �ٷ� ����� �� �����Ƿ�, ��ǻ�Ͱ� �ڵ����� 
	* ���� �������� �ڷ����� ū �ʿ� ���� �ӽ� ������ �Ҵ��ؼ� ���� �����Ͽ� �����Ѵ�.
	* �Ǽ����� ���� ��Ŀ������ Ȯ���Ϸ��� https://www.h-schmidt.net/FloatConverter/IEEE754.html ����.
	*/

	int num1 = 3, num2 = 4;
	double divResult;

	divResult = num1 / num2; // ����� ������ ������!
	printf("int / int ������ ����� double ������ ����: %lf\n", divResult);

	divResult = (double) num1 / num2; // ����� ������ ������!
	printf("(double) int / int ������ ����� double ������ ����: %lf\n", divResult);
	printf("(double) int / int ������ ����� �ٷ� ���: %lf\n", (double)num1 / num2);


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

	printf("����, ����, �̼� ������ �Է��ϼ���: ");
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

	printf("���� �Է��ϼ���: ");
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