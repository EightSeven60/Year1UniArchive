//am facut cu float deoarece nu se specifica faptul ca valorile sunt intregi sau naturale

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

void fGrad2(float fa, float fb, float fc)
{
	float delta = pow(fb, 2) - 4 * fa * fc, x1, x2;
	printf("%g\n", delta);
	if (delta >= 0)
	{
		x1 = (-fb + sqrt(delta)) / (2 * fa);
		x2 = (-fb - sqrt(delta)) / (2 * fa);
		printf("x1 = %g\nx2 = %g\n", x1, x2);
	}
	else printf("delta < 0\n");
}

int main()
{
	float a = 0, b = 0, c = 0;
	char i;
	for (i = 0; i < 3; ++i)
	{
		printf("Daca functia de gradul II arata asa: ax^2 + bx + c = 0\nIntroduceti\na = ");
		(void)scanf("%f", &a);
		getchar();
		printf("b = ");
		(void)scanf("%f", &b);
		getchar();
		printf("c = ");
		(void)scanf("%f", &c);
		getchar();
		fGrad2(a, b, c);
	}
	getchar();
	return 0;
}