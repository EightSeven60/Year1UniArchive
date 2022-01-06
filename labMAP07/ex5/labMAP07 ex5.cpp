#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

//urasc hanoi, mi-a luat mult prea mult timp sa fac asta
void hanoi(int x, char source, char aux, char destination)
{
	if (x == 1) {
		printf("Move disk %d from %c to %c.\n", x, source, destination);
		return;
	}
	hanoi(x - 1, source, destination, aux);
	printf("Move Disk %d from %c to %c.\n", x, source, destination);
	hanoi(x - 1, aux, source, destination);
}

int main()
{
	srand(time(NULL));
	hanoi(3, 'A', 'B', 'C');

    printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
    (void)getchar();
    return 0;
}