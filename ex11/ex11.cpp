#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

void allocIntM0(int** fmatrice, unsigned char* fn, unsigned char* fm)
{
	char* fi = (char*)calloc(1, sizeof(char));
	for (*fi = 0; *fi < *fn; ++ * fi) fmatrice[*fi] = (int*)calloc(*fm, sizeof(int));
	free(fi);
}
void readIntM(int** fmatrice, unsigned char* fn, unsigned char* fm)
{
	char* fi = (char*)calloc(1, sizeof(char));
	char* fj = (char*)calloc(1, sizeof(char));
	for (*fi = 0; *fi < *fn; ++ * fi)
	{
		for (*fj = 0; *fj < *fm; ++ * fj)
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
	for (*fi = 0; *fi < *fn; ++ * fi)
	{
		for (*fj = 0; *fj < *fm; ++ * fj)
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
			//fmatrice[*fi][*fj] = (rand() % 2001) - 1000;
			fmatrice[*fi][*fj] = (rand() % 21) - 10;
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
void diagonalMain(int** fmatrix, int* fdiagonal, unsigned char* fn) {
	char* fi = (char*)calloc(1, sizeof(char));
	for (*fi = 0; *fi < *fn; ++ * fi) {
		fdiagonal[*fi] = fmatrix[*fi][*fi];
	}
	free(fi);
}
void diagonalSeco(int** fmatrix, int* fdiagonal, unsigned char* fn) {
	char* fi = (char*)calloc(1, sizeof(char));
	for (*fi = 0; *fi < *fn; ++ * fi) {
		fdiagonal[*fi] = fmatrix[*fi][*fn - 1 - *fi];
	}
	free(fi);
}

int main()
{
	//alocari si declarari
	srand(time(NULL));
	unsigned char n, tipM, i;
	printf("Introduceti numarul de linii si coloane ale matricei patratice: ");
	(void)scanf("%hhd", &n);
	getchar();
	int** matrix = (int**)calloc(n, sizeof(int*));
	int* diagonal1 = (int*)calloc(n, sizeof(int));
	int* diagonal2 = (int*)calloc(n, sizeof(int));
	allocIntM0(matrix, &n, &n);

	//introducere sau generare matrici
	printf("Introduceti '0' pentru matrice aleatorie sau '1' pentru matrice introdusa de la tastatura: ");
	(void)scanf("%hhd", &tipM);
	getchar();
	if (tipM) readIntM(matrix, &n, &n);
	else randIntM(matrix, &n, &n);
	writeIntM(matrix, &n, &n);

	//returnare diagonale
	diagonalMain(matrix, diagonal1, &n);
	printf("diagonala principala: ");
	for (i = 0; i < n; ++i) {
		printf("%d ", diagonal1[i]);
	}
	diagonalSeco(matrix, diagonal2, &n);
	printf("\ndiagonala secundara: ");
	for (i = 0; i < n; ++i) {
		printf("%d ", diagonal2[i]);
	}

	//eliberare memorie
	freeM(matrix, &n);
	free(diagonal1);
	free(diagonal2);

	getchar();
	return 0;
}