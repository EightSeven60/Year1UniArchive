#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

//si credeam ca nimic nu poate fi mai incet decat bubble sort lol
int intComp(const void* a_p, const void* b_p) {
	return *(int*)a_p - *(int*)b_p;
}
int recSeqSearch(const int* fvector, const unsigned fn, const int fkey) {
	if (fvector[fn - 1] == fkey) {
		return fn - 1;
	}
	else if (fn > 0) return recSeqSearch(fvector, fn - 1, fkey);
	else {
		printf("Programu o puscat.\n");
		exit(0);
	}
}

int main()
{
	srand(time(NULL));
	const unsigned vSize = 100;
	int key;
	int vector[vSize];
	for (int i = 0; i < vSize; ++i) {
		vector[i] = (rand() - RAND_MAX / 2) / 100;
	}

	printf("Gib number: ");
	(void)scanf("%d", &key);
	(void)getchar();

	printf("Pozitia numarului: %d.\n", recSeqSearch(vector, vSize, key));

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}