#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

int main()
{
	LARGE_INTEGER cpu_frequency, initial_time, final_time;
	QueryPerformanceFrequency(&cpu_frequency);
	char keystroke = 'n';
	while (true) {
		QueryPerformanceCounter(&initial_time);
		for (int i = 0; i < 63 && !_kbhit(); ++i) {
			Sleep(1);
		}
		QueryPerformanceCounter(&final_time);
		if (_kbhit()) {
			keystroke = _getch();
			fprintf(stdout, "keystroke: %c\n", keystroke);
		}
		printf("Cycle\n");
		printf("\n%lf\n", (double)(final_time.QuadPart - initial_time.QuadPart) * 1000 / cpu_frequency.QuadPart);
	}
	return 0;
}