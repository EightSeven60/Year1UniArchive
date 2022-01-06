#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

//problema 4

#define MAR 0
#define PARA 1
#define BANANA 2
#define CIREASA 3
#define CAPSUNA 4
#define NR_FRUCTE 5

int n, k, * v;

void init() {
	v[k] = -1;
}

bool succesor() {
	if (v[k] < NR_FRUCTE - 1) {
		++v[k];
		return true;
	}
	else return false;
}

bool valid() {
	if (v[k] >= MAR && v[k] <= CAPSUNA) {
		if (v[k - 1] == CIREASA && v[k] == BANANA) {
			return false;
		}
		else if (v[k - 1] == CAPSUNA && v[k] == MAR) {
			return false;
		}
		else return true;
	}
	else false;
}

bool solutie() {
	if (k == n - 1) {
		return true;
	}
	else return false;
}

void tipar() {
	for (int i = 0; i < n; ++i) {
		printf("Fruct nr %d: %d;\n", i, v[i]);
	}
	printf("\n\n");
}

void back() {
	k = 0;
	init();
	bool AS;
	while (k >= 0) {
		do {} while ((AS = succesor()) && !valid);
		if (AS) {
			if (solutie()) {
				tipar();
			}
			else if (k < n) {
				++k;
				if (k < n) {
					init();
				}
			}
			else {
				--k;
			}
		}
		else {
			--k;
		}
	}
}

int main()
{
	n = 4;
	v = new int[4];
	back();
	(void)getchar();
	return 0;
}

//daca rulati nu se opreste ca n-am mai pierdut timp cu asta, da-tii pauza la rulare
//daca vreti sa vedeti rezultatele

//problema 3
/*
bool check_order(int* vector, size_t start, size_t vSize);

int main(int argc, char* argv[])
{
	int* v = new int[argc];
	for (int i = 0; i < argc - 1; ++i) {
		v[i] = atoi(argv[i + 1]);
	}

	if (check_order(v, 0, argc)) {
		printf("Vectorul e sortat!\n");
	}

	(void)getchar();
	return 0;
}

bool check_order(int* vector, size_t start, size_t vSize) {
	if (vector[(start + vSize) / 2] < vector[((start + vSize) / 2) - 1]) {
		printf("Not sorted!\n");
		return false;
	}
	else {
		check_order(vector, start, (start + vSize) / 2);
		check_order(vector, (start + vSize) / 2, vSize);
	}
}
*/

//problema 1
/*
typedef void (*ASSIGN_PF)(void*, void*);
typedef int (*COMP_PF)(void*, void*);

void assignInt(void* destination, void* source) {
	*(int*)destination = *(int*)source;
}
int compInt(void* x, void* y) {
	return *(int*)x - *(int*)y;
}

void shell_sort(int* fvector, size_t vSize) {
	int ih, nh, temp, pas, i, j;
	int* h = (int*)calloc(1, sizeof(int));
	h[0] = vSize / 3;

	//picking steps
	for (i = 0; h[i] > 0; ++i) {
		h = (int*)realloc(h, (i + 2) * sizeof(int));
		h[i + 1] = h[i] / 3;
	}
	nh = i + 1;
	//check last h entry
	if (h[nh - 1] <= 0 && h[nh - 2] != 1) {
		h[nh - 1] = 1;
	}
	else {
		--nh;
	}

	//sorting
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
void shell_sort_gen(void* fvector, size_t vSize, size_t eSize, COMP_PF compare, ASSIGN_PF assign) {
	int ih, nh, pas, i, j;
	int* h = (int*)calloc(1, sizeof(int));
	void* temp = (void*)calloc(1, eSize);
	h[0] = vSize / 3;

	//picking steps
	for (i = 0; h[i] > 0; ++i) {
		h = (int*)realloc(h, (i + 2) * sizeof(int));
		h[i + 1] = h[i] / 3;
	}
	nh = i + 1;
	//check last h entry
	if (h[nh - 1] <= 0 && h[nh - 2] != 1) {
		h[nh - 1] = 1;
	}
	else {
		--nh;
	}

	//sorting
	for (ih = 0; ih < nh; ++ih) {
		pas = h[ih];
		for (i = pas; i < vSize; ++i) {
			//temp = fvector[i];
			assign(temp, ((char*)fvector + i * eSize));
			//fvector[j - pas] > temp
			for (j = i; j >= pas && compare((char*)fvector + (j - pas) * eSize, temp); j -= pas) {
				//fvector[j] = fvector[j - pas];
				assign((char*)fvector + (j * eSize), (char*)fvector + ((j - pas) * eSize));
			}
			//fvector[j] = temp;
			assign((char*)fvector + j * eSize, temp);
		}
	}
	free(h);
}

int main()
{
	int vector[10] = { 35, 234, 23, 94, 0, 56, 100, 246, 4, 24 };
	shell_sort_gen(vector, 5, sizeof(int), compInt, assignInt);
	(void)getchar();
	return 0;
}

*/
//fereastra 11
