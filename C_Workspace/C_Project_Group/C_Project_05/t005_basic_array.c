#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int test06() {
	int arr[ 5 ];
	int sum = 0;
	arr[ 0 ] = 10, arr[ 1 ] = 20, arr[ 2 ] = 30, arr[ 3 ] = 40, arr[ 4 ] = 50;
	for (int i = 0; i < 5; i++) {
		sum += arr[ i ];
	}

	printf("�� ��: %d\n", sum);
	return 0;
}

int test07() {
	int nData[ 4 ] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		printf("�迭 [%d]: %d\n", i, nData[ i ]);
	}
	return 0;
}

int test08() {
	int ages[ 5 ];
	int sum = 0;
	double avg;

	printf("�ټ� ���� ���̸� �Է��ϼ���:\n");
	for (int i = 0; i < 5; i++) {
		printf("%d��° ��� ����: ", i + 1);
		scanf_s("%d", &ages[ i ]);
	}

	printf("�Էµ� �ټ� ���� ����: ");
	for (int i = 0; i < 5; i++) {
		printf("%d�� | ", ages[ i ]);
		sum += ages[ i ];
	}
	avg = sum / 5.0;
	printf("�ټ� ���� ��� ������ %.2lf � �Դϴ�.\n", avg);

	return 0;
}

int test09() {
	double nums[ 5 ];
	double max;
	int i;

	printf("�ټ� ���� ���ڸ� �Է��ϼ���:\n");
	for (i = 0; i < 5; i++) {
		printf("%d��° ����(�Ǽ�): ", i + 1);
		scanf_s("%lf", &nums[ i ]);
	}
	//max = -INFINITY; // set max a min value
	for (i = 0; i < 5; i++) {
		//if (max < nums[ i ])
			//max = nums[ i ];
		if (i == 0)
			max = nums[ i ];
		else
			if (max < nums[ i ])
				max = nums[ i ];
	}
	printf("�Էµ� �� �� ���� ū ���� : %lf�Դϴ�.\n\n", max);
	return 0;
}

int dynamicArray() {
	// http://www.mathcs.emory.edu/~cheung/Courses/255/Syllabus/2-C-adv-data/dyn-array.html

	int i;
	double* p;    // We uses this reference variable to access
				  // dynamically created array elements

	p = calloc(10, sizeof(double));  // Make double array of 10 elements

	for (i = 0; i < 10; i++)
		*( p + i ) = (double) i;            // put value i in array element i

	for (i = 0; i < 10; i++)
		printf("*(p + %d) = %lf\n", i, *( p + i ));


	free(p);      // Un-reserve the first array

	putchar('\n');
	p = calloc(4, sizeof(double));  // Make a NEW double array of 4 elements    

	   // ***** Notice that the array size has CHANGED !!! ****

	for (i = 0; i < 4; i++)
		*( p + i ) = (double) i * i;            // put value i*i in array element i

	for (i = 0; i < 4; i++)
		printf("*(p + %d) = %lf\n", i, *( p + i ));

	free(p);      // Un-reserve the second array

	return 0;
}

