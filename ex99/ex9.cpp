#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

void allocIntM0(int **fmatrice, unsigned char *fn, unsigned char *fm)
{
	char *fi = (char*)calloc(1, sizeof(char));
	for (*fi = 0; *fi < *fn; ++*fi) fmatrice[*fi] = (int*)calloc(*fm, sizeof(int));
	free(fi);
}
void readIntM(int **fmatrice, unsigned char *fn, unsigned char *fm)
{
	char* fi = (char*)calloc(1, sizeof(char));
	char* fj = (char*)calloc(1, sizeof(char));
	for (*fi = 0; *fi < *fn; ++*fi)
	{
		for (*fj = 0; *fj < *fm; ++*fj)
		{
			(void)scanf("%d", &fmatrice[*fi][*fj]);
		}
	}
	free(fi);
	free(fj);
}
void writeIntM(int** fmatrice, unsigned char* fn, unsigned char* fm)
{
	char* fi = (char*)calloc(1, sizeof(char));
	char* fj = (char*)calloc(1, sizeof(char));
	for (*fi = 0; *fi < *fn; ++*fi)
	{
		for (*fj = 0; *fj < *fm; ++*fj)
		{
			printf("%7d ", fmatrice[*fi][*fj]);
		}
		printf("\n");
	}
	free(fi);
	free(fj);
}
void randIntM(int** fmatrice, unsigned char* fn, unsigned char* fm)
{
	char* fi = (char*)calloc(1, sizeof(char));
	char* fj = (char*)calloc(1, sizeof(char));
	for (*fi = 0; *fi < *fn; ++ * fi)
	{
		for (*fj = 0; *fj < *fm; ++ * fj)
		{
			fmatrice[*fi][*fj] = (rand() % 2001) - 1000;
		}
	}
	free(fi);
	free(fj);
}
void freeM(int** fmatrice, unsigned char* fn)
{
	char* fi = (char*)calloc(1, sizeof(char));
	for (*fi = 0; *fi < *fn; ++ * fi)
	{
		free(fmatrice[*fi]);
	}
	free(fmatrice);
	free(fi);
}
void matrixMaxPos(int** fmatrice, unsigned char* fn, unsigned char* fm, int* fmax, unsigned char* nmax, unsigned char* mmax)
{
	char* fi = (char*)calloc(1, sizeof(char));
	char* fj = (char*)calloc(1, sizeof(char));
	*fmax = fmatrice[0][0];
	*nmax = 0;
	*mmax = 0;
	for (*fi = 0; *fi < *fn; ++ * fi)
	{
		for (*fj = 0; *fj < *fm; ++ * fj)
		{
			if (fmatrice[*fi][*fj] > * fmax)
			{
				*fmax = fmatrice[*fi][*fj];
				*nmax = *fi;
				*mmax = *fj;
			}
		}
	}
	free(fi);
	free(fj);
}

int main()
{
	srand(time(NULL));
	unsigned char n, m, mmax, nmax;
	char i, j;
	int max;

	printf("Linii n = ");
	(void)scanf("%hhd", &n);
	getchar();
	printf("Coloane m = ");
	(void)scanf("%hhd", &m);
	getchar();

	int** matrice = (int**)calloc(n, sizeof(int*));
	allocIntM0(matrice, &n, &m);
	//readIntM(matrice, &n, &m);
	randIntM(matrice, &n, &m);
	writeIntM(matrice, &n, &m);
	matrixMaxPos(matrice, &n, &m, &max, &nmax, &mmax);
	printf("Maxim[%hhd][%hhd]: %d", nmax, mmax, max);

	freeM(matrice, &n);

	getchar();
	return 0;
}