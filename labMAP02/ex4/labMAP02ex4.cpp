#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

struct Disciplina_t {
	char denumire[100];
	int nota;
};
struct Student_t {
	char nume[50];
	char prenume[40];
	Disciplina_t disciplina[10];
	float medie;
};

/*
aux = numere[i];
numere[i] = numere[j];
numere[j] = aux;
*/

void citireStudenti(Student_t* fstudent, char* fstudentiCititi, char* fmateriiCitite)
{
	char decizieStudenti = 1, i = 0, j = 0, sumaNote = 0;

	while(*fmateriiCitite < 1 || *fmateriiCitite > 10) {
		printf("Cate materii doriti sa introduceti pentru fiecare student? Materii = ");
		(void)scanf("%hhd", fmateriiCitite);
	}

	while (decizieStudenti == 1 && i < 100) {
		printf("\nStudentul %hhd:\nIntroduceti numele de familie: ", i);
		(void)scanf("%s", fstudent[i].nume);
		(void)getchar();
		printf("Introduceti prenumele: ");
		(void)scanf("%s", fstudent[i].prenume);
		(void)getchar();

		for (j = 0; j < *fmateriiCitite; ++j) {
			printf("Introduceti numele materiei: ");
			gets_s(fstudent[i].disciplina[j].denumire);
			if (*fstudent[i].disciplina[j].denumire == '0') break;
			printf("Introduceti nota la aceasta materie: ");
			(void)scanf("%d", &fstudent[i].disciplina[j].nota);
			sumaNote = sumaNote + fstudent[i].disciplina[j].nota;
			(void)getchar();
		}

		fstudent[i].medie = (float)sumaNote / j;
		sumaNote = 0;

		printf("\nIntroduceti 1 pentru continuarea introducerii altor studenti, altfel introduceti 0: ");
		(void)scanf("%hhd", &decizieStudenti);
		(void)getchar();
		++i;
		*fstudentiCititi = i;
	}
}
void ordonareDupaMedie(Student_t* fstudent, char fstudentiCititi, char fmateriiCitite) {
	char i, j, auxChar[100], k;
	int auxInt;
	float auxFloat;
	for (i = 0; i < fstudentiCititi; ++i) {
		for (j = 0; j < fstudentiCititi; ++j) {
			if (fstudent[i].medie > fstudent[j].medie) {

				strcpy(auxChar, fstudent[i].nume);
				strcpy(fstudent[i].nume, fstudent[j].nume);
				strcpy(fstudent[j].nume, auxChar);

				strcpy(auxChar, fstudent[i].prenume);
				strcpy(fstudent[i].prenume, fstudent[j].prenume);
				strcpy(fstudent[j].prenume, auxChar);

				for (k = 0; k < fmateriiCitite; ++k) {

					strcpy(auxChar, fstudent[i].disciplina[k].denumire);
					strcpy(fstudent[i].disciplina[k].denumire, fstudent[j].disciplina[k].denumire);
					strcpy(fstudent[j].disciplina[k].denumire, auxChar);

					auxInt = fstudent[i].disciplina[k].nota;
					fstudent[i].disciplina[k].nota = fstudent[j].disciplina[k].nota;
					fstudent[j].disciplina[k].nota = auxInt;
				}

				auxFloat = fstudent[i].medie;
				fstudent[i].medie = fstudent[j].medie;
				fstudent[j].medie = auxFloat;
			}
		}
	}
}
void printareStudenti(Student_t* fstudent, char fstudentiCititi) {
	char i;
	printf("\nStudentii ordonati dupa media lor:\n");
	for (i = 0; i < fstudentiCititi; ++i) {
		printf("Studentul %hhd: %s %s cu media %g.\n", i, fstudent[i].nume, fstudent[i].prenume, fstudent[i].medie);
	}
}
/*
3
Barbu
Matei
Romana
2
Informatica
9
Biologie
7
1
Samartean
Rares
Informatica
7
Romana
5
Biologie
8
1
Covrig
Antonia
Biologie
9
Informatica
7
Romana
9
0
*/

int main()
{
	char studentiCititi = 0, materiiCitite = 0;
	Student_t student[30];
	citireStudenti(student, &studentiCititi, &materiiCitite);
	ordonareDupaMedie(student, studentiCititi, materiiCitite);
	printareStudenti(student, studentiCititi);
	(void)getchar();
	return 0;
}

//io mor domn prof, e duminica dupamasa si doar acum am terminat ex 4...
//2, 5 si 6 nici n-am inceput, si inca mai am de lucru la lab01...