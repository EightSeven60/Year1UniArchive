#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 257; ++i) {
		SetConsoleTextAttribute(hConsole, i);
		printf("%d: I'm gay.\n", i);
	}
	return 0;
}