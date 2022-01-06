#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	short i = 1;
	FILE* file1 = fopen("Text.txt", "r");
	FILE* file2 = fopen("Inlocuitor.txt", "w");
	char* buffer = (char*)malloc(1024 * sizeof(char));
	if (file1 == NULL || file2 == NULL) {
		printf("Eroare\n");
		return -1;
	}
	while (!feof(file1)) {
		fgets(buffer, 1024, file1);
		fprintf(file2, "%hd. ", i);
		fputs(buffer, file2);
		++i;
	}
	remove("Text.txt");
	rename("Inlocuitor.txt", "Text.txt");
	//dice nu merge remove si rename, nu stiu
	free(buffer);
	fclose(file1);
	fclose(file2);
	return 0;
}