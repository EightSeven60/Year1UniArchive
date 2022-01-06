#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

void afisareNrCuvinte(char* fargumente, char fcorectie)
{
	short i, aparitii = 0;
	for (i = 0; i < strlen(fargumente); ++i) {
		if (fargumente[i] == ' ' || fargumente[i] == '\n' || (fargumente[i] == '-' && (fargumente[i + 1] < 48 || fargumente[i + 1] > 57))) {
			++aparitii;
		}
	}
	printf("Cuvinte: %hd.\n", aparitii - 2 * fcorectie + 1);
}
void afisareNrPropozitii(char* fargumente) {
	short i, propozitii = 0;
	for (i = 0; i < strlen(fargumente); ++i) {
		if ( (fargumente[i] == '.' && fargumente[i + 1] != '.') || fargumente[i] == '?' || fargumente[i] == '!') {
			++propozitii;
		}
	}
	printf("Propozitii: %hd.\n", propozitii);
}

int main(int argc, char* argv[])
{
	//declarari
	bool p = 0, c = 0, l = 0;
	char argumente[512], cuvant[64], corectie = 0;
	argumente[0] = '\0';
	short i;

	//transfer argumente in sir
	for (i = 1; i < argc; ++i) {
		strcat(argumente, argv[i]);
		strcat(argumente, " ");
	}
	argumente[strlen(argumente) - 1] = '\0';

	printf("Argumente: ");
	puts(argumente);

	//detectie argumente de control
	for (i = 0; i < strlen(argumente); ++i) {
		if (argumente[i] == '-') {
			if (argumente[i + 1] == 'c') {
				c = 1;
				++i;
				++corectie;
			}
			if (argumente[i + 1] == 'l') {
				l = 1;
				++i;
				++corectie;
			}
			if (argumente[i + 1] == 'p') {
				p = 1;
				++i;
				++corectie;
			}
		}
	}
	printf("Detectie:\nc: %hhd;\nl: %hhd;\np: %hhd.\n", c, l, p);

	//executie cerinta conform argumentelor
	if (c) afisareNrCuvinte(argumente, corectie);
	if (l) printf("Lungime sir: %u.\n", strlen(argumente) - corectie * 3);
	if (p) afisareNrPropozitii(argumente);

	printf("Apasati Enter pentru a extermina umanitatea.");
	(void)getchar();
	return 0;
}