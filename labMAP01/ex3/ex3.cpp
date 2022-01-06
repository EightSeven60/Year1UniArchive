#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

void ordonare(char** text, short linii) {
	short i, j;
	char* temp = (char*)malloc(512 * sizeof(char));
	for (j = 0; j < linii; ++j) {
		for (i = 0; i < linii; ++i) {
			if (strcmp(text[i], text[j]) > 0) {
				strcpy(temp, text[i]);
				strcpy(text[i], text[j]);
				strcpy(text[j], temp);
			}
		}
	}
	text[i - 1][strlen(text[i-1]) - 1] = 0;
	free(temp);
}

int main()
{
	FILE* file1 = fopen("Text1.txt", "r");
	FILE* file2 = fopen("Text2.txt", "w");
	short i, liniiCitite;
	char** buffer = (char**)malloc(64 * sizeof(char*));
	for (i = 0; i < 64; ++i) buffer[i] = (char*)malloc(512 * sizeof(char));
	if (file1 != NULL || file2 != NULL) {
		i = 0;
		while (!feof(file1)) {
			fgets(buffer[i], 512, file1);
			++i;
		}
		strcat(buffer[i - 1], "\n");
		liniiCitite = i;
		ordonare(buffer, liniiCitite);
		for (i = 0; i < liniiCitite; ++i) {
			fputs(buffer[i], file2);
		}
	}
	else printf("Eroare");

	for (i = 0; i < 64; ++i) {
		free(buffer[i]);
	}
	free(buffer);
	fclose(file1);
	fclose(file2);
	return 0;
}