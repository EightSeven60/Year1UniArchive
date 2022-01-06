#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

int ordonarenumere(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* ordinecrescatoare(int n, ...) {
    int numere[100];
    va_list elemente;
    va_start(elemente, n);
    for (short i = 0; i < n; ++i) {
        numere[i] = va_arg(elemente, int);
    }
    qsort(numere, n, sizeof(int), ordonarenumere);
    cout << "Numerele in ordine crescatoare sunt:";
    for (short i = 0; i < n; ++i) {
        cout << ' ' << numere[i];
    }
    va_end(elemente);
    cout << endl;
    return 0;
}

int main() {
    //timp executie program
    clock_t timpinitial, timpfinal;
    timpinitial = clock();

    srand(time(NULL));
    short condor = rand() % (100 - 5 + 1) + 5;
    if (condor > 100) condor = 100;
    else if (condor < 5) condor = 5;
    short vector[100];

    for (short j = 0; j < condor; ++j) {
        vector[j] = rand() % (100 - 0 + 1) + 0;
    }

    ordinecrescatoare(5, vector[0], vector[1], vector[2], vector[3], vector[4]);
    if (condor >= 15) ordinecrescatoare(10, vector[5], vector[6], vector[7], vector[8], vector[9], vector[10], vector[11], vector[12], vector[13], vector[14]);
    if (condor >= 25) ordinecrescatoare(10, vector[15], vector[16], vector[17], vector[18], vector[19], vector[20], vector[21], vector[22], vector[23], vector[24]);
    if (condor >= 55) ordinecrescatoare(10, vector[45], vector[46], vector[47], vector[48], vector[49], vector[50], vector[51], vector[52], vector[53], vector[54]);
    if (condor >= 75) ordinecrescatoare(10, vector[65], vector[66], vector[67], vector[68], vector[69], vector[70], vector[71], vector[72], vector[73], vector[74]);

    //timp executie
    timpfinal = clock();
    cout << endl << "Executia programului a durat: " << (double)((timpfinal - timpinitial) / CLOCKS_PER_SEC) << endl;

    return 0;
}