#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �Լ���? Ư���� ����� �����ϴ� �ڵ�

/*
* 1. �Լ��� ��ɿ� �˸´� �̸��� ���Ѵ�.
* 2. �Ű������� �������̴�.
* 3. ���ϰ��� �ڷ����� ����Ѵ�. [void, int, long, double, char, ...]
* 4. �Լ��� ��ȣ ()�� �����Ѵ�.
* 5. {} ��ü (body)
* 6. �Լ��� ȣ��Ǳ� ���� ���ǵǾ� �־�� �ϰ�, ȣ��Ǿ�� �۵��Ѵ�.
* 7 . �ٸ� �Լ��� ���� �־ ���α׷��� �׻� main() �Լ����� ���۵ȴ�. [ Entry Point ]
* 
*/

/// <summary>
/// �� ������ a, b�� �μ��� �޾� �� ���� ��ȯ�Ѵ�.
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
	* return ���� ���� ��쿡�� �Լ��� ȣ���� ������ ���� ��ȯ�ϰ� ����
	* �Լ��� ����Ǹ� �޸𸮿��� �������. (unload)
	* return ���� ��쿡�� �Լ� ���Ḧ �ǹ��Ѵ�.
	* �Ű������� �ܺηκ��� ���� ���޹޴´�.
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
	return avg;
}