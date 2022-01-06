#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define UNINITIALIZED_SAVE 0
#define INITIALIZED_SAVE 1
#define SPACE_DEPTH 3
#define SPACE_HEIGHT 9
#define SPACE_WIDTH 19
#define ESCAPE 27

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

typedef const unsigned char c_u_char;
typedef unsigned char u_char;
typedef const char c_char;

void check_for_keystroke(char& fkeystroke) {
	while (!_kbhit()) {
		Sleep(1);
	}
	if (_kbhit()) {
		fkeystroke = _getch();
		//fprintf(stdout, "keystroke: %c\n", fkeystroke);
	}
}
int clear() {
	COORD cursor_position;
	cursor_position.X = 0;
	cursor_position.Y = 0;
	SetConsoleCursorPosition(hConsole, cursor_position);
	printf(
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
	);
	SetConsoleCursorPosition(hConsole, cursor_position);
	return 0;
}
FILE* search_string(char file_path[32], c_char* phrase) {
	FILE* file = fopen(file_path, "r");
	if (file == NULL) {
		return NULL; //passed file pointer is invalid
	}
	int phrase_length = (int)strlen(phrase);
	char reached_EOF = FALSE;
	int index_phrase = 0;
	char character_file;
	while (TRUE) {
		if (feof(file) && reached_EOF) {
			return NULL; //phrase not found
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

		if (index_phrase == phrase_length) {
			return file; //phrase found
		}
	}
	return NULL; //phrase not found
}
FILE* search_string(FILE* file, c_char* phrase) {
	if (file == NULL) {
		return NULL; //passed file pointer is invalid
	}
	int phrase_length = (int)strlen(phrase);
	char reached_EOF = FALSE;
	int index_phrase = 0;
	char character_file;
	while (TRUE) {
		if (feof(file) && reached_EOF) {
			return NULL; //phrase not found
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

		if (index_phrase == phrase_length) {
			return file; //phrase found
		}
	}
	return NULL; //phrase not found
}
long int search_string_pos(FILE* file, c_char* phrase) {
	if (file == NULL) {
		return -1; //passed file pointer is invalid
	}
	int phrase_length = (int)strlen(phrase);
	char reached_EOF = FALSE;
	int index_phrase = 0;
	char character_file;
	while (TRUE) {
		if (feof(file) && reached_EOF) {
			return -2; //phrase not found
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

		if (index_phrase == phrase_length) {
			return ftell(file) - (long int)phrase_length; //phrase found
		}
	}
	return -2; //phrase not found
}
void fontsize(int a, int b) {
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}

class settings {
public:

	char go_up = 119;
	char go_down = 115;
	char go_left = 97;
	char go_right = 100;
	char back = ESCAPE;
	u_char player_icon = 3;
	u_char empty_space = ' ';
	u_char rock_far = 176;
	u_char rock_close = 177;
	u_char rock = 178;
	//u_int wait_multiplier = 63;
	u_int font_color_default = 4;
	u_int font_color_rock = 244; //from this line, the 3 colors are used to display rocks behind the player character,
	u_int font_color_rock_close = 116; //you may need to adjust accordingly if you choose to display custom characters
	u_int font_color_rock_far = 132; //to represent the obstacles / rocks.

	int load_settings() {
		int r_value = 0;
		FILE* settings_file = fopen("Settings.txt", "r");
		FILE* og;
		if (settings_file == NULL) {
			return -1; //settings file not found, will use defaults
		}

		og = settings_file;
		settings_file = search_string(settings_file, "go up: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhd", &go_up);
		}
		else {
			r_value = 1;
			settings_file = og;
		}

		og = settings_file;
		settings_file = search_string(settings_file, "go down: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhd", &go_down);
		}
		else {
			r_value = 1;
			settings_file = og;
		}

		og = settings_file;
		settings_file = search_string(settings_file, "go left: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhd", &go_left);
		}
		else {
			r_value = 1;
			settings_file = og;
		}

		og = settings_file;
		settings_file = search_string(settings_file, "go right: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhd", &go_right);
		}
		else {
			r_value = 1;
			settings_file = og;
		}

		og = settings_file;
		settings_file = search_string(settings_file, "player icon: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhd", &player_icon);
		}
		else {
			r_value = 1;
			settings_file = og;
		}

		og = settings_file;
		settings_file = search_string(settings_file, "empty_space: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhu", &empty_space);
		}
		else {
			r_value = 1;
			settings_file = og;
		}

		og = settings_file;
		settings_file = search_string(settings_file, "rock_far: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhu", &rock_far);
		}
		else {
			r_value = 1;
			settings_file = og;
		}

		og = settings_file;
		settings_file = search_string(settings_file, "rock_close: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhu", &rock_close);
		}
		else {
			r_value = 1;
			settings_file = og;
		}

		og = settings_file;
		settings_file = search_string(settings_file, "rock: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%hhu", &rock);
		}
		else {
			r_value = 1;
			settings_file = og;
		}
		/*
		og = settings_file;
		settings_file = search_string(settings_file, "wait_multiplier: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%u", &wait_multiplier);
		}
		else {
			r_value = 1;
			settings_file = og;
		}
		*/
		og = settings_file;
		settings_file = search_string(settings_file, "font_color_default: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%u", &font_color_default);
		}
		else {
			r_value = 1;
			settings_file = og;
		}

		og = settings_file;
		settings_file = search_string(settings_file, "font_color_rock: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%u", &font_color_rock);
		}
		else {
			r_value = 1;
			settings_file = og;
		}

		og = settings_file;
		settings_file = search_string(settings_file, "font_color_rock_close: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%u", &font_color_rock_close);
		}
		else {
			r_value = 1;
			settings_file = og;
		}

		og = settings_file;
		settings_file = search_string(settings_file, "font_color_rock_far: ");
		if (settings_file) {
			(void)fscanf(settings_file, "%u", &font_color_rock_far);
		}
		else {
			r_value = 1;
			settings_file = og;
		}

		if (settings_file != NULL) {
			fclose(settings_file);
		}
		else r_value = 2;
		return r_value;
	}
	int save_settings() {
		int r_value = 0;
		FILE* settings_file = fopen("Settings.txt", "w");
		if (settings_file == NULL) {
			return -1; //this should not have happened, check standing with your local gods
		}

		fprintf(settings_file, "go up: %hhd\n"
			"go down: %hhd\n"
			"go left: %hhd\n"
			"go right: %hhd\n"
			"player icon: %hhu //check note below before editing\n"
			"empty_space: %hhu\n"
			"rock_far: %hhu\n"
			"rock_close: %hhu\n"
			"rock: %hhu\n"
			"font_color_default: %u\n"
			"\n//from this line, the 3 colors are used to display rocks behind the player character\n"
			"//you may need to adjust accordingly if you choose to display a custom character color\n"
			"font_color_rock: %u\n"
			"font_color_rock_close: %u\n"
			"font_color_rock_far: %u",
			go_up, go_down, go_left, go_right, player_icon, empty_space,
			rock_far, rock_close, rock, font_color_default, font_color_rock, font_color_rock_close, font_color_rock_far);
		fclose(settings_file);
		return 0;

	}
	int run() {
		char keystroke;
		char escape = 0;
		settings default_options;
		while (escape == 0) {
			clear();
			fontsize(40, 40);
			printf("OPTIONS - some have the representative characters but also their ASCII codes.\n\n"
				"0. go forward = any key that isn't assigned to some other action\n"
				"1. go_up = \'%c\'\n"
				"2. go_down = \'%c\'\n"
				"3. go_left = \'%c\'\n"
				"4. go_right = \'%c\'\n"
				"5. back = ESCAPE\n"
				"6. player_icon = %hhu \'%c\'\n"
				"7. empty_space = \'%c\'\n"
				"8. rock_far = %hhu \'%c\'\n"
				"9. rock_close = %hhu \'%c\'\n"
				"q. rock = %hhu \'%c\'\n",
				go_up, go_down, go_left, go_right, player_icon, player_icon,
				empty_space, rock_far, rock_far, rock_close, rock_close, rock, rock);
			printf("w. font_color_default = %u ", font_color_default);
			SetConsoleTextAttribute(hConsole, font_color_default);
			printf("\'%c\'\n", player_icon);
			SetConsoleTextAttribute(hConsole, 7);
			printf("e. font_color_rock = %u ", font_color_rock);
			SetConsoleTextAttribute(hConsole, font_color_rock);
			printf("\'%c\'\n", player_icon);
			SetConsoleTextAttribute(hConsole, 7);
			printf("r. font_color_rock_close = %u ", font_color_rock_close);
			SetConsoleTextAttribute(hConsole, font_color_rock_close);
			printf("\'%c\'\n", player_icon);
			SetConsoleTextAttribute(hConsole, 7);
			printf("t. font_color_rock_far = %u ", font_color_rock_far);
			SetConsoleTextAttribute(hConsole, font_color_rock_far);
			printf("\'%c\'\n", player_icon);
			SetConsoleTextAttribute(hConsole, 7);
			printf("\np. Load default settings\nPress escape to save and exit settings menu.\n");

			check_for_keystroke(keystroke);
			switch (keystroke) {
			case '1':
				clear();
				printf("Press new key.\n1. go_up = ");
				check_for_keystroke(keystroke);
				go_up = keystroke;
				break;
			case '2':
				clear();
				printf("Press new key.\n2. go_down = ");
				check_for_keystroke(keystroke);
				go_down = keystroke;
				break;
			case '3':
				clear();
				printf("Press new key.\n3. go_left = ");
				check_for_keystroke(keystroke);
				go_left = keystroke;
				break;
			case '4':
				clear();
				printf("Press new key.\n4. go right = ");
				check_for_keystroke(keystroke);
				go_right = keystroke;
				break;
			case '5':
				clear();
				printf("This keybind cannot be changed. Press Enter to return.\n");
				(void)getchar();
				break;
			case '6':
				clear();
				printf("Enter new ASCII code.\n6. player_icon = ");
				(void)scanf("%hhu", &player_icon);
				(void)getchar();
				break;
			case '7':
				clear();
				printf("Enter new ASCII code.\n7. empty_space = ");
				(void)scanf("%hhu", &empty_space);
				(void)getchar();
				break;
			case '8':
				clear();
				printf("Enter new ASCII code.\n8. rock_far = ");
				(void)scanf("%hhu", &rock_far);
				(void)getchar();
				break;
			case '9':
				clear();
				printf("Enter new ASCII code.\n9. rock_close = ");
				(void)scanf("%hhu", &rock_close);
				(void)getchar();
				break;
			case 'q':
				clear();
				printf("Enter new ASCII code.\nq. rock = ");
				(void)scanf("%hhu", &rock);
				(void)getchar();
				break;
			case 'w':
				clear();
				printf("Enter new value.\nw. font_color_default = ");
				(void)scanf("%u", &font_color_default);
				(void)getchar();
				break;
			case 'e':
				clear();
				printf("Enter new value.\ne. font_color_rock = ");
				(void)scanf("%u", &font_color_rock);
				(void)getchar();
				break;
			case 'r':
				clear();
				printf("Enter new value.\nr. font_color_rock_close = ");
				(void)scanf("%u", &font_color_rock_close);
				(void)getchar();
				break;
			case 't':
				clear();
				printf("Enter new value.\nt. font_color_rock_far = ");
				(void)scanf("%u", &font_color_rock_far);
				(void)getchar();
				break;
			case 'p':
				clear();
				printf("Are you sure?\n1. Yes\n2. No, don't load defaults\n");
				do {
					check_for_keystroke(keystroke);
				} while (keystroke != '1' && keystroke != '2');
				if (keystroke == '2') break;
				*this = default_options;
				printf("Loaded defaults. Press Enter to continue.\n");
				(void)getchar();
				break;
			case ESCAPE:
				escape = 1;
				break;
			default:
				break;
			}
		}
		save_settings();
		return 0;
	}
};
class space {
public:

	u_char depth;
	u_char height;
	u_char width;
	u_char*** content;
	long distance_travelled;
	int rock_spawn_chance;

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
						for (int index_width = 0; index_width < SPACE_WIDTH; ++index_width) {
							fspace[index_depth][index_height][index_width] = ' ';
						}
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
				if (object_seed == 0) {
					content[depth - 1][index_height][index_width] = options.rock;
				}
				else {
					content[depth - 1][index_height][index_width] = options.empty_space;
				}

				//generation of visualisation of far space
				for (index_depth = depth - 2; index_depth >= 0; --index_depth) {
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
		clear();
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
				rock_spawn_chance = -0.004 * distance_travelled + 10;
				if (rock_spawn_chance < 3) rock_spawn_chance = 3;
				object_seed = rand() % rock_spawn_chance;
				if (object_seed == 0) {
					content[depth - 1][index_height][index_width] = options.rock;
					//generation of projection of far space
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

	player_entity(u_char space_height, u_char space_width) {
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
class save_cls {
public:
	int state = 0;
	char name[21] = { 0 };
	int distance_travelled = 0;
	u_char*** content = 0;
	u_char player_x = 10;
	u_char player_y = 5;

	u_char*** allocate_space() {
		content = (u_char***)calloc(3, sizeof(u_char**));
		int index_depth, index_height;
		if (content != NULL) {
			for (index_depth = 0; index_depth < 3; ++index_depth) {
				content[index_depth] = (unsigned char**)calloc(9, sizeof(unsigned char*));
				if (content[index_depth] != NULL) {
					for (index_height = 0; index_height < 9; ++index_height) {
						content[index_depth][index_height] = (unsigned char*)calloc((18 + 1), sizeof(unsigned char));
						//+1 adds a '\0' to be used by the printing function
					}
				}
			}
			return content;
		}
		else {
			return NULL; //could not allocate space
		}
	}
	int read_space(FILE* save_file) {
		if (save_file == NULL) {
			return -1;
		}

		save_file = search_string(save_file, "Matrix 0:\n");
		if (save_file == NULL) {
			return -1;
		}
		for (int height_index = 0; height_index < 9; ++height_index) {
			fgets((char*)content[0][height_index], 21, save_file);
		}

		save_file = search_string(save_file, "Matrix 1:\n");
		if (save_file == NULL) {
			return -1;
		}
		for (int height_index = 0; height_index < 9; ++height_index) {
			fgets((char*)content[1][height_index], 21, save_file);
		}

		save_file = search_string(save_file, "Matrix 2:\n");
		if (save_file == NULL) {
			return -1;
		}
		for (int height_index = 0; height_index < 9; ++height_index) {
			fgets((char*)content[2][height_index], 21, save_file);
		}

		return 0;
	}
	bool check_duplicate(FILE* Save_names, char* new_entry, char* written_entries) {
		//check Save_names file for dupes
		char file_path[32] = "saves\\Save_names.txt";
		if (search_string(file_path, new_entry)) {
			return 1; //new_entry dupe found
		}
		//check newly entered file names string for dupes
		int index_we = 0;
		int index_ne = 0;
		bool reached_EOString = FALSE;
		char read_character = 0;
		size_t new_entry_length = strlen(new_entry);
		if (strlen(written_entries) == 0) {
			return 0; //new_entry dupe not found
		}
		while (TRUE) {
			if (written_entries[index_we] == -1 && reached_EOString) {
				return 0; //new_entry dupe not found
			}
			else if (written_entries[index_we] == -1) {
				reached_EOString = TRUE;
				index_we = 0;
			}

			read_character = written_entries[index_we];
			if (new_entry[index_ne] == read_character) {
				++index_ne;
			}
			else {
				index_ne = 0;
			}

			if (index_ne == new_entry_length) {
				return 1; //new_entry dupe found
			}
			++index_we;
		}
		return 0; //new_entry dupe not found
	}
	bool check_duplicate(FILE* Save_names, char* new_entry) {
		//check Save_names file for dupes
		if (search_string(Save_names, new_entry)) {
			return 1; //new_entry dupe found
		}
		return 0; //new_entry dupe not found
	}
	bool check_duplicate(char* new_entry, char* written_entries) {
		//check newly entered file names string for dupes
		int index_we = 0;
		int index_ne = 0;
		bool reached_EOString = FALSE;
		char read_character = 0;
		size_t new_entry_l = strlen(new_entry);
		if (strlen(written_entries) == 0) {
			return 0; //new_entry dupe not found
		}
		while (TRUE) {
			if (written_entries[index_we] == -1 && reached_EOString) {
				return 0; //new_entry dupe not found
			}
			else if (written_entries[index_we] == -1) {
				reached_EOString = TRUE;
				index_we = 0;
			}

			read_character = written_entries[index_we];
			if (new_entry[index_ne] == read_character) {
				++index_ne;
			}
			else {
				index_ne = 0;
			}

			if (index_ne == new_entry_l) {
				return 1; //new_entry dupe found
			}
			++index_we;
		}
		return 0; //new_entry dupe not found
	}
	int check_save_amount(FILE* Save_names) {
		rewind(Save_names);
		char character = 0;
		u_int saves_nr = 0;
		while (character = fgetc(Save_names) != EOF) {
			if (character == '\n') {
				++saves_nr;
			}
		}
		return saves_nr;
	}
	int write_new_save_name(char new_entry[21], int& write_counter, char* written_entries) {
		FILE* Save_names = fopen("saves\\Save_names.txt", "r");
		bool dupe = 0;
		if (Save_names != NULL) {
			fclose(Save_names);
			Save_names = fopen("saves\\Save_names.txt", "a");
			if (!(dupe = check_duplicate(Save_names, new_entry, written_entries)) && check_save_amount(Save_names) + write_counter < 9) {
				fprintf(Save_names, "%s\n", new_entry);
				++write_counter;
				strcat(written_entries, new_entry);
			}
			else if (dupe) {
				printf("\nDuplicate file name! You can't have 2 save files with identical names.\n");
			}
			else {
				printf("\nMaximum number of supported saves reached (9).\n");
			}
			fflush(Save_names);
			fclose(Save_names);
		}
		else {
			Save_names = fopen("saves\\Save_names.txt", "a");
			if (!(dupe = check_duplicate(new_entry, written_entries)) && check_save_amount(Save_names) + write_counter < 9) {
				fprintf(Save_names, "%s\n", new_entry);
				++write_counter;
				strcat(written_entries, new_entry);
			}
			else if (dupe) {
				printf("\nDuplicate file name! You can't have 2 save files with identical names.\n");
			}
			else {
				printf("\nMaximum number of supported saves reached (9).\n");
			}
			fflush(Save_names);
			fclose(Save_names);
		}
		return 0;
	}
	int create_save_file(char save_name[21], space place, player_entity player) {
		//determine file to be opened and open it
		char save_path[32] = "saves\\";
		strcat(save_path, save_name);
		strcat(save_path, ".txt");
		FILE* save_new = fopen(save_path, "w");
		if (save_new == NULL) {
			clear();
			fontsize(60, 60);
			printf("Could not create file!\nDo not panic and do not close the game.\n"
				"To be able to save, you need to find your game folder\n"
				"and add a \"saves\" folder inside of it,"
				"\nthen try to save again.\n"
				"Press Enter to exit this dialogue.\n");
			(void)getchar();
			return -1; //FAILED TO SAVE
		}
		//print data into the new file
		fprintf(save_new, "distance_travelled %d\n\n", place.distance_travelled);
		for (int depth = 0; depth < place.depth; ++depth) {
			fprintf(save_new, "Matrix %d:\n", depth);
			for (int height = 0; height < place.height; ++height) {
				fputs((char*)place.content[depth][height], save_new);
				fprintf(save_new, "\n");
			}
			fprintf(save_new, "\n");
		}
		fprintf(save_new, "\nplayer_x: %hhu\nplayer_y: %hhu", player.x_coord, player.y_coord);
		//add file name to Save_names.txt if it doesn't exist
		FILE* Save_names = fopen("saves\\Save_names.txt", "r");
		if (Save_names == NULL) {
			create_save_names_entry(save_name);
		}
		else {
			if (search_string(Save_names, save_name) == NULL) {
				create_save_names_entry(save_name);
			}
		}
		//exit
		fclose(save_new);
		if (Save_names != NULL) {
			fclose(Save_names);
		}
		clear();
		printf("Game saved!\nPress enter to continue.\n");
		(void)getchar();
		return 0;
	}
	int create_save_names_entry(char save_name[21]) {
		FILE* Save_names = fopen("saves\\Save_names.txt", "a");
		fputs(save_name, Save_names);
		fprintf(Save_names, "\n");
		fclose(Save_names);
		return 0;
	}
	int delete_save_names_entry(FILE* Save_names, char selected_save[21]) {
		long int exception_pos = 0;
		long int current_pos = 0;
		char buffer[21] = { 0 };
		char new_sn[189] = { 0 };
		if (Save_names == NULL) {
			return -1;
		}
		rewind(Save_names);
		exception_pos = search_string_pos(Save_names, selected_save);
		rewind(Save_names);
		current_pos = ftell(Save_names);
		while (!feof(Save_names)) {
			if (fgets(buffer, 21, Save_names) && exception_pos != current_pos) {
				strcat(new_sn, buffer);
			}
			current_pos = ftell(Save_names);
		}
		fclose(Save_names);
		Save_names = fopen("saves\\Save_names.txt", "w");
		for (int i = 0; i < 189 && new_sn[i] != 0; ++i) {
			fputc(new_sn[i], Save_names);
		}
		fclose(Save_names);
		for (int i = 0; i < 21; ++i) {
			buffer[i] = 0;
		}
		for (int i = 0; i < 189; ++i) {
			new_sn[i] = 0;
		}
		return 0;
	}
	bool check_save_name_existence(char save_name[21]) {
		char file_path[28] = "saves\\";
		strcat(file_path, save_name);
		strcat(file_path, ".txt");
		FILE* save = fopen(file_path, "r");
		if (!save) {
			return 0;
		}
		else {
			fclose(save);
			return 1;
		}
	}
	int get_save_name(char*& new_entry, int& index) {
		char keystroke = 0;
		int new_entry_size = 0;
		while (keystroke != 13) { //gets save name
			check_for_keystroke(keystroke);
			//check if input character is allowed, reads and prints it if so
			if ((keystroke > 47 && keystroke < 58 || keystroke > 64 && keystroke < 91 || keystroke > 96 && keystroke < 123 || keystroke == '_') && index < 20) {
				++new_entry_size;
				new_entry = (char*)realloc(new_entry, new_entry_size);
				new_entry[index++] = keystroke;
				printf("%c", keystroke);
			}
			else if (keystroke == '\b' && new_entry_size > 0) {
				--index;
				--new_entry_size;
				new_entry = (char*)realloc(new_entry, new_entry_size);
				printf("\b \b");
			}
			else if (keystroke == ESCAPE) { //escape case
				new_entry = (char*)realloc(new_entry, 0);
				index = 0;
				return -1;
			}
		}
		++new_entry_size;
		new_entry = (char*)realloc(new_entry, new_entry_size);
		new_entry[index++] = 0;
		return 0;
	}
	int get_save_name(char*& new_entry) {
		char keystroke = 0;
		int new_entry_size = 0;
		int index = 0;
		while (keystroke != 13) { //gets save name
			check_for_keystroke(keystroke);
			//check if input character is allowed, reads and prints it if so
			if ((keystroke > 47 && keystroke < 58 || keystroke > 64 && keystroke < 91 || keystroke > 96 && keystroke < 123 || keystroke == '_') && index < 20) {
				++new_entry_size;
				new_entry = (char*)realloc(new_entry, new_entry_size);
				new_entry[index++] = keystroke;
				printf("%c", keystroke);
			}
			else if (keystroke == '\b' && new_entry_size > 0) {
				--index;
				--new_entry_size;
				new_entry = (char*)realloc(new_entry, new_entry_size);
				printf("\b \b");
			}
			else if (keystroke == ESCAPE) { //escape case
				new_entry = (char*)realloc(new_entry, 0);
				return -1;
			}
		}
		++new_entry_size;
		new_entry = (char*)realloc(new_entry, new_entry_size);
		new_entry[index++] = 0;
		return 0;
	}
	int create_save_names_file() {
		fontsize(40, 40);
		clear();
		printf("The Save_names.txt file stores all of the names of your save files, obviously.\n"
			"These names are needed by the game to know what files to look for when trying\n"
			"to find your saves. If you do have available save files that have not yet been\n"
			"added to this list for some reason, please enter their full names and press Enter.\n\n"
			"Save names can only contain letters, numbers and underscores '_'.\n"
			"\nYour save file names might look simmilar to:\n"
			"My_save_file\n"
			"Save_game_1\n"
			"jdjsf392834jndf923w\n\n");

		char keystroke = 0;
		char* new_entry = (char*)calloc(0, sizeof(char));
		int index = 0;
		int write_counter = 0;
		char written_entries[200] = { 0 };
		int size_written_entries = 0;

		while (keystroke != '2') {
			keystroke = 0;
			printf("New entered name:\n");

			get_save_name(new_entry, index);

			if (new_entry != NULL && index != 0) { //checks existence and writes the new save name to disk
				new_entry[index] = 0;
				clear();
				printf("Entered name: ");
				puts(new_entry);
				if (check_save_name_existence(new_entry)) { //when file with input name exists
					write_new_save_name(new_entry, write_counter, written_entries);
				}
				else { //when file with input name doesn't exist
					printf("Unable to find save file with this name.\n"
						"Would you like to add the %s entry to the Save_names file regardless?\n\n"
						"1. Yes\n"
						"2. No\n\n", new_entry);
					keystroke = 0;
					while (keystroke != '1' && keystroke != '2') {
						check_for_keystroke(keystroke);
					}
					if (keystroke == '1') {
						write_new_save_name(new_entry, write_counter, written_entries);
					}
				}
				new_entry = { 0 };
				index = 0;
			}
			else {
				clear();
			}
			printf("1. Continue entering file names\n"
				"2. Quit entering file names\n");
			keystroke = 0;
			while (keystroke != '1' && keystroke != '2') {
				check_for_keystroke(keystroke);
			}
			printf("\n");
		}
		return 0;
	}
	int load(char save_name[21]) {
		char save_path[32] = { 0 };
		strcpy(save_path, "saves\\");
		strcat(save_path, save_name);
		strcat(save_path, ".txt");
		FILE* save_file = fopen(save_path, "r");
		if (save_file == NULL) { //save file not found
			clear();
			printf("Save file with path Game_folder\\%s doesn't exist.\nTry checking the file name spelling.\n", save_path);
			(void)getchar();
			return -1;
		}
		else { //save file found
			allocate_space();
			FILE* og = save_file;
			save_file = search_string(save_file, "distance_travelled ");
			if (save_file != NULL) {
				(void)fscanf(save_file, "%d", &distance_travelled);
			}
			else {
				save_file = og;
			}
			read_space(save_file);
			og = save_file;
			save_file = search_string(save_file, "player_x: ");
			if (save_file != NULL) {
				(void)fscanf(save_file, "%hhu", &player_x);
			}
			else {
				save_file = og;
			}
			og = save_file;
			save_file = search_string(save_file, "player_y: ");
			if (save_file != NULL) {
				(void)fscanf(save_file, "%hhu", &player_y);
			}
			else {
				save_file = og;
			}
			state = INITIALIZED_SAVE;
			strcpy(name, save_name);
			fclose(save_file);
			clear();
			printf("Save %s loaded!\n", save_name);
			(void)getchar();
			return 0;
		}
	}
	int read_and_print_saves(FILE* Save_names, char **&menu_content) {
		int menu_entry_index = 1; //gonna have a -1 offset whenever working with the vector, since it starts at 1
		FILE* save_file = 0;
		char save_path[32] = { 0 };
		long distance_travelled = 0;
		while (menu_entry_index < 10) {
			if (Save_names != NULL && fgetc(Save_names) != -1) {
				fseek(Save_names, -1, SEEK_CUR);
				fgets(menu_content[menu_entry_index - 1], 21, Save_names);
				menu_content[menu_entry_index - 1][strlen(menu_content[menu_entry_index - 1]) - 1] = 0;

				strcpy(save_path, "saves\\");
				strcat(save_path, menu_content[menu_entry_index - 1]);
				strcat(save_path, ".txt");
				save_file = fopen(save_path, "r");
				if (save_file) save_file = search_string(save_file, "distance_travelled ");
				if (save_file) (void)fscanf(save_file, "%d", &distance_travelled);

				printf("%d. %s", menu_entry_index, menu_content[menu_entry_index - 1]);
				if (save_file) {
					printf("\tdistance: %d", distance_travelled);
					distance_travelled = 0;
				}
				printf("\n");
				menu_content[menu_entry_index - 1][strlen(menu_content[menu_entry_index - 1])] = '\n';
				++menu_entry_index;

				if (save_file) fclose(save_file);
			}
			else {
				strcpy(menu_content[menu_entry_index - 1], "Empty_slot\n");
				printf("%d. %s", menu_entry_index, menu_content[menu_entry_index - 1]);
				++menu_entry_index;
			}
		}
		return 0;
	}
	char* run() {
		char keystroke = 0;
		FILE* Save_names;
		char** menu_content = (char**)calloc(9, sizeof(char*));
		char selected_save[21] = { 0 };
		char file_path[32] = { 0 };
		char* renamed_save = (char*)calloc(21, sizeof(char));
		char renamed_file_path[32] = { 0 };
		if (menu_content == NULL) {
			return NULL; //allocation error
		}
		for (int i = 0; i < 9; ++i) {
			menu_content[i] = (char*)calloc(21, sizeof(char));
			if (menu_content[i] == NULL) {
				return NULL; //allocation error
			}
		}
		do {
			fontsize(60, 60);
			Save_names = fopen("saves\\Save_names.txt", "r");
			if (Save_names != NULL) {
				rewind(Save_names);
			}
			clear();
			printf("SAVE FILES\n\n");
			keystroke = 0;
			for (int i = 0; i < 21; ++i) {
				selected_save[i] = 0;
			}
			read_and_print_saves(Save_names, menu_content);
			printf("\n0. Add an existing save file to the list\n");
			do {
				check_for_keystroke(keystroke);
			} while ((keystroke < 47 || keystroke > 58) && keystroke != ESCAPE);
			if (keystroke > 48 && keystroke < 58) {
				keystroke = keystroke - 48;
				strcpy(selected_save, menu_content[keystroke - 1]);
				selected_save[strlen(selected_save) - 1] = 0;
				if (strcmp(selected_save, "Empty_slot") == 0) {
					continue;
				}
				clear();
				fontsize(80, 80);
				printf("1. Load\n"
					"2. Rename //WIP\n"
					"3. Delete\n");
				do {
					check_for_keystroke(keystroke);
				} while (keystroke != '1' && keystroke != '2' && keystroke != '3' && keystroke != ESCAPE);
				switch (keystroke) {
				case '1':
					if (!load(selected_save)) {
						for (int i = 0; i < 9; ++i) {
							free(menu_content[i]);
						}
						free(menu_content);
						if (Save_names != NULL) {
							fclose(Save_names);
						}
						return (char*)"play_loaded_game";
					}
					break;
				case '2':
					strcpy(file_path, "saves\\");
					strcat(file_path, selected_save);
					strcat(file_path, ".txt");
					clear();
					fontsize(60, 60);
					printf("Enter new save name: ");
					if (get_save_name(renamed_save)) {
						break;
					}
					strcpy(renamed_file_path, "saves\\");
					strcat(renamed_file_path, renamed_save);
					strcat(renamed_file_path, ".txt");
					if (rename(file_path, renamed_file_path)) {
						clear();
						fontsize(40, 40);
						printf("The file to be renamed can't be found.\n");
						(void)getchar();
					}
					if (delete_save_names_entry(Save_names, selected_save)) {
						clear();
						fontsize(40, 40);
						printf("Save name to be replaced couldn't be replaced.\n");
						(void)getchar();
					}
					if (create_save_names_entry(renamed_save)) {
						clear();
						fontsize(40, 40);
						printf("Couldn't replace file name inside Save_names file.\n"
							"Check that the app has permission to access it's\n"
							"install folder please.\n"
							"Having the game in a hidden folder might be causing this.\n");
						(void)getchar();
					}
					break;
				case '3':
					clear();
					fontsize(40, 40);
					printf("Are you sure you want to delete %s?\n"
						"1. Yes\n"
						"2. No\n", selected_save);
					do {
						check_for_keystroke(keystroke);
					} while (keystroke != '1' && keystroke != '2' && keystroke != ESCAPE);
					if (keystroke != '1') break;
					strcpy(file_path, "saves\\");
					strcat(file_path, selected_save);
					strcat(file_path, ".txt");
					if (remove(file_path)) { //deletes the save file
						clear();
						fontsize(40, 40);
						printf("File to be deleted wasn't present in the first place.\n"
							"Task failed successfully!\n");
						(void)getchar();
					}
					//deletes the save file name from the available saves list
					if (delete_save_names_entry(Save_names, selected_save)) {
						clear();
						fontsize(40, 40);
						printf("File name to be removed wasn't present inside Save_names.txt\n"
							"in the first place...Task failed successfully, I guess!\n");
						(void)getchar();
					}
					break;
				default:
					break;
				}
			}
			else if (keystroke == '0') {
				create_save_names_file();
			}
			if (Save_names != NULL) {
				fclose(Save_names);
			}
		} while (keystroke != ESCAPE);
		keystroke = 0;
		for (int i = 0; i < 9; ++i) {
			free(menu_content[i]);
		}
		free(menu_content);
		if (Save_names != NULL) {
			fclose(Save_names);
		}
		free(renamed_save);
		return NULL;
	}
};
class pause_menu {
public:
	int run(settings options, save_cls saves_obj, char save_name[24], space place, player_entity player) {
		int escape = 0;
		char keystroke;
		while (escape == 0) {
			clear();
			printf("Pause menu\n\n"
				"1. Continue\n"
				"2. Save\n"
				"3. Quit");
			check_for_keystroke(keystroke);
			switch (keystroke) {
			case '1':
				return 2;
				break;
			case '2':
				saves_obj.create_save_file(save_name, place, player);
				keystroke = 0;
				break;
			case '3':
				return 0;
				break;
			case ESCAPE:
				return 2;
				break;
			default:
				break;
			}
		}
		return -1;
	}
};
class play {
public:

	int copy_space_content(space place, save_cls save_obj) {
		for (int d_index = 0; d_index < 3; ++d_index) {
			for (int h_index = 0; h_index < 9; ++h_index) {
				for (int w_index = 0; w_index < 19; ++w_index) {
					place.content[d_index][h_index][w_index] = save_obj.content[d_index][h_index][w_index];
				}
			}
		}
		return 0;
	}
	int run(settings options, save_cls save_obj) {
		//game initialization
		srand(time(NULL));
		//LARGE_INTEGER frequency, time1, time2;
		//QueryPerformanceFrequency(&frequency);

		char keystroke, quit = 1;
		char* save_name = (char*)calloc(21, sizeof(char));

		space place(SPACE_DEPTH, SPACE_HEIGHT, SPACE_WIDTH);
		player_entity player(SPACE_HEIGHT, SPACE_WIDTH);

		if (save_obj.state == UNINITIALIZED_SAVE) {
			FILE* Save_names = fopen("saves\\Save_names.txt", "r");
			bool dupe = 0;
			do {
				clear();
				fontsize(80, 80);
				printf("Please enter a name for your save\ngame of up to 20 letters.\n"
					"Name: ");
				if (save_obj.get_save_name(save_name) == -1) {
					return -1;
				}
				if (Save_names != NULL) {
					if (dupe = save_obj.check_duplicate(Save_names, save_name)) {
						printf("\nYou entered a save name that already exists, please enter a save name that is different compared to "
							"all of your other save files.\n");
						(void)getchar();
					}
				}
			} while (dupe);
			printf("\nGLHF! Press Enter to start playing.\n");
			(void)getchar();
			//initial generation of environment
			//place.generate(options);
		}
		else {
			if (save_name == NULL) {
				return -2;
			}
			strcpy(save_name, save_obj.name);
			copy_space_content(place, save_obj);
			place.distance_travelled = save_obj.distance_travelled;
			player.x_coord = save_obj.player_x;
			player.y_coord = save_obj.player_y;
		}

		fontsize(97, 97);

		while (quit) {
			quit = 1;
			//QueryPerformanceCounter(&time1);
			place.print_space_visible3(player.x_coord, player.y_coord, options.player_icon, options); //1.5 ms latest average exec time
			//QueryPerformanceCounter(&time2);
			//puts("\nTime taken: ");
			//printf("%lf.\n", (double)(time2.QuadPart - time1.QuadPart) * 1000 / frequency.QuadPart);
			check_for_keystroke(keystroke);
			if (keystroke) {
				if (player.move_accordingly(keystroke, place.height, place.width, options) == options.back) {
					pause_menu pause;
					quit = pause.run(options, save_obj, save_name, place, player);
					fontsize(97, 97);
					place.print_space_visible3(player.x_coord, player.y_coord, options.player_icon, options);
				}
				keystroke = 0;
			}
			if (player.check_death(place.content, options)) {
				quit = 0; //replace with death screen
			}
			else if (quit == 1) {
				place.progress_space(options); //0.022 ms latest exec time
			}
		}
		return 0;
	}
};

int main() {
	settings options;
	options.load_settings();
	char keystroke = 0;
	save_cls save_obj;
	char* decision = NULL;
	play game;

	//go fullscreen
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	while (keystroke != ESCAPE) { //exits when player presses escape
		keystroke = 0;
		clear();
		fontsize(100, 100);
		fprintf(stdout, "MAIN MENU\n\n1. Continue\n2. Game Saves\n3. New Game\n4. Settings\n\nPress escape to quit.\n");

		if (!decision) {
			check_for_keystroke(keystroke);
		}

		if (keystroke == '1') { //continue

		}
		else if (keystroke == '2') { //game saves
			decision = save_obj.run();
		}
		else if (keystroke == '3' || decision == "new_game") { //new game
			save_obj.state = UNINITIALIZED_SAVE;
			game.run(options, save_obj);
			decision = { 0 };
		}
		else if (keystroke == '4') { //settings
			options.run();
		}

		//this if statement is for decisions made in one of the other 4 branches above
		if (decision == "play_loaded_game") {
			game.run(options, save_obj);
			decision = { 0 };
		}
	}

	clear();
	return 0;
}