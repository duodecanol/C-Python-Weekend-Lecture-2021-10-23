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


void binprint() {
	char ch = 8;
	short int si = 1024;
	int ii = 4096;
	long li = 8192;
	unsigned long long llli = 16384;
	
	printf("char: "BINARY_PATTERN_INT8"\n", BYTE_TO_BINARY_INT8(ch));
	printf("sint: "BINARY_PATTERN_INT16"\n", BYTE_TO_BINARY_INT16(si));
	printf("int : "BINARY_PATTERN_INT32"\n", BYTE_TO_BINARY_INT32(ii));
	printf("long: "BINARY_PATTERN_INT32"\n", BYTE_TO_BINARY_INT32(li));
	printf("llong "BINARY_PATTERN_INT64"\n", BYTE_TO_BINARY_INT64(llli));
}