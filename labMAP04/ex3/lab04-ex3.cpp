#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <winnt.h>
using namespace std;

const int marime_vector = 100000;

typedef int (*compF_p)(const void*, const void*);

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

void *genBinarySearch(const void* fvector, const void *vectorLen, const void *key) {
	int *vector_p = (int*)fvector;
	int* key_p = (int*)key;
	int* high_p = (int*)vectorLen;

	int mid, low = 0;
	while (low <= *high_p) {
		mid = (low + *high_p) / 2;
		if (vector_p[mid] == *key_p) return &mid;
		else if (vector_p[mid] < *key_p) {
			low = mid+ 1;
		}
		else *high_p = mid - 1;
	}
	return NULL;
}


//nu stiu ce doamne iarta-ma am facut aici dar merge
int main()
{
	//declarari si generari
	srand(time(NULL));
	int i, cheie, vector[marime_vector], * nrAdr, marime = marime_vector;
	for (i = 0; i < marime_vector; ++i) {
		vector[i] = rand();
	}
	cheie = rand();
	directSort(vector, marime_vector);

	nrAdr = (int*)genBinarySearch(vector, &marime, &cheie);
	if (nrAdr != NULL) printf("Adresa elementului gasit: %p.\n", nrAdr);
	else printf("Elementul este un ninja si nu este de gasit!\n");

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}