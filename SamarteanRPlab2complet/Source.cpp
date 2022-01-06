//EX1

/*#include <iostream>
#include <conio.h>
int main()
{
	char b = 0;
	char a = 65;
	printf("%40c %c %40c", b, a, b);
	getchar();
	return 0;
}*/

//EX2

/*#include <xlocinfo>
#include <stdio.h>
#include <conio.h>
int main()
{
	printf("AAAAAAAAAAA\n");
	char a = 'A';
	char b = 'B';
	char c = 0;
	printf("%c %3c%c %3c", a, b, b, a);
	printf("\nAAAAAAAAAAA");
	getchar();
	return 0;
}*/

//EX3

/*#include <xlocinfo>
#include <stdio.h>
#include <conio.h>

int main()
{
	char a = 65;
	char b = 66;
	char c = 34;
	char d = 39;
	char e = 0;
	printf("%c%c\n%4c%c\n%9c%c%c%c\n%4c%c\n%c%c\n%4c%c\n%4c%c%4c%c%c%c\n%4c%c\n%c%c", a, a, a, a, c, a, a, c, a, a, b, b, b, b, b, b, d, b, b, d, b, b, b, b);
	getchar();
	return 0;

	//Aici puteam face si cu un loop, dar am vazut ca un coleg a facut asa si am vrut sa fac diferit,
	//nu avea rost sa fac acelasi lucru dupa ce deja am vazut cum se face, dar pot face si in loop daca doriti.
}*/

//EX4

/*#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

int main()
{
	printf("\tLaborator de programare\n");
	getchar();
	system("cls");
	int x;
	for (x = 0; x < 3; x++)
	{
		if (x == 0)
		{
			printf("\t");
		}
		else if (x == 1)
		{
			printf("\t\t");
		}
		else if (x == 2)
		{
			printf("\t\t\t");
		}
		printf("\a\tLaborator de programare\n");
		Sleep(1000);
	}
	getchar();
	return 0;
}*/

//EX5

/*#include <stdio.h>


int main()
{
	int x;
	char a = 65;
	char b = 66;
	for (x = 1; x <= 7; x = x + 1)
	{
		if (x % 2 == 1 && x != 5)
		{
			printf("%c%10c\n", a, a);
		}
		else if (x % 2 == 0 && x !=5)
		{
			printf("%6c%c\n", a, a);
		}
		else
		{
			printf("%11c%c\n", b, b);
		}
	}
	getchar();
	return 0;
}*/

//EX6

/*#include <conio.h>
#include <stdio.h>
int main()
{
	short x = 1;
	char b = 'B';
	char z;
	char y = 0;
	for (; x <= 4; x++)
	{
		if (x <= 2)
		{
			z = '\'';
		}
		else if (x >> 1 && x <= 4)
		{
			z = '\"';
		}
		printf("%c%c%c%c%2c", z, b, b, z, y);
	}
	getchar();
	return 0;
}*/

//EX7

/*#include <stdio.h>
#include <string>
#include <Windows.h>

int main()
{
	unsigned short m;
	for (m = 1; m <= 16; m++)
	{
		if (m % 2 == 1)
		{
			printf("\\\\\b\t\\\\\b\t//\t//\t\n");
		}
		else if (m % 2 == 0)
		{
			printf("//\t//\t\\\\\b\t\\\\\b\n");
		}
		Sleep(10);
	}
	//char z = 0;
	//printf("\\\\\b\t\\\\\b\t//\t//\t");
	//printf("//\t//\t\\\\\b\t\\\\\b");
	getchar();
	return 0;
}*/
//Oficial am ajuns la primul meu "Merge, dar nu stiu cum sau de ce merge".
//Trebuia folosit un char x = (numarul \ din ascii).

//EX8

/*#include <stdio.h>
#include <conio.h>
#include <Windows.h>
int main()
{
	printf("\tNumele si prenumele");
	_getch();
	_getch();
	system("cls");
	unsigned short x;
	for (x = 1; x <= 5; ++x)
	{
		Sleep(1000);
		printf("\n\tNumele si prenumele");
		Sleep(1000);
		printf("\a");
		Sleep(1000);
		printf("\a");
	}
	_getch();
	return 0;
}*/