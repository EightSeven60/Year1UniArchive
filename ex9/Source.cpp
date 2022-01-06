#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	char i = 0, j = 0;
	int n, m;

	printf("n = ");
	(void)scanf("%d", &n);
	printf("m = ");
	(void)scanf("%d", &m);

	int** matrice = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; ++i)
	{
		matrice[i] = (int*)calloc(m, sizeof(int));
	}

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			(void)scanf("%d", &matrice[i][j]);
		}
	}

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
	return 0;
}