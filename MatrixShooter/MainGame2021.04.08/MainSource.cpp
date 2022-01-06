#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
using namespace std;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#define EMPTY_SPACE ' '
#define ROCK_OUT_OF_VIEW 175
#define ROCK_FAR 176
#define ROCK_CLOSE 177
#define ROCK 178
#define ROCK_BEHIND 179
#define WAIT_MULTIPLIER 63 //default 63

typedef const unsigned char c_u_char;

struct entity {
	unsigned char x_coord;
	unsigned char y_coord;
	bool alive = TRUE;
};

void fontsize(int, int);

void generate_space(unsigned char*** fspace, c_u_char space_depth, c_u_char space_width, c_u_char space_height);
void progress_space(unsigned char*** fspace, c_u_char space_depth, c_u_char space_height, c_u_char space_width, c_u_char player_x, c_u_char player_y);
void print_space_all(unsigned char*** fspace, c_u_char space_depth, c_u_char space_height, c_u_char space_width);
void print_space_visible(unsigned char*** fspace, c_u_char space_height, entity& player);
void check_for_keystroke(char& fkeystroke);
void space_allocation(unsigned char*** fspace, c_u_char space_depth, c_u_char space_height, c_u_char space_width);
char move_accordingly(entity& player, const char keystroke, c_u_char space_depth, c_u_char space_height, c_u_char space_width);
void print_space_visible2(unsigned char*** fspace, c_u_char space_height, c_u_char space_width, entity& player);
void print_space_visible3(unsigned char*** fspace, c_u_char space_height, c_u_char space_width, entity& player);

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
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	//set font size
	//fontsize(97, 97);
	//initial generation of environment
	generate_space(space, space_depth, space_height, space_width);

	while (true) {
		system("cls");
		QueryPerformanceCounter(&time1);
		//print_space_visible(space, space_height, player); //0.45 ms latest exec time
		print_space_visible3(space, space_height, space_width, player); //0.5 ms latest exec time
		QueryPerformanceCounter(&time2);
		puts("\nTime taken: ");
		printf("%lf.\n", (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart);
		check_for_keystroke(keystroke);
		if (keystroke) {
			if (move_accordingly(player, keystroke, space_depth, space_height, space_width) == 10) {
				return 0;
			}
			keystroke = 0;
		}
		progress_space(space, space_depth, space_height, space_width, player.x_coord, player.y_coord); //0.022 ms latest exec time
	}

	return 0;
}

void generate_space(unsigned char*** fspace, c_u_char space_depth, c_u_char space_height, c_u_char space_width) {
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
void print_space_all(unsigned char*** fspace, c_u_char space_depth, c_u_char space_height, c_u_char space_width) {
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
void print_space_visible(unsigned char*** fspace, c_u_char space_height, entity& player) {
	int index_height, index_width;
	for (index_height = 0; index_height < space_height; ++index_height) {
		fputs((char*)fspace[0][index_height], stdout);
		printf("\n");
	}
}
void print_space_visible2(unsigned char*** fspace, c_u_char space_height, c_u_char space_width, entity& player) {
	int index_height, index_width;
	for (index_height = 0; index_height < space_height; ++index_height) {
		for (index_width = 0; index_width < space_width; ++index_width) {
			fputc(fspace[0][index_height][index_width], stdout);
		}
		fputc(10, stdout);
	}
}
void print_space_visible3(unsigned char*** fspace, c_u_char space_height, c_u_char space_width, entity& player) {
	int index_height, index_width;
	for (index_height = 0; index_height < space_height; ++index_height) {
		if (index_height != player.y_coord) { //if we are not writing the line on which the player is located we use fputs for efficiency
			fputs((char*)fspace[0][index_height], stdout);
			putc('\n', stdout);
		}
		else { //when we come across the line that contains the player we use a buffer to print everything up to the player, then print the player, then print the rest
			unsigned char* buffer = (unsigned char*)calloc(max(player.x_coord, space_width - player.x_coord) + 1, sizeof(unsigned char));
			int index_buffer;

			for (index_width = 0; index_width < player.x_coord; ++index_width) {
				buffer[index_width] = fspace[0][index_height][index_width];
			}
			++index_width;
			printf("%s", buffer);

			SetConsoleTextAttribute(hConsole, 4);
			fputc(3, stdout);
			SetConsoleTextAttribute(hConsole, 15);

			for (index_buffer = 0; index_buffer < max(player.x_coord, space_width - player.x_coord); ++index_width, ++index_buffer) {
				if (buffer != NULL) {
					if (index_width < space_width) {
						buffer[index_buffer] = fspace[0][index_height][index_width];
					}
					else {
						buffer[index_buffer] = 0;
					}
				}
			}
			printf("%s\n", buffer);
		}
	}
}
void check_for_keystroke(char& fkeystroke) {
	for (int i = 0; i < WAIT_MULTIPLIER && !_kbhit(); ++i) {
		Sleep(1);
	}
	if (_kbhit()) {
		fkeystroke = _getch();
		//fprintf(stdout, "keystroke: %c\n", fkeystroke);
	}
}
void space_allocation(unsigned char*** fspace, c_u_char space_depth, c_u_char space_height, c_u_char space_width) {
	int index_depth, index_height, index_width;
	if (fspace != NULL) {
		for (index_depth = 0; index_depth < space_depth; ++index_depth) {
			fspace[index_depth] = (unsigned char**)calloc(space_height, sizeof(unsigned char*));
			if (fspace[index_depth] != NULL) {
				for (index_height = 0; index_height < space_height; ++index_height) {
					fspace[index_depth][index_height] = (unsigned char*)calloc(space_width + 1, sizeof(unsigned char));
					//+1 adds a '\0' to be used by the printing function
				}
			}
		}
	}
}
char move_accordingly(entity& player, const char keystroke, c_u_char space_depth, c_u_char space_height, c_u_char space_width) {
	switch (keystroke) {
	case 'w':
		if (player.y_coord > 0) {
			--player.y_coord;
		}
		break;
	case 'a':
		if (player.x_coord > 0) {
			--player.x_coord;
		}
		break;
	case 's':
		if (player.y_coord < space_height - 1) {
			++player.y_coord;
		}
		break;
	case 'd':
		if (player.x_coord < space_width - 1) {
			++player.x_coord;
		}
		break;
	case 27: //27 is 'ESC' in ASCII
		return 10; //10 means that the user pressed escape to exit the program
	default:
		//in the default case, the player moves forward before the move time is up
		return 0;
	}
}
void progress_space(unsigned char*** fspace, c_u_char space_depth, c_u_char space_height, c_u_char space_width, c_u_char player_x, c_u_char player_y) {
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
	fspace[0][player_y][player_x] = 3;
}

void fontsize(int a, int b) {
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}