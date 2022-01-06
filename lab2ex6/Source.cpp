#include <conio.h>
#include <stdio.h>
int main()
{
	int x = 1;
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
}