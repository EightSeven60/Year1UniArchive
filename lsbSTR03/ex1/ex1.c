#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

//for lsi
typedef struct bracket_int {
	int content;
	struct bracket_int* next;
}data_point_int;

//for ldi
typedef struct bracket_ldi {
	struct bracket_ldi* previous;
	int content;
	struct bracket_ldi* next;
}bracket_ldi;
typedef struct chain_ldi {
	struct bracket_ldi* inception;
	struct bracket_ldi* termination;
	size_t size;
	size_t max_size;
}chain_ldi;

//for lsi
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

//for ldi
chain_ldi* initialise_ldi(const size_t maximum); //initializes list with given maximum size
bracket_ldi* find_in_ldi(chain_ldi* ldi, const int key); //returns pointer to bracket containing "key"
int insert_ldi(chain_ldi* ldi, const int to_be_inserted, const char* location); //inserts anywhere depending on "location"
int delete_from_ldi(chain_ldi* ldi, const char* to_be_deleted); //deallocates bracket containing to_be_deleted
int replace_in_ldi(chain_ldi* ldi, const int replace_this, const int with_this); //replaces given target with new data
int shell_sort_ldi_int(chain_ldi* ldi, const char order); //sorting
bracket_ldi* go_to_in_ldi(chain_ldi* ldi, const size_t position); //returns a pointer to the bracket at position when position can be 0 <-> size
int ldi_free(chain_ldi* ldi); //complete deallocation
int swap_ldi(chain_ldi* ldi, const int swap_this, const int with_this); //swap

int main()
{
	chain_ldi* ldi = initialise_ldi(1000);

	//demonstreisan
	insert_ldi(ldi, 69, "<");
	insert_ldi(ldi, 420, "<");
	insert_ldi(ldi, -256, ">");
	insert_ldi(ldi, -1, "420");
	insert_ldi(ldi, 8, "69");
	insert_ldi(ldi, 6, "-256");
	printf("%d", insert_ldi(ldi, 35, "<s")); //returns an error code
	delete_from_ldi(ldi, "-1");
	delete_from_ldi(ldi, ">");
	delete_from_ldi(ldi, "<");
	delete_from_ldi(ldi, "-256");
	delete_from_ldi(ldi, "69");
	delete_from_ldi(ldi, "69"); //returns an error code
	delete_from_ldi(ldi, ">");
	insert_ldi(ldi, 6, "-256");
	replace_in_ldi(ldi, 6, 7);
	replace_in_ldi(ldi, 0, 10); //returns an error code
	insert_ldi(ldi, 29, ">");
	insert_ldi(ldi, -9, ">");
	insert_ldi(ldi, 3, ">");
	insert_ldi(ldi, 100, ">");
	insert_ldi(ldi, -100, ">");
	insert_ldi(ldi, 2, ">");
	insert_ldi(ldi, 99, ">");
	insert_ldi(ldi, 1111, ">");
	insert_ldi(ldi, -1275, ">");
	insert_ldi(ldi, 2743, ">");
	bracket_ldi* test = go_to_in_ldi(ldi, 12);
	shell_sort_ldi_int(ldi, '>');
	swap_ldi(ldi, -1275, 2);
	ldi_free(ldi);

	fputs("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAI'm never gonna give you up, never gonna let you downAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n", stdout);
	(void)getchar();
	return 0;
}

//for LDI

chain_ldi* initialise_ldi(const size_t maximum) {
	struct chain_ldi* ldi = (chain_ldi*)calloc(1, sizeof(chain_ldi));
	if (ldi == NULL) {
		return NULL; //allocation error
	}
	if (!maximum) {
		return NULL; //why would you send a max of 0
	}
	ldi->size = 0;
	ldi->max_size = maximum;
	ldi->inception = (bracket_ldi*)calloc(1, sizeof(bracket_ldi));
	if (ldi->inception == NULL) {
		free(ldi);
		return NULL; //allocation error
	}
	ldi->inception->previous = NULL;
	ldi->inception->next = NULL;
	ldi->termination = ldi->inception;
	return ldi;
}
int insert_ldi(chain_ldi* ldi, const int to_be_inserted, const char* location){ //location can be < for beginning, > for end or a number to insert after
	if (ldi == NULL || ldi->inception == NULL || ldi->termination == NULL) {
		return -1; //when ldi hasn't been initialized. use "ldi = initialize_ldi()", you son of a queen
	}
	if (ldi->size >= ldi->max_size) {
		return -5; //list is already full, sowry master
	}
	if (ldi->size == 0) { //when size == 0 we don't give a qvack
		if (ldi->inception != NULL) {
			ldi->inception->content = to_be_inserted;
			++ldi->size;
		}
		else {
			ldi->inception = (bracket_ldi*)calloc(1, sizeof(bracket_ldi));
			ldi->inception->content = to_be_inserted;
			ldi->inception->next = NULL;
			ldi->inception->previous = NULL;
			ldi->termination = ldi->inception;
			++ldi->size;
		}
		return 0;
	}
	else if (!strcmp(location, "<")) { //inserts at the beginning
		bracket_ldi* new_bracket = (bracket_ldi*)calloc(1, sizeof(bracket_ldi));
		if (new_bracket == NULL) {
			return -4; //allocation error
		}
		new_bracket->content = to_be_inserted;
		ldi->inception->previous = new_bracket;
		new_bracket->next = ldi->inception;
		new_bracket->previous = NULL;
		ldi->inception = new_bracket;
		++ldi->size;
		return 0;
	}
	else if (!strcmp(location, ">")) { //inserts at the end
		bracket_ldi* new_bracket = (bracket_ldi*)calloc(1, sizeof(bracket_ldi));
		if (new_bracket == NULL) {
			return -4; //allocation error
		}
		new_bracket->content = to_be_inserted;
		ldi->termination->next = new_bracket;
		new_bracket->previous = ldi->termination;
		new_bracket->next = NULL;
		ldi->termination = new_bracket;
		++ldi->size;
		return 0;
	}
	else {
		int loc_len = strlen(location);
		for (int i = 0; i < loc_len; ++i) {
			if (location[i] != 45 && (location[i] < 47 || location[i] > 58)) {
				return -2; //when location wasn't '<', '>', nor a valid whole number
			}
		}
		int number = atoi(location);
		bracket_ldi* hit_location = find_in_ldi(ldi, number);
		if (hit_location == NULL) {
			return -3; //when data to insert after isn't present in list
		}
		else if (hit_location != ldi->termination) {
			bracket_ldi* to_be_next = hit_location->next;
			bracket_ldi* new_bracket = (bracket_ldi*)calloc(1, sizeof(bracket_ldi));
			if (new_bracket == NULL) {
				return -4; //allocation error
			}
			new_bracket->content = to_be_inserted;
			hit_location->next = new_bracket;
			new_bracket->previous = hit_location;
			new_bracket->next = to_be_next;
			to_be_next->previous = new_bracket;
			++ldi->size;
			return 0;
		}
		else { //insertion at the end if hit_location is the last in the list
			bracket_ldi* new_bracket = (bracket_ldi*)calloc(1, sizeof(bracket_ldi));
			if (new_bracket == NULL) {
				return -4; //allocation error
			}
			new_bracket->content = to_be_inserted;
			ldi->termination->next = new_bracket;
			new_bracket->previous = ldi->termination;
			new_bracket->next = NULL;
			ldi->termination = new_bracket;
			++ldi->size;
			return 0;
		}
	}
}
bracket_ldi* find_in_ldi(chain_ldi* ldi, const int key) {
	if (ldi == NULL || ldi->inception == NULL || ldi->termination == NULL) {
		return NULL; //when ldi hasn't been initialised
	}
	bracket_ldi* temporary_bracket = ldi->inception;
	while (temporary_bracket != ldi->termination && temporary_bracket->content != key) {
		temporary_bracket = temporary_bracket->next;
	}
	if (temporary_bracket->content != key) {
		return NULL; //when key isn't present
	}
	else {
		return temporary_bracket; //returned adress of bracket that contains specified data
	}
}
int delete_from_ldi(chain_ldi* ldi, const char* to_be_deleted) {
	if (ldi == NULL || ldi->inception == NULL || ldi->termination == NULL) {
		return -1; //when ldi hasn't been initialized. use "ldi = initialize_ldi()", you son of a queen
	}
	if (!ldi->size) {
		return -2; //can't delete from already-empty list
	}
	
	if (!strcmp(to_be_deleted, "<")) { //delete at the beginning
		if (ldi->size != 1) {
			ldi->inception = ldi->inception->next;
			free(ldi->inception->previous);
			ldi->inception->previous = NULL;
		}
		--ldi->size;
		return 0;
	}
	else if (!strcmp(to_be_deleted, ">")) { //delete at the end
		if (ldi->size != 1) {
			ldi->termination = ldi->termination->previous;
			free(ldi->termination->next);
			ldi->termination->next = NULL;
		}
		--ldi->size;
		return 0;
	}
	else { //delete somewhere in the middle
		int to_be_deleted_len = strlen(to_be_deleted);
		for (int i = 0; i < to_be_deleted_len; ++i) {
			if (to_be_deleted[i] != 45 && (to_be_deleted[i] < 47 || to_be_deleted[i] > 58)) {
				return -3; //when location wasn't '<', '>', nor a valid whole number
			}
		}
		int number = atoi(to_be_deleted);
		bracket_ldi* delete_this = find_in_ldi(ldi, number);
		if (delete_this == NULL) {
			return -4; //couldn't find item to be deleted
		}
		else if (delete_this == ldi->inception) { //delete at the beginning
			if (ldi->size != 1) {
				ldi->inception = ldi->inception->next;
				free(ldi->inception->previous);
				ldi->inception->previous = NULL;
			}
		}
		else if (delete_this == ldi->termination) { //delete at the end
			if (ldi->size != 1) {
				ldi->termination = ldi->termination->previous;
				free(ldi->termination->next);
				ldi->termination->next = NULL;
			}
		}
		else { //delete somewhere in the middle
			delete_this->previous->next = delete_this->next;
			delete_this->next->previous = delete_this->previous;
			free(delete_this);
		}
		--ldi->size;
		return 0;
	}
}
int replace_in_ldi(chain_ldi* ldi, const int replace_this, const int with_this) {
	if (ldi == NULL || ldi->inception == NULL || ldi->termination == NULL) {
		return -1; //when ldi hasn't been initialized. use "ldi = initialize_ldi()", you son of a queen
	}
	if (!ldi->size) {
		return -2; //can't replace something in an empty list
	}
	bracket_ldi* to_be_replaced = find_in_ldi(ldi, replace_this);
	if (to_be_replaced == NULL) {
		return -3; //when item to be replaced isn't present
	}
	to_be_replaced->content = with_this;
	return 0;
}
int shell_sort_ldi_int(chain_ldi* ldi, const char order) {
	if (ldi == NULL) {
		return -1; //when passed list doesn't exist
	}
	int* h = (int*)malloc(sizeof(int));
	int nh = 1, ih, pas, i, j;
	int temp;

	//picking step intervals
	if (h == NULL) {
		return -2; //allocation error
	}
	h[0] = (ldi->size - 1) / 3;
	for (i = 0; h[i] > 0; ++i) { //checks if we reached 1 which should be the end of the vector
		h = (int*)realloc(h, (i + 2) * sizeof(int)); // (i + 2) to take into account offset
		if (h == NULL) {
			return -2; //allocation error
		}
		h[i + 1] = (h[i] - 1) / 3; // (i + 1) to take into account offset
	}
	nh = i + 1;
	if (h[nh - 1] <= 0 && h[nh - 2] != 1) { //checks wether last entry was 0 or 1 and corrects accordingly
		h[nh - 1] = 1;
	}
	else {
		--nh;
	}

	//sorting
	if (order == '>') {
		for (ih = 0; ih < nh; ++ih) {
			pas = h[ih];
			for (i = pas; (unsigned)i < ldi->size; ++i) {
				//temp = fvector[i];
				temp = go_to_in_ldi(ldi, i)->content;
				//fvector[j - pas] > temp
				for (j = i; j >= pas && go_to_in_ldi(ldi, j - pas)->content > temp; j -= pas) {
					//fvector[j] = fvector[j - pas];
					go_to_in_ldi(ldi, j)->content = go_to_in_ldi(ldi, j - pas)->content;
				}
				//fvector[j] = temp;
				go_to_in_ldi(ldi, j)->content = temp;
			}
		}
	}
	else if (order == '<') {
		for (ih = 0; ih < nh; ++ih) {
			pas = h[ih];
			for (i = pas; (unsigned)i < ldi->size; ++i) {
				//temp = fvector[i];
				temp = go_to_in_ldi(ldi, i)->content;
				//fvector[j - pas] > temp
				for (j = i; j >= pas && go_to_in_ldi(ldi, j - pas)->content < temp; j -= pas) {
					//fvector[j] = fvector[j - pas];
					go_to_in_ldi(ldi, j)->content = go_to_in_ldi(ldi, j - pas)->content;
				}
				//fvector[j] = temp;
				go_to_in_ldi(ldi, j)->content = temp;
			}
		}
	}
	else {
		return -2; //when choice is invalid
	}
	free(h);
	return 0;
}
bracket_ldi* go_to_in_ldi(chain_ldi* ldi, const size_t position) {
	if (ldi == NULL) {
		return NULL; //when passed list doesn't exist
	}
	if (ldi->size == 0) {
		return NULL; //when list is empty
	}
	if (position >= ldi->size) {
		return NULL; //when position requested is not included in list
	}
	if (position < ldi->size - position) {
		bracket_ldi* scout = ldi->inception;
		for (int i = 0; (unsigned)i < position && scout->next != NULL; ++i) {
			scout = scout->next;
		}
		return scout;
	}
	else {
		bracket_ldi* scout = ldi->termination;
		for (int i = 0; (unsigned)i < ldi->size - position - 1 && scout->previous != NULL; ++i) {
			scout = scout->previous;
		}
		return scout;
	}
}
//in heap profiler imi apare ca imi creste memoria folosita de la 50kb la 55kb dupa alocari si inserari iar cand dealoc
//imi scade doar la 54kb chiar daca arata ca am dealocat si alocat acelasi numar de bytes, e normal?
int ldi_free(chain_ldi* ldi) { 
	if (ldi == NULL) {
		return -1; //when passed list doesn't exist
	}

	bracket_ldi* scout = ldi->termination;
	if (scout != NULL) {
		while (scout->previous != NULL) {
			scout = scout->previous;
			free(scout->next);
		}
		free(scout);
	}
	free(ldi);
	return 0;
}
int swap_ldi(chain_ldi* ldi, const int swap_this, const int with_this) {
	if (ldi == NULL) {
		return -1; //when passed list doesn't exist
	}

	bracket_ldi* scout = ldi->inception;
	bracket_ldi* first_hit = NULL;
	bracket_ldi* second_hit = NULL;
	//I didn't use find_in_ldi because looking for both at the same time is faster
	while (scout->next != NULL && (first_hit == NULL || second_hit == NULL)) {
		if (scout->content == swap_this) {
			first_hit = scout;
		}
		else if (scout->content == with_this) {
			second_hit = scout;
		}
		scout = scout->next;
	}
	if (first_hit == NULL || second_hit == NULL) {
		return -2; //when one of the keywords could not be found
	}

	first_hit->content += second_hit->content;
	second_hit->content = first_hit->content - second_hit->content;
	first_hit->content -= second_hit->content;
	return 0;
}

//for LSI

int initialize_lsi_int(data_point_int* start, int to_be_inserted) {
	start->content = to_be_inserted;
	start->next = NULL;
	return 0;
}

data_point_int* insert_lsi_int_beginning(data_point_int* start, int to_be_inserted) {
	if (start == NULL) {
		return NULL; //don't enter NULL as a parameter, ever, I don't care, initialize it first you beautiful person
	}

	data_point_int* new_data_point_int = (data_point_int*)calloc(1, sizeof(data_point_int));
	initialize_lsi_int(new_data_point_int, to_be_inserted);
	if (new_data_point_int == NULL) {
		return NULL; //allocation error
	}
	new_data_point_int->next = start;
	return new_data_point_int;
}
int insert_lsi_int_end(data_point_int* start, int to_be_inserted) {
	if (start == NULL) {
		return -1; //don't enter NULL as a parameter, ever, I don't care, initialize it first you beautiful person
	}

	data_point_int* new_data_point_int = (data_point_int*)calloc(1, sizeof(data_point_int));
	initialize_lsi_int(new_data_point_int, to_be_inserted);
	data_point_int* temp_data_point = start;
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
	if (new_data_point_int == NULL) {
		return -3; //allocation error
	}
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
		if (temp_data_point_int->next->content > * max) {
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