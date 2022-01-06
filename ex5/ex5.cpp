#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

float arie(float fn)
{
	return fn * fn;
}

int main()
{
	float n;
	char i;
	for (i = 0; i < 3; ++i)
	{
		printf("n = ");
		(void)scanf("%f", &n);
		getchar();
		printf("aria: %g\n", arie(n));
	}
	getchar();
	return 0;
}