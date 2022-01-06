#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

int euclid(int x, int y) {
	int temp;
	while (y != 0) {
		temp = y;
		y = x % y;
		x = temp;
	}
	return x;
}
int euclidRecursive(int x, int y) {
	if (y == 0) return x;
	else return euclidRecursive(y, x % y);
}


int main()
{
	srand(time(NULL));
	printf("%d\n", euclidRecursive(200, 75));

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}