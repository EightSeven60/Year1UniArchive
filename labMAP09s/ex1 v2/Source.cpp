#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

int k, * v, n;

void init() {
	v[k] = 0;
}
bool am_succesor() {
	if (v[k] < n) {
		++v[k];
		return true;
	}
	else return false;
}
bool e_valid() {
	for (int i = 0; i < k; ++i) {
		if (v[k] == v[i]) {
			return false;
		}
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
	printf("Enter n: ");
	(void)fscanf(stdin, "%d", &n);
	(void)getchar();
	v = (int*)malloc(n * sizeof(int));

	printf("All possible permutations: \n");
	back();
	free(v);
	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}