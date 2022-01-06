#include <stdio.h>
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
}