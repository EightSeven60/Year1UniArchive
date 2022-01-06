#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[])
{
	short i, caractere = 0;
	for (i = 1; i < argc; ++i) {
		caractere += strlen(argv[i]);
	}
	caractere += argc - 2;
	printf("Caractere: %hd.\nApasati Enter pentru a omori programul.", caractere);
	(void)getchar();
	return 0;
}