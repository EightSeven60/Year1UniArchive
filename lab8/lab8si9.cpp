#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

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
		if (i >= n)
			break;
		c1 = prop[i];
		//Extragere c2
		while ((prop[j] == ' ' || prop[j] == '.') && j >= 0) --j;
		if (j < 0)
			break;
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

//EX5

/*
int main()
{
	char prop[1024];
	unsigned int n1, start, stop, numar = 0;
	int i;
	printf("Introduceti o propozitie sfarsita cu Enter.\n");
	gets_s(prop, 1024);
	n1 = strlen(prop);
	for (i = 0; i < n1; ++i) {
		if (prop[i] < 48 || prop[i] > 57) {
			printf("%c", prop[i]);
		}
		else if (prop[i] >= 48 && prop[i] <= 57) {
			while (i < n1 && prop[i] >= 48 && prop[i] <= 57) {
				numar = (numar * 10) + prop[i] - 48;
				++i;
			}
			for (int j = 0; j < numar; ++j) {
				printf("*");
			}
			numar = 0;
			printf("%c", prop[i]);
		}
		
	}
	return 0;
}
*/

//EX6


int main()
{
	char prop[1024];
	unsigned int n1, start, stop, numar = 0;
	int i;
	printf("Introduceti o propozitie sfarsita cu Enter.\n");
	gets_s(prop, 1024);
	n1 = strlen(prop);
	for (i = 0; i < n1; ++i) {
		while (prop[i] != 0) {
			
		}
	}
	return 0;
}