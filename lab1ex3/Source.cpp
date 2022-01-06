#include <xlocinfo>
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
}