#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

//EX2


int main()
{
	int n, i, j, n1 = 0; //n este numarul de linii si coloane introdus; n1 este numarul de l si c de afisat
	srand(time(NULL));
	//Citire si initializare
	printf("Introduceti n = ");
	(void)scanf("%d", &n);
	int** a = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; ++i) {
		a[i] = (int*)calloc(n, sizeof(int));
	}
	//Generare matrice aleatorie
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			a[i][j] = (rand() % 51) + 100;
		}
	}
	//Verificare
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
	//Executie problema
	for (; n1 <= n; ++n1) {
		for (i = 0; i < n1; ++i) {
			for (j = 0; j < n1; ++j) {
				printf("%5d", a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	(void)getchar();
	return 0;
}


//EX3

/*
int main()
{
	unsigned int a, bina = 0, byte1 = 0, byte2 = 0;
	int i1, i, j;
	printf("Introduceti un numar natural a = ");
	(void)scanf("%ud", &a);
	(void)getchar();
	printf("Numarul in binar unde bitul 31 se afla la dreapta:\n");
	for (i1 = 0; i1 < 32; ++i1) {
		printf("%u", ((a & (1 << i1)) >> i1));
	}
	printf("Bytes sunt considerati de la 1 la 4 inclusiv.\n");
	printf("Introduceti i = ");
	(void)scanf("%d", &i);
	printf("Introduceti j = ");
	(void)scanf("%d", &j);
	i = i * 4 - 4;
	j = j * 4 - 4;
	for (i1 = i + 4; i1 > i; --i1) {
		byte1 = byte1 | (a & (1 << i1));
	}
	byte1 = byte1 >> i - j;
	for (i1 = j + 4; i1 > j; --i1) {
		byte2 = byte2 | (a & (1 << i1));
	}
	byte2 = byte2 >> j - i;
	//Trebuia sa mai pun bitii corespunzatori celor doi bytes alesi pe 0 in numarul introdus apoi sa
	//fac o operatie de sau intre numarul introdus a si byte1 si byte2 dar nu mai apuc.
	(void)getchar();
	return 0;
}
*/

//EX1

/*
int main()
{
	int x, la, lb, i, j;
	char a[1024], b[1024];
	char* pozrez;
	printf("Introduceti primul sir:\n");
	gets_s(a);
	printf("Sirul introdus:\n");
	puts(a);
	printf("Introduceti cel de-al doilea sir:\n");
	gets_s(b);
	printf("Sirul introdus:\n");
	puts(b);
	printf("Introduceti pozitia de la care sa se caute al doilea sir in primul.\n x = ");
	(void)scanf("%d", &x);
	la = strlen(a);
	lb = strlen(b);
	//printf("%d %d", la, lb);
	for (i = x, j = 0; i < la; ++i, ++j) {
		pozrez = &a[i];
			if (a[i] != b[j]) ++i;
	}

	(void)getchar();
	return 0;
}
*/