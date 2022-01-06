#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

struct Data_t {
	unsigned char zi;
	unsigned char luna;
	short an;
};
struct Alimente_t {
	unsigned short cod;
	char denumire[30];
	char unitateDM[15];
	unsigned short cantitate;
	float pret;
	Data_t dataExpirare;
};

void citireAlimente(Alimente_t* faliment, unsigned char* falimenteCitite) {
	char i, decizie = 1;
	printf("Bine ati venit la Magazinul lui nea Nelu!\n");
	for (i = 0; i < 4 && decizie == 1; ++i) {

		printf("\nIntroduceti codul alimentului (1-999): ");
		(void)scanf("%hu", &faliment[i].cod);
		(void)getchar();
		printf("%hhu", faliment[i].cod);

		printf("Introduceti denumirea alimentului: ");
		gets_s(faliment[i].denumire);

		printf("Introduceti unitatea de masura a alimentului: ");
		(void)scanf("%s", faliment[i].unitateDM);
		(void)getchar();

		printf("Introduceti cantitatea alimentului: ");
		(void)scanf("%hu", &faliment[i].cantitate);
		(void)getchar();

		printf("Introduceti pretul alimentului: ");
		(void)scanf("%f", &faliment[i].pret);
		(void)getchar();

		printf("Introduceti ziua expirarii: ");
		(void)scanf("%hhu", &faliment[i].dataExpirare.zi);
		(void)getchar();

		printf("Introduceti luna expirarii: ");
		(void)scanf("%hhu", &faliment[i].dataExpirare.luna);
		(void)getchar();

		printf("Introduceti anul expirarii (4 cifre): ");
		(void)scanf("%hd", &faliment[i].dataExpirare.an);
		(void)getchar();

		printf("Introduceti 1 pentru introducerea unui alt aliment, altcumva introduceti 0: ");
		(void)scanf("%hhd", &decizie);
		(void)(void)getchar();
	}
	*falimenteCitite = i;
}
void printareAlimente(Alimente_t* faliment, unsigned char falimenteCitite) {
	char i;

	printf("\nAlimente:\n");
	for (i = 0; i < falimenteCitite; ++i) {
		printf("%hu - %s - %hu %s\n", faliment[i].cod, faliment[i].denumire, faliment[i].cantitate, faliment[i].unitateDM);
	}

	//am hard-codat data curenta dar puteam sa o si cer la inceputul subprogramului
	//considerata 21/2/2021
	printf("\nAlimente expirate:\n");
	for (i = 0; i < falimenteCitite; ++i) {
		if (faliment[i].dataExpirare.an < 2021) {
			printf("%hu - %s - %hu %s - %g lei - %hhu/%hhu/%hd\n", faliment[i].cod, faliment[i].denumire, faliment[i].cantitate, faliment[i].unitateDM, faliment[i].pret, faliment[i].dataExpirare.zi, faliment[i].dataExpirare.luna, faliment[i].dataExpirare.an);
		}
		else if (faliment[i].dataExpirare.an == 2021 && faliment[i].dataExpirare.luna < 2) {
			printf("%hu - %s - %hu %s - %g lei - %hhu/%hhu/%hd\n", faliment[i].cod, faliment[i].denumire, faliment[i].cantitate, faliment[i].unitateDM, faliment[i].pret, faliment[i].dataExpirare.zi, faliment[i].dataExpirare.luna, faliment[i].dataExpirare.an);
		}
		else if (faliment[i].dataExpirare.an == 2021 && faliment[i].dataExpirare.luna == 2 && faliment[i].dataExpirare.zi < 21) {
			printf("%hu - %s - %hu %s - %g lei - %hhu/%hhu/%hd\n", faliment[i].cod, faliment[i].denumire, faliment[i].cantitate, faliment[i].unitateDM, faliment[i].pret, faliment[i].dataExpirare.zi, faliment[i].dataExpirare.luna, faliment[i].dataExpirare.an);
		}
	}
}
/*
1
Branza de vacuta
kg
245
16.5
25
2
2021
1
2
MicroPop
buc
69
1.9
19
2
2021
1
3
Cancer
litri
100
600009
30
1
2022
0
*/

int main()
{
	unsigned char alimenteCitite;
	Alimente_t aliment[4];
	citireAlimente(aliment, &alimenteCitite);
	printareAlimente(aliment, alimenteCitite);
	(void)getchar();
	return 0;
}