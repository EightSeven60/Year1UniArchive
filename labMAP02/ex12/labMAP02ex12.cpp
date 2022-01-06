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
	char randNr, positiveVector[256], negativeVector[256];
	short iPositive = 0, iNegative = 0;
	int aux;

	while (iPositive < 256 && iNegative < 256) {
		randNr = rand();
		if (!randNr) {
			break;
		}
		else if (randNr > 0) {
			positiveVector[iPositive] = randNr;
			++iPositive;
		}
		else if (randNr < 0) {
			negativeVector[iNegative] = randNr;
			++iNegative;
		}
	}
	if (iPositive > 255) {
		printf("Maximum positive vector capacity reached!\n");
	}
	else if (iNegative > 255) {
		printf("Maximum negative vector capacity reached!\n");
	}

	for (int i = 0; i < iPositive; ++i) {
		for (int j = 0; j < iPositive; ++j) {
			if (positiveVector[i] < positiveVector[j]) {
				positiveVector[i] += positiveVector[j];
				positiveVector[j] = positiveVector[i] - positiveVector[j];
				positiveVector[i] -= positiveVector[j];
			}
		}
	}

	for (int i = 0; i < iNegative; ++i) {
		for (int j = 0; j < iNegative; ++j) {
			if (negativeVector[i] < negativeVector[j]) {
				negativeVector[i] += negativeVector[j];
				negativeVector[j] = negativeVector[i] - negativeVector[j];
				negativeVector[i] -= negativeVector[j];
			}
		}
	}

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c", 12, 693, 248, 32468, -235, -3427, 238, 18231, -348, -12);
	(void)getchar();
	return 0;
}