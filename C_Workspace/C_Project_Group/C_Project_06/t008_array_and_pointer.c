#pragma once
#include "projectheader.h"

int test08() {
	puts("============= int ");

	int arr[5] = { 10, 20, 30, 40, 50 };
	int* ap = &arr[0];

	for (int i = 0; i < 5; i++) {
		printf(" addr of elem #%d: %p\n", i, ap + i);
		printf("value of elem #%d: %12d\n", i, *(ap + i));
	}

	printf("Memory size of each elem: %ld\n", ((long)(ap + 1) - (long)ap));

	return 0;
}

int test08_long() {
	puts("============= long long ");

	long long arr[5] = { 10, 20, 30, 40, 50 };
	long long* ap = &arr[0];

	for (int i = 0; i < 5; i++) {
		printf(" addr of elem #%d: %p\n", i, ap + i);
		printf("value of elem #%d: %12lld\n", i, *(ap + i));
	}

	printf("Memory size of each elem: %ld\n", ((long)(ap + 1) - (long)ap));

	return 0;
}

int ex11_1() {
	/* ���� �迭�� ��հ��� ���Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	* ��, �迭 ��Ҹ� ������ ���� �迭�� �������� ���ϴ� ������ ǥ���� ����ϸ�,
	* ����� �Ҽ��� ���� ��°�ڸ����� ����Ͻÿ�.
	*/
	puts("=============");

	double arr[] = { 1.5, 20.1, 16.4, 2.3, 3.5 };
	double* ap = &arr; // �迭���� �̿��� ������ ǥ��
	double sum = 0;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		//sum = sum + *(ap + i);
		sum = sum + *(arr + i); //TODO: �迭������ ��ü�� �������̴�.
		//sum = sum + *(&arr + i); // ����. �׷��� �����ͺ��� �Ҵ��ϰ� ���� ������ �������� �ʴ´�.
	}

	double avg = sum / (sizeof(arr) / sizeof(arr[0]));

	//printf("%lf\n", sum);                                                                           
	printf("double �迭�� ���: %0.2lf\n", avg);

	return 0;
}

int test10() {
	puts("=============");

	int arr[5] = { 10, 20, 30, 40, 50 };
	int* ap = arr;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%5d", *ap);
		ap++; //FIXME: get next elem by shifting addr 
	}
	puts("");
	return 0;
}

void arr_prn(int* ap) {
	for (int i = 0; i < 5; i++) {
		printf("%5d", ap[i]);
		//ap++;
	}
	puts("");
}

int test11() {
	puts("=============");

	int arr[5] = { 10, 20, 30, 40, 50 };

	arr_prn(arr);

	return 0;
}

void show_arr_elements(int* arr, int arr_len) {
	for (int i = 0; i < arr_len; i++) {
		printf("%6d", arr[i]);
	}
	puts("");
}

int test12() {
	puts("=============");

	int arr1[3] = { 1,2,3 };
	int arr2[5] = { 4,5,6,7,8 };

	show_arr_elements(arr1, sizeof(arr1)/sizeof(int));
	show_arr_elements(arr2, sizeof(arr2)/sizeof(int));

	return 0;
}

double arr_avg(int* arr, int arr_len) {
	double sum = 0;
	double avg;
	for (int i = 0; i < arr_len; i++) {
		sum = sum + arr[i];
	}
	avg = sum / arr_len;

	return avg;
}

int test13() {
	puts("=============");

	int arr[5] = { 75, 80, 92, 88, 98 };

	double res = arr_avg(arr, sizeof(arr) / sizeof(int));
	printf("Average: %0.2lf\n", res);

	return 0;
}

double arr_min(double* arr, int arr_len) {
	double min = 100000000;

	for (int i = 0; i < arr_len; i++) {
		//printf("%6.2lf", arr[i]);
		if (min > arr[i]) min = arr[i];
	}

	return min;
}

int test14() {
	puts("=============");

	double arr[] = { 1.5, 20.1, 16.4, 23.7, 69.7, 88.55 };
	
	double res;
	res= arr_min(arr, sizeof(arr) / sizeof(double));

	printf("The minimum value in the array: %.2lf\n", res);

	return 0;
}

int test15() {
	puts("=============");

	int arr[10];
	int len = sizeof(arr) / sizeof(int);
	double res;
	int* ap;
	ap = arr;

	// �ݺ����� �̿��Ͽ� �����͸� �Է¹��� �� ��� ���
	printf("������ �Է��Ͻÿ�(%d��): ", len);
	for (int i = 0; i < len; i++) {
		scanf_s(" %d", (ap + i));
	}

	res = arr_avg(arr, len);
	printf("Average: %0.2lf\n", res);

	return 0;
}
