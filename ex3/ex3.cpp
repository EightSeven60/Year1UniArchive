#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

void div(unsigned int fn)
{
	unsigned int i;
	if (fn != 0) printf("divizori : ");
	else printf("0 nu are divizori.");
	for (i = 1; i <= fn; ++i)
	{
		if (fn % i == 0) printf("%d ", i);
	}
	printf("\n");
}

int main()
{
	unsigned int n, i;
	for (i = 0; i < 3; ++i)
	{
		printf("n = ");
		(void)scanf("%d", &n);
		getchar();
		div(n);
	}
	getchar();
	return 0;
}