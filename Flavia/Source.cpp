#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
/*
int main()
{
	int x;
	char f;
	printf("numar intreg de 4 cifre\n");
	scanf("%d", &x);
	printf("1. paritate ultima cifra \n");
	printf("2. paritate prima cifra \n");
	printf("3. suma cifrelor\n");
	printf("4. numar rezultat dupa inserare\n");
	getchar();
	scanf("%c", &f);
	switch (f)
	{
	case '1':
		x = (x % 10);
		if (x % 2 == 0)
			printf(" ultima cifra para\n");
		else printf("ultima cifra impara\n");
		break;
	case '2':
		x = (x / 1000);
		if (x % 2 == 0)
			printf("prima cifra para\n");
		else printf("prima cifra impara\n");
		break;
	case '3':
		int a = x / 1000;
		int b = (x % 1000) / 100;
		int c = (x % 100) / 10;
		int d = x % 10;
		x = a + b + c + d;
		printf("suma cifrelor%d", x);
		break;

	}
	return 0;
}
*/
/*
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <math.h>
int main()
{
	int i, E = 1, n, x = 1, Factorial = 1, A;
	scanf_s("%d %d", &n, &x);
	for (i = 1; i <= n; i++)
	{
		x = x * n;
		Factorial = Factorial * i;
		E = E + (x / Factorial);
	}
	A = E - exp(x);
	printf("%d", A);
	return 0;
}
*/
/*
int main()
{
	int i, y = 0, a, b, z = 1, Numarul = 0, ultimacifra = 0, rasturnat = 0;
	for (i = 0; i <= 9999; i++)
	{
		b = i;
		do
		{
			a = b % 10;
			y = y + a;
			z = z * a;
			b = b / 10;
		} while (b);
		if (z != 0)
		{
			if (i % y == 0 && i % z == 0)
			{
				printf(" %d ", i);
			}
		}

	}
	return 0;
}
*/
/*
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
int main()
{
	int n, a, b, c;
	scanf_s("%d", &n);
	getchar();
	for (c = 1; c <= n; ++c) {
		for (b = c + 1; b <= n; ++b) {
			for (a = b + 1; a <= n; ++a) {
				if ((a * a) == (b * b + c * c)) {
					printf("a=%d\n", a);
					printf("b=%d\n", b);
					printf("c=%d\n", c);
					printf("\n");
				}
			}
		}
	}
	getchar();
	return 0;
}
*/
/*
int main()
{
	int n, x, y, z;
	printf("n = ");
	scanf("%d", &n);
	for (z = 1; z < n; ++z) {
		for (y = z + 1; y < n; ++y) {
			for (x = y + 1; x < n; ++x) {
				if ((x * x) == (y * y) + (z * z)) {
					printf("%d %d %d\n", x, y, z);
				}
			}
		}
	}
	getchar();
	return 0;
}
*/
/*
void unu()
{
	unsigned short numar;
	printf("----------------------------------------\n");
	printf("Introduceti un numar de la tastatura: ");
	scanf_s("%hu", &numar);
	unsigned short masca;
	masca = (1 << 3);     //binar: 0000 0001 devine 0000 0100

	printf("----------------------------------------\n");
	if ((numar & masca) != 0)     //operatie binara
		printf("Bitul \"3\" este 1");
	else printf("Bitul \"3\" este 0");
	printf("\n----------------------------------------\n");

	if (numar & 1)
		printf("Bitul de paritate este 1");
	else printf("Bitul de paritate este 0");
	printf("\n----------------------------------------\n");

	unsigned short masca2 = ~(1 << 2), rezultat;
	rezultat = (numar & masca2);
	printf("Resetare bit (k=2): %d", rezultat);

	printf("\n----------------------------------------\n");
	masca2 = (1 << 4);
	rezultat = (numar | masca2);
	printf("Setare bit (k=4): %d", rezultat);
	printf("\n----------------------------------------\n");
	//return 0;
}
*/
/*
void main()
{
	unsigned short numar;
	printf("----------------------------------------------\n");
	printf("Introduceti un numar de la tastatura: ");
	scanf_s("%hu", &numar);

	unsigned short masca, rezultat;
	short i;
	printf("----------------------------------------------\n");
	for (i = 0; i < ((sizeof(numar) * 8)); ++i)
	{
		masca = (1 << i);
		if ((numar & masca) != 0) printf("Bitul %hu este: 1 \n", i);
		else printf("Bitul %hu este: 0 \n", i);
	}
	printf("----------------------------------------------\n");
	for (i = ((sizeof(numar) * 8) - 1); i > -1; --i)
	{
		masca = (1 << i);
		if ((numar & masca) != 0) printf("1 ");
		else printf("0 ");
	}
	printf("\n----------------------------------------------\n");
	//return 0;
}
*/
/*
void main()
{
	unsigned short numar;
	printf("----------------------------------------------\n");
	printf("Introduceti un numar de la tastatura: ");
	scanf_s("%hu", &numar);
	printf("----------------------------------------------\n");

	unsigned short masca;
	masca = (1 << 2);
	//22 devine 54
	if ((numar & masca) != 0)
	{
		masca = (1 << 5);
		numar = (numar | masca);
		printf("Rezultatul satari bit 5 este: %hu", numar);
	}
	//128 devine 0
	else if ((numar & masca) != 1)
	{
		masca = ~(1 << 7);
		numar = (numar & masca);
		printf("Rezultatul resetari bit 7 este: %hu", numar);
	}
	printf("\n----------------------------------------------\n");
	//return 0;
}
*/

//      | &
//0 0   0 0
//0 1   1 0
//1 0   1 0
//1 1   1 1

/*
void main()
{
	unsigned int n;
	printf("----------------------------------------------\n");
	printf("Introduceti un numar de la tastatura: ");
	scanf_s("%u", &n);
	printf("----------------------------------------------\n");
	char m;

	printf("Introduceti un numar de la tastatura: ");
	scanf_s(" %c", &m);
	printf("----------------------------------------------\n");
	unsigned int masca1, masca2;
	masca1 = (1 << ((sizeof(m) * 8) - 1));
	unsigned int rezultat1;
	rezultat1 = (m | masca1);
	printf("Setarea bitul al m-lea pe 1 este: %u \n", rezultat1);
	printf("----------------------------------------------\n");

	unsigned int rezultat2;
	masca2 = ~(1 << (((sizeof(n) * 8) - 1) - ((sizeof(m) * 8) - 1)));
	rezultat2 = (n & masca2);
	printf("Setarea bitul al m-lea pe 1 este: %u \n", rezultat2);
	printf("----------------------------------------------\n");
	//return 0;
}
*/
/*
int main()
{
	char prop[10000];
	unsigned int cuv[256] = { 0 };
	printf("Scrieti o propozitie.\n");
	gets_s(prop);
	printf("%s\n", prop);
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 10000; ++j) {
			if (prop[j] == i) ++cuv[i];
		}
	}
	for (int i = 0; i < 256; ++i) {
		if (cuv[i]) printf("Caracterul '%c' apare de %u ori.\n", i, cuv[i]);
	}
	return 0;
}
*/

//EX1

/*
int main()
{
	unsigned short a, masca = ~(1<<3);
	printf("Introduceti un numar natural.\n");
	(void)scanf("%d", &a);
	getchar();
	a = a & masca;
	printf("Numarul dupa setarea celui de-al 4-lea bit pe 0 este:\n");
	for (int i = 0; i < sizeof(a) * 8; ++i) {
		printf("%d", (a & (1 << i)) >> i);
	}
	return 0;
}
*/

//EX2

/*
int main()
{
	unsigned short a;
	printf("Introduceti un numar natural.\n");
	(void)scanf("%hd", &a);
	getchar();
	for (int i = 0; i < 16; ++i) {
		printf("%hd", (a & (1 << i)) >> i);
	}
	return 0;
}
*/

//EX3

/*
int main()
{
	int a;
	printf("Introduceti un intreg.\n");
	(void)scanf("%d", &a);
	getchar();
	if (((a & (1 << 1)) << 30) >> 31) {
		a = a | (1 << 4);
	}
	else {
		a = a & 4294967231;
	}
	for (int i = 0; i < 32; ++i) {
		printf("%d", (a & (1 << i)) >> i);
	}
	//printf("%d", sizeof(int));
	return 0;
}
*/

//EX4

/*
int main()
{
	unsigned int n;
	unsigned char m;
	printf("Introduceti doua numere naturale.\nn = ");
	(void)scanf("%u", &n);
	getchar();
	printf("m = ");
	(void)scanf("%hhu", &m);
	getchar();
	n = (n | (1 << m));
	n = (n & ~(1 << (31 - m)));
	//printf("%u\n", n);
	//printf("%hhu\n", m);
	for (int i = 31; i > -1; --i) {
		printf("%u", (n & (1 << i)) >> i);
	}
	printf("\nBitul 31 se afla la dreapta.\n");
	return 0;
}
*/
//    ^
//0 0 0
//0 1 1
//1 0 1
//1 1 0

//EX5

/*
int main()
{
	short a, x;
	printf("Introduceti a = ");
	(void)scanf("%hd", &a);
	//x = (a & (1 << 15)) >> 15;
	printf("Binar initial:\n");
	for (int i = 0; i < 16; ++i) {
		printf("%hd", (a & (1 << i)) >> i);
	}
	printf("\nBitul 31 se afla la dreapta.\n");
	a = ((a >> 1) << 1) | ((a & (1 << 15)) >> 15) | ((a & 1) << 15);
	printf("%hd\nBinar final:\n", a);
	for (int i = 0; i < 16; ++i) {
		printf("%hd", (a & (1 << i)) >> i);
	}
	printf("\nBitul 31 se afla la dreapta.\n");
	return 0;
}
*/

//EX6

/*
int main()
{
	unsigned int m;
	unsigned char n;
	printf("Introduceti un numar natural.\nn = ");
	(void)scanf("%hhd", &n);
	printf("Pe cati biti sa se roteasca?\nm = ");
	(void)scanf("%u", &m);
	for (int i = 1; i <= m; ++i) {
		n = (n << 1) | (((1 << 7) & n) >> 7);
	}
	for (int i = 0; i < 8; ++i) {
		printf("%hhd", (n & (1 << i)) >> i);
	}
	return 0;
}
*/

//EX7

/*
int main()
{
	unsigned char n, i, s = 0;
	printf("Introduceti un numar natural.\nn = ");
	(void)scanf("%hhd", &n);
	for (i = 0; i < 8; ++i) {
		s = s + (((1 << i) & n) >> i);
	}
	printf("Suma este %hhd.", s);
	return 0;
}
*/

//EX8

/*
int main()
{
	unsigned char n, i, s = 0;
	printf("Introduceti un numar natural.\nn = ");
	(void)scanf("%hhd", &n);
	for (i = 0; i < 8; i += 2) {
		s = s + (((1 << i) & n) >> i);
	}
	printf("Exista %hhd biti egali cu 1 pe pozitii pare.\n", s);
	return 0;
}
*/

//EX9

/*
int main()
{
	unsigned char n, i, s = 0;
	printf("Introduceti un numar natural.\nn = ");
	(void)scanf("%hhd", &n);
	for (i = 1; i < 8; i += 2) {
		if ((((1 << i) & n) >> i) == 0) ++s;
	}
	printf("Exista %hhd biti egali cu 0 pe pozitii impare in numar.\n", s);
	return 0;
}
*/

//EX10

/*
int main()
{
	unsigned char n = 1, m;
	printf("(Fiecare ciclu tine 8 secunde)\nCicluri: ");
	(void)scanf("%hhd", &m);
	getchar();
	system("cls");
	for (int i = 0; i < 8; ++i) {
		printf("%hhd", (n & (1 << i)) >> i);
	}
	Sleep(1000);
	system("cls");
	for (int i = 1; i <= m * 8; ++i) {
		n = (n << 1) | (((1 << 7) & n) >> 7);
		for (int i = 0; i < 8; ++i) {
			printf("%hhd", (n & (1 << i)) >> i);
		}
		Sleep(1000);
		system("cls");
	}
	return 0;
}
*/

//EX11

/*
int main()
{
	unsigned char n = 129;
	unsigned int m, c;
	printf("Introduceti intarzierea in ms: ");
	(void)scanf("%u", &m);
	printf("Cicluri: ");
	(void)scanf("%u", &c);
	getchar();
	system("cls");
	while (c > 0) {
		for (int i = 0; i < 8; ++i) {
			printf("%hhd", (n & (1 << i)) >> i);
		}
		Sleep(m);
		system("cls");
		for (int i = 0; i < sizeof(unsigned char) * 7; ++i) {
			n = (((1 << 7 - i) & n) >> 1) | (((1 << i) & n) << 1);
			for (int i = 0; i < 8; ++i) {
				printf("%hhd", (n & (1 << i)) >> i);
			}
			Sleep(m);
			system("cls");
		}
		--c;
	}

	return 0;
}
*/

//LAB9

//EX1

/*
int main()
{
	char prop[10000], cuv[256] = { 0 };
	printf("Scrieti o propozitie.\n");
	gets_s(prop);
	printf("%s\n", prop);
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 10000; ++j) {
			if (prop[j] == i) ++cuv[i];
		}
	}
	for (int i = 0; i < 256; ++i) {
		if (cuv[i]) printf("Caracterul '%c' apare de %hhd ori.\n", i, cuv[i]);
	}
	return 0;
}
//Stiu ca puteam face cu strlen si doar un for mai eficient, dar ma grabesc sa termin ca nu mai am timp xD
*/

//EX2

/*
int main()
{
	char prop[1024];
	int n, i = 0, j;
	unsigned char palindrom = 1;
	char c1, c2;
	printf("Introduceti propozitia:\n");
	gets_s(prop, 1024);
	//printf("S-a citit propozitia:\n%s\n", prop);
	n = strlen(prop);
	j = n - 1;
	while (i < j) {
		//Extragere c1
		while ((prop[i] == ' ' || prop[i] == '.') && i < n) ++i;
		if (i >= n) break;
		c1 = prop[i];
		//Extragere c2
		while ((prop[j] == ' ' || prop[j] == '.') && j >= 0) --j;
		if (j < 0) break;
		c2 = prop[j];
		//Transformare
		if (c1 >= 'A' && c1 <= 'Z')
			c1 = c1 + 32;
		if (c2 >= 'A' && c2 <= 'Z')
			c2 = c2 + 32;
		//Compararea
		if (c1 != c2) {
			palindrom = 0;
			break;
		}
		//Trecere la caracterul urmator
		i++;
		j--;
	}
	if (palindrom) {
		printf("Sirul este palindrom\n");
	}
	else {
		printf("Sirul nu este palindrom\n");
	}
}
*/

//EX3

/*
//Fara sir de caractere
int main()
{
	int a[50] = { 0 }, b[50] = { 0 }, i, n1, n2, c[51], t, n3;
	printf("Cate cifre are primul numar?\nn1 = ");
	(void)scanf("%d", &n1);
	printf("Cate cifre are al doilea numar?\nn2 = ");
	(void)scanf("%d", &n2);
	if (n1 > n2) n3 = n1 + 1;
	else n3 = n2 + 1;
	//Citire nr1
	printf("Introduceti cifrele primului numar separate de Enter.\n");
	for (i = 50 - n1; i < 50; ++i) {
		(void)scanf("%d", &a[i]);
	}
	printf("Primul numar este:\n");
	for (i = 50 - n1; i < 50; ++i) {
		printf("%d", a[i]);
	}
	printf("\n");

	//Citire nr2
	printf("Introduceti cifrele celui de-al doilea numar separate de Enter.\n");
	for (i = 50 - n2; i < 50; ++i) {
		(void)scanf("%d", &b[i]);
	}
	printf("Al doilea numar este:\n");
	for (i = 50 - n2; i < 50; ++i) {
		printf("%d", b[i]);
	}
	printf("\n");

	//Adunare
	t = 0;
	for (i = 50; i > 50 - n3; --i) {
		c[i] = ((a[i - 1] + b[i - 1]) + t) % 10;
		t = ((a[i - 1] + b[i - 1]) + t) / 10;
	}
	c[i] = t;
	//Printare suma
	printf("Suma este:\n");
	for (i = 50 - n3 + 1; i < 51; ++i) {
		printf("%d", c[i]);
	}
	printf("\n");
	return 0;
}
*/

/*
//Cu sir de caractere
int main()
{

	int a[50] = { 0 }, b[50] = { 0 }, i, n1, n2, c[51], t, n3;
	char x[50], y[50];
	//Citire nr1
	printf("Introduceti primul numar.\na = ");
	gets_s(x);
	n1 = strlen(x);
	//Citire nr2
	printf("Introduceti al doilea numar.\nb = ");
	gets_s(y);
	n2 = strlen(y);
	if (n1 > n2) n3 = n1 + 1;
	else n3 = n2 + 1;
	//Conversii
	for (i = 0; i < n1; ++i) {
		a[49 - n1 + 1 + i] = x[i] - 48;
	}
	for (i = 0; i < n2; ++i) {
		b[49 - n2 + 1 + i] = y[i] - 48;
	}
	//Adunare
	t = 0;
	for (i = 50; i > 50 - n3; --i) {
		c[i] = ((a[i - 1] + b[i - 1]) + t) % 10;
		t = ((a[i - 1] + b[i - 1]) + t) / 10;
	}
	c[i] = t;
	//Printare suma
	printf("Suma este:\n");
	for (i = 50 - n3 + 1; i < 51; ++i) {
		printf("%d", c[i]);
	}
	printf("\n");
	return 0;
}
*/

//EX4

/*
int main()
{
	char lit[50], num[50], n1, n2;
	printf("Introduceti un sir de caractere.\n");
	gets_s(lit);
	n1 = strlen(lit);
	printf("Introduceti un sir de numere.\n");
	gets_s(num);
	n2 = strlen(num);
	for (int i = 0; i < n2; ++i) {
		num[i] = num[i] - 48;
	}
	for (int i = 0; i < n2; ++i) {
		for (int j = 0; j < num[i]; ++j) {
			printf("%c", lit[i]);
		}
	}
	return 0;
}
*/
/*
int main()
{
	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int j = 0;
		if (i % 2 != 0)
		{
			int q = 2;
			while (j < i)
			{

				printf("%d ", q);
				q = q + 2;
				j++;
			}
		}
		else
		{
			int q = 1;
			while (j < i)
			{

				printf("%d ", q);
				q = q + 2;
				j++;
			}
		}

		printf_s("\n");
	}
}
*/