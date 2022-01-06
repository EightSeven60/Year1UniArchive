#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

//EX1

/*
int main()
{
	int n[100], x = 0, nrl = 1, max = 0, min = 32767, alegere, s = 0, p = 1, k, y, helper;
	printf("!Am considerat pozitiile incepand de la 1 inclusiv in toate cererile de pozitii!\nCate numere doriti sa introduceti in vector?\nMaximul este 100.\nnrl = ");
	NumarElemente:
	(void)scanf("%d", &nrl);
	if (nrl > 100 || nrl <= 0) {
		printf("Introduceti un numar intre 1 si 100 inclusiv!\n");
		goto NumarElemente;
	}
	printf("Introduceti numerele separate de Enter.\n");
	while (x <= nrl - 1) {
		(void)scanf("%d", &n[x]);
		getchar();
		++x;
	}
	x = 0;
	printf("Sirul este: ");
	while (x <= nrl - 1) {
		printf("%d ", n[x]);
		++x;
	}
	printf("\nIntroduceti un numar intre 1 si 6 inclusiv care sa indice optiunea aleasa.\n\
1. determinarea maximului si minimului\n\
2. suma si produsul numerelor\n\
3. eliminarea elementului din pozitia k data(0 <= k <= n - 1)\n\
4. inserarea unui element y in pozitia k data (0<=k<=n-1)\n\
5. permutarea circulara cu o pozitie spre stanga\n\
6. permutarea circulara cu o pozitie spre dreapta\n");
	Swtch:
	(void)scanf("%d", &alegere);
	getchar();
	switch (alegere) {
		case 1:
			for (x = 0; x <= nrl - 1; ++x) {
				if (n[x] > max) max = n[x];
			}
			printf("Maximul este: %d.\n", max);
			for (x = 0; x <= nrl - 1; ++x) {
				if (n[x] < min) min = n[x];
			}
			printf("Minimul este: %d.\n", min);
			break;
		case 2:
			for (x = 0; x <= nrl - 1; ++x) {
				s = s + n[x];
			}
			printf("Suma este: %d.\n", s);
			for (x = 0; x <= nrl - 1; ++x) {
				p = p * n[x];
			}
			printf("Produsul este: %d.\n", p);
			break;
		case 3:
			printf("Din ce pozitie doriti sa se elimine elementul?\n");
			Cazul3:
			(void)scanf("%d", &k);
			getchar();
			if (k > nrl || k < 1) {
				printf("Introduceti un numar intre 1-%d!\n", nrl);
				goto Cazul3;
			}
			for (x = k - 1; x <= nrl - 2; ++x) {
				n[x] = n[x + 1];
			}
			--nrl;
			x = 0;
			printf("Sirul este: ");
			while (x <= nrl - 1) {
				printf("%d ", n[x]);
				++x;
			}
			break;
		case 4:
			//x = 0;
			//printf("Sirul este: ");
			//while (x <= nrl - 1) {
			//	printf("%d ", n[x]);
			//	++x;
			//}
			printf("\n");
			printf("Introduceti numarul intreg de inserat:\n");
			(void)scanf("%d", &y);
			printf("Introduceti pozitia pe care sa se suprascrie:\n");
			Cazul4:
			(void)scanf("%d", &k);
			if (k > nrl || k < 1) {
				printf("Introduceti un numar intre 1-%d!\n", nrl);
				goto Cazul4;
			}
			for (x = nrl; x >= k - 1; --x) {
				n[x] = n[x - 1];
			}
			n[k - 1] = y;
			++nrl;
			x = 0;
			printf("Sirul este: ");
			while (x <= nrl - 1) {
				printf("%d ", n[x]);
				++x;
			}
			break;
		case 5:
			helper = n[0];
			for (x = 0; x <= nrl - 2; ++x) {
				n[x] = n[x + 1];
			}
			n[x] = helper;
			x = 0;
			printf("Sirul este: ");
			while (x <= nrl - 1) {
				printf("%d ", n[x]);
				++x;
			}
			break;
		case 6:
			helper = n[nrl - 1];
			for (x = nrl - 1; x >= 0; --x) {
				n[x] = n[x - 1];
			}
			n[0] = helper;
			x = 0;
			printf("Sirul este: ");
			while (x <= nrl - 1) {
				printf("%d ", n[x]);
				++x;
			}
			break;
		default:
			printf("Introduceti un numar intre 1-6!\n");
			goto Swtch;

	}
	getchar();
	return 0;
}
*/

//EX2

/*
int main()
{
	int* a;
	int nrel, n = 0, r = 0;
	//Citire si validare
	printf("Cate numere doriti sa introduceti in vector?\nn = ");
	(void)scanf("%d", &nrel);
	a = (int*)malloc(nrel * sizeof(int));
	printf("Introduceti numerele separate de Enter.\n");
	while (n <= nrel - 1) {
		(void)scanf("%d", &a[n]);
		getchar();
		++n;
	}
	n = 0;
	printf("Sirul este: ");
	while (n <= nrel - 1) {
		printf("%d ", a[n]);
		++n;
	}
	printf("\n");
	//Verificare simetric
	for (n = 0; n <= nrel / 2; ++n) {
		if (a[n] != a[nrel - n - 1]) {
			r = 1;
			break;
		}
	}
	if (r == 1) printf("Sirul este asimetric.\n");
	else if (r == 0) printf("Sirul este simetric.\n");
	free(a);
	getchar();
	return 0;
}
*/

//EX3

/*
int main()
{
	int n, nrel, x;
	float ultimaAparitie = 3.14;
	int* a;
	//Citire si validare
	printf("Cate numere doriti sa introduceti in sir?\nnrel = ");
	(void)scanf("%d", &nrel);
	getchar();
	a = (int*)malloc(nrel * sizeof(int));
	printf("Introduceti numerele separate de Enter.\n");
	for (n = 0; n < nrel; ++n) {
		(void)scanf("%d", &a[n]);
		getchar();
	}
	printf("Sirul este: ");
	for (n = 0; n < nrel; ++n) printf("%d ", a[n]);
	printf("\n");
	//Executie
	printf("Introduceti numarul care se va cauta in sir.\nx = ");
	(void)scanf("%d", &x);
	for (n = 0; n < nrel; ++n) {
		if (a[n] == x) {
			printf("Prima pozitie egala cu %d este a[%d].\n", x, n);
			break;
		}
	}
	for (; n < nrel; ++n) {
		if (a[n] == x) ultimaAparitie = n;
	}
	if (ultimaAparitie == (int)ultimaAparitie) printf("Ultima pozitie egala cu %d este a[%g].\n", x, ultimaAparitie);
	else printf("Numarul nu apare niciodata in sir.\n");
	free(a);
	return 0;
}
*/

//EX4

/*
int main()
{
	int n, nrel, nn, flag = 0;
	int* a;
	//Citire si validare
	printf("Cate numere doriti sa introduceti in sir?\nnrel = ");
	(void)scanf("%d", &nrel);
	getchar();
	a = (int*)malloc(nrel * sizeof(int));
	printf("Introduceti numerele separate de Enter.\n");
	for (n = 0; n < nrel; ++n) {
		(void)scanf("%d", &a[n]);
		getchar();
	}
	printf("Sirul este: ");
	for (n = 0; n < nrel; ++n) printf("%d ", a[n]);
	printf("\n");
	//Executie
	printf("Multimea este: ");
	for (n = 0; n < nrel; ++n) {
		flag = 0;
		for (nn = 0; nn < n; ++nn) {
			if (a[nn] == a[n]) flag = 1;
		}
		if (flag == 0) printf("%d ", a[n]);
	}
	printf("\n");
	free(a);
	getchar();
	return 0;
}
*/

//EX5

/*
int main()
{
	//Am presupus ca multimile introduse nu contin dubluri, sper ca asa trebuia.
	int n1, n2, nrel1, nrel2, flag = 0;
	int* a;
	int* b;
	//Citire si validare a
	printf("Cate numere doriti sa introduceti in sirul a?\nnrel = ");
	(void)scanf("%d", &nrel1);
	getchar();
	a = (int*)malloc(nrel1 * sizeof(int));
	printf("Introduceti numerele separate de Enter.\n");
	for (n1 = 0; n1 < nrel1; ++n1) {
		(void)scanf("%d", &a[n1]);
		getchar();
	}
	printf("Sirul este: ");
	for (n1 = 0; n1 < nrel1; ++n1) printf("%d ", a[n1]);
	printf("\n");
	//Citire si validare b
	printf("Cate numere doriti sa introduceti in sirul b?\nnrel = ");
	(void)scanf("%d", &nrel2);
	getchar();
	b = (int*)malloc(nrel2 * sizeof(int));
	printf("Introduceti numerele separate de Enter.\n");
	for (n2 = 0; n2 < nrel2; ++n2) {
		(void)scanf("%d", &b[n2]);
		getchar();
	}
	printf("Sirul este: ");
	for (n2 = 0; n2 < nrel2; ++n2) printf("%d ", b[n2]);
	printf("\n");
	//Reuniunea
	printf("A U B = ");
	for (n1 = 0; n1 < nrel1; ++n1) printf("%d ", a[n1]);
	for (n2 = 0; n2 < nrel2; ++n2) {
		for (n1 = 0; n1 < nrel1; ++n1) if (a[n1] == b[n2]) flag = 1;
		if (flag == 0) printf("%d ", b[n2]);
		flag = 0;
	}
	printf("\n");
	//Intersectia
	printf("A intersectat cu B = ");
	for (n1 = 0; n1 < nrel1; ++n1) {
		flag = 0;
		for (n2 = 0; n2 < nrel2; ++n2) {
			if (a[n1] == b[n2]) flag = 1;
		}
		if (flag == 1) printf("%d ", a[n1]);
	}
	printf("\n");
	//A - B
	printf("A - B = ");
	for (n1 = 0; n1 < nrel1; ++n1) {
		flag = 0;
		for (n2 = 0; n2 < nrel2; ++n2) {
			if (a[n1] == b[n2]) flag = 1;
		}
		if (flag == 0) printf("%d ", a[n1]);
	}
	printf("\n");
	//B - A
	printf("B - A = ");
	for (n2 = 0; n2 < nrel2; ++n2) {
		flag = 0;
		for (n1 = 0; n1 < nrel1; ++n1) {
			if (a[n1] == b[n2]) flag = 1;
		}
		if (flag == 0) printf("%d ", b[n2]);
	}
	printf("\n");
	free(a);
	free(b);
	getchar();
	return 0;
}
*/

//EX6

/*
int main()
{
	int n1, n11, nrel1, flag = 0;
	int* a;
	printf("Cate numere doriti sa introduceti in sir?\nnrel = ");
	(void)scanf("%d", &nrel1);
	getchar();
	a = (int*)malloc(nrel1 * sizeof(int));
	printf("Introduceti numerele separate de Enter.\n");
	for (n1 = 0; n1 < nrel1; ++n1) {
		(void)scanf("%d", &a[n1]);
		getchar();
	}
	printf("Sirul este: ");
	for (n1 = 0; n1 < nrel1; ++n1) printf("%d ", a[n1]);
	printf("\n");
	for (n1 = 0; n1 < nrel1; ++n1) {
		flag = 0;
		for (n11 = 0; n11 < nrel1; ++n11) {
			if (a[n1] == a[n11]) ++flag;
		}
		printf("%d: %d ori\n", a[n1], flag);
	}
	free(a);
	getchar();
	return 0;
}
*/

//EX7

/*
int main()
{
	int n1, n2, nrel1, nrel2, flag = 0, s = 0, p = 1, nrel3 = 0, n3;
	int* a;
	int* b;
	int* c;
	//Citire si validare a
	printf("Cate numere doriti sa introduceti in sirul a?\nnrel = ");
	(void)scanf("%d", &nrel1);
	getchar();
	a = (int*)malloc(nrel1 * sizeof(int));
	printf("Introduceti numerele separate de Enter.\n");
	for (n1 = 0; n1 < nrel1; ++n1) {
		(void)scanf("%d", &a[n1]);
		getchar();
	}
	printf("Sirul este: ");
	for (n1 = 0; n1 < nrel1; ++n1) printf("%d ", a[n1]);
	printf("\n");
	//Citire si validare b
	printf("Cate numere doriti sa introduceti in sirul b?\nnrel = ");
	(void)scanf("%d", &nrel2);
	getchar();
	b = (int*)malloc(nrel2 * sizeof(int));
	if (nrel1 >= nrel2) c = (int*)malloc(nrel1 * sizeof(int));
	else c = (int*)malloc(nrel2 * sizeof(int));
	printf("Introduceti numerele separate de Enter.\n");
	for (n2 = 0; n2 < nrel2; ++n2) {
		(void)scanf("%d", &b[n2]);
		getchar();
	}
	printf("Sirul este: ");
	for (n2 = 0; n2 < nrel2; ++n2) printf("%d ", b[n2]);
	printf("\n");
	//Suma
	if (nrel1 > nrel2) {
		for (n1 = nrel1 - 1; n1 >= 0; --n1) {
			n2 = n1;
			if (n1 >= nrel2) s = a[n1];
			else s = a[n1] + b[n2];
			c[n1] = s;
			++nrel3;
		}
	}
	else {
		for (n2 = nrel2 - 1; n2 >= 0; --n2) {
			n1 = n2;
			if (n2 >= nrel1) s = b[n2];
			else s = a[n1] + b[n2];
			c[n2] = s;
			++nrel3;
		}
	}
	printf("Suma polinoamelor este: ");
	for (n3 = 0; n3 < nrel3; ++n3) printf("%d ", c[n3]);
	free(a);
	free(b);
	free(c);
	getchar();
	return 0;
}
*/

//EX8

/*
int main()
{
	int a[5][5], n, m, max, maxn, maxm;
	//Creeare matrice aleatorie
	srand(time(NULL));
	for (n = 0; n < 5; ++n) {
		for (m = 0; m < 5; ++m) {
			a[n][m] = rand();
		}
	}
	//Printare matrice
	for (n = 0; n < 5; ++n) {
		for (m = 0; m < 5; ++m) {
			printf("%7d ", a[n][m]);
		}
		printf("\n");
	}
	//Verificare maxim
	max = a[0][0];
	for (n = 0; n < 5; ++n) {
		for (m = 0; m < 5; ++m) {
			if (a[n][m] > max) {
				max = a[n][m];
				maxn = n;
				maxm = m;
			}
		}
	}
	printf("Maximul este elementul %d de pe linia %d si coloana %d.\n", max, maxn + 1, maxm + 1);
	getchar();
	return 0;
}
*/

//EX9, EX10, EX11

/*
int main()
{
	int a[5][5], n, m;
	//Creeare matrice aleatorie
	srand(time(NULL));
	for (n = 0; n < 5; ++n) {
		for (m = 0; m < 5; ++m) {
			a[n][m] = rand();
		}
	}
	//Printare matrice
	for (n = 0; n < 5; ++n) {
		for (m = 0; m < 5; ++m) {
			printf("%7d ", a[n][m]);
		}
		printf("\n");
	}
	//Printare diagonala principala
	printf("Elementele diagonalei principale: ");
	for (n = 0; n < 5; ++n) {
		m = n;
		printf("%7d ", a[n][m]);
	}
	printf("\n");
	//Printare diagonala secundara
	printf("Elementele diagonalei secundare: ");
	for (n = 0; n < 5; ++n) {
		m = 4 - n;
		printf("%7d ", a[n][m]);
	}
	printf("\n");
	//Triunghi superior
	printf("Triunghiul superior este format din: ");
	for (n = 0; n < 5; ++n) {
		for (m = 0; m < 5; ++m) {
			if (m > n) printf("%7d ", a[n][m]);
		}
	}
	printf("\n");
	//Triunghiul inferior
	printf("Triunghiul inferior este format din: ");
	for (n = 0; n < 5; ++n) {
		for (m = 0; m < 5; ++m) {
			if (m < n) printf("%7d ", a[n][m]);
		}
	}
	printf("\n");
	//Elementele matricei coloana cu coloana
	printf("Elementele matricei coloana cu coloana:\n");
	for (n = 0; n < 5; ++n) {
		for (m = 0; m < 5; ++m) {
			printf("%7d ", a[m][n]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
*/

//EX12, EX13

/*
int main()
{
	int n, m, nel, mel, a[100][100];
	//Citire si validare matrice
	Citire:
	printf("Maximele de linii si coloane este de 100.\nCate linii sa aiba matricea?\nn = ");
	(void)scanf("%d", &nel);
	getchar();
	printf("Cate coloane sa aiba matricea?\nm = ");
	(void)scanf("%d", &mel);
	getchar();
	if (nel <= 0 || nel > 100 || mel <= 0 || mel > 100) {
		printf("Introduceti valori intre 1 si 100 inclusiv!\n");
		goto Citire;
	}
	for (n = 0; n < nel; ++n) {
		printf("Introduceti elementele intregi, de la stanga la dreapta, ale liniei %d separate de Enter.\n", n);
		for (m = 0; m < mel; ++m) {
			(void)scanf("%d", &a[n][m]);
		}
	}
	printf("Matricea introdusa:\n");
	for (n = 0; n < nel; ++n) {
		for (m = 0; m < mel; ++m) {
			printf("%7d ", a[n][m]);
		}
		printf("\n");
	}
	printf("\n");
	//Contur
	printf("Numerele aflate pe conturul matricei sunt:\n");
	for (n = 0; n < nel; ++n) {
		for (m = 0; m < mel; ++m) {
			if (n == 0 || n == nel - 1 || m == 0 || m == mel - 1) printf("%7d ", a[n][m]);
			else printf("        ");
		}
		printf("\n");
	}
	printf("\n");
	//Interschimbare linii
	n = 0;
	for (m = 0; m < mel; ++m) {
		a[n][m] = a[n][m] + a[nel - 1][m];
		a[nel - 1][m] = a[n][m] - a[nel - 1][m];
		a[n][m] -= a[nel - 1][m];
	}
	printf("Matricea cu linii interschimbate:\n");
	for (n = 0; n < nel; ++n) {
		for (m = 0; m < mel; ++m) {
			printf("%7d ", a[n][m]);
		}
		printf("\n");
	}
	printf("\n");
	//Interschimbare coloane
	m = 0;
	for (n = 0; n < nel; ++n) {
		a[n][m] = a[n][m] + a[n][mel - 1];
		a[n][mel - 1] = a[n][m] - a[n][mel - 1];
		a[n][m] -= a[n][mel - 1];
	}
	printf("Matricea cu coloane interschimbate:\n");
	for (n = 0; n < nel; ++n) {
		for (m = 0; m < mel; ++m) {
			printf("%7d ", a[n][m]);
		}
		printf("\n");
	}
	printf("\n");
	free(a);
	return 0;
}
*/

//EX14

/*
int main()
{
	int n, m, nel, mel, a[100][100], min, max;
	//Citire si validare matrice
	Citire:
	printf("Maximele de linii si coloane este de 100.\nCate linii sa aiba matricea?\nn = ");
	(void)scanf("%d", &nel);
	getchar();
	printf("Cate coloane sa aiba matricea?\nm = ");
	(void)scanf("%d", &mel);
	getchar();
	if (nel <= 0 || nel > 100 || mel <= 0 || mel > 100) {
		printf("Introduceti valori intre 1 si 100 inclusiv!\n");
		goto Citire;
	}
	for (n = 0; n < nel; ++n) {
		printf("Introduceti elementele intregi, de la stanga la dreapta, ale liniei %d separate de Enter.\n", n);
		for (m = 0; m < mel; ++m) {
			(void)scanf("%d", &a[n][m]);
		}
	}
	printf("Matricea introdusa:\n");
	for (n = 0; n < nel; ++n) {
		for (m = 0; m < mel; ++m) {
			printf("%7d ", a[n][m]);
		}
		printf("\n");
	}
	//Minimul si maximul
	for (m = 0; m < mel; ++m) {
		n = 0;
		min = a[n][m];
		for (n = 0; n < nel; ++n) {
			if (a[n][m] < min) min = a[n][m];
		}
		--n;
		printf("Minimul pe coloana %d: %d\n", m, min);
	}
	printf("\n");
	for (n = 0; n < nel; ++n) {
		m = 0;
		max = a[n][m];
		for (m = 0; m < mel; ++m) {
			if (a[n][m] > max) max = a[n][m];
		}
		--m;
		printf("Maximul pe linia %d: %d\n", n, max);
	}
	getchar();
	return 0;
}
*/

//EX15

/*
int main()
{
	srand(time(NULL));
	int n, m, i, n1, m1, l, c;
	int** a;
	//Citire marime matrice si alocare dinamica
	printf("Cate linii sa aiba matricea?\nn = ");
	(void)scanf("%d", &n);
	printf("Cate coloane sa aiba matricea?\nm = ");
	(void)scanf("%d", &m);
	getchar();
	a = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; ++i) a[i] = (int*)calloc(m, sizeof(int));
	//Creeare matrice aleatorie
	for (n1 = 0; n1 < n; ++n1) {
		for (m1 = 0; m1 < m; ++m1) {
			a[n1][m1] = rand();
		}
	}
	//Printare matrice
	for (n1 = 0; n1 < n; ++n1) {
		for (m1 = 0; m1 < m; ++m1) {
			printf("%7d ", a[n1][m1]);
		}
		printf("\n");
	}
	//Citire linie si coloana de eliminat
	printf("Ce line doriti sa eliminati?\nl = ");
	scanf("%d", &l);
	printf("Ce coloana doriti sa eliminati?\nc = ");
	scanf("%d", &c);
	getchar();
	//Eliminare linie
	for (n1 = l; n1 < n - 1; ++n1) {
		for (m1 = 0; m1 < m; ++m1) {
			a[n1][m1] = a[n1 + 1][m1];
		}
	}
	--n;
	//Eliminare coloana
	for (m1 = c; m1 < m - 1; ++m1) {
		for (n1 = 0; n1 < n; ++n1) {
			a[n1][m1] = a[n1][m1 + 1];
		}
	}
	--m;
	//Printare matrice
	printf("Matrice finalizata:\n");
	for (n1 = 0; n1 < n; ++n1) {
		for (m1 = 0; m1 < m; ++m1) {
			printf("%7d ", a[n1][m1]);
		}
		printf("\n");
	}
	getchar();
	return 0;
}
*/

//EX16

/*
int main()
{
	srand(time(NULL));
	int n, m, i, n1, m1, p, q, p1, q1, x, produs = 0, dl1, dc1;
	int** a;
	int** b;
	int** c;
	int** d;
	//Citire marime matrici
	printf("Cate linii sa aiba matricea 'a'?\nn = ");
	(void)scanf("%d", &n);
	printf("Cate coloane sa aiba matricea 'a'?\nm = ");
	(void)scanf("%d", &m);
	printf("Cate linii sa aiba matricea 'b'?\np = ");
	(void)scanf("%d", &p);
	printf("Cate coloane sa aiba matricea 'b'?\nq = ");
	(void)scanf("%d", &q);
	getchar();
	//Alocare dinamica
	a = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; ++i) {
		a[i] = (int*)calloc(m, sizeof(int));
	}
	b = (int**)calloc(p, sizeof(int*));
	for (i = 0; i < p; ++i) {
		b[i] = (int*)calloc(q, sizeof(int));
	}
	c = (int**)calloc(p, sizeof(int*));
	for (i = 0; i < p; ++i) {
		c[i] = (int*)calloc(q, sizeof(int));
	}
	d = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; ++i) {
		d[i] = (int*)calloc(n, sizeof(int));
	}
	//Creare matrici
	printf("x = 1 => matrici introduse de la tastatura\nx = 0 => matrici aleatorii\nx = ");
	(void)scanf("%d", &x);
	getchar();
	if (x == 1) {
		printf("Introducere matrice a:\n");
		for (n1 = 0; n1 < n; ++n1) {
			for (m1 = 0; m1 < m; ++m1) {
				printf("a[%d][%d] = ", n1, m1);
				(void)scanf("%d", &a[n1][m1]);
			}
		}
		printf("Introducere matrice b:\n");
		for (p1 = 0; p1 < p; ++p1) {
			for (q1 = 0; q1 < q; ++q1) {
				printf("b[%d][%d] = ", p1, q1);
				(void)scanf("%d", &b[p1][q1]);
			}
		}
	}
	else if (x == 0) {
		for (n1 = 0; n1 < n; ++n1) {
			for (m1 = 0; m1 < m; ++m1) {
				a[n1][m1] = rand() % 21;
			}
		}
		for (p1 = 0; p1 < p; ++p1) {
			for (q1 = 0; q1 < q; ++q1) {
				b[p1][q1] = rand() % 21;
			}
		}
	}
	//Printare matrici
	printf("Matricea a:\n");
	for (n1 = 0; n1 < n; ++n1) {
		for (m1 = 0; m1 < m; ++m1) {
			printf("%7d ", a[n1][m1]);
		}
		printf("\n");
	}
	printf("Matricea b:\n");
	for (p1 = 0; p1 < p; ++p1) {
		for (q1 = 0; q1 < q; ++q1) {
			printf("%7d ", b[p1][q1]);
		}
		printf("\n");
	}
	//Suma
	if (n != p || m != q) printf("Matricele nu se pot aduna deoarece nu au dimensiuni identice.\n");
	else {
		for (n1 = 0; n1 < n; ++n1) {
			for (m1 = 0; m1 < m; ++m1) {
				c[n1][m1] = a[n1][m1] + b[n1][m1];
			}
		}
		printf("Matricea c (suma):\n");
		for (n1 = 0; n1 < n; ++n1) {
			for (m1 = 0; m1 < m; ++m1) {
				printf("%7d ", c[n1][m1]);
			}
			printf("\n");
		}
	}
	//Produsul
	if (n != q || m != p) printf("Matricele nu se pot inmulti deoarece nu au dimensiuni corespunzatoare.\n");
	else if (n <= m){
		n1 = 0; dl1 = 0; dc1 = 0;
		for (dl1 = 0; dl1 < m; ++dl1) {
			dc1 = 0;
			for (i = 0; i < q; ++i) {
				if (dc1 < m && dl1 < m) {
					for (m1 = 0; m1 < m && n1 < n; ++m1) {
						d[dl1][dc1] = d[dl1][dc1] + a[n1][m1] * b[m1][i];
					}
					++dc1;
				}
			}
			++n1;
		}
		//Printarea matricei
		printf("Matricea d (produsul):\n");
		for (dl1 = 0; dl1 < n; ++dl1) {
			for (dc1 = 0; dc1 < n; ++dc1) {
				printf("%7d ", d[dl1][dc1]);
			}
			printf("\n");
		}
	}
	else if (n >= m) {
		n1 = 0; dl1 = 0; dc1 = 0;
		for (dl1 = 0; dl1 < q; ++dl1) {
			dc1 = 0;
			for (i = 0; i < q; ++i) {
				if (dc1 < q && dl1 < q) {
					for (m1 = 0; m1 < m && n1 < n; ++m1) {
						d[dl1][dc1] = d[dl1][dc1] + a[n1][m1] * b[m1][i];
					}
					++dc1;
				}
			}
			++n1;
		}
		//Printarea matricei
		printf("Matricea d (produsul):\n");
		for (dl1 = 0; dl1 < n; ++dl1) {
			for (dc1 = 0; dc1 < n; ++dc1) {
				printf("%7d ", d[dl1][dc1]);
			}
			printf("\n");
		}
	}
	//Eliberarea memoriei
	for (i = 0; i < n; ++i) {
		free(a[i]);
	}
	free(a);
	for (i = 0; i < p; ++i) {
		free(b[i]);
	}
	free(b);
	for (i = 0; i < p; ++i) {
		free(c[i]);
	}
	free(c);
	for (i = 0; i < n; ++i) {
		free(d[i]);
	}
	free(d);
	getchar();
	return 0;
}
//Stiu ca produsul e un mare spaghetti, asa mi-a iesit, daca uit, sa imi amintiti la LP
//sa va cer o rezolvare mai ok la acesta si la produsul polinoamelor...si la 17c si d, va rog.
*/

//EX17

/*
int main()
{
	srand(time(NULL));
	int n, m, i, n1, m1, x = 0;
	int** a;
	//Citire marime matrice si alocare dinamica
	Input:
	printf("Cate linii sa aiba matricea?\nn = ");
	(void)scanf("%d", &n);
	printf("Cate coloane sa aiba matricea?\nm = ");
	(void)scanf("%d", &m);
	getchar();
	if (n != m) {
		printf("Matricea trebuie sa fie patratica!\n");
		goto Input;
	}
	else if (n <= 0 || m <= 0) {
		printf("Matricea nu poate avea linii si coloane egale sau mai mici decat 0!\n");
		goto Input;
	}
	a = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; ++i) a[i] = (int*)calloc(m, sizeof(int));
	//Creeare matrice aleatorie
	for (n1 = 0; n1 < n; ++n1) {
		for (m1 = 0; m1 < m; ++m1) {
			a[n1][m1] = rand() % 51;
		}
	}
	//Printare matrice
	for (n1 = 0; n1 < n; ++n1) {
		for (m1 = 0; m1 < m; ++m1) {
			printf("%5d ", a[n1][m1]);
		}
		printf("\n");
	}
	printf("\n");
	//Printare matrice dupa cerinta a
	printf("Printare matrice dupa cerinta a:\n");
	for (m1 = 0; m1 < m; ++m1) {
		for (n1 = x; n1 < n; ++n1) {
			printf("%5d ", a[n1][m1]);
		}
		++x;
	}
	printf("\n");
	//Printare matrice dupa cerinta b
	printf("Printare matrice dupa cerinta b:\n");
	x = 1;
	for (n1 = 0; n1 < m; ++n1) {
		for (m1 = m - x; m1 >= 0; --m1) {
			printf("%5d ", a[n1][m1]);
		}
		++x;
	}
	printf("\n");
	//Printare matrice dupa cerinta c
	//Partea asta e incorecta, habar nu am cum sa fac la 17 c si d
	*/
	/*printf("Printare matrice dupa cerinta c:\n");
	x = 0;
	for (int y = 1; y < n; ++y) {
		if (y % 2 == 1) {
			m1 = x;
			while (m1 >= m) --m1;
			for (n1 = m1 - x; n1 >= 0 && m1 < m; --n1, ++m1) {
				printf("%5d ", a[n1][m1]);
			}
			++x;
			m1 = x;
			while (m1 >= m) --m1;
			for (n1 = m1 - x; n1 < n && m1 >= 0; ++n1, --m1) {
				printf("%5d ", a[n1][m1]);
			}
			++x;
		}
		else if (y % 2 == 0) {
			n1 = x;
			while (n1 >= n) --n1;
			for (m1 = n1 - x; m1 < m && n1 >= 0; ++m1, --n1) {
				printf("%5d ", a[n1][m1]);
			}
			++x;
			m1 = x;
			while (m1 >= m) --m1;
			for (n1 = m1 - x; n1 < n && m1 >= 0; ++n1, --m1) {
				printf("%5d ", a[n1][m1]);
			}
			++x;
		}
	}*/
	/*
	for (i = 0; i < n; ++i) {
		free(a[i]);
	}
	free(a);
	return 0;
}
*/

//LAB7
//EX18, EX19, EX20

/*
int main()
{
	float a = 3.14;
	unsigned char* pa1 = (unsigned char*)&a;
	int* pa2 = (int*)&a;
	int b = *pa2, bbinar, ibbinar;
	printf("%d\n", *pa1);
	printf("%d\n", *(pa1 + (sizeof(float)-1)));
	for (bbinar = 0; b != 0;) {
		bbinar = (bbinar * 10) + b % 2;
		b = b / 10;
	}
	for (ibbinar = 0; bbinar != 0;) {
		ibbinar = (ibbinar * 10) + bbinar % 10;
		bbinar = bbinar / 10;
	}
	printf("%d", ibbinar);
	getchar();
	return 0;
}
*/