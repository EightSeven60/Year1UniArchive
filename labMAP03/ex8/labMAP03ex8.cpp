#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[])
{
	short i, j, propozitii = 0, lungimeCuvant;
	for (i = 1; i < argc; ++i) {
		lungimeCuvant = strlen(argv[i]);
		for (j = 0; j < lungimeCuvant; ++j) {
			if (argv[i][j] == '.' || argv[i][j] == '?' || argv[i][j] == '!') ++propozitii;
		}
	}
	printf("Propozitii: %hd.\n", propozitii);
	printf("Apasati Enter pentru a da neveu' la program.");
	(void)getchar();
	return 0;
}