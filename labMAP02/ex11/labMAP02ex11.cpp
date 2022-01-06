#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	char buffer[256];
	short i, cuvinte = 0, litere = 0, propozitii = 0;
	FILE* file1 = fopen("Text.txt", "r");
	if (file1 == NULL) {
		printf("Eroare citire fisier.\n");
		return -1;
}
	while (!feof(file1)) {
		fgets(buffer, 256, file1);
		for (i = 0; i < 256; ++i) {
			if ((buffer[i] == '.' && buffer[i + 1] != '.') || buffer[i] == '?' || buffer[i] == '!') {
				++propozitii;
				++cuvinte;
				++i;
				continue;
			}
			else if ((buffer[i] == ',' && (buffer[i] < 48 || buffer[i] > 57)) || (buffer[i] == ';' && (buffer[i] < 48 || buffer[i] > 57)) || (buffer[i] == '\\' && (buffer[i] < 48 || buffer[i] > 57)) || (buffer[i] == '/' && (buffer[i] < 48 || buffer[i] > 57)) || (buffer[i] == '-' && (buffer[i] < 48 || buffer[i] > 57))) {
				++cuvinte;
				++i;
				continue;
			}
			else if (buffer[i] == ' ' && (buffer[i - 1] < 48 || buffer[i - 1] > 57)) {
				++cuvinte;
				continue;
			}
			else if ((buffer[i] > 64 && buffer[i] < 91) || (buffer[i] > 96 && buffer[i] < 123)) {
				++litere;
				continue;
			}
		}
	}
	printf("Cuvinte: %hd\nPropozitii: %hd\nLitere: %hd\n", cuvinte, propozitii, litere);
	(void)getchar();
	return 0;
}

//in cazul acesta, "continue" e folosit pentru a sari peste verificari aditionale care nu ajuta cu nimic, doar iau timp