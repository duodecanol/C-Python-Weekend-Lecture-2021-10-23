/*
    C언어 Hello, World! 예제
*/
#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("Hello, World!\n");

    int arr[] = { 1, 1, 0, 1 }; // 8 4 0 1 => 13

    for (int i = 0; i < 4; i++) {
        if (arr[ i ] == 1)
            printf("%d ", arr[ i ] << ( 4 - i - 1 ));
    }
    puts("");
    printf("%d ", 13);      // 1101 : 1
    printf("%d ", 13 >> 1); // 110  : 0
    printf("%d ", 13 >> 2); // 11   : 1
    printf("%d ", 13 >> 3); // 1    : 1
    printf("%d ", 13 >> 4); //      : 0
    printf("%d ", 13 >> 5); //      : 0
    puts("");

    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(char*));
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(int*));
    printf("%d\n", sizeof(long));
    printf("%d\n", sizeof(long*));
    printf("%d\n", sizeof(long long));
    printf("%d\n", sizeof(long long*));
    puts("");
    decTobin(13);
    binToDec(arr);

    return 0;
}

int* decTobin(int n) {
    int bits = sizeof(int) * 8;
    static int arr[ bits ];

    for (int i = 0; i < bits; i++) {
        // printf("%d\n", (n >> (bits - i-1)) % 2);
        arr[ i ] = ( n >> ( bits - i - 1 ) ) % 2;
    }

    printf("{ ");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[ 0 ]); i++) {
        printf("%d ", arr[ i ]);
        if (( i + 1 ) % 4 == 0)
            printf(" ");
    }
    printf("}");
    return&

}

int binToDec(int arr[]) {
    int size = sizeof(arr) / sizeof(arr[ 0 ]);
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (arr[ i ] == 1) {
            res += ( arr[ i ] << ( 4 - i - 1 ) );
            printf("%d ", arr[ i ] << ( 4 - i - 1 ));
        }
    }

    puts("");
    printf("%d\n", res);
    return res;
}
