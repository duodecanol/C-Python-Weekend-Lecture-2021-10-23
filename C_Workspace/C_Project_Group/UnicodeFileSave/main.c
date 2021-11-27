#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <Windows.h>

void main() {
	//setlocale(LC_ALL, "ko-KR.utf-8");
	setlocale(LC_ALL, "");

	FILE* stream;

	int    i = 10;
	double fp = 1.5;
	char   s[] = "this is a string";
	char   c = '\n';


	//fopen_s(&stream, "fprintf_s.out", "w"); // Western Windows 1252
	fopen_s(&stream, "fprintf_s.txt", "wt");
	//fopen_s(&stream, "fprintf_s.txt", "rw, ccs=UTF-8");

	fprintf_s(stream, "%lc\n", (wchar_t)0x2591);
	fprintf_s(stream, "%s%c", s, c);
	fprintf_s(stream, "%d\n", i);
	fprintf_s(stream, "%f\n", fp);
	fprintf_s(stream, "%c\n", 176);			// FAIL
	fprintf_s(stream, "%lc\n", 176);		// FAIL
	fprintf_s(stream, "%lc\n", 9619);					// good!
	fprintf_s(stream, "%lc\n", (wchar_t)0x2591);        // good!
	fprintf_s(stream, "%c\n", 0x2591);		// FAIL
	fwprintf_s(stream, "%lc\n", L"░");		// FAIL



	fclose(stream);
	puts("type fprintf_s.txt");
}