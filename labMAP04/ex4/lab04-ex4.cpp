#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <winnt.h>
using namespace std;

const int marime_vector = 100000;

int compInt(const void* nr1, const void* nr2) {
	return *(int*)nr1 - *(int*)nr2;
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
void* genBinarySearch(const void* fvector, const void* vectorLen, const void* key) {
	int* vector_p = (int*)fvector;
	int* key_p = (int*)key;
	int* high_p = (int*)vectorLen;

	int mid, low = 0;
	while (low <= *high_p) {
		mid = (low + *high_p) / 2;
		if (vector_p[mid] == *key_p) return &mid;
		else if (vector_p[mid] < *key_p) {
			low = mid + 1;
		}
		else *high_p = mid - 1;
	}
	return NULL;
}

int main()
{
	//declarari si generari
	srand(time(NULL));
	int i, cheie, vector[marime_vector], * nrAdr, * hit_p, marime = marime_vector;
	LARGE_INTEGER frequency, time1, time2;
	double elapsedTime1, elapsedTime2;
	QueryPerformanceFrequency(&frequency);
	for (i = 0; i < marime_vector; ++i) {
		vector[i] = rand();
	}
	cheie = rand();
	qsort(vector, marime_vector, sizeof(int), compInt);
	
	QueryPerformanceCounter(&time1);
	hit_p = (int*)genBinarySearch(vector, &marime, &cheie);
	QueryPerformanceCounter(&time2);
	elapsedTime1 = (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart;
	if (hit_p == NULL) printf("GenBinarySearch nu a gasit numarul.\n");
	else printf("Numar gasit de catre genBinarySearch la adresa: %p.\n", hit_p);
	printf("GenBinarySearch a rulat pentru %lf secunde.\n\n", elapsedTime1);

	QueryPerformanceCounter(&time1);
	hit_p = (int*)bsearch(&cheie, vector, marime_vector, sizeof(int), compInt);
	QueryPerformanceCounter(&time2);
	elapsedTime2 = (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart;
	if (hit_p == NULL) printf("Bsearch nu a gasit numarul.\n");
	else printf("Numar gasit de catre bsearch la adresa: %p.\n", hit_p);
	printf("Bsearch a rulat pentru %lf secunde.\n\n", elapsedTime2);

	if (elapsedTime1 < elapsedTime2) printf("GenBinarySearch e mai rapid!\n");
	else printf("Bsearch e mai rapid!\n");

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}