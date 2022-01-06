#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

typedef struct data_point_int {
	int content;
	struct data_point_int* next;
}data_point_int;

int initialize_lsi_int(data_point_int* start, int to_be_inserted);
data_point_int* insert_lsi_int_beginning(data_point_int* start, int to_be_inserted);
int insert_lsi_int_end(data_point_int* start, int to_be_inserted);
int insert_lsi_int(data_point_int* start, int to_be_inserted, int insert_after);
int delete_lsi_int(data_point_int* start, int to_be_deleted);
data_point_int* delete_lsi_int_beginning(data_point_int* start);
int delete_lsi_int_end(data_point_int* start);
int replace_lsi_int(data_point_int* start, int replace_this, int with_this);
int find_min_max_lsi_int(data_point_int* start, int* min, int* max);
int destroy_lsi_int(data_point_int* start);
int sort_bubble_lsi_int(data_point_int* start, char comparison);

int main()
{
	int min, max;
	data_point_int* start_lsi = (data_point_int*)calloc(1, sizeof(data_point_int));

	//demonstreisan
	initialize_lsi_int(start_lsi, 10);
	start_lsi = insert_lsi_int_beginning(start_lsi, 69);
	start_lsi = insert_lsi_int_beginning(start_lsi, -3578);
	insert_lsi_int_end(start_lsi, 286);
	insert_lsi_int_end(start_lsi, -999);
	start_lsi = delete_lsi_int_beginning(start_lsi);
	delete_lsi_int_end(start_lsi);
	delete_lsi_int(start_lsi, 10);
	replace_lsi_int(start_lsi, 69, 0);
	start_lsi = insert_lsi_int_beginning(start_lsi, -256);
	start_lsi = insert_lsi_int_beginning(start_lsi, 50);
	insert_lsi_int_end(start_lsi, -24);
	insert_lsi_int_end(start_lsi, 9);
	find_min_max_lsi_int(start_lsi, &min, &max);
	sort_bubble_lsi_int(start_lsi, '>');
	printf("%d\n", delete_lsi_int(start_lsi, 2));
	printf("%d\n", delete_lsi_int(start_lsi, 286));
	destroy_lsi_int(start_lsi);

	fputs("Press enter to do a barrel roll.\n", stdout);
	(void)getchar();
	return 0;
}

int initialize_lsi_int(data_point_int* start, int to_be_inserted) {
	start->content = to_be_inserted;
	start->next = NULL;
	return 0;
}

data_point_int* insert_lsi_int_beginning(data_point_int *start, int to_be_inserted) {
	if (start == NULL) {
		return NULL; //don't enter NULL as a parameter, ever, I don't care, initialize it first you beautiful person
	}

	data_point_int* new_data_point_int = (data_point_int*)calloc(1, sizeof(data_point_int));
	initialize_lsi_int(new_data_point_int, to_be_inserted);
	new_data_point_int->next = start;
	//return start = new_data_point_int;
	return new_data_point_int;
}
int insert_lsi_int_end(data_point_int* start, int to_be_inserted) {
	if (start == NULL) {
		return -1; //don't enter NULL as a parameter, ever, I don't care, initialize it first you beautiful person
	}

	data_point_int* new_data_point_int = (data_point_int*)calloc(1, sizeof(data_point_int));
	initialize_lsi_int(new_data_point_int, to_be_inserted);
	data_point_int *temp_data_point = start;
	while (temp_data_point->next != NULL) {
		temp_data_point = temp_data_point->next;
	}
	temp_data_point->next = new_data_point_int;
	return 0;
}
int insert_lsi_int(data_point_int* start, int to_be_inserted, int insert_after) {
	if (start == NULL) {
		return -1; //when start of list doesn't exist
	}

	data_point_int* new_data_point_int = (data_point_int*)calloc(1, sizeof(data_point_int));
	initialize_lsi_int(new_data_point_int, to_be_inserted);
	data_point_int* temp_data_point = start;

	while (temp_data_point->content != insert_after && temp_data_point->next != NULL) {
		temp_data_point = temp_data_point->next;
	}
	if ((temp_data_point->next == NULL) && (temp_data_point->content != insert_after)) {
		return -2; //when key wasn't found
	}

	data_point_int* future_succesor = temp_data_point->next;
	temp_data_point->next = new_data_point_int;
	new_data_point_int->next = future_succesor;

	return 0;
}

int delete_lsi_int(data_point_int* start, int to_be_deleted) {
	if (start == NULL) {
		return -1; //when start of list doesn't exist
	}

	data_point_int* temp_data_point = start;
	while ((temp_data_point->next->content != to_be_deleted && temp_data_point->next->next != NULL)) {
		temp_data_point = temp_data_point->next;
	}
	if (temp_data_point->next->next == NULL) {
		return -2; //when key wasn't found
	}

	data_point_int* temp_data_point_last = temp_data_point->next->next;
	free(temp_data_point->next);
	temp_data_point->next = temp_data_point_last;
	return 0;
}
data_point_int* delete_lsi_int_beginning(data_point_int* start) {
	if (start == NULL) {
		return NULL; //when start of list doesn't exist
	}
	data_point_int* new_start = start->next;
	free(start);
	return new_start;
}
int delete_lsi_int_end(data_point_int* start) {
	if (start == NULL) {
		return -1; //when start of list doesn't exist
	}
	data_point_int* temp_data_point_int = start;
	while (temp_data_point_int->next->next != NULL) {
		temp_data_point_int = temp_data_point_int->next;
	}
	free(temp_data_point_int->next); //asa e bine...
	//free(temp_data_point_int->next->next); //sau asa????
	temp_data_point_int->next = NULL;
	return 0;
}

int replace_lsi_int(data_point_int* start, int replace_this, int with_this) {
	if (start == NULL) {
		return -1; //when start of list doesn't exist
	}
	data_point_int* temp_data_point_int = start;
	while (temp_data_point_int->content != replace_this && temp_data_point_int->next != NULL) {
		temp_data_point_int = temp_data_point_int->next;
	}
	if (temp_data_point_int->content != replace_this && temp_data_point_int->next == NULL) {
		return -2; //when key wasn't found
	}
	temp_data_point_int->content = with_this;
	return 0;
}

int find_min_max_lsi_int(data_point_int* start, int* min, int* max) {
	if (start == NULL) {
		return -1; //when start of list doesn't exist
	}
	*min = start->content;
	*max = start->content;
	data_point_int* temp_data_point_int = start;
	while (temp_data_point_int->next != NULL) {
		if (temp_data_point_int->next->content < *min) {
			*min = temp_data_point_int->next->content;
		}
		if (temp_data_point_int->next->content > *max) {
			*max = temp_data_point_int->next->content;
		}
		temp_data_point_int = temp_data_point_int->next;
	}
	return 0;
}

//pls don't judge me for using bubble sort
int sort_bubble_lsi_int(data_point_int* start, char comparison) {
	if (start == NULL) {
		return -1; //when passed adress is invalid
	}
	if (comparison == '<') {
		char swap = 1;
		while (swap) {
			data_point_int* temp_data_point = start;
			swap = 0;
			while (temp_data_point->next != NULL) {
				if (temp_data_point->content < temp_data_point->next->content) {
					temp_data_point->content += temp_data_point->next->content;
					temp_data_point->next->content = temp_data_point->content - temp_data_point->next->content;
					temp_data_point->content -= temp_data_point->next->content;
					swap = 1;
				}
				temp_data_point = temp_data_point->next;
			}
		}
		return 0;
	}
	else if (comparison == '>') {
		char swap = 1;
		while (swap) {
			data_point_int* temp_data_point = start;
			swap = 0;
			while (temp_data_point->next != NULL) {
				if (temp_data_point->content > temp_data_point->next->content) {
					temp_data_point->content += temp_data_point->next->content;
					temp_data_point->next->content = temp_data_point->content - temp_data_point->next->content;
					temp_data_point->content -= temp_data_point->next->content;
					swap = 1;
				}
				temp_data_point = temp_data_point->next;
			}
		}
		return 0;
	}
	else {
		return -2; //when comparison choice is invalid
	}
}

int destroy_lsi_int(data_point_int* start) {
	if (start == NULL) {
		return -1; //when start of list doesn't exist
	}
	while (start != NULL) {
		data_point_int* temp_data_point_int = start;
		while (temp_data_point_int->next != NULL && temp_data_point_int->next->next != NULL) {
			temp_data_point_int = temp_data_point_int->next;
		}
		if (start == temp_data_point_int) {
			free(temp_data_point_int->next);
			temp_data_point_int->next = NULL;
			free(start);
			start = NULL;
		}
		else {
			free(temp_data_point_int->next);
			temp_data_point_int->next = NULL;
		}
	}
	return 0;
}