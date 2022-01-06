#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

void fibo(unsigned int fn)
{
	unsigned int a = 0, b = 1, i;
	if(fn > 0) printf("%d ", a);
	if (fn > 1) printf("%d ", b);
	for (i = 0; i < fn; ++i)
	{
		if (i % 2 == 0)
		{
			a = a + b;
			printf("%d ", a);
		}
		else
		{
			b = a + b;
			printf("%d ", b);
		}
	}
	printf("\n");
}

int main()
{
	unsigned int n, i;
	for (i = 0; i < 4; ++i)
	{
		printf("n = ");
		(void)scanf("%d", &n);
		getchar();
		fibo(n);
	}
	getchar();
	return 0;
}