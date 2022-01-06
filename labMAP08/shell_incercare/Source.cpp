#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
using namespace std;

void shell_sort(int* fvector, size_t vSize) {
	int temp, ih, pas, i, j, nh;
	int *h = (int*)calloc(1, sizeof(int));
	h[0] = vSize / 3;

	for (i = 0; h[i] >= 0; ++i) {
		h = (int*)realloc(h, (i + 2) * sizeof(int));
		h[i + 1] = h[i] / 3;
	}
	nh = i;

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