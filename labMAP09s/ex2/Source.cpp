#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

int k, * v, n;

void init() {
	v[k] = -1;
}
bool am_succesor() {
	if (v[k] < n - 1) {
		++v[k];
		return true;
	}
	else return false;
}
bool e_valid() {
	int temp1, temp2;
	for (int i = 0; i < k; ++i) {
		if (v[k] == v[i]) {
			return false;
		}

		temp1 = v[i] - v[k];
		if (temp1 < 0) {
			temp1 = -1 * temp1;
		}
		temp2 = i - k;
		if (temp2 < 0) {
			temp2 = -1 * temp2;
		}
		if (temp1 == temp2) {
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
		printf("v[%d] = %d ", i, v[i]);
	}
	printf("\n");
}
void toConsole() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("Possible solution:\n");

	//print indicators
	printf("  ");
	for (int i = 0; i <= k; ++i) {
		printf(" %d", i);
	}

	//print checkerboard
	for (int i = k; i >= 0; --i) {
		SetConsoleTextAttribute(hConsole, 7); //white
		printf("\n");
		printf("%d  ", i);
		for (int j = k; j >= 0; --j) {
			if (v[i] == j) {
				SetConsoleTextAttribute(hConsole, 12); //red
				printf("%c ", 3);
			}
			else {
				SetConsoleTextAttribute(hConsole, 8); //grey
				printf("+ ");
			}
		}
	}
	SetConsoleTextAttribute(hConsole, 7); //white
	printf("\n\n");
}
void back() {
	k = 0;
	init();
	bool AS;
	while (k >= 0) {
		do {} while ((AS = am_succesor()) && (!e_valid()));
		if (AS) {
			if (solutie()) {
				toConsole();
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

	back();
	free(v);
	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}