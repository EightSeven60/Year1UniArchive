#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

/*
int main()
{
	printf("Introduceti a.\n");
	float absolut, a;
	cin >> a;
	if (a >= 0)
	{
		absolut = a;
	}
	else
	{
		absolut = -a;
	}
}
*/

//Radical de ordinul 3

/*
#include <stdio.h>

float abso(float a) {
    if (a >= 0) {
        return a;
    }
    else {
        return -a;
    }
}

float radical3(float a, float eps) {
    float r1 = 1, r2 = 1;
    do {
        r1 = r2;
        r2 = (2 * r1 + a / (r1 * r1)) / 3;
    } while (abso(r2 - r1) >= eps);
    return r2;
}





int main()
{
    printf("Hello World\n");

    float x = 9;
    printf("Radical din 9 este: %.8f", radical3(x, 0.00000001));


    return 0;
}

*/

//Derived Function

/*
#include <iostream>
using namespace std;

class Base {
public:
    void print() {
        cout << "Base Function" << endl;
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "Derived Function" << endl;
    }
};

int main() {
    Derived derived1;
    derived1.print();
    return 0;
}
*/

//labPseudocodBinar

/*
int main()
{
    int n, x = 1000000000, y = 0;
    printf("n poate avea maxim 9 cifre.\nn = ");
    scanf("%d", &n);
    getchar();
    while (x >= 10) {
        if ((n % x) / (x / 10) != 0) {
            y = 1;
        }
        if (y != 0) {
            printf("%d ", (n % x) / (x / 10));
        }
        x = x / 10;
    }
    getchar();
    return 0;
}
*/
/*
int suma(int i)
{
    i = i + 2;
    return i;
}

int main()
{
    printf("%d", suma(5));
}
*/