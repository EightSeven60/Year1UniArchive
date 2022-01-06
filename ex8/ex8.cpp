#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

unsigned int vocale(char fsir[64])
{
	unsigned char i, v = 0;
	for (i = 0; i < 64; ++i)
	{
		if (fsir[i] == 'A' || fsir[i] == 'a' || fsir[i] == 'E' || fsir[i] == 'e' || fsir[i] == 'I' || fsir[i] == 'i' || fsir[i] == 'O' || fsir[i] == 'o' || fsir[i] == 'U' || fsir[i] == 'u')
		{
			++v;
		}
	}
	return v;
}

int main()
{
	char sir[64];
	gets_s(sir);
	//puts(sir);
	printf("vocale : %u", vocale(sir));
	getchar();
	return 0;
}