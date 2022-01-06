#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <winnt.h>
using namespace std;

const int marime_vector = 50000;

void seqSearch(int* fvector, int fn, int fkey) {
	bool find = 0;
	for (int i = 0; i < fn; ++i) {
		if (fvector[i] == fkey) {
			printf("Pozitia elementului: %d.\n", i);
			find = 1;
			break;
		}
	}
	if (!find) printf("Nu s-a gasit elementul.\n");
}
void directSort(int* fvector, int fn) {
	int i, j, aux;
	for (i = 0; i < fn; ++i) {
		for (j = i; j < fn; ++j) {
			if (fvector[i] > fvector[j]) {
				aux = fvector[i];
				fvector[i] = fvector[j];
				fvector[j] = aux;
			}
		}
	}
}
int binarySearch(int* fvector, int low, int high, int key) {
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (fvector[mid] == key) return mid;
		else if (fvector[mid] < key) {
			low = mid + 1;
		}
		else high = mid - 1;
	}
	return -1;
}

int main()
{
	srand(time(NULL));
	int i, cheie, vector[marime_vector];
	//am setat o cheie de cautat predefinita pentru a nu afecta rezultatele
	//i.e. am facut-o ca sa treaca ambii algoritmi de sortare prin INTREGUL vector, nu doar pana la gasirea cheii
	//cheie = 5000;
	LARGE_INTEGER time1, time2, frequency;
	double elapsedTime1, elapsedTime2;
	QueryPerformanceFrequency(&frequency);

	for (i = 0; i < marime_vector; ++i) {
		vector[i] = rand();
	}

	cheie = rand();

	QueryPerformanceCounter(&time1);
	seqSearch(vector, marime_vector, cheie);
	QueryPerformanceCounter(&time2);

	elapsedTime1 = (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart;
	printf("Timp de executie: %lf milisecunde.\n", elapsedTime1);

	printf("Incepe sortarea...\n");
	directSort(vector, marime_vector);
	printf("Sortare terminata!\n");
	QueryPerformanceCounter(&time1);
	printf("Numarul se afla pe pozitia %d.\n", binarySearch(vector, 0, marime_vector-1, cheie));
	QueryPerformanceCounter(&time2);

	elapsedTime2 = (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart;
	printf("Timp de executie: %lf milisecunde.\n", elapsedTime2);

	if (elapsedTime1 < elapsedTime2) printf("Cautarea secventiala este mai rapida decat cea binara!\n");
	else printf("Cautarea binara este mai rapida decat cea secventiala!\n");

	(void)getchar();
	return 0;
}

//din ce vad eu ca rezulta din testele acestea, rezultatele sunt foarte mixte, dar cautarea secventiala este mai rapida in multe cazuri
//mi se pare ca binarySearch e mai rapid doar cand are "noroc" si se intampla sa nimereasca elementul cautat mai devreme,
//ceea ce este mult mai probabil in vectori mai mici de elemente.