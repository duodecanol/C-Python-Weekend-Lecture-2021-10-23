extern void test10() {
	// A basic example of ternary operator.
	// (conditional statement) ? true : false
	int a, b;
	int min, max;

	printf("Input two integers (separated by space bar) :  ");
	scanf_s("%d %d", &a, &b);
	min = (a < b) ? a : b; // Ternary operator
	max = (a < b) ? b : a;
	printf("The smaller number is: %d\n", min);
	printf("The greater number is: %d\n", max);
}
