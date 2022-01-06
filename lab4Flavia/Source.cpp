#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
	int a, b, c, delta;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	delta = b * b - 4 * a * c;
	printf("delta=%lf\n", delta);
	if (delta < 0)
		printf("nu are solutii reale");
	else if (delta = 0)
	{
		printf("x1=%lf", (-b / 2 * a));
	}
	else if (delta > 0)
	{
		printf("x1=%lf", (-b + sqrt(delta) / 2 * a));
		printf("x2=%lf", (-b - sqrt(delta) / 2 * a));
	}
	
	return 0;


}