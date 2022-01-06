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

typedef int (*COMPINT_PF)(const void*, const void*);
typedef void (*ASSIGNINT_PF)(void*, const void*);

void print_vector_int(int* fvector, size_t vSize) {
	for (int i = 0; i < vSize; ++i) {
		printf("%d ", fvector[i]);
	}
	printf("\n");
}

void assignInt(void* receiver, const void* source) {
	*(int*)receiver = *(int*)source;
}
int intComp(const void* a_p, const void* b_p) {
	return *(int*)a_p -  *(int*)b_p;
}
void interchange(void* a_p, void* b_p) {
	*(int*)a_p += *(int*)b_p;
	*(int*)b_p = *(int*)a_p - *(int*)b_p;
	*(int*)a_p -= *(int*)b_p;
}
void intDirectSelectionSort(int* fvector, const size_t vectorSize) {
	//int pas = 1;
	for (int i = 0; i < vectorSize - 1; ++i) {
		for (int j = i + 1; j < vectorSize; ++j) {
			if (fvector[i] > fvector[j]) {
				interchange((void*)(fvector + i), (void*)(fvector + j));
			}
			//printf("Pasul %3d: ", pas++);
			//print_vector_int(fvector, vectorSize);
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
	int h[5] = { 121, 40, 13, 4, 1 }, nh = 5, ih, pas, temp, i, j;
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
//intShellSort2 e de 10 ori mai rapida decat cea generalizata dar prelucreaza doar tipul int
void shell_sort(int* fvector, size_t vSize) {
	int temp, ih, pas, i, j, nh;
	int* h = (int*)calloc(1, sizeof(int));
	h[0] = vSize / 3;

	for (i = 0; h[i] > 0; ++i) {
		h = (int*)realloc(h, (i + 2) * sizeof(int));
		h[i + 1] = (h[i] - 1) / 3;
	}
	nh = i + 1;

	if (h[nh - 1] <= 0 && h[nh - 2] != 1) {
		h[nh - 1] = 1;
	}
	else {
		--nh;
	}

	for (ih = 0; ih < nh; ++ih) {
		pas = h[ih];
		for (i = pas; i < vSize; ++i) {
			temp = fvector[i];
			for (j = i; j >= pas && fvector[j - pas] > temp; j -= pas) {
				fvector[j] = fvector[j - pas];
			}
			fvector[j] = temp;
		}
	}
	free(h);
}
void intShellSort2(int* fvector, const size_t vectorSize) {
	int* h = (int*)malloc(sizeof(int));
	int nh = 1, ih, pas, temp, i, j;

	//picking step intervals
	h[0] = (vectorSize - 1) / 3;
	for (i = 0; h[i] > 0; ++i) { //checks if we reached 1 which should be the end of the vector
		h = (int*)realloc(h, (i + 2) * sizeof(int)); // (i + 2) to take into account offset
		h[i + 1] = (h[i] - 1) / 3; // (i + 1) to take into account offset
	}
	nh = i + 1;
	if (h[nh - 1] <= 0 && h[nh - 2] != 1) { //checks wether last entry was 0 or 1 and corrects accordingly
		h[nh - 1] = 1;
	}
	else {
		--nh;
	}

	//sorting
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
	free(h);
}	 
void intShellSort2Gen(char* fvector, const size_t vectorSize, const size_t elementSize, ASSIGNINT_PF assignment, COMPINT_PF compare) {
	int* h = (int*)malloc(sizeof(int));
	int nh = 1, ih, pas, i, j;
	void* temp = (void*)malloc(sizeof(char) * elementSize);

	//picking step intervals
	h[0] = (vectorSize - 1) / 3;
	for (i = 0; h[i] > 0; ++i) { //checks if we reached 1 which should be the end of the vector
		h = (int*)realloc(h, (i + 2) * sizeof(int)); // (i + 2) to take into account offset
		h[i + 1] = (h[i] - 1) / 3; // (i + 1) to take into account offset
	}
	nh = i + 1;
	if (h[nh - 1] <= 0 && h[nh - 2] != 1) { //checks wether last entry was 0 or 1 and corrects accordingly
		h[nh - 1] = 1;
	}
	else {
		--nh;
	}

	//sorting
	for (ih = 0; ih < nh; ++ih) {
		pas = h[ih];
		for (i = pas; i < vectorSize; ++i) {
			//temp = fvector[i];
			assignment((void*)&temp, (void*)(fvector + i * elementSize));
			//fvector[j - pas] > temp <- inside the for condition
			for (j = i; j >= pas && compare((fvector + ((j - pas) * elementSize)), (void*)&temp) > 0; j -= pas) {
				//fvector[j] = fvector[j - pas];
				assignment((void*)(fvector + (j * elementSize)), (void*)(fvector + ((j - pas) * elementSize)));
			}
			//fvector[j] = temp;
			assignment((void*)(fvector + (j * elementSize)), (void*)&temp);
		}
	}
	free(h);
}
void intCountingSort(int* fvector, int* fsortedVector, const size_t vectorSize) {
	int* counter = (int*)calloc(vectorSize, sizeof(int));
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
//for QuickSort
int randomPivot(int inceput, int sfarsit, int* vector, int* adr_index) {
	int poz1 = rand() % (sfarsit - inceput + 1);
	poz1 += inceput;
	int poz2 = rand() % (sfarsit - inceput + 1);
	poz2 += inceput;
	int poz3 = rand() % (sfarsit - inceput + 1);
	poz3 += inceput;

	int nr = (vector[poz1] < vector[poz2]) ? ((vector[poz2] < vector[poz3]) ? vector[poz2] : max(vector[poz1], vector[poz3]))
		: ((vector[poz1] < vector[poz3]) ? vector[poz1] : max(vector[poz2], vector[poz3]));
	if (nr == vector[poz1]) *adr_index = poz1;
	if (nr == vector[poz2]) *adr_index = poz2;
	if (nr == vector[poz3]) *adr_index = poz3;

	return nr;

}
int Partitionare_2indici_random(int inceput, int sfarsit, int* vector) {
	int pozPivot, P;
	P = randomPivot(inceput, sfarsit, vector, &pozPivot);
	swap(vector[pozPivot], vector[inceput]);
	P = vector[inceput];
	int i, j;
	i = inceput + 1;
	j = sfarsit;
	while (i <= j) {
		while (i <= j && vector[i] <= P) i++;
		while (i <= j && vector[j] >= P) j--;
		if (i < j) {
			swap(vector[i], vector[j]);
		}
	}
	swap(vector[inceput], vector[j]);
	return j;

}
void QuickSort(int inceput, int sfarsit, int* vector) {
	if (inceput < sfarsit) {
		int pozPivot = Partitionare_2indici_random(inceput, sfarsit, vector);
		QuickSort(inceput, pozPivot - 1, vector);
		QuickSort(pozPivot + 1, sfarsit, vector);
	}
}
int Partitionare_2indici_random2(int inceput, int sfarsit, int* vector) {
	int pozPivot = (inceput + sfarsit) / 2, P = vector[pozPivot];
	swap(vector[pozPivot], vector[inceput]);
	P = vector[inceput];
	int i, j;
	i = inceput + 1;
	j = sfarsit;
	while (i <= j) {
		while (i <= j && vector[i] <= P) i++;
		while (i <= j && vector[j] >= P) j--;
		if (i < j) {
			swap(vector[i], vector[j]);
		}
	}
	swap(vector[inceput], vector[j]);
	return j;

}
void QuickSort2(int inceput, int sfarsit, int* vector) {
	if (inceput < sfarsit) {
		int pozPivot = Partitionare_2indici_random2(inceput, sfarsit, vector);
		QuickSort2(inceput, pozPivot - 1, vector);
		QuickSort2(pozPivot + 1, sfarsit, vector);
	}
}
//for MergeSort
void Interclasare(int inceput, int mijloc, int sfarsit, int* v) {
	int i = inceput;
	int j = mijloc + 1;
	int k = 0;
	int* temp = new int[sfarsit - inceput + 1];
	while (i <= mijloc && j <= sfarsit) {
		if (v[i] < v[j]) temp[k++] = v[i++];
		else temp[k++] = v[j++];
	}
	while (i <= mijloc)  temp[k++] = v[i++];
	while (j <= sfarsit)  temp[k++] = v[j++];
	for (int i = inceput; i <= sfarsit; ++i)
		v[i] = temp[i - inceput];
	delete[] temp;
}
void MergeSort(int inceput, int sfarsit, int* v) {
	if (inceput < sfarsit) {
		int mijloc = (inceput + sfarsit) / 2;
		MergeSort(inceput, mijloc, v);
		MergeSort(mijloc + 1, sfarsit, v);
		Interclasare(inceput, mijloc, sfarsit, v);
	}
}

int cautareBinara(int* vector, int inf, int sup, int cheie) {
	int mijl;
	while (inf <= sup) {
		mijl = (inf + sup) / 2;
		if (vector[mijl] == cheie) return mijl;
		else if (vector[mijl] < cheie) inf = mijl + 1;
		else sup = mijl - 1;
	}
	return -1;
}
int recursiveBinarySearch(int *fvector, int low, int high, int fkey) {
	if (high >= low) {
		int mid = low + (high - low) / 2;
		if (fvector[mid] == fkey) {
			return mid;
		}
		if (fvector[mid] > fkey) {
			return recursiveBinarySearch(fvector, low, mid - 1, fkey);
		}
		return recursiveBinarySearch(fvector, mid + 1, high, fkey);
	}
	return -1;
}


int main()
{
	//declarari si initializari
	const int vSize = 5, repetitions = 1;
	srand(time(NULL));
	int vector[vSize], key, *hit;
	int* sortedVector = (int*)calloc(vSize, sizeof(int));
	double elapsedTime, sumOfTime = 0;
	LARGE_INTEGER frequency, time1, time2;
	QueryPerformanceFrequency(&frequency);

	//masurare timp
	for (int c = 0; c < repetitions; ++c) {
		for (int i = 0; i < vSize; ++i) {
			vector[i] = rand() - RAND_MAX / 2;
		}
		vector[0] = 7;
		vector[1] = 1;
		vector[2] = 2;
		vector[3] = 4;
		vector[4] = 8;
		QueryPerformanceCounter(&time1);
		intDirectSelectionSort(vector, vSize);
		QueryPerformanceCounter(&time2);
		
		printf("%lf\n", (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart);
		sumOfTime += (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart;
		
	}
	printf("Medie de timp: %lf\n", sumOfTime / repetitions);

	return 0;
}


int Partitionare_2indici(int inceput, int sfarsit, int* vector) {
	int P = vector[inceput];
	int i, j;
	i = inceput + 1;
	j = sfarsit;
	while (i <= j) {
		while (i <= j && vector[i] <= P) i++;
		while (i <= j && vector[j] >= P) j--;
		if (i < j) {
			swap(vector[i], vector[j]);
		}
	}
	swap(vector[inceput], vector[j]);
	return j;

}
int Partitionare_Lomuto(int inceput, int sfarsit, int* vector) {
	int P = vector[inceput];
	int pozPivot = inceput;
	for (int i = inceput + 1; i <= sfarsit; ++i) {
		if (vector[i] < P) {
			pozPivot++;
			swap(vector[i], vector[pozPivot]);
		}
	}
	swap(vector[inceput], vector[pozPivot]);
	return pozPivot;
}