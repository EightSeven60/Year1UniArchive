#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//I allowed the user to create vectors with empty spaces in them by defining the vector with type = 'discontinuous'

struct vector_int {
	int* content = 0; //holds the actual array
	bool* used_spaces = 0; //determines which spaces have been used within the vector
	int max_size = 0; //maximum vector size
	int size = 0; //current vector size counting the amount of elements that were inserted
	char* type = 0; //determines wether array is continuous or discontinuous
	bool initialised = false; //wether array has been initialised (using an allocation function, usually)
};

int alloc_vector_int(vector_int& fvector, const size_t fmax_size, const char* ftype);
int insert_vector_int(vector_int* fvector, const int to_be_inserted, const size_t insertion_position);
int replace_vector_int(vector_int* fvector, const int to_be_inserted, const size_t insertion_position);
int remove_from_vector_int(vector_int* fvector, const size_t removal_position);
int search_vector_int(vector_int* fvector, const int key);


int main()
{
	vector_int vector;
	if (alloc_vector_int(vector, 10, "discontinuous")) { //example of using return code
		printf("Erroare la alocare.\nApasati Enter pentru a iesi din program.\n");
		(void)getchar();
		return 0;
	}

	(void)getchar();
	return 0;
}

int alloc_vector_int(vector_int& fvector, const size_t fmax_size, const char* ftype) {
	fvector.content = (int*)calloc(0, sizeof(int));
	if (!fvector.content) {
		return -1; //couldn't allocate content vector
	}
	fvector.max_size = fmax_size;
	fvector.size = 0;
	fvector.used_spaces = (bool*)calloc(fmax_size, sizeof(bool));
	if (!fvector.used_spaces) {
		return -2; //couldn't allocate used spaces vector
	}
	for (int i = 0; i < fmax_size; ++i) {
		fvector.used_spaces[i] = 0;
	}
	fvector.type = (char*)calloc(13, sizeof(char));
	if (!fvector.type) {
		return -3; //couldn't allocate type char vector
	}
	strcpy(fvector.type, ftype);
	fvector.initialised = true;
	return 0; //successful
}
int insert_vector_int(vector_int* fvector, const int to_be_inserted, const size_t insertion_position) {
	if (fvector->initialised == false) {
		return -1; //if vector hasn't been initialised
	}
	else if (insertion_position >= fvector->max_size) {
		return -2; //when insertion position is past array maximum size
	}

	if (insertion_position <= fvector->size) {
		if (strcmp(fvector->type, "continuous") == 0) {
			if (insertion_position == fvector->size) {
				fvector->content = (int*)realloc(fvector->content, (fvector->size + 1) * sizeof(int));
				++fvector->size;
				fvector->content[insertion_position] = to_be_inserted;
				fvector->used_spaces[insertion_position] = true;
			}
			else {
				fvector->content = (int*)realloc(fvector->content, (fvector->size + 1) * sizeof(int));
				++fvector->size;
				for (int i = fvector->size - 1; i > insertion_position; --i) {
					fvector->content[i] = fvector->content[i - 1];
					fvector->used_spaces[i] = true;
				}
				fvector->content[insertion_position] = to_be_inserted;
				fvector->used_spaces[insertion_position] = true;
			}
		}
		else  if (strcmp(fvector->type, "discontinuous") == 0){
			if (!fvector->used_spaces[insertion_position]) {
				fvector->content[insertion_position] = to_be_inserted;
				fvector->used_spaces[insertion_position] = true;
			}
			else {
				int empty_slot = -1;
				for (int i = insertion_position; i < fvector->size; ++i) {
					if (!fvector->used_spaces[i]) {
						empty_slot = i;
						break;
					}
				}
				if (empty_slot == -1) {
					fvector->content = (int*)realloc(fvector->content, (fvector->size + 1) * sizeof(int));
					++fvector->size;
					empty_slot = fvector->size - 1;
				}
				for (int i = empty_slot; i > insertion_position; --i) {
					fvector->content[i] = fvector->content[i - 1];
					fvector->used_spaces[i] = true;
				}
				fvector->content[insertion_position] = to_be_inserted;
				fvector->used_spaces[insertion_position] = true;
			}
		}
		else {
			return -3; //when array type has been wrongly defined
		}
	}
	else if (strcmp("discontinuous", fvector->type) == 0) {
		fvector->content = (int*)realloc(fvector->content, (insertion_position + 1) * sizeof(int));
		fvector->size = insertion_position + 1;
		fvector->content[insertion_position] = to_be_inserted;
		fvector->used_spaces[insertion_position] = true;
	}
	else  if (strcmp(fvector->type, "continuous") == 0){
		return -4; //when insertion position is past current array end and array is continuous
	}
	else {
		return -3; //when array type has been wrongly defined
	}

	return 0; //success
}
int replace_vector_int(vector_int* fvector, const int to_be_inserted, const size_t insertion_position) {
	if (fvector->initialised == false) {
		return -1; //if vector hasn't been initialised
	}
	else if (insertion_position >= fvector->max_size) {
		return -2; //when insertion position is past array maximum size
	}
	else if (!fvector->used_spaces[insertion_position]) {
		return -3; //when data to be updated is missing; use insert to add data instead
	}

	fvector->content[insertion_position] = to_be_inserted;
	return 0; //done
}
int remove_from_vector_int(vector_int* fvector, const size_t removal_position) {
	if (!fvector->initialised) {
		return -1; //if vector hasn't been initialised
	}
	else if (removal_position >= fvector->size) {
		return -2; //when removal position is past array current size
	}
	else if (!fvector->used_spaces[removal_position]) {
		return -3; //when data to be removed is missing already
	}

	if (!strcmp(fvector->type, "continuous")) {
		for (int i = removal_position; i < fvector->size - 1; ++i) {
			fvector->content[i] = fvector->content[i + 1];
		}
		--fvector->size;
		fvector->used_spaces[fvector->size] = false;
		fvector->content = (int*)realloc(fvector->content, fvector->size * sizeof(int));
	}
	else if (!strcmp(fvector->type, "discontinuous")) {
		fvector->content[removal_position] = -888888; //for clarity, could be removed if not needed
		fvector->used_spaces[removal_position] = false;
		int space_to_shrink = 0;
		while (!fvector->used_spaces[removal_position - space_to_shrink - 1]) {
			++space_to_shrink;
		}
		fvector->content = (int*)realloc(fvector->content, (fvector->size - space_to_shrink) * sizeof(int));
		fvector->size -= space_to_shrink;
	}
	else {
		return -4; //when vector type has been wrongly defined
	}
	return 0; //removal complete
}
int search_vector_int(vector_int* fvector, const int key) {
	if (!fvector->initialised) {
		return -1; //if vector hasn't been initialised
	}
	for (int index = 0; index < fvector->size; ++index) {
		while (fvector->used_spaces[index] == false) { //skips unused spaces
			++index;
		}
		if (fvector->content[index] == key) {
			return index; //returns index of found item
		}
	}
	return -2; //when key hasn't been found
}