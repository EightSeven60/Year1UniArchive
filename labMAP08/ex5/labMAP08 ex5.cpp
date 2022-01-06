#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
using namespace std;


int rows, columns, xEntry, yEntry, xExit, yExit;
int** matrixLabirinth;

struct Punct {
	int x, y;
}*road;

void labirinth(int x, int y, int steps) {
	//cazul in care suntem la iesire (cazul trivial) printam drumul pe care l-am parcurs
	if (x == xExit && y == yExit) {
		printf("Lungimea drumului: %d trece prin:", steps + 1);
		for (int i = 0; i < steps; ++i) {
			printf("(%d,%d), ", road[i].x, road[i].y);
		}
		printf("(%d,%d)\n\n", xExit, yExit);
	}
	//altcumva, daca tocmai am intrat intr-o camera
	else if(matrixLabirinth[x][y]==0) {
		//stocam sau suprascriem pasul facut
		road[steps].x = x;
		road[steps].y = y;

		matrixLabirinth[x][y] = 1;

		labirinth(x + 1, y, steps + 1);
		labirinth(x, y + 1, steps + 1);
		labirinth(x - 1, y, steps + 1);
		labirinth(x, y - 1, steps + 1);

		matrixLabirinth[x][y] = 0;
	}
	//daca nu am intrat intr-o camera, algoritmul nu face nimic, pentru ca am dat cu capu de perete si am ramas lati pe jos
	//chiar ma plictisesc deja, se vede?
}

int main() {
	//declarari si initializari
	FILE* file1 = fopen("Labirint.txt", "r");
	(void)fscanf(file1, "%d%d%d%d%d%d", &rows, &columns, &xEntry, &yEntry, &xExit, &yExit);
	road = new Punct[rows * columns];
	matrixLabirinth = new int* [rows + 2];
	for (int i = 0; i < rows + 2; ++i) {
		matrixLabirinth[i] = new int[columns + 2];
	}
	for (int i = 1; i <= rows; ++i) {
		for (int j = 1; j <= columns; ++j) {
			(void)fscanf(file1, "%d", &matrixLabirinth[i][j]);
		}
	}

	//vine nea Dorel sa zideasca exteriorul
	for (int i = 0; i < rows + 2; ++i) {
		matrixLabirinth[i][0] = matrixLabirinth[i][columns + 1] = -1;
	}
	for (int j = 0; j < columns + 2; ++j) {
		matrixLabirinth[0][j] = matrixLabirinth[rows + 1][j] = -1;
	}

	labirinth(xEntry, yEntry, 0);

	fclose(file1);
	delete[] road;
	for (int i = 0; i < rows + 2; ++i) {
		delete[] matrixLabirinth[i];
	}
	delete[] matrixLabirinth;
	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}