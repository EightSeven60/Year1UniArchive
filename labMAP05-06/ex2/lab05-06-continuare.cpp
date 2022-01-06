#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
using namespace std;

//am facut toate functiile si le schimb pe rand in program si masor timpul ca sa nu ma mai complic cu cod degeaba

typedef int (*COMP_PF)(const void*, const void*);

int intComp(const void* a_p, const void* b_p) {
	return *(int*)b_p - *(int*)a_p;
}
void interchange(void* a_p, void* b_p) {
	*(int*)a_p += *(int*)b_p;
	*(int*)b_p = *(int*)a_p - *(int*)b_p;
	*(int*)a_p -= *(int*)b_p;
}
void intDirectSelectionSort(int* fvector, const size_t vectorSize) {
	for (int i = 0; i < vectorSize - 1; ++i) {
		for (int j = i + 1; j < vectorSize; ++j) {
			if (fvector[i] > fvector[j]) {
				interchange((void*)(fvector + i), (void*)(fvector + j));

			}
		}
	}
}
void intInsertionSort(int* fvector, const size_t vectorSize) {
	int aux;
	for (int i = 1, j = vectorSize - 1; i < vectorSize; ++i) {
		aux = fvector[i];
		while (j >= 0 && aux < fvector[j]) {
			fvector[j + 1] = fvector[j];
			--j;
		}
		fvector[j + 1] = aux;
	}
} //broke
void intInsertionSort2(int* fvector, const size_t vectorSize) {
	int holePosition, valueToInsert;
	for (int i = 1; i < vectorSize; ++i) {
		valueToInsert = fvector[i];
		holePosition = i;
		while (holePosition > 0 && fvector[holePosition - 1] > valueToInsert) {
			fvector[holePosition] = fvector[holePosition - 1];
			holePosition = holePosition - 1;
		}
		fvector[holePosition] = valueToInsert;
	}
}
void intShellSort(int* fvector, const size_t vectorSize) {
	int h[5] = { 250, 15, 5, 3, 1 }, nh = 5, ih, pas, temp, i, j;
	for (ih = 0; ih < nh; ++ih) {
		pas = h[ih];
		for (i = pas; i < vectorSize; ++i) {
			temp = fvector[i];
			for (j = i; j >= pas && fvector[j - pas] > temp; j -= pas) {
				fvector[j] = fvector[j - pas];
			}
			fvector[j] = temp;
		}
	}
}
void intShellSort2(int* fvector, const size_t vectorSize) { //aici vreau sa fac un shell sort care isi gaseste singur h-urile, dar nu e gata, nu apuc azi
	int* h = (int*)malloc(sizeof(int));
	int nh = 0, ih, pas, temp, i, j;
	for (i = 2; h[i - 1] < log(vectorSize); ++i) {
		printf("%lf", log(vectorSize));
		h = (int*)realloc(h, i * sizeof(int));
		h[i - 1] = (pow(2, i - 1)) - 1;
	}
	nh = i - 1;

	for (ih = 0; ih < nh; ++ih) {
		pas = h[ih];
		for (i = pas; i < vectorSize; ++i) {
			temp = fvector[i];
			for (j = i; j >= pas && fvector[j - pas] > temp; j -= pas) {
				fvector[j] = fvector[j - pas];
			}
			fvector[j] = temp;
		}
	}
}
void intCountingSort(int* fvector, int* fsortedVector, const size_t vectorSize) {
	int *counter = (int*)calloc(vectorSize, sizeof(int));
	for (int i = 0; i < vectorSize - 1; ++i) {
		for (int j = i + 1; j < vectorSize; ++j) {
			if (fvector[i] > fvector[j]) ++counter[i];
			else ++counter[j];
		}
	}
	for (int i = 0; i < vectorSize; ++i) {
		fsortedVector[counter[i]] = fvector[i];
	}
	free(counter);
}
void intBubbleSortv2(int* fvector, const size_t vectorSize) {
	int interchangePosition = vectorSize - 1, position;
	bool switcheroo;
	do {
		switcheroo = 0;
		position = 0;
		for (int i = 0; i < interchangePosition; ++i) {
			if (fvector[i] > fvector[i + 1]) {
				interchange((void*)(fvector + i), (void*)(fvector + i + 1));
				switcheroo = 1;
				position = i;
			}
		}
		interchangePosition = position;
	} while (switcheroo);
}
void intShakerSort(int* fvector, const size_t vectorSize) {
	bool switcheroo;
	do {
		switcheroo = false;
		for (int i = 0; i < vectorSize - 1; ++i) {
			if (fvector[i] > fvector[i + 1]) {
				interchange((void*)(fvector + i), (void*)(fvector + i + 1));
				switcheroo = 1;
			}
		}
		if (!switcheroo) break;
		switcheroo = false;
		for (int i = vectorSize - 2; i > 0; --i) {
			if (fvector[i] > fvector[i + 1]) {
				interchange((void*)(fvector + i), (void*)(fvector + i + 1));
				switcheroo = 1;
			}
		}
	} while (switcheroo);
}
void countingSortCifra(int* vector, const size_t vectorSize, char pozCifra) {
	char m = 9;
	int i, cifra;
	int* fr = (int*)calloc(m, sizeof(int));
	int* y = (int*)calloc(vectorSize, sizeof(int));
	for (i = 1; i <= m; ++i) {
		fr[i] = 0;
	}
	for (i = 0; i < vectorSize; ++i) {
		cifra = (vector[i] / (int)pow(10, pozCifra)) % 10;
		++fr[cifra];
	}
	for (i = 1; i <= m; ++i) {
		fr[i] = fr[i - 1] + fr[i];
	}
	for (i = vectorSize - 1; i >= 0; --i) {
		cifra = (vector[i] / (int)pow(10, pozCifra)) % 10;
		y[fr[cifra] - 1] = vector[i];
		--fr[cifra];
	}
	for (i = 0; i < vectorSize; ++i) {
		vector[i] = y[i];
	}
}
void radixSort(int* vector, const size_t vectorSize) {
	char pozCifra;
	for (pozCifra = 0; pozCifra < 10; ++pozCifra) {
		countingSortCifra(vector, vectorSize, pozCifra);
	}
}

int main()
{
	//declarari si initializari
	const int vSize = 1000, repetitions = 10;
	srand(time(NULL));
	int vector[vSize];
	int* sortedVector = (int*)calloc(vSize, sizeof(int));
	double elapsedTime, sumOfTime = 0;
	LARGE_INTEGER frequency, time1, time2;
	QueryPerformanceFrequency(&frequency);

	//masurare timp
	for (int c = 0; c < repetitions; ++c) {
		for (int i = 0; i < vSize; ++i) {
			vector[i] = rand();
		}
		//qsort(vector, vSize, sizeof(int), intComp);
		QueryPerformanceCounter(&time1);
		radixSort(vector, vSize);
		QueryPerformanceCounter(&time2);
		printf("%lf\n", (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart);
		sumOfTime += (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart;
	}
	printf("Medie de timp: %lf\n", sumOfTime / repetitions);

	return 0;
}