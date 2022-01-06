#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

int intComp(const void* a_p, const void* b_p) {
	return *(int*)a_p - *(int*)b_p;
}
//am folosit functia din labMAP08ex1-2
int recursiveBinarySearch(int* fvector, int low, int high, int fkey) {
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
	srand(time(NULL));
	const unsigned vSize = 100;
	int key;
	int vector[vSize];
	for (int i = 0; i < vSize; ++i) {
		vector[i] = (rand() - RAND_MAX / 2) / 100;
	}
	qsort(vector, vSize, sizeof(int), intComp);

	printf("Gib number: ");
	(void)scanf("%d", &key);
	(void)getchar();
	printf("Found number at position: %d.\n", recursiveBinarySearch(vector, 0, vSize - 1, key));

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}