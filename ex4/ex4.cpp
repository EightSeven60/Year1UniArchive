#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

float rasturnat(unsigned int fn)
{
	if (fn == 0) return -1;
	else return (float)1 / fn;
}

int main()
{
	unsigned int n;
	char i;
	for (i = 0; i < 3; ++i)
	{
		printf("n = ");
		(void)scanf("%d", &n);
		getchar();
		if (rasturnat(n) == -1) printf("Impartire la 0!");
		else printf("rasturnat: %g\n", rasturnat(n));
	}
	getchar();
	return 0;
}