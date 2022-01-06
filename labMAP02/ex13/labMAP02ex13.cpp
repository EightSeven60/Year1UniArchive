#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

typedef short(*friendTest_p)(const short, const short);
//void friendNumbers(const short flowEnd, const short fhighEnd, short* fnrPartner1, short* fnrPartner2, friendTest_p ffriendTest)
//friendNumbers(lowEnd, highEnd, &nrPartner1, &nrPartner2, friendTest);

void friendNumbers(const short flowEnd, const short fhighEnd, short* fnrPartner1, short* fnrPartner2, friendTest_p ffriendTest) {
	short max;
	bool gasit = 0;
	for (max = flowEnd; max < fhighEnd; ++max) {
		for (short i = flowEnd; i < max; ++i) {
			for (short j = flowEnd; j < max; ++j) {
				if (ffriendTest(i, j)) {
					*fnrPartner1 = i;
					*fnrPartner2 = j;
					gasit = 1;
					goto Acolo;
				}
			}
		}
	}

Acolo:
	printf("Gata!\n");
}
short friendTest(const short firstNumber, const short secondNumber) {
	short firstDivSum = 0, secondDivSum = 0;
	for (int i = 1; i < ((max(firstNumber, secondNumber)) + 3) / 2; ++i) {
		if (firstNumber % i == 0) {
			firstDivSum += i;
		}
		if (secondNumber % i == 0) {
			secondDivSum += i;
		}
	}
	if (firstDivSum == secondNumber && secondDivSum == firstNumber) {
		return 1;
	}
	else return 0;
}

int main()
{
	srand(time(NULL));
	short lowEnd, highEnd, nrPartner1 = 0, nrPartner2 = 0;

	printf("Enter lower limit of interval.\n");
	(void)scanf("%hd", &lowEnd);
	(void)getchar();
	printf("Enter higher limit of interval.\n");
	(void)scanf("%hd", &highEnd);
	(void)getchar();

	friendNumbers(lowEnd, highEnd, &nrPartner1, &nrPartner2, friendTest);
	//bine ca nu fac restul de exercitii cu functii in functii dar fac aici functii in functii lol
	//it's big brain time
	//mai am 100 de exercitii si imediat trebuie sa predau exercitiile so I'll go to heck now brb
	if (nrPartner1) printf("Numere prietene: %hd, %hd.\n", nrPartner1, nrPartner2);
	else printf("N-am gast domnu'!\n");

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}