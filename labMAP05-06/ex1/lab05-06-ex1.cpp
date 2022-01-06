#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
using namespace std;

const int vSize = 6;

typedef int (*COMP_PF)(const void*, const void*);

int intComp(const void* a_p, const void* b_p) {
	return *(int*)a_p - *(int*)b_p;
}
void interchange(void* a_p, void* b_p) {
	*(int*)a_p += *(int*)b_p;
	*(int*)b_p = *(int*)a_p - *(int*)b_p;
	*(int*)a_p -= *(int*)b_p;
}
void genDirectSelectionSort(const void* vector, size_t vectorSize, size_t elSize, COMP_PF compF) {
	for (int i = 0; i < vectorSize; ++i) {
		char* el1_p = (char*)vector + elSize * i;
		for (int j = i + 1; j < vectorSize; ++j) {
			char* el2_p = (char*)vector + elSize * j;
			if (compF(el1_p, el2_p) >= 1) {
				interchange(el1_p, el2_p);
			}
		}
	}
}
void genBubbleSort(const void* vector, size_t vectorSize, size_t elSize, COMP_PF compF) {
	bool flag = 1;
	while (flag) {
		flag = 0;
		for (int i = 0; i < vectorSize - 1;) {
			char* el1_p = (char*)vector + elSize * i;
			char* el2_p = (char*)vector + elSize * (++i);
			if (compF(el1_p, el2_p) >= 1) {
				interchange(el1_p, el2_p);
				flag = 1;
			}
		}
	}
}
void genCocktailSort(const void* vector, size_t vectorSize, size_t elSize, COMP_PF compF) {
	bool flag = 1;
	while (flag) {
		flag = 0;
		for (int i = 0; i < vectorSize - 1; ++i) {
			char* el1_p = (char*)vector + elSize * i;
			char* el2_p = (char*)vector + elSize * (i + 1);
			if (compF(el1_p, el2_p) >= 1) {
				interchange(el1_p, el2_p);
				flag = 1;
			}
		}
		for (int i = vectorSize - 2; i > 0; --i) {
			char* el1_p = (char*)vector + elSize * i;
			char* el2_p = (char*)vector + elSize * (i + 1);
			if (compF(el1_p, el2_p) >= 1) {
				interchange(el1_p, el2_p);
				flag = 1;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	int vector[vSize];

	for (int i = 0; i < vSize; ++i) {
		vector[i] = rand();
	}
	genDirectSelectionSort(vector, vSize, sizeof(int), intComp);

	for (int i = 0; i < vSize; ++i) {
		vector[i] = rand();
	}
	genBubbleSort(vector, vSize, sizeof(int), intComp);

	for (int i = 0; i < vSize; ++i) {
		vector[i] = rand();
	}
	genCocktailSort(vector, vSize, sizeof(int), intComp);

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}