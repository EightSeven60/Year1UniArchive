#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[])
{
	bool flag = 1;
	short i, j, aparitii = 0;
	short lungimeCheie = strlen(argv[1]);
	for (j = 2; j < argc; ++j) {
		flag = 1;
		for (i = 0; i < lungimeCheie; ++i) {
			if (argv[1][i] != argv[j][i]) flag = 0;
		}
		if (flag) ++aparitii;
	}
	printf("Aparitii: %hd.\nApasati pe Enter pentru a termina programul.\n", aparitii);
	(void)getchar();
	return 0;
}

//program.exe Ana Ana are mere. Ana pute.