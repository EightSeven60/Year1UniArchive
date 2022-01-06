#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

int k, * v, n, * vInput, nTemp, maxV = -2147483648, minV = 2147483647;

void init() {
	v[k] = minV - 1;
}
bool am_succesor() {
	if (v[k] < maxV) {
		++v[k];
		return true;
	}
	else return false;
}
bool e_valid() {
	bool match = false;
	for (int i = 0; i < nTemp; ++i) {
		if (v[k] == vInput[i]) {
			match = true;
			break;
		}
	}
	if (match) {
		match = false;
		for (int i = 0; i < k; ++i) {
			if (v[k] == v[i]) {
				return false;
			}
		}
	}
	else {
		return false;
	}
	return true;
}
bool solutie() {
	if ((k == n - 1)) {
		return true;
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
	k = 0;
	init();
	bool AS;
	while (k >= 0) {
		do {} while ((AS = am_succesor()) && (!e_valid()));
		if (AS) {
			if (solutie()) {
				tipar();
			}
			else if (k < n) {
				k++;
				if (k < n) init();
			}
			else {
				break;
			}
		}
		else {
			--k;
		}
	}
}

int main()
{
	//declarari si initializari
	srand(time(NULL));
	printf("Enter vector size: ");
	(void)fscanf(stdin, "%d", &n);
	(void)getchar();
	nTemp = n;
	v = (int*)malloc(n * sizeof(int));
	vInput = (int*)malloc(n * sizeof(int));

	printf("Enter the numbers: ");
	for (int i = 0; i < n; ++i) {
		(void)fscanf(stdin, "%d", &vInput[i]);
		(void)getchar();
		maxV = max(vInput[i], maxV);
		minV = min(vInput[i], minV);
	}

	printf("Display k-permutetions of the vector with length n where k is: ");
	(void)fscanf(stdin, "%d", &n);
	(void)getchar();

	//F-call
	printf("k-permutations of n for the given vector: \n");
	back();

	free(v);
	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}

//am folosit baza de la problema doi ca sa se poate si introduce vectorul pe care se
//vor face A de n cate k, dar puteam lua baza de la ex1 v2 pentru a folosi numerele de la 0 la n.