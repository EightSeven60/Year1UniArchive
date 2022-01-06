#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

//este case-senzitive, daca voiam sa nu fie schimbam in buffer literele mari in mici cu un -27 sau asa ceva, ma ajutam de codul ASCII

int main()
{
	FILE* file1 = fopen("Text1.txt", "r");
	if (file1 == NULL) {
		printf("Eroare\n");
		return -1;
	}
	char cuvant[64];
	char* sir = (char*)malloc(128);
	short aparitii = 0, i = 0;
	printf("Introduceti un cuvant de cautat in fisier: ");
	gets_s(cuvant);
	while (!feof(file1)) {
		(void)fscanf(file1, "%s", sir);
		for (i = 0; i < 128; ++i) {
			if (sir[i] == '.' || sir[i] == '!' || sir[i] == ';' || sir[i] == '?' || sir[i] == ',' || sir[i] == '"' || sir[i] == ')' || sir[i] == '(') sir[i] = 0;
		}
		if (strcmp(sir, cuvant) == 0) {
			++aparitii;
		}
	}
	printf("Aparitii ale cuvantului \"%s\": %hd", cuvant, aparitii);
	fclose(file1);
	free(sir);
	(void)getchar();
	return 0;
}