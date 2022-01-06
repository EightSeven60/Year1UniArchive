#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
using namespace std;

struct stracciar {
	int whole;
	short half;
};

void printAll(int input_size, ...);

int main()
{
	stracciar cristos[2];
	cristos[0].whole = 69;
	cristos[0].half = 3;
	cristos[1].whole = 420;
	cristos[1].half = 8;
	swap(cristos[0], cristos[1]);
	printAll(2, cristos[0], cristos[1]);
	return 0;
}


void printAll(int input_size, ...) {
	stracciar* vector = (stracciar*)(&input_size + 1);
	for (int i = 0; i < input_size; ++i) {
		printf("Structura numaru #%d:\nWhole: %d\nHalf: %hd\n\n", i, vector[i].whole, vector[i].half);
	}
}