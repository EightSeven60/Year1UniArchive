
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;


//EX1

/*
int main()
{
	int a = 'a', aa = 'A', z = 'z', zz = 'Z', zero = '0', noua = '9', punct = '.', liniuta = '-', plus = '+';
	printf("a = %d\nA = %d\nz = %d\nZ = %d\n0 = %d\n9 = %d\n. = %d\n- = %d\n+ = %d\n", a, aa, z, zz, zero, noua, punct, liniuta, plus);
	getchar();
	return 0;
}
*/

//EX2

/*
int main()
{
	char ch;
	printf("Introduceti un singur caracter.\n");
	scanf("%c", &ch);
	printf("Majuscula corespunzatoare: %c\n", ch - 32);
	printf("Caracterul urmator din alfabet: %c\n", ch + 1);
	printf("Caracterul precedent din alfabet: %c\n", ch - 1);
	getchar();
	return 0;
}
*/

//EX3

/*
int main()
{
	printf("Introduceti un caracter.\n");
	char x;
	scanf("%c", &x);
	printf("Codul ASCII al caracterului introdus este %d\n", x);
	if (x >= 48 && x <= 57) printf("Caracterul introdus este o cifra.\n");
	else if (x == 43 || x == 45 || x == 42 || x == 47 || x == 37) printf("Caracterul introdus este un operator matematic.\n");
	else printf("Caracterul introdus nu este nici cifra, nici operator matematic.\n");
	getchar();
	return 0;
}
*/

//EX4

/*
int main()
{
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
	int a, b, c;
	char z;
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("c = ");
	scanf("%d", &c);
	getchar();
	printf("Alegeti o optiune de mai jos, scriind litera corespunzatoare (fara punct) si apasand Enter.\na. Afisare maxim\nb. Afisare minim\nc. Afisare suma\nd. Afisare produs\ne. Afisarea solutiilor ecuatiei de gradul II ax^2+bx+c=0\n");
	scanf("%c", &z);
	switch (z)
	{
	case 'a':
		printf("Maximul este %d\n", MAX(MAX(a, b), c));
		break;
	case 'b':
		printf("Minimul este %d\n", MIN(MIN(a, b), c));
		break;
	case 'c':
		printf("Suma lor este %d\n", a + b + c);
		break;
	case 'd':
		printf("Produsul lor este %d\n", a * b * c);
		break;
	case 'e':
		printf("Ecuatia de gradul II:\n");
		int delta = b * b - 4 * a * c;
		printf("delta = %d\n", delta);
		if (delta < 0) printf("Ecuatia nu are solutii rationale.\n");
		else
		{
			printf("x1 = %g\n", (-b + sqrt(delta)) / 2 * a);
			printf("x2 = %g\n", (-b - sqrt(delta)) / 2 * a);
		}
		break;
	}
	getchar();
	return 0;
}
*/

//EX5

/*
int main()
{
	int x, a, b;
	scanf("%d", &x);
	a = (x - (x % 1000)) / 10;
	b = x % 100;
	x = a + b;
	printf("%d", x);
	getchar();
	return 0;
}
*/

//EX6

/*
int main()
{
	double x;
	scanf("%lf", &x);
	x = (100 * x) - (int)(100 * x);
	printf("%.4lf", x);
	getchar();
	return 0;
}
*/

//EX7

/*
int main()
{
	int x; //x e numarul de prelucrat;
	char b; //b e alegerea care determina operatiunea aleasa
	printf("Introduceti un numar intreg de 4 cifre.\n");
	scanf("%d", &x);
	getchar();
	printf("Introduceti litera corespunzatoare optiunii dorite de mai jos, urmata de un Enter.\na. Afisare paritate ultima cifra\nb. Afisare paritate prima cifra\nc. Afisare suma cifrelor\nd. Afisare numar rezultat dupa inserarea cifrei '0' la mijlocul numarului\n");
	scanf("%c", &b);
	switch (b)
	{
	case 'a':
		if ((x % 10) % 2 == 0) printf("Ultima cifra este para.\n");
		else printf("Ultima cifra este impara.\n");
		break;
	case 'b':
		if ((x / 1000) % 2 == 0) printf("Prima cifra este para.\n");
		else if ((x / 1000) % 2 == 1) printf("Prima cifra este impara.\n");
		break;
	case 'c':
		printf("Suma cifrelor este\n%d", (x / 1000) + ((x / 100) % 10) + ((x / 10) % 10) + (x % 10));
		break;
	case 'd':
		printf("Numarul rezultat dupa inserarea unui 0 la mijlocul acestuia este:\n%d", ((x / 100) * 1000) + (x % 100));
		break;
	}
	//printf("%d\n", a); //linie pentru debug
	getchar();
	return 0;
}
*/

//EX8

/*
int main()
{
	int x; //variabila intrare
	float a; 
	printf("Introduceti un numar intreg.\n");
	scanf("%d", &x);
	if (x % 2 == 0) printf("Numarul este par.\n");
	else printf("Numarul nu este par.\n");
	if (x % 4 == 0) printf("Numarul este divizibil cu 4.\n");
	else printf("Numarul nu este divizibil cu 4.\n");
	a = (float)x / 5;
	//printf("%f\n", a); //linie pentru debug
	if (a == (int)a) printf("Numarul este multiplu de 5.\n");
	else printf("Numarul nu este multiplu de 5.\n");
	getchar();
	return 0;
}
*/

//EX9

/*
int main()
{
	int x, y;
	printf("Introduceti primul numar si apasati Enter.\n");
	scanf("%d", &x);
	printf("Introduceti al doilea numar si apasati Enter.\n");
	scanf("%d", &y);
	printf("Introduceti litera corespunzatoare (fara punct) si Enter pentru a selecta optiunea dorita:\na. Suma\nb. Produsul\nc. Catul\nd. Restul\ne. Iesire\n");
	getchar();
	char alegere;
	printf("alegere = ");
	scanf("%c", &alegere);
	//printf("%c\n", alegere);
	switch (alegere)
	{
		case 'a':
			printf("Suma este %d.\n", x + y);
			break;
		case 'b':
			printf("Produsul este %d.\n", x * y);
			break;
		case 'c':
			printf("Catul este %g.\n", (float)x / y);
			break;
		case 'd':
			printf("Restul este %d.\n", x % y);
			break;
		case 'e':
			exit(0);
			break;
		default:
			printf("Optiune invalida!\n");
			break;
	}
	getchar();
	return 0;
}
*/

//EX10

/*
int main()
{
	int a, b, c, d, e; //variabile introduse
	printf("Sa se introduca 5 numere intregi, separate de tasta Enter.\n");
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	//printf("%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e); linie pentru debug
	printf("Valoarea maxima este ");
	if (a > b && a > c && a > d && a > e) printf("%d\n", a);
	else if (b > a && b > c && b > d && b > e) printf("%d\n", b);
	else if (c > a && c > b && c > d && c > e) printf("%d\n", c);
	else if (d > a && d > b && d > c && d > e) printf("%d\n", d);
	else if (e > a && e > b && e > c && e > d) printf("%d\n", e);
	printf("Valoarea minima este ");
	if (a < b && a < c && a < d && a < e) printf("%d\n", a);
	else if (b < a && b < c && b < d && b < e) printf("%d\n", b);
	else if (c < a && c < b && c < d && c < e) printf("%d\n", c);
	else if (d < a && d < b && d < c && d < e) printf("%d\n", d);
	else if (e < a && e < b && e < c && e < d) printf("%d\n", e);
	getchar();
	return 0;
}
*/

//EX11

/*
int main()
{
#define MAX(m,n) (m > n ? m : n)
#define MIN(m,n) (m < n ? m : n)
#define SUMA(m, n, o) (m + n + o)
#define PRODUS(m, n, o) (m * n * o)
	int a, b, c;
	char ch;
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("c = ");
	scanf("%d", &c);
	getchar();
	printf("Alegeti una dintre optiuni prin a introduce litera corespunzatoare urmata de Enter.\na. Afisare maxim\nb. Afisare minim\nc. Afisare suma\nd. Afisare produs\ne. Afisarea solutiilor ecuatiei de gradul II ax^2+bx+c=0\n");
	scanf("%c", &ch);
	switch (ch)
	{
	case 'a':
		printf("Maximul este %d\n", MAX(MAX(a, b), c));
		break;
	case 'b':
		printf("Minimul este %d\n", MIN(MIN(a, b), c));
		break;
	case 'c':
		printf("Suma este %d", SUMA(a, b, c));
		break;
	case 'd':
		printf("Produsul este %d", PRODUS(a, b, c));
		break;
	case 'e':
		printf("Ecuatia de gradul II:\n");
		int delta = b * b - 4 * a * c;
		printf("delta = %d\n", delta);
		if (delta < 0) printf("Ecuatia nu are solutii rationale.\n");
		else
		{
			printf("x1 = %g\n", (-b + sqrt(delta)) / 2 * a);
			printf("x2 = %g\n", (-b - sqrt(delta)) / 2 * a);
		}
		break;
	}
	getchar();
	return 0;
}
*/

//EX12

/*
int main()
{
#define PARULTIM(m) ((x % 10) % 2 == 0 ? "Ultima cifra este para.\n" : "Ultima cifra este impara.\n")
#define PARPRIM(m) ((x / 1000) % 2 == 0 ? "Prima cifra este para.\n" : "Prima cifra este impara.\n")
	int x; //x e numarul de prelucrat;
	char b; //b e alegerea care determina operatiunea aleasa
	printf("Introduceti un numar intreg de 4 cifre.\n");
	scanf("%d", &x);
	getchar();
	printf("Introduceti litera corespunzatoare optiunii dorite de mai jos, urmata de un Enter.\na. Afisare paritate ultima cifra\nb. Afisare paritate prima cifra\nc. Afisare suma cifrelor\nd. Afisare numar rezultat dupa inserarea cifrei '0' la mijlocul numarului\n");
	scanf("%c", &b);
	switch (b)
	{
	case 'a':
		printf("%s", PARULTIM(x));
		break;
	case 'b':
		printf("%s", PARPRIM(x));
		break;
	case 'c':
		printf("Suma cifrelor este\n%d", (x / 1000) + ((x / 100) % 10) + ((x / 10) % 10) + (x % 10));
		break;
	case 'd':
		printf("Numarul rezultat dupa inserarea unui 0 la mijlocul acestuia este:\n%d", ((x / 100) * 1000) + (x % 100));
		break;
	}
	//printf("%d\n", a); //linie pentru debug
	getchar();
	return 0;
}
*/

//EX13 se afla in celelalte fisiere trimise

//EX14

/*
int main()
{
	int a = 50, b = 50, x = 1; //a e input, b e incrementul care din prima se injumatateste, daca x ajunge la 8 programul a pierdut.
	char ch; //cu ch se dau indicatii de > < = sau x (pentru iesire)
	printf("Se va ghici numarul la care te gandesti, foloseste '>', '<' sau '='\npentru a da indicii sau 'x' pentru a iesi din program,\ntoate fiind urmate de Enter. Numarul sa fie intre 1 si 100!\n(Asteapta macar prima ghicire)\nApasa Enter pentru a continua.\n");
	getchar();
	while (x <= 8)
	{
		printf("%d?\n", a);
		b = ((b + 1) / 2);
		if (b == 0) b = 1; //de multe ori ajungea b la 0 si nu mai incrementa, de asta exista if-ul asta
		//printf("b = %d\n", b); //linie pentru debug
		scanf("%c", &ch);
		getchar();
		switch (ch)
		{
		case '<':
			a = a - b;
			break;
		case '>':
			a = a + b;
			break;
		case '=':
			printf("Iei :-D\nApasa Enter pentru a iesi din program.\n");
			getchar();
			exit(0);
			break;
		case 'x':
			exit(0);
			break;
		}
		x += 1;
	}
	printf("N-am ghicit :-(\nApasa Enter pentru a iesi din program.\n");
	getchar();
	return 0;
}
*/

//EX15

/*
int main()
{
	short int o, m, s; //Timpul de intrare
	int a, stotal; //a sunt secundele de adaugat, stotal este timpul de intrare in secunde
	char ch = 'y'; //determina alegerea de a rerula programul
	while (ch == 'y')
	{
		printf("Ora este ");
		scanf("%hd", &o);
		printf("Minutul este ");
		scanf("%hd", &m);
		printf("Secunda este ");
		scanf("%hd", &s);
		printf("Secunde de adaugat timpului initial: ");
		scanf("%d", &a);
		getchar();
		stotal = o * 3600 + m * 60 + s + a;
		o = stotal / 3600; m = (stotal % 3600) / 60; s = ((stotal % 3600) % 60);
		(o > 23 ? o = o - 24 : o = o);
		printf("Acum este ora %2d:%2d:%2d.\nRepetati? (y = da, n = nu)\n", o, m, s);
		scanf("%c", &ch);
	}
	getchar();
	return 0;
}
*/

//O zi buna si spor la treaba, domn' profesor :-)