#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;

struct punct_t {
	int x = 0, y = 0, z = 0;
};

double distanta3D(punct_t fA, punct_t fB) {
	return sqrt(pow(fA.x - fB.x, 2) + pow(fA.y - fB.y, 2) + pow(fA.z - fB.z, 2));
}

int main()
{
	//declarari
	srand(time(NULL));
	punct_t A;
	punct_t B;

	//generare aleatorie puncte
	A.x = rand() % 21 - 10;
	printf("xA = %d\n", A.x);
	A.y = rand() % 21 - 10;
	printf("yA = %d\n", A.y);
	A.z = rand() % 21 - 10;
	printf("zA = %d\n\n", A.z);
	B.x = rand() % 21 - 10;
	printf("xB = %d\n", B.x);
	B.y = rand() % 21 - 10;
	printf("yB = %d\n", B.y);
	B.z = rand() % 21 - 10;
	printf("zB = %d\n\n", B.z);

	//calculare distanta
	printf("Distanta dintre punctul A si B: %g", distanta3D(A, B));

	(void)getchar();
	return 0;
}