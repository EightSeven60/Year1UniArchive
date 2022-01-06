#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
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
void matrixSum(int** fmatrice1, int** fmatrice2, int** fmatriceSuma, unsigned char* fn, unsigned char* fm)
{
	char* fi = (char*)calloc(1, sizeof(char));
	char* fj = (char*)calloc(1, sizeof(char));
	for (*fi = 0; *fi < *fn; ++ * fi)
	{
		for (*fj = 0; *fj < *fm; ++ * fj)
		{
			fmatriceSuma[*fi][*fj] = fmatrice1[*fi][*fj] + fmatrice2[*fi][*fj];
		}
	}
	free(fi);
	free(fj);
}
void matrixDif(int** fmatrice1, int** fmatrice2, int** fmatriceDif, unsigned char* fn, unsigned char* fm)
{
	char* fi = (char*)calloc(1, sizeof(char));
	char* fj = (char*)calloc(1, sizeof(char));
	for (*fi = 0; *fi < *fn; ++ * fi)
	{
		for (*fj = 0; *fj < *fm; ++ * fj)
		{
			fmatriceDif[*fi][*fj] = fmatrice1[*fi][*fj] - fmatrice2[*fi][*fj];
		}
	}
	free(fi);
	free(fj);
}
void sMatrixMul(int** fmatrice1, int** fmatrice2, int** fmatriceMul, unsigned char* fn, unsigned char* fm)
{
	//MERGE DOAR PENTRU n = m !!!
	char* fi = (char*)calloc(1, sizeof(char));
	char* fj = (char*)calloc(1, sizeof(char));
	char* n1 = (char*)calloc(1, sizeof(char));
	char* m1 = (char*)calloc(1, sizeof(char));
	char* dl1 = (char*)calloc(1, sizeof(char));
	char* dc1 = (char*)calloc(1, sizeof(char));

	*n1 = 0; *dl1 = 0; *dc1 = 0;
	for (*dl1 = 0; *dl1 < *fm; ++ * dl1) {
		*dc1 = 0;
		for (*fi = 0; *fi < *fm; ++ * fi) {
			if (*dc1 < *fm && *dl1 < *fm) {
				for (*m1 = 0; *m1 < *fm && *n1 < *fn; ++ * m1) {
					fmatriceMul[*dl1][*dc1] = fmatriceMul[*dl1][*dc1] + fmatrice1[*n1][*m1] * fmatrice2[*m1][*fi];
				}
				++* dc1;
			}
		}
		++* n1;
	}
	free(fi);
	free(fj);
	free(n1);
	free(m1);
	free(dl1);
	free(dc1);
}

//PRODUS MATRICI Fundamentele Programarii
/*
//Produsul
if (n != q || m != p) printf("Matricele nu se pot inmulti deoarece nu au dimensiuni corespunzatoare.\n");
else if (n <= m) {
	n1 = 0; dl1 = 0; dc1 = 0;
	for (dl1 = 0; dl1 < m; ++dl1) {
		dc1 = 0;
		for (i = 0; i < q; ++i) {
			if (dc1 < m && dl1 < m) {
				for (m1 = 0; m1 < m && n1 < n; ++m1) {
					d[dl1][dc1] = d[dl1][dc1] + a[n1][m1] * b[m1][i];
				}
				++dc1;
			}
		}
		++n1;
	}
	//Printarea matricei
	printf("Matricea d (produsul):\n");
	for (dl1 = 0; dl1 < n; ++dl1) {
		for (dc1 = 0; dc1 < n; ++dc1) {
			printf("%7d ", d[dl1][dc1]);
		}
		printf("\n");
	}
}
*/

int main()
{
	//Initializari si alocari
	srand(time(NULL));
	unsigned char n, m, tipM;
	printf("Introduceti dimensiunile matricilor. Acestea trebuie sa fie egale ca sa se poata efectua toate operatiile.\nlinii si coloane: ");
	(void)scanf("%hhd", &n);
	getchar();
	m = n;
	int** matrice1 = (int**)calloc(n, sizeof(int*));
	int** matrice2 = (int**)calloc(n, sizeof(int*));
	int** matriceSuma = (int**)calloc(n, sizeof(int*));
	int** matriceDif = (int**)calloc(n, sizeof(int*));
	int** matriceMul = (int**)calloc(n, sizeof(int*));
	allocIntM0(matrice1, &n, &m);
	allocIntM0(matrice2, &n, &m);
	allocIntM0(matriceSuma, &n, &m);
	allocIntM0(matriceDif, &n, &m);
	allocIntM0(matriceMul, &n, &m);

	//Introducere / generare matrici
	printf("Introduceti '0' pentru matrici aleatorii sau '1' pentru matrici introduse de la tastatura: ");
	(void)scanf("%hhd", &tipM);
	getchar();
	if (tipM) {
		printf("Introduceti matricea 1:\n");
		readIntM(matrice1, &n, &m);
	}
	else {
		randIntM(matrice1, &n, &m);
	}
	printf("Matricea 1:\n");
	writeIntM(matrice1, &n, &m);
	if (tipM) {
		printf("Introduceti matricea 2:\n");
		readIntM(matrice2, &n, &m);
	}
	else {
		randIntM(matrice2, &n, &m);
	}
	printf("Matricea 2:\n");
	writeIntM(matrice2, &n, &m);

	//Suma
	matrixSum(matrice1, matrice2, matriceSuma, &n, &m);
	printf("Matricea suma:\n");
	writeIntM(matriceSuma, &n, &m);

	//Diferenta
	matrixDif(matrice1, matrice2, matriceDif, &n, &m);
	printf("Matricea diferenta:\n");
	writeIntM(matriceDif, &n, &m);

	//Produsul
	sMatrixMul(matrice1, matrice2, matriceMul, &n, &m);
	printf("Matrice produs:\n");
	writeIntM(matriceMul, &n, &m);

	//Eliberari memorie
	freeM(matrice1, &n);
	freeM(matrice2, &n);
	freeM(matriceSuma, &n);
	freeM(matriceDif, &n);
	freeM(matriceMul, &n);

	getchar();
	return 0;
}