#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

struct person {
	char age;
	char name[20];
	char birth[20];
};
struct point {
	short x, y, z;
};

union number {
	short nr;
	char byte[2];
};

int main() 
{
	point A, B, C;
	A.x;
	return 0;
}