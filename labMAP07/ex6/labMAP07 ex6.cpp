#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

//asta e probabil cel mai prost algoritm pe care l-am scris in toata viata mea
//daca primeste mai mult de 30 de numere ia mai mult timp sa termine decat mine la baie cu telefonul
//dar e recursiv :-D
int findMaxRec(int *A, int n) {
    if (n == 1)
        return A[0];
    return max(A[n - 1], findMaxRec(A, n - 1));
}
int main()
{
    srand(time(NULL));
    const unsigned vSize = 10;
    int vector[vSize];
    for (int i = 0; i < vSize; ++i) {
        vector[i] = rand();
    }

    printf("Maximul: %d.\n", findMaxRec(vector, vSize));

    printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
    (void)getchar();
    return 0;
}