#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

typedef const unsigned char c_u_char;
typedef unsigned char u_char;
typedef const char c_char;

class settings {
public:

	char play_area_height = 9;
	char play_area_width = 18;
	u_int font_size = 97;
	char go_up = 119;
	char go_down = 115;
	char go_left = 97;
	char go_right = 100;
	char back = 27;
	u_char player_icon = 3;
	u_char empty_space = ' ';
	u_char rock_far = 176;
	u_char rock_close = 177;
	u_char rock = 178;
	u_int wait_multiplier = 63;
	u_int font_color_default = 4;
	u_int font_color_rock = 244; //from this line, the 3 colors are used to display rocks behind the player character,
	u_int font_color_rock_close = 116; //you may need to adjust accordingly if you choose to display custom characters
	u_int font_color_rock_far = 132; //to represent the obstacles / rocks.
	

	FILE* search_string(FILE* file, c_char* phrase) {
		if (file == NULL) {
			return NULL; //passed file pointer is invalid
		}
		int phrase_lenth = (int)strlen(phrase);
		char reached_EOF = FALSE;
		int index_phrase = 0;
		char character_file;
		character_file = fgetc(file);
		void* original_file = file->_Placeholder;
		fseek(file, -1, SEEK_CUR);
		while (TRUE) {
			if (feof(file) && reached_EOF) {
				file->_Placeholder = original_file;
				return file; //phrase not found
			}
			else if (feof(file)) {
				reached_EOF = TRUE;
				rewind(file);
			}

			character_file = fgetc(file);
			if (phrase[index_phrase] == character_file) {
				++index_phrase;
			}
			else {
				index_phrase = 0;
			}

			if (index_phrase == phrase_lenth) {
				return file;
			}
		}
		file->_Placeholder = original_file;
		return file;
	}
	int load_settings() {
		int r_value = 0;
		FILE* settings_file = fopen("Settings.txt", "r");
		if (settings_file == NULL) {
			return -1; //settings file not found, will use defaults
		}

		settings_file = search_string(settings_file, "play area size: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhd", &play_area_height);
			fseek(settings_file, 3, SEEK_CUR);
			(void)fscanf(settings_file, "%hhd", &play_area_width);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "font size: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%ud", &font_size);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "go up: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhd", &go_up);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "go down: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhd", &go_down);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "go left: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhd", &go_left);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "go right: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhd", &go_right);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "back: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhd", &back);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "player icon: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhd", &player_icon);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "empty_space: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhu", &empty_space);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "rock_far: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhu", &rock_far);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "rock_close: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhu", &rock_close);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "rock: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhu", &rock);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "wait_multiplier: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%u", &wait_multiplier);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "font_color_default: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%u", &font_color_default);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "font_color_rock: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%u", &font_color_rock);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "font_color_rock_close: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%u", &font_color_rock_close);
		}
		else r_value = 1;

		settings_file = search_string(settings_file, "font_color_rock_far: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%u", &font_color_rock_far);
		}
		else r_value = 1;

		if (settings_file != NULL) {
			fclose(settings_file);
		}
		else r_value = 2;
		return r_value;
	}
};
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
						fspace[index_depth][index_height] = (unsigned char*)calloc((width + 1), sizeof(unsigned char));
						//+1 adds a '\0' to be used by the printing function
					}
				}
			}
		}
		return fspace;
	}
	void generate(settings options) {
		int index_depth, index_height, index_width;
		unsigned char object_seed;
		for (index_height = 0; index_height < height; ++index_height) {
			for (index_width = 0; index_width < width; ++index_width) {
				object_seed = rand() % 5;

				//generation of far space
				if (object_seed == 4) {
					content[depth - 1][index_height][index_width] = options.rock;
				}
				else {
					content[depth - 1][index_height][index_width] = options.empty_space;
				}

				//generation of visualisation of far space
				for (index_depth = depth - 2; index_depth >= 0; --index_depth) {
					/*
					if (content[index_depth + 1][index_height][index_width] > ROCK_FAR && content[index_depth + 1][index_height][index_width] < ROCK_BEHIND) {
						content[index_depth][index_height][index_width] = content[index_depth + 1][index_height][index_width] - 1;
					}
					else {
						content[index_depth][index_height][index_width] = EMPTY_SPACE;
					}
					*/
					if (content[index_depth + 1][index_height][index_width] == options.rock_close ||
						content[index_depth + 1][index_height][index_width] == options.rock) {
						content[index_depth][index_height][index_width] = content[index_depth + 1][index_height][index_width] - 1;
					}
					else {
						content[index_depth][index_height][index_width] = options.empty_space;
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
	void print_space_visible3(u_char player_x_coord, u_char player_y_coord, c_char player_icon, settings options) {
		int index_height, index_width;
		//system("cls");
		COORD cursor_position;
		cursor_position.X = 0;
		cursor_position.Y = 0;
		SetConsoleCursorPosition(hConsole, cursor_position);
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
				if (content[0][player_y_coord][player_x_coord] == options.rock) {
					SetConsoleTextAttribute(hConsole, options.font_color_rock);
				}
				else if (content[1][player_y_coord][player_x_coord] == options.rock) {
					SetConsoleTextAttribute(hConsole, options.font_color_rock_close);
				}
				else if (content[2][player_y_coord][player_x_coord] == options.rock) {
					SetConsoleTextAttribute(hConsole, options.font_color_rock_far);
				}
				else {
					SetConsoleTextAttribute(hConsole, options.font_color_default);
				}
				fputc(player_icon, stdout);
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
	void progress_space(settings options) {
		int index_depth, index_height, index_width;
		unsigned char object_seed;
		for (index_height = 0; index_height < height; ++index_height) {
			for (index_width = 0; index_width < width; ++index_width) {
				//move perspective forward
				for (index_depth = 0; index_depth < depth - 1; ++index_depth) {
					content[index_depth][index_height][index_width] = content[index_depth + 1][index_height][index_width];
				}
				//generation of far space
				object_seed = rand() % 5;
				if (object_seed == 4) {
					content[depth - 1][index_height][index_width] = options.rock;
					//generation of projection of far space
					/*
					if (content[depth - 2][index_height][index_width] < ROCK_OUT_OF_VIEW || content[depth - 2][index_height][index_width] > ROCK_BEHIND) {
						content[depth - 2][index_height][index_width] = ROCK_CLOSE;
					}
					if (content[depth - 3][index_height][index_width] < ROCK_OUT_OF_VIEW || content[depth - 3][index_height][index_width] > ROCK_BEHIND) {
						content[depth - 3][index_height][index_width] = ROCK_FAR;
					}
					*/
					if (content[depth - 2][index_height][index_width] != options.rock && 
						content[depth - 2][index_height][index_width] != options.rock_close && 
						content[depth - 2][index_height][index_width] != options.rock_far) {
						content[depth - 2][index_height][index_width] = options.rock_close;
					}
					if (content[depth - 3][index_height][index_width] != options.rock && 
						content[depth - 3][index_height][index_width] != options.rock_close && 
						content[depth - 3][index_height][index_width] != options.rock_far) {
						content[depth - 3][index_height][index_width] = options.rock_far;
					}
				}
				else {
					content[depth - 1][index_height][index_width] = options.empty_space;
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
	char move_accordingly(c_char keystroke, u_char space_height, u_char space_width, settings options) {
		if (keystroke == options.go_up) {
			if (y_coord > 0) {
				--y_coord;
			}
			return options.go_up;
		}
		else if (keystroke == options.go_left) {
			if (x_coord > 0) {
				--x_coord;
			}
			return options.go_left;
		}
		else if (keystroke == options.go_down) {
			if (y_coord < space_height - 1) {
				++y_coord;
			}
			return options.go_down;
		}
		else if (keystroke == options.go_right) {
			if (x_coord < space_width - 1) {
				++x_coord;
			}
			return options.go_right;
		}
		else if (keystroke == options.back) {
			return options.back;
		}
		else return 0;
	}
	bool check_death(u_char*** space_content, settings options) {
		if (space_content[0][y_coord][x_coord] == options.rock) {
			system("cls");
			puts("You died colliding with a rock!\n");
			return true;
		}
		else return false;
	}
};

void check_for_keystroke(char& fkeystroke, settings options) {
	for (int i = 0; i < options.wait_multiplier && !_kbhit(); ++i) {
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
	//game initialization
	srand(0);
	LARGE_INTEGER frequency, time1, time2;
	QueryPerformanceFrequency(&frequency);
	settings options;
	options.load_settings();

	char keystroke;

	space place(3, options.play_area_height, options.play_area_width);
	player_entity player(place.width, place.height);

	//go fullscreen
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	fontsize(options.font_size, options.font_size);
	//initial generation of environment
	place.generate(options);

	while (true) {
		QueryPerformanceCounter(&time1);
		place.print_space_visible3(player.x_coord, player.y_coord, options.player_icon, options); //1.5 ms latest average exec time
		QueryPerformanceCounter(&time2);
		puts("\nTime taken: ");
		printf("%lf.\n", (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart);
		check_for_keystroke(keystroke, options);
		if (keystroke) {
			if (player.move_accordingly(keystroke, place.height, place.width, options) == options.back) {
				return 0;
			}
			keystroke = 0;
		}
		if (player.check_death(place.content, options)) {
			exit(0); //replace with death screen
		}
		place.progress_space(options); //0.022 ms latest exec time
	}

	return 0;
}