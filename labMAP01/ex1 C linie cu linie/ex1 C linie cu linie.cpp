#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	FILE* file1 = fopen("Text1.txt", "r");
	FILE* file2 = fopen("Text2.txt", "w");
	int i = 0;
	char c;
	char* sir = (char*)malloc(512 * sizeof(char));
	if (file1 != NULL && file2 != NULL) {
		while (!feof(file1) && -1 != fscanf(file1, "%c", &c)) {
			fgets(sir, 512, file1);
			fputs(sir, file2);
		}
		fclose(file1);
		fclose(file2);
	}
	else printf("Fisier(e) negasit(e)!\n");
	free(sir);
	(void)getchar();
	return 0;
}