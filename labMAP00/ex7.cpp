#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

void panaLaN(unsigned int fn)
{
	unsigned int i, j;
	for (i = 0; i <= fn; ++i)
	{
		for (j = 0; j <= i; ++j)
		{
			printf("%d ", j);
		}
		printf("\n");
	}
}

int main()
{
	unsigned int n, i;
	for (i = 0; i < 3; ++i)
	{
		printf("n = ");
		(void)scanf("%d", &n);
		getchar();
		panaLaN(n);
	}
	getchar();
	return 0;
}