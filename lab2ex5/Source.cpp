#include <stdio.h>


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
}