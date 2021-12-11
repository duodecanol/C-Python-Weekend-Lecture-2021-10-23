#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수란? 특별한 기능을 수행하는 코드

/*
* 1. 함수의 기능에 알맞는 이름을 정한다.
* 2. 매개변수는 선택적이다.
* 3. 리턴값의 자료형을 명시한다. [void, int, long, double, char, ...]
* 4. 함수는 괄호 ()가 존재한다.
* 5. {} 몸체 (body)
* 6. 함수는 호출되기 전에 정의되어 있어야 하고, 호출되어야 작동한다.
* 7 . 다른 함수가 먼저 있어도 프로그램은 항상 main() 함수부터 시작된다. [ Entry Point ]
*
*/

/// <summary>
/// 두 정수값 a, b를 인수로 받아 그 합을 반환한다.
/// </summary>
/// <param name="a">int</param>
/// <param name="b">int</param>
/// <returns>(int) a + b</returns>
int add(int a, int b) {

	int result = 0;
	result = a + b;
	printf("%d\n", result);
	return result;
	/*
	* return 값이 있을 경우에는 함수를 호출한 곳으로 값을 반환하고 종료
	* 함수가 종료되면 메모리에서 사라진다. (unload)
	* return 없을 경우에는 함수 종료를 의미한다.
	* 매개변수는 외부로부터 값을 전달받는다.
	*/
}

int total(int kor, int eng, int mat) {
	int tot;
	tot = kor + eng + mat;
	return tot;
}

double average(int tot) {
	double avg;
	avg = tot / 3.0;
	//printf("%.1lf\n", avg);
	return avg;
}

int test03() {
	int kor, eng, mat;
	int tot;
	double avg;

	printf("세 과목의 점수를 입력하세요 : ");
	scanf_s("%d %d %d", &kor, &eng, &mat);
	tot = total(kor, eng, mat);
	avg = average(tot);
	printf("총점: %d, 평균: %.1lf\n", tot, avg);

	return 0;
}