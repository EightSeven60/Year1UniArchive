#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

struct arrey_int {
	int* arrey = 0;
	int max_size = 4294967295 / 2 - 1;    // maximum arrey size (max int value)
	int size = 0;    // current arrey size, counting the amount of elements that were inserted, can decrease because of element delete
	bool allocated = false;    // false if the arrey wasn't allocated, true if do
};

int arrey_allocation(arrey_int& structure, const size_t size) {   //initialisation
	structure.arrey = (int*)calloc(size, sizeof(int));
	if (!structure.arrey) {
		return -1;   // couldn't allocate arrey
	}
	else {
		structure.size = size;
		structure.allocated = true;   // arrey was alocated successfully
		return 0;   // operation success
	}
}

int arrey_data_command(arrey_int& structure, int* command_arrey) {   // data insertion
	for (int i = 0; i < structure.size; ++i) {
		structure.arrey[i] = command_arrey[i];
	}
	for (int i = 0; i < structure.size; ++i) {
		if (structure.arrey[i] == NULL) return -1;   // insertion error
	}
	return 0;   // operation success
}

int arrey_data_file(arrey_int& structure, char* line, char* pointer) {   // data insertion
	int i = 0;
	pointer = strtok(line, " ,.;:!?<>-_=+");
	do {

		structure.arrey[i] = atoi(pointer);
		pointer = strtok(NULL, " ,.;:!?<>-_=+");
		++i;
	} while (i < structure.size || pointer != NULL);
	if (pointer == NULL && i == structure.size) {   //process succeed
		for (int j = 0; j < structure.size; ++j) {
			if (structure.arrey[j] == NULL) return -1;   // insertion error
		}
	}
	return 0;   // operation success
}

int data_insertion(arrey_int& structure) {
	int value, position;
	char* answer = (char*)calloc(3, sizeof(char)), * last = (char*)calloc(3, sizeof(char));
	cout << "Do you wont to insert data (YES/NO): "; cin >> answer;
	if (answer == "YES" || answer == "Yes" || answer == "yes") {

		cout << "Value: "; cin >> value;
		cout << "Do you want to insert an aditional value (extend structure) (YES/NO): "; cin >> last;

		if (last == "YES" || last == "Yes" || last == "yes") {
			++structure.size;
			structure.arrey = (int*)realloc(structure.arrey, structure.size * sizeof(int));
			structure.arrey[structure.size - 1] = value;
		}
		else if (last == "NO" || last == "No" || last == "no") {
			cout << "Position: "; cin >> position;

			++structure.size;
			structure.arrey = (int*)realloc(structure.arrey, structure.size * sizeof(int));
			for (int i = structure.size - 1; i > position; --i) {
				structure.arrey[i] = structure.arrey[i - 1];
			}
			structure.arrey[position] = value;
		}
		else {
			cout << "Position: "; cin >> position;

			++structure.size;
			structure.arrey = (int*)realloc(structure.arrey, structure.size * sizeof(int));
			for (int i = structure.size - 1; i > position; --i) {
				structure.arrey[i] = structure.arrey[i - 1];
			}
			structure.arrey[position] = value;
		}
	}
	else if (answer == "NO" || answer == "No" || answer == "no") {
		int max = -999999;
		for (int i = 0; i < structure.size; ++i) {
			if (structure.arrey[i] != NULL) max = max < structure.arrey[i] ? structure.arrey[i] : max;
		}

		value = rand() % max;
		position = rand() % (structure.size);

		if (position == structure.size) {
			++structure.size;
			structure.arrey = (int*)realloc(structure.arrey, structure.size * sizeof(int));
			structure.arrey[structure.size - 1] = value;
		}
		else {
			++structure.size;
			structure.arrey = (int*)realloc(structure.arrey, structure.size * sizeof(int));
			for (int i = structure.size - 1; i > position; --i) {
				structure.arrey[i] = structure.arrey[i - 1];
			}
			structure.arrey[position] = value;
		}
	}
	else {
		int max = -999999;
		for (int i = 0; i < structure.size; ++i) {
			if (structure.arrey[i] != NULL) max = max < structure.arrey[i] ? structure.arrey[i] : max;
		}

		value = rand() % max;
		position = rand() % (structure.size);

		if (position == structure.size) {
			++structure.size;
			structure.arrey = (int*)realloc(structure.arrey, structure.size * sizeof(int));
			structure.arrey[structure.size - 1] = value;
		}
		else {
			++structure.size;
			structure.arrey = (int*)realloc(structure.arrey, structure.size * sizeof(int));
			for (int i = structure.size - 1; i > position; --i) {
				structure.arrey[i] = structure.arrey[i - 1];
			}
			structure.arrey[position] = value;
		}
	}
	for (int i = 0; i < structure.size; ++i) {
		if (structure.arrey[i] == value) return 0;   //operation success, data insered
	}
	return -1;    //operation failure
}

void arrey_view(arrey_int structure) {
	cout << "Data structure is: " << endl;
	for (int i = 0; i < structure.size; ++i) {
		if (structure.arrey[i] != NULL) cout << ' ' << structure.arrey[i];
	}
	cout << endl;
}

// program executed via command line
void command(int argc, int* command_arrey) {
	arrey_int structure;
	structure.max_size = argc;
	if (arrey_allocation(structure, structure.max_size) == 0) {
		if (arrey_data_command(structure, command_arrey) == 0) {
		ETICHETA:
			short operation;
			cout << "What operation would you like to do?" << endl << " - stop program ==> 0" << endl << " - insert data ==> 1" << endl << " - delete data ==> 2" << endl << " - search data ==> 3" << endl << " - alter data ==> 4" << endl << " - view data ==> 5" << endl << "Answer: "; cin >> operation;

			switch (operation)
			{
			case 0: break;
			case 1: if (data_insertion(structure) == 0) cout << "Insertion succeed!" << endl; else cout << "Insertion failed!" << endl << "Try again..." << endl; goto ETICHETA;
			case 2: if (data_insertion(structure) == 0) cout << "Delete succeed!" << endl; else cout << "Delete failed!" << endl << "Try again..." << endl; goto ETICHETA;
			case 3: if (int position = data_insertion(structure) != 1) cout << "Search succeed!" << endl << "Element found on position: " << position << endl; else cout << "Search failed!" << endl << "Element not found, try again..." << endl; goto ETICHETA;
			case 4: goto ETICHETA;
			case 5: arrey_view(structure); goto ETICHETA;
			default: cout << "Operation not founded!" << endl << "Try again" << endl;
			}
		}
		else {
			cout << "Arrey data not corectly inserted!" << endl << "Try again..." << endl;
		}
	}
	else {
		cout << "Arrey not corectly allocated!" << endl << "Try again..." << endl;
	}
}

// program executed via file line
void file() {
	arrey_int structure;
	FILE* textin = fopen("Text.txt", "rt");
	if (textin == NULL) {
		cout << "Could not open the file!" << endl << "Try again!" << endl;
	}
	else {
		char* file_line = (char*)calloc(50, sizeof(char));
		fgets(file_line, 50, textin);
		if (file_line != NULL) {
			char* pointer = strtok(file_line, " ,.;:!?<>-_=+");
			structure.max_size = atoi(pointer);
			if (arrey_allocation(structure, structure.max_size) == 0) {
				fgets(file_line, 50, textin);
				if (arrey_data_file(structure, file_line, pointer) == 0) {

				ETICHETA1:
					short operation;
					cout << "What operation would you like to do?" << endl << " - stop program ==> 0" << endl << " - insert data ==> 1" << endl << " - delete data ==> 2" << endl << " - search data ==> 3" << endl << " - alter data ==> 4" << endl << "Answer: "; cin >> operation;

					switch (operation)
					{
					case 0: break;
					case 1: if (data_insertion(structure) == 0) cout << "Insertion succeed!" << endl; else cout << "Insertion failed!" << endl << "Try again..." << endl; goto ETICHETA1;
					case 2: if (data_insertion(structure) == 0) cout << "Delete succeed!" << endl; else cout << "Delete failed!" << endl << "Try again..." << endl; goto ETICHETA1;
					case 3: if (int position = data_insertion(structure) != 1) cout << "Search succeed!" << endl << "Element found on position: " << position << endl; else cout << "Search failed!" << endl << "Element not found, try again..." << endl; goto ETICHETA1;
					case 4: goto ETICHETA1;
					case 5: arrey_view(structure); goto ETICHETA1;
					default: cout << "Operation not founded!" << endl << "Try again" << endl;
					}
				}
				else {
					cout << "Arrey data not corectly inserted!" << endl << "Try again..." << endl;
				}
			}
			else {
				cout << "Arrey not corectly allocated!" << endl << "Try again..." << endl;
			}
		}
	}
}

int main(int arg_count, int arg_arrey[])
{
	srand(time(NULL));
	short program_type = 0;   // null value by default
	cout << "You wont to read data from: " << endl << " - command line ==> 1" << endl << " - text file ==> 2" << endl << "Answer: "; cin >> program_type;
	if (program_type != 0 and program_type != 1) program_type = rand() % 1;

	system("cls"); // clear screen

	switch (program_type)
	{
	case 1: command(arg_count, arg_arrey); // break;
	case 2: file(); // break;
	default: break;
	}

	return 0;
}