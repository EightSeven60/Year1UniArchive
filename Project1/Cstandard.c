#include <stdio.h>
#include <stdlib.h>

#include <conio.h>


int main()
{
    int i, j;
    for (j = 1; j <= 3; j++)
    {
        if (j % 2 == 1) for (i = 1; i <= 11; i++) printf("A");
        else
        {
            char a = 'A';
            char b = 'B';
            printf("%c   %c%c   %c", a, b, b, a);
        }

        printf("\n");
    }
    getchar();
    return 0;
}