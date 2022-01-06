#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
	int* vector = new int[100];
	vector[34] = 34;
	vector[0] = 0;
	//vector[100] = 100;
	printf("%d %d\n", vector[0], vector[34]);
	return 0;
}