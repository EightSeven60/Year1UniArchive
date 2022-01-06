#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

void reversa(int x)
{
    int r;
    if (x == 0) {
        return;
    }
    else {
        r = x % 10;
        printf("%d", r);
        reversa(x / 10);
    }

}

int main()
{
    srand(time(NULL));
    reversa(1233843);
    printf("\n");

    printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
    (void)getchar();
    return 0;
}