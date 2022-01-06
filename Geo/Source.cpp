#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

void citire(int* n, int* m, int** matrice)
{

    cout << "Introduceti valoarea lui n = ";
    cin >> *n;
    cout << "Introduceti valoarea lui m = ";
    cin >> *m;
    if (*n > 20 || *m > 20 || *n < 0 || *m < 0)
    {
        cout << '\n' << "Valorle date nu sunt corespunzatoare";
    }
    cout << "Introduceti elementele matricei" << '\n';
    for (int i = 0; i < *n; ++i)
    {
        for (int j = 0; j < *m; ++j)
        {
            cout << "matrice[" << i << "][" << j << "]";
            cin >> matrice[i][j];
        }
    }

}
int main()
{
    int n, m, matrice[20][20];
    int matrice1[100][100];
    citire(&n, &m, matrice);

    return 0;
}