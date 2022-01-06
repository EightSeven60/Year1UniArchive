#include <stdio.h>
#include <conio.h>
#include <Windows.h>
int main()
{
	printf("\tNumele si prenumele");
	_getch();
	_getch();
	system("cls");
	int x;
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
}