//mostra de intrare la sfarsitul codului

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

struct person_t {
	char CNP[14];
	char nume[50];
	char prenume[50];
	char locNastere[100];
	char domiciliu[100];
};

void citirePersoane(person_t* fpersoana, char* fpersoaneCitite)
{
	char decizie = 1, i = 0;
	while (decizie == 1 && i < 100) {
		printf("\nPersoana %hhd:\nIntroduceti CNP: ", i);
		(void)scanf("%s", fpersoana[i].CNP);
		(void)getchar();
		printf("Introduceti numele de familie: ");
		(void)scanf("%s", fpersoana[i].nume);
		(void)getchar();
		printf("Introduceti prenumele: ");
		(void)scanf("%s", fpersoana[i].prenume);
		(void)getchar();
		printf("Introduceti locul nasterii: ");
		(void)gets_s(fpersoana[i].locNastere, 100);
		printf("Introduceti domiciliul: ");
		(void)gets_s(fpersoana[i].domiciliu);
		printf("Introduceti 1 pentru continuarea introducerii altor persoane, altfel introduceti 0: ");
		(void)scanf("%hhd", &decizie);
		(void)getchar();
		++i;
		*fpersoaneCitite = i;
	}
}
void printarePersoane(person_t* fpersoana, char* fpersoaneCitite) {
	char i = 0;
	while (i < *fpersoaneCitite) {
		printf("\nPresoana %hhd:\n", i);
		printf("CNP: \"%s\"\n", fpersoana[i].CNP);
		printf("Nume: \"%s\"\n", fpersoana[i].nume);
		printf("Prenume: \"%s\"\n", fpersoana[i].prenume);
		printf("Locul Nasterii: \"%s\"\n", fpersoana[i].locNastere);
		printf("Domiciliu: \"%s\"\n", fpersoana[i].domiciliu);
		++i;
	}
}
/*
aux = numere[i];
numere[i] = numere[j];
numere[j] = aux;
*/
void ordonarePersoaneDupaNume(person_t* fpersoana, char* fpersoaneCitite)
{
	char i, j;
	char aux[100];

	for (i = 0; i < *fpersoaneCitite; ++i) {
		for (j = 0; j < *fpersoaneCitite; ++j) {
			if (strcmp(fpersoana[i].nume, fpersoana[j].nume) < 0) {

				strcpy(aux, fpersoana[i].CNP);
				strcpy(fpersoana[i].CNP, fpersoana[j].CNP);
				strcpy(fpersoana[j].CNP, aux);

				strcpy(aux, fpersoana[i].nume);
				strcpy(fpersoana[i].nume, fpersoana[j].nume);
				strcpy(fpersoana[j].nume, aux);

				strcpy(aux, fpersoana[i].prenume);
				strcpy(fpersoana[i].prenume, fpersoana[j].prenume);
				strcpy(fpersoana[j].prenume, aux);

				strcpy(aux, fpersoana[i].locNastere);
				strcpy(fpersoana[i].locNastere, fpersoana[j].locNastere);
				strcpy(fpersoana[j].locNastere, aux);

				strcpy(aux, fpersoana[i].domiciliu);
				strcpy(fpersoana[i].domiciliu, fpersoana[j].domiciliu);
				strcpy(fpersoana[j].domiciliu, aux);
			}
			else if (strcmp(fpersoana[i].nume, fpersoana[j].nume) == 0) {
				if (strcmp(fpersoana[i].prenume, fpersoana[j].prenume) < 0) {

					strcpy(aux, fpersoana[i].CNP);
					strcpy(fpersoana[i].CNP, fpersoana[j].CNP);
					strcpy(fpersoana[j].CNP, aux);

					strcpy(aux, fpersoana[i].nume);
					strcpy(fpersoana[i].nume, fpersoana[j].nume);
					strcpy(fpersoana[j].nume, aux);

					strcpy(aux, fpersoana[i].prenume);
					strcpy(fpersoana[i].prenume, fpersoana[j].prenume);
					strcpy(fpersoana[j].prenume, aux);

					strcpy(aux, fpersoana[i].locNastere);
					strcpy(fpersoana[i].locNastere, fpersoana[j].locNastere);
					strcpy(fpersoana[j].locNastere, aux);

					strcpy(aux, fpersoana[i].domiciliu);
					strcpy(fpersoana[i].domiciliu, fpersoana[j].domiciliu);
					strcpy(fpersoana[j].domiciliu, aux);

				}
			}
		}
	}
}
void ordonarePersoaneDupaVarsta(person_t* fpersoana, char* fpersoaneCitite) {
	//am considerat anul curent fiind 2021, si nu am luat in considerare decat anul nasterii
	//daca voiam sa iau data exacta in considerare foloseam un struct data_nasterii_t
	char i, j;
	char aux[100];
	short varstai, varstaj, anNasterei, anNasterej;

	for (i = 0; i < *fpersoaneCitite; ++i) {

		memcpy(aux, fpersoana[i].CNP + 1, 2);
		anNasterei = atoi(aux);

		if (anNasterei < 22) varstai = 21 - anNasterei;
		else varstai = 21 + (100 - anNasterei);

		for (j = 0; j < *fpersoaneCitite; ++j) {

			memcpy(aux, fpersoana[j].CNP + 1, 2);
			anNasterej = atoi(aux);

			if (anNasterej < 22) varstaj = 21 - anNasterej;
			else varstaj = 21 + (100 - anNasterej);

			if (varstai < varstaj) {

				strcpy(aux, fpersoana[i].CNP);
				strcpy(fpersoana[i].CNP, fpersoana[j].CNP);
				strcpy(fpersoana[j].CNP, aux);

				strcpy(aux, fpersoana[i].nume);
				strcpy(fpersoana[i].nume, fpersoana[j].nume);
				strcpy(fpersoana[j].nume, aux);

				strcpy(aux, fpersoana[i].prenume);
				strcpy(fpersoana[i].prenume, fpersoana[j].prenume);
				strcpy(fpersoana[j].prenume, aux);

				strcpy(aux, fpersoana[i].locNastere);
				strcpy(fpersoana[i].locNastere, fpersoana[j].locNastere);
				strcpy(fpersoana[j].locNastere, aux);

				strcpy(aux, fpersoana[i].domiciliu);
				strcpy(fpersoana[i].domiciliu, fpersoana[j].domiciliu);
				strcpy(fpersoana[j].domiciliu, aux);
			}
		}
	}
}

int main()
{
	char persoaneCitite;
	person_t persoana[100];
	citirePersoane(persoana, &persoaneCitite);
	ordonarePersoaneDupaNume(persoana, &persoaneCitite);
	printf("\nPersoane aranjate alfabetic:\n");
	printarePersoane(persoana, &persoaneCitite);
	ordonarePersoaneDupaVarsta(persoana, &persoaneCitite);
	printf("\nPersoane aranjate crescator, dupa varsta:\n");
	printarePersoane(persoana, &persoaneCitite);
	(void)getchar();
	return 0;

}

/*
1234567890123
Samartean
Rares
Sweet Home Alabama
Saszreghen
1
0987654321098
Crovig
Antoanela
Dubai, ma
acolo
1
6969696969696
Samartean
Skebi
Mother Russia
pi' dincolo
0
*/