#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

#define EMPTY_SPACE ' '
#define ROCK_OUT_OF_VIEW 175
#define ROCK_FAR 176
#define ROCK_CLOSE 177
#define ROCK 178
#define ROCK_BEHIND 179
#define WAIT_MULTIPLIER 63

/*
#define EMPTY_SPACE 1
#define ROCK_OUT_OF_VIEW 10
#define ROCK_FAR 11
#define ROCK_CLOSE 12
#define ROCK 13
#define ROCK_BEHIND 14
#define WAIT_MULTIPLIER 63
*/

typedef const unsigned char csize_t;

struct entity {
	unsigned char x_coord;
	unsigned char y_coord;
	bool alive = TRUE;
};

void fontsize(int, int);

void generate_space(unsigned char*** fspace, const unsigned char space_depth, const unsigned char space_width, const unsigned char space_height);
void progress_space(unsigned char*** fspace, csize_t space_depth, csize_t space_height, csize_t space_width, csize_t player_x, csize_t player_y);
void print_space_all(unsigned char*** fspace, const unsigned char space_depth, const unsigned char space_height, const unsigned char space_width);
void print_space_visible(unsigned char*** fspace, csize_t space_height);
void check_for_keystroke(char& fkeystroke);
void space_allocation(unsigned char*** fspace, const unsigned char space_depth, const unsigned char space_height, const unsigned char space_width);
char move_accordingly(entity& player, const char keystroke);

int main()
{
	//declarations and allocations
	srand(time(NULL));
	LARGE_INTEGER frequency, time1, time2;
	QueryPerformanceFrequency(&frequency);
	unsigned char space_depth = 3;
	unsigned char space_height = 9;
	unsigned char space_width = 34;
	char keystroke;

	unsigned char*** space = (unsigned char***)calloc(space_depth, sizeof(unsigned char**));
	space_allocation(space, space_depth, space_height, space_width);

	entity player;
	player.y_coord = space_height / 2;
	player.x_coord = space_width / 2;

	//go fullscreen
	//SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	//set font size
	//fontsize(97, 97);
	//initial generation of environment
	//generate_space(space, space_depth, space_height, space_width);

	while (true) {
		system("cls");
		print_space_visible(space, space_height); //0.4 ms latest exec time
		check_for_keystroke(keystroke);
		if (keystroke) {
			move_accordingly(player, keystroke);
			keystroke = 0;
		}
		progress_space(space, space_depth, space_height, space_width, player.x_coord, player.y_coord); //0.022 ms latest exec time
	}

	return 0;
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
void print_space_all(unsigned char*** fspace, const unsigned char space_depth, const unsigned char space_height, const unsigned char space_width) {
	int index_depth, index_height, index_width;
	printf("Matrici:\n\n");
	for (index_depth = 0; index_depth < space_depth; ++index_depth) {
		printf("Matrice #%d:\n\n", index_depth);
		for (index_height = 0; index_height < space_height; ++index_height) {
			for (index_width = 0; index_width < space_width; ++index_width) {
				printf("%c", fspace[index_depth][index_height][index_width]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
void print_space_visible(unsigned char*** fspace, csize_t space_height) {
	int index_height, index_width;
	for (index_height = 0; index_height < space_height; ++index_height) {
		fputs((char*)fspace[0][index_height], stdout);
		printf("\n");
	}
}
void check_for_keystroke(char &fkeystroke) {
	for (int i = 0; i < WAIT_MULTIPLIER && !_kbhit(); ++i) {
		Sleep(1);
	}
	if (_kbhit()) {
		fkeystroke = _getch();
		fprintf(stdout, "keystroke: %c\n", fkeystroke);
	}
}
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
char move_accordingly(entity &player, const char keystroke) {
	switch (keystroke) {
	case 'w':
		--player.y_coord;
		break;
	case 'a':
		--player.x_coord;
		break;
	case 's':
		++player.y_coord;
		break;
	case 'd':
		++player.x_coord;
		break;
	default:
		return -1;
	}
	return 0;
}
void progress_space(unsigned char*** fspace, csize_t space_depth, csize_t space_height, csize_t space_width, csize_t player_x, csize_t player_y) {
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
			//fspace[0][player_y][player_x] = 3;
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