#include <stdio.h>
#include <string>
#include <Windows.h>

int main()
{
	int m;
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
		Sleep(100);
	}
	//char z = 0;
	//printf("\\\\\b\t\\\\\b\t//\t//\t");
	//printf("//\t//\t\\\\\b\t\\\\\b");
	getchar();
	return 0;
}
//Oficial am ajuns la primul meu "Merge, dar nu stiu cum sau de ce merge".