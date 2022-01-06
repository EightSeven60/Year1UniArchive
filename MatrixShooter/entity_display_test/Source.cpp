#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

#define EMPTY_SPACE ' '
#define ROCK_OUT_OF_VIEW 175
#define ROCK_FAR 176
#define ROCK_CLOSE 177
#define ROCK 178
#define ROCK_BEHIND 179


HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

struct entity {
	unsigned char x_coord;
	unsigned char y_coord;
};

void space_allocation(unsigned char*** fspace, const unsigned char space_depth, const unsigned char space_height, const unsigned char space_width) {
	int index_depth, index_height, index_width;
	if (fspace != NULL) {
		for (index_depth = 0; index_depth < space_depth; ++index_depth) {
			fspace[index_depth] = (unsigned char**)calloc(space_height, sizeof(unsigned char*));
			if (fspace[index_depth] != NULL) {
				for (index_height = 0; index_height < space_height; ++index_height) {
					fspace[index_depth][index_height] = (unsigned char*)calloc(space_width, sizeof(unsigned char));
				}
			}
		}
	}
}
void fontsize(int a, int b) {
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}
void generate_space(unsigned char*** fspace, const unsigned char space_depth, const unsigned char space_height, const unsigned char space_width) {
	int index_depth, index_height, index_width;
	unsigned char object_seed;
	for (index_height = 0; index_height < space_height; ++index_height) {
		for (index_width = 0; index_width < space_width; ++index_width) {
			object_seed = rand() % 5;

			//generation of far space
			if (object_seed == 4) {
				fspace[space_depth - 1][index_height][index_width] = ROCK;
			}
			else {
				fspace[space_depth - 1][index_height][index_width] = EMPTY_SPACE;
			}

			//generation of visualisation of far space
			for (index_depth = space_depth - 2; index_depth >= 0; --index_depth) {
				if (fspace[index_depth + 1][index_height][index_width] > ROCK_FAR && fspace[index_depth + 1][index_height][index_width] < ROCK_BEHIND) {
					fspace[index_depth][index_height][index_width] = fspace[index_depth + 1][index_height][index_width] - 1;
				}
				else {
					fspace[index_depth][index_height][index_width] = EMPTY_SPACE;
				}
			}
		}
	}
}
void progress_space(unsigned char*** fspace, const unsigned char space_depth, const unsigned char space_height, const unsigned char space_width) {
	int index_depth, index_height, index_width;
	unsigned char object_seed;
	for (index_height = 0; index_height < space_height; ++index_height) {
		for (index_width = 0; index_width < space_width; ++index_width) {
			//move perspective forward
			for (index_depth = 0; index_depth < space_depth - 1; ++index_depth) {
				if (fspace[index_depth + 1][index_height][index_width] > ROCK_OUT_OF_VIEW && fspace[index_depth + 1][index_height][index_width] < ROCK_BEHIND) {
					fspace[index_depth][index_height][index_width] = fspace[index_depth + 1][index_height][index_width];
				}
				else {
					fspace[index_depth][index_height][index_width] = EMPTY_SPACE;
				}
			}
			//generation of far space
			object_seed = rand() % 5;
			if (object_seed == 4) {
				fspace[space_depth - 1][index_height][index_width] = ROCK;
				//generation of projection of far space
				if (fspace[space_depth - 2][index_height][index_width] < ROCK_OUT_OF_VIEW || fspace[space_depth - 2][index_height][index_width] > ROCK_BEHIND) {
					fspace[space_depth - 2][index_height][index_width] = ROCK_CLOSE;
				}
				if (fspace[space_depth - 3][index_height][index_width] < ROCK_OUT_OF_VIEW || fspace[space_depth - 3][index_height][index_width] > ROCK_BEHIND) {
					fspace[space_depth - 3][index_height][index_width] = ROCK_FAR;
				}
			}
			else {
				fspace[space_depth - 1][index_height][index_width] = EMPTY_SPACE;
			}
		}
	}
}
void print_space_visible(unsigned char*** fspace, const unsigned char space_depth, const unsigned char space_height, const unsigned char space_width) {
	int index_height, index_width;
	for (index_height = 0; index_height < space_height; ++index_height) {
		fputs((char*)fspace[0][index_height], stdout);
		printf("\n");
	}
}

int main()
{
	//declarations and allocations
	srand(time(NULL));
	LARGE_INTEGER frequency, time1, time2;
	QueryPerformanceFrequency(&frequency);
	unsigned char space_depth = 3;
	unsigned char space_height = 9;
	unsigned char space_width = 33;
	char keystroke;

	unsigned char*** space = (unsigned char***)calloc(space_depth, sizeof(unsigned char**));
	space_allocation(space, space_depth, space_height, space_width);

	entity player;
	player.x_coord = space_height / 2;
	player.y_coord = space_width / 2;

	//go fullscreen
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	//set font size
	fontsize(97, 97);
	//initial generation of environment
	//generate_space(space, space_depth, space_height, space_width);

	generate_space(space, space_depth, space_height, space_width);
	progress_space(space, space_depth, space_height, space_width);
	progress_space(space, space_depth, space_height, space_width);
	progress_space(space, space_depth, space_height, space_width);
	progress_space(space, space_depth, space_height, space_width);
	print_space_visible(space, space_depth, space_height, space_width);
	(void)_getch();

	return 0;
}