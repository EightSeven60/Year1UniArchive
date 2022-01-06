/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int n;
	int* m = &n;
	printf("n = ");
	(void)scanf("%d", &n);
	printf("%d\n", n);
	printf("%d\n", &n);
	printf("%d\n", m);
	printf("%d\n", &m);
	return 0;
}
*/
//&n si m sunt exact aceleasi deoarece reprezinte ambele adresa variabilei n
//&m este adresa la care este stocata adresa lui n adica &n