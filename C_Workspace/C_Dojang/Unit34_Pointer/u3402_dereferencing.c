#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 34.2 역참조 연산자 사용하기
// https://dojang.io/mod/page/view.php?id=276

/*  포인터를 선언할 때 *는 "이 변수가 포인터다"라고 알려주는 역할이고, 
    포인터에 사용할 때 *는 "포인터의 메모리 주소를 역참조하겠다"라는 뜻입니다.
*/

int test3402()
{
    int* numPtr;      // 포인터 변수 선언
    int num1 = 10;    // 정수형 변수를 선언하고 10 저장

    numPtr = &num1;   // num1의 메모리 주소를 포인터 변수에 저장

    printf("*numPtr:  %d\n", *numPtr);    // 10: 역참조 연산자로 num1의 메모리 주소에 접근하여 값을 가져옴

    return 0;
}

int referenceWarning() {
    int* numPtr;
    int num1 = 10;

    numPtr = num1;   // 컴파일 경고, numPtr은 int 포인터형이고 num1은 int형이라 자료형이 일치하지 않음
    // warning C4047: '=': 'int *' differs in levels of indirection from 'int'

    *numPtr = num1;  // *numPtr은 int형이고 num1도 int형이라 자료형이 일치함
    return 0;
}