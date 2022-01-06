#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

const short marime_linie = 128;

int strcmpReversed(const void* str1, const void* str2) {
	return strcmp((const char*)str1, (const char*)str2);
}

int main()
{
	char text[3][marime_linie] = { 0 }, i = 0, liniiCitite;
	FILE* file1 = fopen("Text.txt", "r");
	if (file1 == NULL) {
		printf("Prinde-ma ca pic...\n");
		return -1;
	}
	while (!feof(file1)) {
		fgets(text[i], marime_linie, file1);
		++i;
	}
	liniiCitite = i;

	qsort(text, 3, marime_linie, strcmpReversed);

	printf("Press Enter to halt The Matrix.");
	(void)getchar();
	return 0;
}