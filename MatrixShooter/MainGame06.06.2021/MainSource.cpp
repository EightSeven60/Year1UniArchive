#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
//using namespace std;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#define EMPTY_SPACE ' '
#define ROCK_OUT_OF_VIEW 175
#define ROCK_FAR 176
#define ROCK_CLOSE 177
#define ROCK 178
#define ROCK_BEHIND 179
#define WAIT_MULTIPLIER 1000 //default 63
#define FONT_COLOR_DEFAULT 4
#define FONT_COLOR_ROCK 244
#define FONT_COLOR_ROCK_CLOSE 116
#define FONT_COLOR_ROCK_FAR 132

typedef const unsigned char c_u_char;
typedef unsigned char u_char;
typedef const char c_char;

class space {
public:

	u_char depth;
	u_char height;
	u_char width;
	u_char*** content;
	long distance_travelled;

	space(u_char d, u_char h, u_char w) {
		depth = d;
		height = h;
		width = w;
		content = allocation();
	}
	u_char*** allocation() {
		u_char*** fspace = (u_char***)calloc(depth, sizeof(u_char**));
		int index_depth, index_height;
		if (fspace != NULL) {
			for (index_depth = 0; index_depth < depth; ++index_depth) {
				fspace[index_depth] = (unsigned char**)calloc(height, sizeof(unsigned char*));
				if (fspace[index_depth] != NULL) {
					for (index_height = 0; index_height < height; ++index_height) {
						fspace[index_depth][index_height] = (unsigned char*)calloc(width + 1, sizeof(unsigned char));
						//+1 adds a '\0' to be used by the printing function
					}
				}
			}
		}
		return fspace;
	}
	void generate() {
		int index_depth, index_height, index_width;
		unsigned char object_seed;
		for (index_height = 0; index_height < height; ++index_height) {
			for (index_width = 0; index_width < width; ++index_width) {
				object_seed = rand() % 5;

				//generation of far space
				if (object_seed == 4) {
					content[depth - 1][index_height][index_width] = ROCK;
				}
				else {
					content[depth - 1][index_height][index_width] = EMPTY_SPACE;
				}

				//generation of visualisation of far space
				for (index_depth = depth - 2; index_depth >= 0; --index_depth) {
					if (content[index_depth + 1][index_height][index_width] > ROCK_FAR && content[index_depth + 1][index_height][index_width] < ROCK_BEHIND) {
						content[index_depth][index_height][index_width] = content[index_depth + 1][index_height][index_width] - 1;
					}
					else {
						content[index_depth][index_height][index_width] = EMPTY_SPACE;
					}
				}
			}
		}
	}
	void print_space_all() {
		int index_depth, index_height, index_width;
		printf("Matrici:\n\n");
		for (index_depth = 0; index_depth < depth; ++index_depth) {
			printf("Matrice #%d:\n\n", index_depth);
			for (index_height = 0; index_height < height; ++index_height) {
				for (index_width = 0; index_width < width; ++index_width) {
					printf("%c", content[index_depth][index_height][index_width]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	void print_space_visible3(u_char player_x_coord, u_char player_y_coord) {
		int index_height, index_width;
		system("cls");
		for (index_height = 0; index_height < height; ++index_height) {
			if (index_height != player_y_coord) { //if we are not writing the line on which the player is located we use fputs for efficiency   0.05
				fputs((char*)content[0][index_height], stdout);
				putc('\n', stdout);
			}
			else { //when we come across the line that contains the player we use a buffer to print everything up to the player, then print the player, then the rest
				unsigned char* buffer = (unsigned char*)calloc(max(player_x_coord, width - player_x_coord) + 1, sizeof(unsigned char));
				int index_buffer;

				//puts the start of the line into the buffer then prints it
				for (index_width = 0; index_width < player_x_coord; ++index_width) {
					buffer[index_width] = content[0][index_height][index_width];
				}
				++index_width;
				printf("%s", buffer);

				//we need to pick a color scheme for the player display character, then print it
				if (content[0][player_y_coord][player_x_coord] == ROCK) {
					SetConsoleTextAttribute(hConsole, FONT_COLOR_ROCK);
				}
				else if (content[1][player_y_coord][player_x_coord] == ROCK) {
					SetConsoleTextAttribute(hConsole, FONT_COLOR_ROCK_CLOSE);
				}
				else if (content[2][player_y_coord][player_x_coord] == ROCK) {
					SetConsoleTextAttribute(hConsole, FONT_COLOR_ROCK_FAR);
				}
				else {
					SetConsoleTextAttribute(hConsole, FONT_COLOR_DEFAULT);
				}
				fputc(3, stdout);
				SetConsoleTextAttribute(hConsole, 15);

				//transfers the rest into the buffer then prints it
				for (index_buffer = 0; index_buffer < max(player_x_coord, width - player_x_coord); ++index_width, ++index_buffer) {
					if (buffer != NULL) {
						if (index_width < width) {
							buffer[index_buffer] = content[0][index_height][index_width];
						}
						else {
							buffer[index_buffer] = 0;
						}
					}
				}
				printf("%s\n", buffer);
			}
		}
		//printf("\n\n0: %c\n1: %c\n2: %c", content[0][player_y_coord][player_x_coord], content[1][player_y_coord][player_x_coord], content[2][player_y_coord][player_x_coord]);
	}
	void progress_space() {
		int index_depth, index_height, index_width;
		unsigned char object_seed;
		for (index_height = 0; index_height < height; ++index_height) {
			for (index_width = 0; index_width < width; ++index_width) {
				//move perspective forward
				for (index_depth = 0; index_depth < depth - 1; ++index_depth) {
					if (content[index_depth + 1][index_height][index_width] > ROCK_OUT_OF_VIEW && content[index_depth + 1][index_height][index_width] < ROCK_BEHIND) {
						content[index_depth][index_height][index_width] = content[index_depth + 1][index_height][index_width];
					}
					else {
						content[index_depth][index_height][index_width] = EMPTY_SPACE;
					}
				}
				//generation of far space
				object_seed = rand() % 5;
				if (object_seed == 4) {
					content[depth - 1][index_height][index_width] = ROCK;
					//generation of projection of far space
					if (content[depth - 2][index_height][index_width] < ROCK_OUT_OF_VIEW || content[depth - 2][index_height][index_width] > ROCK_BEHIND) {
						content[depth - 2][index_height][index_width] = ROCK_CLOSE;
					}
					if (content[depth - 3][index_height][index_width] < ROCK_OUT_OF_VIEW || content[depth - 3][index_height][index_width] > ROCK_BEHIND) {
						content[depth - 3][index_height][index_width] = ROCK_FAR;
					}
				}
				else {
					content[depth - 1][index_height][index_width] = EMPTY_SPACE;
				}
			}
		}
		//content[0][player_y][player_x] = 3;
		++distance_travelled;
	}
};

class player_entity {
public:

	unsigned char x_coord;
	unsigned char y_coord;
	bool alive;

	player_entity(u_char space_width, u_char space_height) {
		x_coord = space_width / 2;
		y_coord = space_height / 2;
		alive = TRUE;
	}
	char move_accordingly(c_char keystroke, u_char space_height, u_char space_width) {
		switch (keystroke) {
		case 'w':
			if (y_coord > 0) {
				--y_coord;
			}
			return 'w';
		case 'a':
			if (x_coord > 0) {
				--x_coord;
			}
			return 'a';
		case 's':
			if (y_coord < space_height - 1) {
				++y_coord;
			}
			return 's';
		case 'd':
			if (x_coord < space_width - 1) {
				++x_coord;
			}
			return 'd';
		case 27: //27 is 'ESC' in ASCII
			return 27; //27 means that the user pressed escape to exit
		default:
			//in the default case, the player moves forward before the move time is up
			return 0;
		}
	}
	bool check_death(u_char*** space_content) {
		if (space_content[0][y_coord][x_coord] == ROCK) {
			system("cls");
			puts("You died colliding with a rock!\n");
			return true;
		}
		else return false;
	}
};

void check_for_keystroke(char& fkeystroke) {
	for (int i = 0; i < WAIT_MULTIPLIER && !_kbhit(); ++i) {
		Sleep(1);
	}
	if (_kbhit()) {
		fkeystroke = _getch();
		//fprintf(stdout, "keystroke: %c\n", fkeystroke);
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

int main()
{
	//declarations and allocations
	srand(time(NULL));
	LARGE_INTEGER frequency, time1, time2;
	QueryPerformanceFrequency(&frequency);

	char keystroke;

	space place(3, 9, 18);
	player_entity player(place.width, place.height);

	//go fullscreen
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	//set font size
	//fontsize(97, 97);
	fontsize(50, 50);
	//initial generation of environment
	place.generate();

	while (true) {
		//QueryPerformanceCounter(&time1);
		place.print_space_visible3(player.x_coord, player.y_coord); //0.5 ms latest exec time
		//QueryPerformanceCounter(&time2);
		//puts("\nTime taken: ");
		//printf("%lf.\n", (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart);
		check_for_keystroke(keystroke);
		if (keystroke) {
			if (player.move_accordingly(keystroke, place.height, place.width) == 10) {
				return 0;
			}
			keystroke = 0;
		}
		if (player.check_death(place.content)) {
			exit(0); //replace with death screen
		}
		place.progress_space(); //0.022 ms latest exec time
	}

	return 0;
}