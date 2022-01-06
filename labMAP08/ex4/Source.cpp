#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>
using namespace std;

int n;

struct Punct {
	int x, y;
}*v;
struct Dreptunghi {
	int x, y, h, l;
}DrMax;

bool esteDreptunghiMaxim(int x, int y, int L, int H) {
	return ((L * H) > (DrMax.h * DrMax.l));
}
int gasireGauri(int x, int y, int L, int H) {
	for (int i = 0; i < n; ++i) {
		if (v[i].x > x && v[i].x<x + L && v[i].y>y && v[i].y < y + H) return i;
	}
	return -1;
}
void taieturi(int x, int y, int L, int H) {//coordonate stanga sus+latime+inaltime
	int indexGaura = gasireGauri(x, y, L, H);
	if (indexGaura == -1) {
		if (esteDreptunghiMaxim(x, y, L, H)) {
			DrMax.x = x; DrMax.y = y;
			DrMax.h = H; DrMax.l = L;
		}
	}
	else {
		int gx, gy;
		gx = v[indexGaura].x;
		gy = v[indexGaura].y;
		taieturi(x, y, gx - x, H);
		taieturi(gx, y, L - gx + x, H);
		taieturi(x, y, L, gy - y);
		taieturi(x, gy, L, H - gy + y);
	}

}
void taieturi2(int x, int y, int xplusL, int yplusH) { //coordonate colt st. sus + colt dr jos
	int L = xplusL - x, H = yplusH - y;
	int indexGaura = gasireGauri(x, y, L, H);
	if (indexGaura == -1) {
		if (esteDreptunghiMaxim(x, y, L, H)) {
			DrMax.x = x; DrMax.y = y;
			DrMax.h = H; DrMax.l = L;
		}
	}
	else {
		int gx, gy;
		gx = v[indexGaura].x;
		gy = v[indexGaura].y;
		taieturi2(x, y, gx, y + H);
		taieturi2(gx, y, x + L, y + H);
		taieturi2(x, y, x + L, gy);
		taieturi2(x, gy, x + L, y + H);
	}
}

int main()
{
	int H, L;
	FILE* file1 = fopen("Taieturi2.txt", "r");
	(void)fscanf(file1, "%d%d%d", &H, &L, &n);
	v = new Punct[n];
	for (int i = 0; i < n; ++i) {
		(void)fscanf(file1, "%d%d", &v[i].x, &v[i].y);
	}
	fclose(file1);
	//taieturi(0,0,L,H);
	taieturi2(0, 0, 0 + L, 0 + H);
	cout << "Aria maxima este: " << DrMax.h * DrMax.l << " Coodonatele tablei: " << DrMax.x << " " << DrMax.y << " " << DrMax.h << " " << DrMax.l << endl;
	delete[] v;

	printf("Press Enter to %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand(), rand());
	(void)getchar();
	return 0;
}