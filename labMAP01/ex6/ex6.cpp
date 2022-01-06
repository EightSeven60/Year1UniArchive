#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	FILE* file1 = fopen("Text1.txt", "r");
	FILE* file2 = fopen("Text2.txt", "a");
	char c = 0;
	if (file1 == NULL || file2 == NULL) {
		printf("Eroare\n");
		return -1;
	}
	while (!feof(file1)) {
		if (c != 0) fputc(c, file2);
		c = fgetc(file1);
	}
	fclose(file1);
	fclose(file2);
	return 0;
}