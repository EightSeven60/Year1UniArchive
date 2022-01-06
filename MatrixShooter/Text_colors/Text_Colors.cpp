#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// you can loop k higher to see more color choices
int main() {
    for (int k = 1; k < 255; k++)
    {
       // pick the colorattribute k you want
      SetConsoleTextAttribute(hConsole, k);
       cout << k << " I want to be nice today!" << endl;
    }
    (void)getchar();
}