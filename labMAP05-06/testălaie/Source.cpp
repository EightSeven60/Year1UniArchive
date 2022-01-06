#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
using namespace std;

int main()
{
	int* v = (int*)malloc(sizeof(int));
	v = (int*)realloc(v, 1 * sizeof(int));
	v[0] = 24;
	v = (int*)realloc(v, 2 * sizeof(int));
	v[1] = 69;
	v = (int*)realloc(v, 3 * sizeof(int));
	v[2] = 169;
	v[3] = -12;
	v[4] = 265;

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}