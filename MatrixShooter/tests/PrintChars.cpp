#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

void all_character_print(size_t lower, size_t upper);

int main()
{
	all_character_print(0, 254);
	(void)getchar();
	return 0;
}


void all_character_print(size_t lower, size_t upper) {
	if (upper > 254 || lower > upper) {
		return;
	}
	unsigned char index_character;
	for (index_character = lower; index_character <= upper; ++index_character) {
		//printf("%hd: %c\n", index_character, index_character);
		printf("%c ", index_character);
	}
}