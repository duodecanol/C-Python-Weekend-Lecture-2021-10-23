#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int u3410_drill() 
{
    int* numPtr1;
    int** numPtr2;
    int num1;

    scanf("%d", &num1);
    
    numPtr1 = &num1;
    numPtr2 = &numPtr1;
    
    printf("%d\n", **numPtr2);

    return 0;
}

int u3506_drill()
{
    int num1;
    int num2;

    int* numPtr1 = malloc(sizeof(int));
    int* numPtr2 = malloc(sizeof(int));

    scanf_s("%d %d", &num1, &num2);

    *numPtr1 = num1;
    *numPtr2 = num2;

    printf("%d\n", *numPtr1 + *numPtr2);

    free(numPtr1);
    free(numPtr2);

    return 0;
}
/*
    핵심 정리
    포인터와 메모리
    https://dojang.io/mod/page/view.php?id=605
*/
