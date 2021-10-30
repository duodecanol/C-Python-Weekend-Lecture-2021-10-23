#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BINARY_PATTERN_INT8 "%c%c%c%c_%c%c%c%c"
#define BYTE_TO_BINARY_INT8(i) \
  (((i) & 0x80ll) ? '1' : '0'), \
  (((i) & 0x40ll) ? '1' : '0'), \
  (((i) & 0x20ll) ? '1' : '0'), \
  (((i) & 0x10ll) ? '1' : '0'), \
  (((i) & 0x08ll) ? '1' : '0'), \
  (((i) & 0x04ll) ? '1' : '0'), \
  (((i) & 0x02ll) ? '1' : '0'), \
  (((i) & 0x01ll) ? '1' : '0')

#define BINARY_PATTERN_INT16 \
	BINARY_PATTERN_INT8  BINARY_PATTERN_INT8

#define BYTE_TO_BINARY_INT16(i) \
	BYTE_TO_BINARY_INT8((i) >> 8), BYTE_TO_BINARY_INT8(i)

#define BINARY_PATTERN_INT32 \
	BINARY_PATTERN_INT16 BINARY_PATTERN_INT16

#define BYTE_TO_BINARY_INT32(i) \
	BYTE_TO_BINARY_INT16((i) >> 8), BYTE_TO_BINARY_INT16(i)

#define BINARY_PATTERN_INT64 \
	BINARY_PATTERN_INT16 BINARY_PATTERN_INT16

#define BYTE_TO_BINARY_INT64(i) \
	BYTE_TO_BINARY_INT32((i) >> 8), BYTE_TO_BINARY_INT32(i)



//#define EMP {'0','0','0','0','0','0','0','0', '\0'};
//
//#define AAAA(num) num >> 8	
//
//#define BBBB(num) \
//	((num >> 8) > 0 ? BINARY_OCT_CHUNK(num	 >> 8) : EMP), \
//	((num ) > 0 ? BINARY_OCT_CHUNK(num) : EMP)

void main() {

	binprint(8);
	binprint(780); binprint(9990);
	binprint(76313);
	//char aaa[] = { '0','0','0','0','0','0','0','0', '\0' };
	//printf("%s", aaa);
	//printf("------------- %s", BBBB(128));
	//printf("wowowowowow  "BYTE_TO_BINARY_PATTERN"  "BYTE_TO_BINARY_PATTERN, BBBB(128));
	//printf("%d\n", AAAA(256));
	//printf("%d", AAAA(520));
}


int binprint(int num) {
	int front, back;
	front = num >> 8;
	if (front > 0) {
		back = num - (front << 8);
		printf(" "BYTE_TO_BINARY_PATTERN, BINARY_OCT_CHUNK(front));
		binprint(back);
	}
	if (front == 0) {
		printf(" "BYTE_TO_BINARY_PATTERN"\n", BINARY_OCT_CHUNK(num));
		return 0;
	}
}