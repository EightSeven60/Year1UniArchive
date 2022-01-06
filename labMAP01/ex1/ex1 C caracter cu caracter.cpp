#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	FILE* file1 = fopen("C:\\Codes\\labMAP01\\ex1\\Text1.txt", "r");
	FILE* file2 = fopen("Text2.txt", "w");
	int i = 0;
	char* sir = (char*)malloc(512 * sizeof(char));
	if (file1 != NULL && file2 != NULL) {
		while (!feof(file1)) {
			fscanf(file1, "%c", &sir[i]);
			fprintf(file2, "%c", sir[i]);
			++i;
		}
		fclose(file1);
		fclose(file2);
	}
	else printf("Fisier(e) negasit(e)!\n");
	free(sir);
	getchar();
	return 0;
}