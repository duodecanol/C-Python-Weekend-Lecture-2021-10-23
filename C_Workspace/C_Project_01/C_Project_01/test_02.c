#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c %c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 


void main() {
	printf("%x\n", 129 >> 8);
	printf("Radix friends %d  %x  %o  %#x  %#o\n", 128, 128, 128, 128, 128);
	printf("10\n");
	printf("%08d %08d %08d %08d\n", 0, 0, 0, 0);
	printf("Leading text "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(130));
	int m = 8900;
	printf("m: "BYTE_TO_BINARY_PATTERN" "BYTE_TO_BINARY_PATTERN"\n",
		BYTE_TO_BINARY(m >> 8), BYTE_TO_BINARY(m));


}