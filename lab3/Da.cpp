#include <iostream>
#include <math.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
using namespace std;

//EX1
/*
int main()
{
	printf("Marimea unui char este de %d bytes.\n", sizeof(char));
	printf("Marimea unui unsigned char este de %d bytes.\n", sizeof(unsigned char));
	printf("Marimea unui short int este de %d bytes.\n", sizeof(short int));
	printf("Marimea unui int este de %d bytes.\n", sizeof(int));
	printf("Marimea unui unsigned int este de %d bytes.\n", sizeof(unsigned int));
	printf("Marimea unui signed int este de %d bytes.\n", sizeof(signed int));
	printf("Marimea unui long int este de %d bytes.\n", sizeof(long int));
	printf("Marimea unui float este de %d bytes.\n", sizeof(float));
	printf("Marimea unui double este de %d bytes.\n", sizeof(double));
	printf("Marimea unui long double este de %d bytes.\n", sizeof(long double));
	getchar();
	return 0;
}
*/

//EX2
/*
int main()
{
	int a, b;
	printf("Introduceti a.\n");
	cin >> a;
	printf("Introduceti b.\n");
	cin >> b;
	printf("%d %d\n", --a, --b);
	printf("%d %d\n", a--, b--);
	printf("%d %d\n", ++a, ++b);
	printf("%d %d\n", a++, b++);
	printf("%d %d\n", a, b);
	printf("Introduceti a.\n");
	cin >> a;
	printf("Introduceti b.\n");
	cin >> b;
	printf("%d %d\n", a + 10, b + 10);
	printf("%d %d\n", a - 10, b - 10);
	printf("%d %d\n", a * 10, b * 10);
	printf("%d %d\n", a / 10, b / 10);
	printf("%d %d\n", a / 5, b / 5);
	printf("%d %d\n", a % 5, b % 5);
	printf("%g %g\n", (float)a / 3, (float)b / 3); //Precizie??
	printf("%g", pow(a, 3) - pow(b, 2) - a * b + 10);
	getchar();
	return 0;
}
*/

//EX2e
/*
int main()
{
	float m;
	float n;
	printf("Introduceti m apoi apasati Enter.\n");
	cin >> m;
	printf("m = %.2g\n", m);
	printf("Introduceti n apoi apasati Enter.\n");
	cin >> n;
	printf("n = %.2g\n", n);
	getchar();
	float x = (float)pow(m, 3) - pow(n, 2) - m * n + 10;
	printf("Rezultatul operatiei \"m^3 - n^2 - m * n + 10\" este: %.0g\n", x);
	getchar();
	return 0;
}
*/

//EX3
/*
int main()
{
	float x, y, z;
	printf("Introduceti x.\n");
	cin >> x;
	printf("Introduceti y.\n");
	cin >> y;
	printf("Introduceti z.\n");
	cin >> z;
	getchar();
	printf("Primul rezultat:\n");
	printf("%g", sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
	getchar();
	printf("Al doilea rezultat:\n");
	printf("%g", exp(x * log(y * z)));
	getchar();
	printf("Al treilea rezultat:\n");
	printf("%g", abs(x - y - z));
	getchar();
	printf("Introduceti x dinnou.\n");
	short m, n;
	cin >> m;
	printf("Introduceti y dinnou.\n");
	cin >> n;
	printf("Al patrulea rezultat\n");
	short a = (m % n);
	printf("%d", a);
	getchar();
	return 0;
}
*/

//Ex4
/*
int main()
{
	int x;
	double y;
	printf("Introduceti valoarea primului numar si apasati Enter.\n");
	cin >> x;
	printf("x = %d\n", x);
	printf("Introduceti valoarea celui de-al doilea numar si apasati Enter.\n");
	cin >> y;
	printf("y = %g\n", y);
	if (x != 2)
	{
		printf("\"N1 nu este egal cu 2\" este adevarat.\n");
	}
	else
	{
		printf("\"N1 nu este egal cu 2\" este fals.\n");
	}
	if (y != 5)
	{
		printf("N2 este diferit de 5.\n");
	}
	else
	{
		printf("N2 este egal cu 5.\n");
	}
	if ((x > 2) && (y <= 5.5))
	{
		printf("N1 este mai mare decat 2 iar n2 este mai mic sau egal decat 5.5.\n");
	}
	else
	{
		printf("N1 nu este mai mare decat 2 sau n2 nu este mai mic sau egal decat 5.5.\n");
	}
	//printf("x = %d, y = %g\n", x, y); //linie pentru debug
	getchar();
	return 0;
}
*/

//EX5
/*
int main()
{
	float x, y, z;
	printf("Z va fi cea mai mare latura.\n");
	//Input
	printf("Introduceti x.\n");
	cin >> x;
	printf("Introduceti y.\n");
	cin >> y;
	printf("Introduceti z.\n");
	cin >> z;
	//z = 5 * sqrt(2); //Testare pentru triunghi isoscel dreptunghic cu x, y = 5.
	printf("Triunghiul este ");
	short unsigned int a, b, c;
	a = 0, b = 0, c = 0;
	//Verificare dreptunghic
	if (pow(x, 2) + pow(y, 2) == pow(z, 2))
	{
		printf("dreptunghic");
		a = 1;
		b = 1;
		c = 1;
	}
	if (b == 1)
	{
		printf(", ");
	}
	//Verificare echilateral
	if ((x == y) && (y == z))
	{
		printf("echilateral.");
		a = 1;
		c = 0;
	}
	//Verificare isoscel
	else if (x == y || y == z)
	{
		printf("isoscel.");
		a = 1;
		c = 0;
	}
	//Exceptii
	else if (a == 0)
	{
		printf("un triunghi oarecare.");
	}
	else if (b == 1)
	{
		printf("\b\b");
	}
	if (c == 1)
	{
		printf(".");
	}
	getchar();
	getchar();
	return 0;
}
*/
//EX6
/*
int main()
{
	long int x, a, b, c, d, e, f;
	printf("Introduceti a.\n");
	scanf_s("%d", &a);
	printf("Introduceti b.\n");
	scanf_s("%d", &b);
	printf("Introduceti c.\n");
	scanf_s("%d", &c);
	printf("Introduceti d.\n");
	scanf_s("%d", &d);
	printf("Introduceti e.\n");
	scanf_s("%d", &e);
	printf("Introduceti f.\n");
	scanf_s("%d", &f);
	//P(x) = ax^5 + bx^4 + cx^3 + dx^2 + ex + f
	printf("Pentru care \"x\" doriti sa se calculeze polinomul P(x) = ax^5 + bx^4 + cx^3 + dx^2 + ex + f?\n");
	scanf_s("%d", &x);
	printf("%g", (a * pow(x, 5)) + (b * pow(x, 4)) + (c * pow(x, 3)) + (d * pow(x, 2)) + (e * x) + f );
	getchar();
	return 0;
}
*/
//EX 7
/*
int main()
{
	double a, b, c, d, e;
	int n;
	printf("Introduceti coeficientii functiei.\na=");
	scanf_s("%lg", &a);
	printf("b=");
	scanf_s("%lg", &b);
	printf("c=");
	scanf_s("%lg", &c);
	printf("d=");
	scanf_s("%lg", &d);
	printf("e=");
	scanf_s("%lg", &e);
	printf("Introduceti abscisa.\nn=");
	scanf_s("%d", &n);
	printf("f(%d)=%lg", n, (a * pow(n, 2) + 3 * b * n + 6 * c) / (d * n - e));
	getchar();
	return 0;
}
*/
//EX8
/*
int main()
{
	int a, b;
	printf("a=");
	scanf_s("%d", &a);
	printf("b=");
	scanf_s("%d", &b);
	printf("Media aritmetica = %g\n", (float)(a + b) / 2);
	printf("Media geometrica = %g\n", sqrt(a * b));
	printf("Media armonica = %g\n", (float)(2 * a * b) / (a + b));
	getchar();
	return 0;
}
*/
//Ex9
/*
int main()
{
	unsigned int n, x;
	printf("Introduceti un numar natural care sa fie mai mic decat 2 147 483 648.\n");
	cin >> n;
	for (x = 1; x <= sqrt(n); x++)
	{
		if (pow(x, 2) == n)
		{
			printf("n este patrat perfect.\n");
			exit(0);
		}
	}
	if (x >= sqrt(n))
	{
		printf("n nu este patrat perfect.\n");
	}
}
*/

//Algoritmica
/*
int main()
{
	short a, b;
	cin >> a >> b;
	a = b + a;
	b = a - b;
	a = a - b;
	printf("%d %d", a, b);
	getchar();
	return 0;
}
*/