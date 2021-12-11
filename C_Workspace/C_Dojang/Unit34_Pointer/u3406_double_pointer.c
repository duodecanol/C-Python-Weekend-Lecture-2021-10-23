#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
34.6 이중 포인터 사용하기
https://dojang.io/mod/page/view.php?id=279


포인터도 실제로는 변수이기 때문에 메모리 주소를 구할 수 있습니다. 
하지만 포인터의 메모리 주소는 일반 포인터에 저장할 수 없고, 
int **numPtr2;처럼 이중 포인터에 저장해야 합니다. 
int **numPtr2;를 영어로 읽으면 pointer to pointer to int가 됩니다(numPtr2 → numPtr1 → num1).

여기서 이중 포인터 numPtr2를 끝까지 따라가서 실제 값을 가져오려면 
**numPtr2처럼 변수 앞에 역참조 연산자를 두 번 사용하면 됩니다. 
즉, 역참조를 두 번 하므로 numPtr2 ← numPtr1 ← num1과 같은 모양이 되고 num1의 값을 가져올 수 있습니다.

*/
int doublePointerExample() {
	int* numPtr;
	int** numPtrPtr;
	int num = 10;

	numPtr = &num;
	numPtrPtr = &numPtr;

	printf("    **numPtrPtr at [0x%p] : %d\n", &numPtrPtr, **numPtrPtr);
	return 0;
}