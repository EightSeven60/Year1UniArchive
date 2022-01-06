#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

void afisareCrescatoare(int felements, int ...) {
	int* nr1, * nr2;
	int i, j, aux;
	for (i = 0; i < felements; ++i) {
		nr1 = &felements + 1 + i;
		for (j = 0; j < felements; ++j) {
			nr2 = &felements + 1 + j;
			if (*nr1 < *nr2) {
				aux = *nr1;
				*nr1 = *nr2;
				*nr2 = aux;
			}
		}
	}
	nr1 = &felements + 1;
	printf("Numere in ordine crescatoare: ");
	for (i = 0; i < felements; ++i) {
		printf("%d ", *nr1);
		nr1 = nr1 + 1;
	}
	printf("\n");
}

int main()
{
	afisareCrescatoare(2, 99, -5);
	afisareCrescatoare(5, -543, -25, 643, 992, -0);
	afisareCrescatoare(10, 69, -45, 0, 1, 999, 536, 7, 10, 234, -5382);
	return 0;
}