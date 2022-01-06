#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

//nu stiam daca trebuia sa verific daca litera introdusa e vreuna din literele introduse anterior sau ultima introdusa anterior, am facut a doua varianta.
//pentru prima varianta, trebuia doar sa folosesc un loop pentru a verifica intregul vector cu maximul i + 1 (cred) la verificare
//probabil faceam o functie separata pentru asta pe care o puneam in if() dinainte de goto
int main()
{
	srand(time(NULL));
	char c1 = 0, c2 = 1, charV[64], i = 0, j = 0, marimeV;

	Aici:
	c2 = c1;
	printf("Enter a letter: ");
	(void)scanf("%c", &c1);
	(void)getchar();
	charV[i] = c1;
	++i;
	if (c1 != c2) goto Aici;

	charV[i - 1] = 0;
	marimeV = i;

	for (i = 0; i < marimeV; ++i) {
		for (j = 0; j < marimeV; ++j) {
			if (charV[i] > charV[j]) {
				charV[i] += charV[j];
				charV[j] = charV[i] - charV[j];
				charV[i] -= charV[j];
			}
		}
	}

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}