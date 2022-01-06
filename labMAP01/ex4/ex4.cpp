#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    char text[1024] = { 0 };
    int i = 0;
    FILE* file1;
    file1 = fopen("Text.txt", "w");
    if (file1 == NULL) {
        printf("Eroare\n");
        return -1;
    }
    (void)scanf("%c", &text[i]);
    for (;text[i] != 0 && text[i] != 26;)
    {
        //printf("%c", text[i]);
        fputc(text[i], file1);
        i++;
        (void)scanf("%c", &text[i]);
    }
    fclose(file1);
    return 0;
}