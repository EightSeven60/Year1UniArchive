#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

//EX2

/*
int main()
{
	unsigned char ch = 0;
	int c = 0;

	while (c < 256)
	{
		printf("%c ", ch);
		++ch;
		++c;
	}
	//printf("\n\n%d", ch);
	printf("\n");

	c = 0;
	do {
		printf("%c ", ch);
		++ch;
		++c;
	} while (c < 256);

	printf("\n");
		for (c = 0 ; c < 256; ++c) {
			printf("%c ", ch);
			++ch;
	}
	getchar();
	return 0;
}
*/

//EX3

/*
int main()
{
	unsigned int n, c, x, y = 1; c = 1; x = 0;
	printf("n = ");
	scanf("%d", &n);
	if (n < 0) {
		printf("n este negativ!\n");
		return 0;
	}

	while (c <= n) {
		x = x + c;
		y = y * c;
		c++;
	}
	printf("Suma este %d. Produsul este %d\n", x, y);

	c = 1; y = 1; x = 0;
	do {
		x = x + c;
		y = y * c;
		c++;
	} while (c <= n);
	printf("Suma este %d. Produsul este %d\n", x, y);

	c = 1; y = 1; x = 0;
	for (c = 1; c <= n; c++) {
		x = x + c;
		y = y * c;
	}
	printf("Suma este %d. Produsul este %d\n", x, y);
	getchar();
	return 0;
}
*/

//EX4

/*
int main() {
	unsigned int n, c = 1000;
	printf("n = ");
	scanf("%d", &n);
	while (c <= 9999 - n) {
		if (c % n == 0) printf("%d ", c);
		if (c % n == 0) {
			while (c <= 9999 - n) {
				printf("%d ", c + n);
				c = c + n;
			}
		}
		c++;
	}
	
	printf("\n\n");
	c = 1000;
	do {
		if (c % n == 0) printf("%d ", c);
		if (c % n == 0) {
			while (c <= 9999 - n) {
				printf("%d ", c + n);
				c = c + n;
			}
		}
		c++;
	} while (c <= 9999 - n);

	printf("\n\n");
	for (c = 1000; c <= 9999 - n; c++) {
		if (c % n == 0) printf("%d ", c);
		if (c % n == 0) {
			while (c <= 9999 - n) {
				printf("%d ", c + n);
				c = c + n;
			}
		}
	}
	getchar();
	return 0;
}
*/

//EX5

/*
int main()
{
	int n, x, y;
	printf("n = ");
	scanf("%d", &n);
	x = 1, y = 1;
	while (x < n) {
		y = y * (x + 1);
		++x;
	}
	printf("n! = %d\n", y);
	x = 1; y = 1;
	do {
		y = y * (x + 1);
		++x;
	} while (x < n);
	printf("n! = %d\n", y);
	x = 1; y = 1;
	for (; x < n; ++x) {
		y = y * (x + 1);
	}
	printf("n! = %d\n", y);
	getchar();
	return 0;
}
*/

//EX6

/*
int main()
{
	int n, m, c, in;
	printf("baza n = ");
	scanf("%d", &n);
	in = n;
	printf("exponentul m = ");
	scanf("%d", &m);
	getchar();
	for (c = 1; c < m; ++c) {
		n = n * in;
	}
	printf("%d\n", n);

	printf("baza n = ");
	scanf("%d", &n);
	in = n;
	printf("exponentul m = ");
	scanf("%d", &m);
	getchar();
	c = 1;
	while (c < m) {
		n = n * in;
		++c;
	}
	printf("%d\n", n);

	printf("baza n = ");
	scanf("%d", &n);
	in = n;
	printf("exponentul m = ");
	scanf("%d", &m);
	getchar();
	c = 1; in = n;
	do {
		n = n * in;
		++c;
	} while (c < m);
	printf("%d\n", n);
	getchar();
	return 0;
}
*/

//EX7

/*
int main()
{
	int n, m, c = 10000, x = 0;
	printf("n = ");
	scanf("%d", &n);
	printf("m = ");
	scanf("%d", &m);

	while (c <= 99999 - (n * m)) {
		if (c % n == 0 && c % m == 0) {
			printf("%d ", c);
			x++;
		}
		if (c % n == 0 && c % m == 0) {
			while (c <= 99999 - (n * m)) {
				printf("%d ", c + (n * m));
				c = c + (n * m);
			}
		}
		c++;
	}
	if (x == 0) printf("Nici un numar nu este divizibil cu ambele numere.\n");
	printf("\n");

	c = 10000; x = 0;
	do {
		if (c % n == 0 && c % m == 0) {
			printf("%d ", c);
			x++;
		}
		if (c % n == 0 && c % m == 0) {
			while (c <= 99999 - (n * m)) {
				printf("%d ", c + (n * m));
				c = c + (n * m);
			}
		}
		c++;
	} while (c <= 99999 - (n * m));
	if (x == 0) printf("Nici un numar nu este divizibil cu ambele numere.\n");
	printf("\n");

	c = 10000; x = 0;
	for (; c <= 99999 - (n * m); c++) {
		if (c % n == 0 && c % m == 0) {
			printf("%d ", c);
			x++;
		}
		if (c % n == 0 && c % m == 0) {
			while (c <= 99999 - (n * m)) {
				printf("%d ", c + (n * m));
				c = c + (n * m);
			}
		}
	}
	if (x == 0) printf("Nici un numar nu este divizibil cu ambele numere.\n");
	getchar();
	return 0;
}
*/

//EX8

/*
int main()
{
	int n, x = 1;
	printf("n = ");
	scanf("%d", &n);
	getchar();
	while (x <= n) {
		int i = 1;
		while (i <= x) {
			printf("%d ", i);
			++i;
		}
		printf("\n");
		++x;
	}

	//printf("\n");

	//x = 1;
	//do {
	//	int i = 1;
	//	while (i <= x) {
	//		printf("%d ", i);
	//		++i;
	//	}
	//	printf("\n");
	//	++x;
	//} while (x <= n);

	//printf("\n");

	//for (x = 1; x <= n; ++x) {
	//	int i = 1;
	//	while (i <= x) {
	//		printf("%d ", i);
	//		++i;
	//	}
	//	printf("\n");
	//}
	getchar();
	return 0;
}
*/

//EX9

/*
int main()
{
	int ix, in, x, n, nfac;
	double E = 1;
	printf("n = ");
	scanf("%d", &in);
	printf("x = ");
	scanf("%d", &ix);
	nfac = 1;
	for (n = 1; n <= in; ++n) {
		E = E + pow(ix, n) / (float)nfac;
		nfac = nfac * (nfac + 1);
	}
	printf("E = %lf\n", E);
	printf("E - e^x = %lf\n", E - exp(ix));
	getchar();
	return 0;
}
*/

//EX10

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

//EX11

/*
int main()
{
	srand(time_t(NULL));
	int x = rand(), y = rand(), z = rand(), w = x + y + z, r = 0;
	(void)printf("Numarul aleatoriu: %d\n", w);
	for (; w != 0; w = w / 10) {
		r = r + w % 10;
	}
	(void)printf("Suma este: %d\n", r);
	getchar();
	return 0;
}
*/

//EX12

/*
int main()
{
	//VARIABILELE SE INITIALIZEAZA PRIMELE FARA SA CONTEZE UNDE SE AFLA IN COD,
	//DE ACEEA, INTAI AM SCRIS IN X, APOI SRAND, APOI X = ...
	int x, y = 0;
	srand(time(NULL));
	x = (rand() + 5000) % 9999;
	(void)printf("Numarul aleatoriu este: %d\n", x);
	while (x != 0) {
		y = (x % 10) + (y * 10);
		x = x / 10;
	}
	(void)printf("Inversul este: %d\n", y);
	getchar();
	return 0;
}
*/

//EX13

/*
int main()
{
	srand(time(NULL));
	int nn, i, semnal = 1, primn, c = 0, n;
	n = rand() % (20 - 10 + 1) + 10;
	printf("Sa se afiseze al n-lea numar prim unde n = ");
	scanf("%d", &n);
	getchar();
	for (nn = 2; c < n; ++nn) {
		semnal = 1;
		for (i = 2; i <= nn / 2; ++i) {
			if (nn / i == (float)nn / i) {
				semnal = 0;
			}
		}
		if (semnal == 1) {
			primn = nn;
			++c;
		}
	}
	printf("Al n-lea numar prim este %d\n", nn - 1);
	getchar();
	return 0;
}
*/
//IN SFARSIT AM REUSITAJBFVGSHVFHUASFJ

//IGNORATI ASTEA DE JOS, ERAU DE AJUTOR / DEBUG
/*
for (i = 2; i <= sqrt(nn); ++i) {
	if (nn / i == (float)nn / i) {
		semnal = 0;
	}
}
if (semnal == 1) {
	primn = nn;
	++c;
	printf("Numarul este prim.\n");
}
*/
/*
int main()
{
	int n, nn, nrTest = 1, c = 0, x, primn, semnal = 1, i;
	srand(time(NULL));
	n = rand() % (20 - 10 + 1) + 10;
	(void)printf("Numarul aleatoriu este: %d\n", n);

	(void)printf("Al n-lea nr prim este %d.\n", nn);
	getchar();
	return 0;
}
*/
//IGNORATI ASTEA DE SUS, ERAU DE AJUTOR / DEBUG

//EX14

/*
int main()
{
	int n, i = 0, nr1 = 1, nr2 = 1, suma;
	printf("Sa se scrie numerele Fibonnaci pana la al cate-lea numar?\n");
	scanf("%d", &n);
	if (n >= 1) printf("1 "); ++i;
	if (n >= 2) printf("1 "); ++i;
	while (i <= n) {
		suma = nr1 + nr2;
		printf("%d ", suma);
		++i;
		nr1 = nr2;
		nr2 = suma;
	}
	getchar();
	return 0;
}
*/

//EX15

/*
int main()
{
	unsigned int n, m, mm, nn, boool1 = 1, boool2 = 1, i;
	(void)printf("m = ");
	(void)scanf("%d", &m);
	(void)printf("n = ");
	(void)scanf("%d", &n);
	mm = m; nn = n;
	//CMMDC
	if (m == 0 || n == 0) {
		printf("Numerele nu pot fi 0!\n");
		getchar();
		return 0;
	}
	while (m != n) {
		if (m > n) m = m - n;
		if (n > m) n = n - m;
	}
	if (m == n) (void)printf("%d este cel mai mare divizor comun dintre numere.\n", m);
	//CMMMC
	//VERIFICARI PRIME
	for (i = 2; i <= sqrt(mm); ++i) {
		if (mm / i == (float)mm / i) {
			boool1 = 0;
		}
	}
	for (i = 2; i <= sqrt(nn); ++i) {
		if (nn / i == (float)nn / i) {
			boool2 = 0;
		}
	}
	if (boool1 == 1 || boool2 == 1) printf("%d este cel mai mic multiplu comun.\n", mm * nn);
	else if (m != 1 && m != 0) printf("%d este cel mai mic multiplu comun dintre numere.\n", (mm * nn) / m);
	else if (mm == 0 || nn == 0) printf("Numerele nu au multiplu comun!\n");
	getchar();
	return 0;
}
*/

//EX16

/*
int main()
{
	int m, i, mm = 0, wng = 0, ww = 0; //FOLOSESTE WNG PENTRU A ADAUGA ULTIMUL 0 IN CAZUL BINARELOR PARE
	(void)printf("m = ");
	(void)scanf("%d", &m);
	printf("%d\n", sizeof(int));
	if (m % 2 == 0) wng = 1;
	while (m != 0) {
		mm = (mm * 10) + (m % 2);
		m = m / 2;
	}
	while (mm != 0) {
		ww = (ww * 10) + (mm % 10);
		mm /= 10;
	}
	if (wng == 1) ww = ww * 10;
	printf("%d\n", ww);
	getchar();
	return 0;
}
*/

//EX17

/*
int main()
{
	int m, dm = 0, y = 0;
	printf("n(binar) = ");
	scanf("%d", &m);
	getchar();
	while (m != 0) {
		if (m % 10 == 1) dm = dm + pow(2, y);
		m = m / 10;
		++y;
	}
	printf("%d", dm);
	getchar();
	return 0;
}
*/

//EX19

/*
int main()
{
	int nr, nm, nr2, nm2;
	printf("numarator = ");
	scanf("%d", &nr);
	printf("numitor = ");
	scanf("%d", &nm);
	getchar();
	nr2 = nr; nm2 = nm;
	//CMMDC
	if (nr == 0 || nm == 0) {
		printf("Numerele nu pot fi 0!\n");
		getchar();
		return 0;
	}
	while (nr2 != nm2) {
		if (nr2 > nm2) nr2 = nr2 - nm2;
		if (nm2 > nr2) nm2 = nm2 - nr2;
	}
	if (nr2 == nm2) (void)printf("%d este cel mai mare divizor comun dintre numere.\n", nr2);
	printf("Noua fractie este %d / %d\n", nr / nr2, nm / nm2);
	getchar();
	return 0;
}
*/

//EX18

/*
int main()
{
	int m, mm = 0, ww = 0, bi, bf, wng = 0, y = 0;
	(void)printf("Introduceti un numar de convertit din baza 10 sau in baza 10 m = ");
	(void)scanf("%d", &m);
	(void)printf("Introduceti baza numarului introdus bi = ");
	(void)scanf("%d", &bi);
	(void)printf("Introduceti baza in care doriti sa se converteasca bf = ");
	(void)scanf("%d", &bf);
	if (bi == bf) {
		(void)printf("Ati introdus aceeasi baza!\n");
		return 0;
	}
	else if (bi != 10 && bf != 10) {
		(void)printf("Macar una dintre baze trebuie sa fie 10, nu-s asa destept!\n");
		return 0;
	}
	else if (bi > bf) {
		if (m % bf == 0) wng = 1;
		while (m != 0) {
			mm = (mm * 10) + (m % bf);
			m = m / bf;
		}
		while (mm != 0) {
			ww = (ww * 10) + (mm % bi);
			mm /= 10;
		}
		if (wng == 1) ww = ww * 10;
		(void)printf("Numarul convertit este: %d\n", ww);
	}
	else if (bf > bi) {
		while (m != 0) {
			//if (m < bf) mm = mm * 10 + m;
			if (m % bf != 0) mm = mm + ((m % 10) * pow(bi, y));
			m = m / 10;
			++y;
		}
		(void)printf("Numarul convertit este: %d\n", mm);
	}
	getchar(); 
	return 0;
}
//IN HEX / DIN HEX NU MERGE
*/

//EX20

/*
int main()
{
	int c = 1, s = 0, p = 1, cc, rc;
	printf("Numerele urmatoare sunt divizibile atat cu suma cat si cu produsul lor.\n");
	while (c <= 9999) {
		for (cc = c; cc != 0; cc /= 10) {
			s = s + (cc % 10);
			p = p * (cc % 10);
		}
		cc = c;
		if (s != 0 && p != 0) {
			if (c % s == 0 && c % p == 0) printf("%d ", c);
		}
		s = 0;
		p = 1;
		++c;
	}
	getchar();
	return 0;
}
*/

//EX21

/*
int main()
{
	int m, b100 = 0, b50 = 0, b10 = 0, b5 = 0;
	printf("Cat am de plata sefu'?\n");
	scanf("%d", &m);
	getchar();
	while (m >= 5) {
		if (m >= 100) {
			m -= 100;
			++b100;
		}
		else if (m >= 50) {
			m -= 50;
			++b50;
		}
		else if (m >= 10) {
			m -= 10;
			++b10;
		}
		else if (m >= 5) {
			m -= 5;
			++b5;
		}
	}
	printf("Bancnote de 100: %d\nBancnote de 50: %d\nBancnote de 10: %d\nBancnote de 5: %d\n", b100, b50, b10, b5);
	if (m != 0) printf("Va mai dau eu %d ron altadata.\n", m);
	printf("Nr minim de bancnote este %d.\n", b100 + b50 + b10 + b5);
	getchar();
	return 0;
}
*/
//Apai astea o fost mai usoare decat 18