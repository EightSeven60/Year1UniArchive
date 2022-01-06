#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

struct Angajat_t {
	char nume[30];
	char prenume[30];
	unsigned int salariu;
};

int main()
{
	char i, angajatiCititi;
	unsigned short sumaSalariiNormale = 0, sumaSalariiDiminuate = 0;
	Angajat_t angajat[10];
	FILE* file1 = fopen("Text.txt", "r");
	FILE* file2 = fopen("Text1.txt", "w");
	if (file1 == NULL) {
		printf("Eroare.\n");
		return -1;
	}
	fseek(file1, 3, SEEK_CUR);
	(void)fscanf(file1, "%hhd", &angajatiCititi);
	for (i = 0; i < angajatiCititi; ++i) {
		(void)fscanf(file1, "%s%s%u", &angajat[i].nume, &angajat[i].prenume, &angajat[i].salariu);
	}
	printf("Salariati:\n");
	fprintf(file2, "Salariati:\n");
	for (i = 0; i < angajatiCititi; ++i) {
		printf("%s %s %u\n", angajat[i].nume, angajat[i].prenume, angajat[i].salariu);
		sumaSalariiNormale = sumaSalariiNormale + angajat[i].salariu;
		angajat[i].salariu = angajat[i].salariu - (0.25 * angajat[i].salariu);
		fprintf(file2, "%s %s %u\n", angajat[i].nume, angajat[i].prenume, angajat[i].salariu);
		sumaSalariiDiminuate = sumaSalariiDiminuate + angajat[i].salariu;
	}
	printf("Diferenta este %g la suta din media salariilor initiale.\n", (((((float)sumaSalariiNormale / 4) - ((float)sumaSalariiDiminuate / 4)) * 100) / ((float)sumaSalariiNormale / 4)));
	(void)getchar();
	return 0;
}