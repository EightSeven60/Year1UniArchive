#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <winnt.h>
using namespace std;

typedef int (*TIP_PF)(const void*, const void*);

const int marime_vector = 100000;

int compIntFunction(const void* fx, const void* fy) {
	return (*(int*)fx - *(int*)fy);
}
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
void* genSecSearch(void* fkey, void* fBase, size_t felements, size_t elSize, TIP_PF fcompFunction) {
	for (int i = 0; i < felements; ++i) {
		int* elAdr = (int*)fBase + i;
		if (fcompFunction(fkey, elAdr) == 0) {
			return elAdr;
		}
	}
	return NULL;
}

//am scos printf-urile inainte sa masor timpii.

//ok aparent genSeqSearch e de 23456789 ori mai inceata decat seqSearch...wtf
int main()
{
	//declarari si generari
	srand(time(NULL));
	int i, cheie, vector[marime_vector];
	void* adrSearch;
	LARGE_INTEGER time1, time2, frequency;
	double elapsedTime1, elapsedTime2;
	QueryPerformanceFrequency(&frequency);
	for (i = 0; i < marime_vector; ++i) {
		vector[i] = rand();
	}
	cheie = rand();
	printf("Cheie: %d.\n", cheie);

	//masurare timp executie seqSearch
	printf("\nCautarea seqSearch:\n");
	QueryPerformanceCounter(&time1);
	seqSearch(vector, marime_vector, cheie);
	QueryPerformanceCounter(&time2);
	elapsedTime1 = (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart;
	printf("Timp de executie: %lf milisecunde.\n", elapsedTime1);

	//masurare timp executie genSeqSearch
	printf("\nCautarea genSeqSearch:\n");
	QueryPerformanceCounter(&time1);
	adrSearch = genSecSearch(&cheie, vector, marime_vector, sizeof(int), compIntFunction);
	QueryPerformanceCounter(&time2);
	printf("Adresa elementului gasit: %p.\n", adrSearch);
	printf("Elementul gasit: %d.\n", *(int*)adrSearch);
	elapsedTime2 = (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart;
	printf("Timp de executie: %lf milisecunde.\n", elapsedTime2);

	printf("Press Enter to shut down Google HQ.");
	(void)getchar();
	return 0;
}