#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	//declarari
	short i = 0, j = 0, marimeNumere = 0;
	char detNr = 0;
	int aux, su = 0, pr = 1;
	char* buffer = (char*)calloc(69, sizeof(char));
	int* numere = (int*)calloc(69, sizeof(int));
	FILE* text = fopen("Text.txt", "r");
	FILE* suma = fopen("Suma.txt", "w");
	FILE* produs = fopen("Produs.txt", "w");
	FILE* ordine = fopen("Ordine.txt", "w");

	//transmitere numere in matrice si aflare suma si produs
	while (!feof(text)) {
		fscanf(text, "%s", buffer);
		for (i = 0; i < strlen(buffer); ++i) {
			if ((buffer[i] < 48 || buffer[i] > 57) && (buffer[i] != '-') || ((buffer[i] == '-') && (buffer[i+1] < 48 || buffer[i+1] > 57))) {
				buffer[i] = ' ';
			}
			else detNr = 1;
		}
		if (detNr == 1) {
			numere[j] = atoi(buffer);
			pr = pr * numere[j];
			su = su + numere[j];
			++j;
		}
		detNr = 0;
	}

	//ordonare
	marimeNumere = j;
	printf("\n");
	for (i = 0; i < marimeNumere; ++i) {
		for (j = 0; j < marimeNumere; ++j) {
			if (numere[i] < numere[j]) {
				aux = numere[i];
				numere[i] = numere[j];
				numere[j] = aux;
			}
		}
	}

	//printare in fisiere
	for (i = 0; i < marimeNumere; ++i) {
		fprintf(ordine, "%d ", numere[i]);
	}
	fprintf(produs, "Produs: %d ", pr);
	fprintf(suma, "Suma: %d ", su);
	return 0;
}