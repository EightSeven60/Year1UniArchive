#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

int k, * v, n, ** adjacencyMatrix;

void init() {
	v[k] = 0;
}
bool am_succesor() {
	if (v[k] < n - 1) {
		++v[k];
		return true;
	}
	else return false;
}
bool e_valid() {
	if (k < n) {
		if (adjacencyMatrix[v[k - 1]][v[k]]) {
			for (int i = 0; i < k; ++i) {
				if (v[k] == v[i]) {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
bool solutie() {
	if ((k == n - 1)) {
		if (adjacencyMatrix[v[k]][v[0]]) {
			return true;
		}
	}
	return false;
}
void tipar() {
	for (int i = 0; i <= k; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");
}
void back() {
	v[0] = 0;
	k = 1;
	init();
	bool AS;
	while (k >= 1) {
		do {} while ((AS = am_succesor()) && (!e_valid()));
		if (AS) {
			if (solutie()) {
				tipar();
			}
			else if (k < n - 1) {
				k++;
				if (k < n) init();
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
	srand(time(NULL));
	FILE* file1 = fopen("Text.txt", "r");
	(void)fscanf(file1, "%d", &n);
	v = (int*)malloc(n * sizeof(int));
	adjacencyMatrix = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; ++i) {
		adjacencyMatrix[i] = (int*)calloc(n, sizeof(int));
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			(void)fscanf(file1, "%d", &adjacencyMatrix[i][j]);
		}
	}

	printf("Path: \n");
	back();
	free(v);
	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}