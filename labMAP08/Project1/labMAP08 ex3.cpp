#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
using namespace std;


typedef int (*COMP_PF)(const void*, const void*);

int intComp(const void* a_p, const void* b_p) {
	return *(int*)a_p - *(int*)b_p;
}
void interchange(void* a_p, void* b_p) {
	*(int*)a_p += *(int*)b_p;
	*(int*)b_p = *(int*)a_p - *(int*)b_p;
	*(int*)a_p -= *(int*)b_p;
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
void allocIntM0(int** fmatrice, unsigned char* fn, unsigned char* fm)
{
	unsigned char i = 0;
	for (i = 0; i < *fn; ++i) fmatrice[i] = (int*)calloc(*fm, sizeof(int));
}


void sMatrixMul(int** fmatrice1, unsigned char fn)
{
	//MERGE DOAR PENTRU n = m !!!
	char i = 0;
	char n1 = 0;
	char m1 = 0;
	char dl1 = 0;
	char dc1 = 0;

	int** fmatriceMul = (int**)calloc(fn, sizeof(int*));
	allocIntM0(fmatriceMul, &fn, &fn);

	for (dl1 = 0; dl1 < fn; ++dl1) {
		dc1 = 0;
		for (i = 0; i < fn; ++ i) {
			if (dc1 < fn && dl1 < fn) {
				for (m1 = 0; m1 < fn && n1 < fn; ++m1) {
					fmatriceMul[dl1][dc1] = fmatriceMul[dl1][dc1] + fmatrice1[n1][m1] * fmatrice1[m1][i];
				}
				++dc1;
			}
		}
		++n1;
	}
	for (i = 0; i < fn; ++i) {
		for (int j = 0; j < fn; ++j) {
			fmatrice1[i][j] = fmatriceMul[i][j];
		}
	}
	freeM(fmatriceMul, &fn);
}
int** sMatrixMul2(int** fmatrice1, int** fmatrice2, unsigned char* fn, unsigned char* fm)
{
	//MERGE DOAR PENTRU n = m !!!
	char* fi = (char*)calloc(1, sizeof(char));
	char* fj = (char*)calloc(1, sizeof(char));
	char* n1 = (char*)calloc(1, sizeof(char));
	char* m1 = (char*)calloc(1, sizeof(char));
	char* dl1 = (char*)calloc(1, sizeof(char));
	char* dc1 = (char*)calloc(1, sizeof(char));

	int** fmatriceMul = (int**)calloc(*fn, sizeof(int*));
	allocIntM0(fmatriceMul, fn, fm);

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
	return fmatriceMul;
}
int** powMatrix(int** fmatrix, short pow, unsigned char fn) {
	if (pow == 1) {
		return fmatrix;
	}
	else if (pow == 2) {
		return sMatrixMul2(fmatrix, fmatrix, &fn, &fn);
	}
	else if (pow % 2 == 0) {
		int** M1 = (int**)calloc(fn, sizeof(int));
		allocIntM0(M1, &fn, &fn);
		M1 = powMatrix(fmatrix, pow / 2, fn);
		return sMatrixMul2(M1, M1, &fn, &fn);
	}
	else if (pow % 2 == 1) {
		int** M1 = (int**)calloc(fn, sizeof(int*));
		allocIntM0(M1, &fn, &fn);
		int** M2 = (int**)calloc(fn, sizeof(int*));
		allocIntM0(M2, &fn, &fn);
		M1 = powMatrix(fmatrix, (pow - 1) / 2, fn);
		for (int i = 0; i < fn; ++i) {
			for (int j = 0; j < fn; ++j) {
				M2[i][j] = M1[i][j];
			}
		}
		M1 = powMatrix(fmatrix, (pow + 1) / 2, fn);
		return sMatrixMul2(M1, M2, &fn, &fn);
	}
}

int main()
{
	//declarari si initializari
	srand(time(NULL));
	FILE* file1 = fopen("Text.txt", "r");
	unsigned char marimeMatrice;
	char i, j;
	short power;
	fscanf(file1, "%hhd", &marimeMatrice);
	int** matrix = (int**)calloc(marimeMatrice, sizeof(int*));
	int** matrixProduct1 = (int**)calloc(marimeMatrice, sizeof(int*));
	int** matrixProduct2 = (int**)calloc(marimeMatrice, sizeof(int*));
	int** matrixProductFinal = (int**)calloc(marimeMatrice, sizeof(int*));
	allocIntM0(matrix, &marimeMatrice, &marimeMatrice);
	allocIntM0(matrixProduct1, &marimeMatrice, &marimeMatrice);
	allocIntM0(matrixProduct2, &marimeMatrice, &marimeMatrice);
	allocIntM0(matrixProductFinal, &marimeMatrice, &marimeMatrice);
	for (i = 0; i < marimeMatrice; ++i) {
		for (j = 0; j < marimeMatrice; ++j) {
			fscanf(file1, "%d", &matrix[i][j]);
		}
	}
	printf("Enter da pawar: ");
	(void)scanf("%hd", &power);
	(void)getchar();
	
	//pawar
	matrix = powMatrix(matrix, power, marimeMatrice);

	for (i = 0; i < marimeMatrice; ++i) {
		for (j = 0; j < marimeMatrice; ++j) {
			printf("%10d", matrix[i][j]);
		}
		printf("\n");
	}

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}