#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

int main()
{
	int number = 1, increment_row, increment_addon = 1, max_row_input, max_numbers = 1, increment_numbers;
	printf("Enter max rows:");
	fscanf(stdin, "%d", &max_row_input);
	(void)getchar();
	for (increment_row = 0; increment_row < max_row_input; ++increment_row) {
		for (increment_numbers = 0; increment_numbers < max_numbers; ++increment_numbers) {
			printf("%d ", number);
			number = number + 2;
		}
		printf("\n");
		if (increment_row != 0 && increment_row % 2 == 0) {
			++increment_addon;
		}
		number = number + increment_addon;
		++max_numbers;
	}
	return 0;
}