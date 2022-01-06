#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
using namespace std;

int compara_int(const void* a, const void* b)
{
	//return ( *(int*)a - *(int*)b );
	if (*(int*)a < *(int*)b) return -1;
	else if (*(int*)a == *(int*)b) return 0;
	else return 1;
}
int compara_float(const void* a, const void* b)
{
	float dif = (*(float*)a - *(float*)b);
	if (dif > 0) return 1;
	else if (dif == 0) return 0;
	else return -1;

}
typedef int (*TIP_PF)(const void*, const void*);
void* cautareSecventiala(const void* adrCheie, const void* adrBaza, size_t nrel, size_t dimElement, TIP_PF functieComparare) {
	for (unsigned i = 0; i < nrel; ++i) {
		char* adrElement = (char*)adrBaza + dimElement * i;
		//adresa celui de al i-lea element
		if (functieComparare(adrCheie, adrElement) == 0)
			return adrElement;//exista si revin in main
	}
	return NULL;//nu exista
}

int main()
{
	srand(time(NULL));

	int x = -10;
	float f = 5.2;
	unsigned u = 3;
	char c = 'a';
	char* propozitie[32];


	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}