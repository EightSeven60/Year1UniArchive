#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

void numberGuess(const char min, const char max) {
	char c;
	printf("%hhd?\n", (max + min) / 2);
	(void)fscanf(stdin, "%c", &c);
	(void)getchar();
	if (c == 'y') {
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3);
	}
	else if (c == '<') {
		numberGuess(min, (max + min) / 2);
	}
	else if (c == '>') {
		numberGuess((max + min) / 2, max);
	}
	else {
		printf("Talk properly next time ples thx %c.\n", 3);
	}
}
//zici ca e binary search cu atitudine

int main()
{
	srand(time(NULL));
	printf("Enter 'y' to confirm, '<' to say \"smaller\" or '>' to say \"larger\".\n");
	numberGuess(1, 100);

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}

//m-am plictisit de recursivitate...continui labMAP08 cu timpul pe care il mai am...