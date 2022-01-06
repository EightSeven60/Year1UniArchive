#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;

//EX1

/*
int main()
{
	char prop[1024], cuv[256] = { 0 };
	printf("Scrieti o propozitie.\n");
	gets_s(prop);
	printf("%s\n", prop);
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 1024; ++j) {
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