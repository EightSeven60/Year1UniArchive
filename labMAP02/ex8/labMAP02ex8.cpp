#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

union numar {
	short nr;
	char byte[2];
};

//am facut din greseala fara a folosi union si functie separata....il las comentat aici, macar sa se vada cu ce am pierdut vremea :-)))
/*
int main()
{
	short x, y;
	long long binx = 0, biny = 0, mul = 1;
	char byte1, byte2, i, ix = 0, iy = 0;
	printf("Introduceti un numar: ");
	(void)scanf("%hd", &x);
	byte1 = (char)x;
	byte2 = x >> 8;
	printf("numar: %hd\n", x);
	printf("byte1: %hhd\n", byte1);
	printf("byte2: %hhd\n\n", byte2);
	y = byte1;
	y = y << 8;
	y = y | byte2;
	printf("Nr inversat: %hd\n", y);
	while (x != 0) {
		binx = binx + (x % 2) * mul;
		mul = mul * 10;
		x = x / 2;
	}
	mul = 1;
	while (y != 0) {
		biny = biny + (y % 2) * mul;
		mul = mul * 10;
		y = y / 2;
	}
	printf("Numarul initial in baza 2: %lld\n", binx);
	printf("Numarul inversat in baza 2: %lld\n", biny);
	(void)getchar();
	return 0;
}
*/

void inversare2byte(numar* fx) {
	char aux;
	aux = fx->byte[0];
	fx->byte[0] = fx->byte[1];
	fx->byte[1] = aux;


}

int main()
{
	numar x, y;
	long long binx = 0, biny = 0, mul = 1;

	printf("Introduceti un numar: ");
	(void)scanf("%hd", &x.nr);
	(void)getchar();

	printf("numar: %hd\n", x.nr);
	printf("byte1: %hhd\n", x.byte[0]);
	printf("byte2: %hhd\n", x.byte[1]);
	y = x;
	while (x.nr != 0) {
		binx = binx + (x.nr % 2) * mul;
		mul = mul * 10;
		x.nr = x.nr / 2;
	}
	printf("Numarul initial in baza 2: %lld\n\n", binx);

	x = y;
	inversare2byte(&x);

	printf("Nr inversat: %hd\n", x.nr);
	printf("byte1: %hhd\n", x.byte[0]);
	printf("byte2: %hhd\n", x.byte[1]);
	y = x;
	mul = 1;
	binx = 0;
	while (x.nr != 0) {
		binx = binx + (x.nr % 2) * mul;
		mul = mul * 10;
		x.nr = x.nr / 2;
	}
	printf("Numarul inversat in baza 2: %lld\n\n", binx);

	x = y;
	inversare2byte(&x);

	printf("Nr inversat: %hd\n", x.nr);
	printf("byte1: %hhd\n", x.byte[0]);
	printf("byte2: %hhd\n", x.byte[1]);
	y = x;
	mul = 1;
	binx = 0;
	while (x.nr != 0) {
		binx = binx + (x.nr % 2) * mul;
		mul = mul * 10;
		x.nr = x.nr / 2;
	}
	printf("Numarul inversat in baza 2: %lld\n", binx);

	(void)getchar();
	return 0;
}