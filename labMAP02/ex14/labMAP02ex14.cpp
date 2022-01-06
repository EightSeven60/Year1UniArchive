#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	short nrCitit = -32768, lowEnd, highEnd;
	
	printf("Enter lower limit: ");
	(void)scanf("%hd", &lowEnd);
	(void)getchar;
	printf("Enter upper limit: ");
	(void)scanf("%hd", &highEnd);
	printf("\n");
	(void)getchar();

	Dincolo:
	printf("Enter a number: ");
	(void)scanf("%hd", &nrCitit);
	(void)getchar();
	if (nrCitit < lowEnd || nrCitit > highEnd) goto Dincolo;

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}