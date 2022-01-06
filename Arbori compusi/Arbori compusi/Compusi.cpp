#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

typedef struct bracket_int_stack {
	int content; //storage
	struct bracket_int_stack* next; //next bracket
}bracket_int_stack;
typedef struct stack_int {
	struct bracket_int_stack* top; //top of stack
	size_t size; //current size
	size_t max_size; //can be 0 indicating that there is no max size
}stack_int;

typedef struct bracket_int_queue {
	int content; //storage
	char priority; //higher values represent higher priorities that are taken out first
	struct bracket_int_queue* next; //next bracket
}bracket_int_queue;
typedef struct queue_int {
	struct bracket_int_queue* front;
	size_t size;
	size_t max_size;
	size_t priority_presence[5]; //indexes represent priority levels; values represent the amount of brackets that have said priority
	struct bracket_int_queue* back; //back isn't used anywhere but I let it be
}queue_int;

typedef struct bracket_bst {
	int identifier;
	char* info;
	struct bracket_bst* parent;
	struct bracket_bst* left;
	struct bracket_bst* right;
}bracket_bst;
typedef struct bst {
	bracket_bst* root;
	size_t size;
}bst;

queue_int* initialise_queue(const size_t max_size) {
	queue_int* new_q = (queue_int*)calloc(1, sizeof(queue_int));
	if (new_q == NULL) {
		return NULL;
	}
	if (max_size) {
		new_q->max_size = max_size;
	}
	return new_q;
}
int enqueue_with_priority_int(queue_int* my_queue, const int value, const int priority) {
	if (my_queue == NULL) {
		return -1; //when passed pointer is NULL
	}
	if (!(my_queue->size < my_queue->max_size) && my_queue->max_size) {
		return -2; //when queue is full
	}
	if (priority < 0 || priority > 4) {
		return -4; //invalid priority passed
	}
	bracket_int_queue* new_data = (bracket_int_queue*)calloc(1, sizeof(bracket_int_queue));
	if (new_data == NULL) {
		return -3; //allocation error
	}
	new_data->priority = priority;
	++my_queue->priority_presence[priority];
	new_data->content = value;
	if (++my_queue->size == 1) {
		my_queue->front = my_queue->back = new_data;
	}
	else {
		my_queue->back->next = new_data;
		my_queue->back = new_data;
	}
	return 0;
}
int dequeue_int(queue_int* my_queue) {
	if (my_queue == NULL) {
		return -1; //when passed pointer is NULL
	}
	if (!my_queue->size) {
		return -2; //queue is empty
	}

	int emigrant = my_queue->front->content;
	--my_queue->priority_presence[my_queue->front->priority];
	--my_queue->size;
	if (!my_queue->size) {
		free(my_queue->front);
		my_queue->front = my_queue->back = NULL;
	}
	else {
		bracket_int_queue* old_front = my_queue->front;
		my_queue->front = my_queue->front->next;
		free(old_front);
	}
	return emigrant;
}
int dequeue_highest_priority_int(queue_int* my_queue) {
	if (my_queue == NULL) {
		return -1; //when passed pointer is NULL
	}
	if (!my_queue->size) {
		return -2; //queue is empty
	}
	for (int priority_index = 4; priority_index - 1; --priority_index) { //check priorities from higher to lower
		if (my_queue->priority_presence[priority_index]) { //only search in queue if a bracket with current priority is present
			bracket_int_queue* scout = my_queue->front;
			bracket_int_queue* previous_scout = NULL;
			while (scout->priority != priority_index) { //finds first bracket of highest priority
				previous_scout = scout;
				scout = scout->next;
			}
			--my_queue->size;
			--my_queue->priority_presence[priority_index];
			int return_this = scout->content; //saves the return value
			if (previous_scout != NULL) { //when the found bracket is NOT the front of the queue
				previous_scout->next = scout->next;
				if (scout == my_queue->back) {
					my_queue->back = previous_scout;
					my_queue->back->next = NULL;
				}
			}
			else { //when the found bracket is the front of queue
				my_queue->front = scout->next;
				if (!my_queue->size) { //when the queue empties after this dequeue
					my_queue->back = NULL;
				}
			}
			free(scout);
			return return_this;
		}
	}
}
int reset_queue_int(queue_int* my_queue) {
	if (my_queue == NULL) {
		return -1; //when queue doesn't exist
	}

	if (my_queue->size) {
		bracket_int_queue* scout = my_queue->front;
		bracket_int_queue* delete_this;
		while (scout != NULL && scout->next != NULL) {
			delete_this = scout;
			scout = scout->next;
			free(delete_this);
		}
		free(scout);
	}
	free(my_queue);
	return 0;
}
int peek_int(queue_int* my_queue) {
	if (my_queue == NULL) {
		return -1; //when passed pointer is NULL
	}
	if (!my_queue->size) {
		return -2; //queue is empty
	}

	for (int priority_index = 4; priority_index - 1; --priority_index) {
		if (my_queue->priority_presence[priority_index]) {
			bracket_int_queue* scout = my_queue->front;
			while (scout->priority != priority_index) {
				scout = scout->next;
			}
			int return_this = scout->content;
			return return_this;
		}
	}
}

stack_int* initialise_stack(const size_t size_max) {
	stack_int* new_stack = (stack_int*)calloc(1, sizeof(stack_int));
	if (new_stack == NULL) {
		return NULL; //allocation error
	}
	new_stack->max_size = 0;
	new_stack->size = 0;
	new_stack->top = NULL;
	return new_stack;
}
int push_int(stack_int* my_stack, int to_be_pushed) {
	if (my_stack == NULL) {
		return -1; //passed stack pointer is null
	}
	if (!(my_stack->max_size > my_stack->size) && my_stack->max_size) {
		return -3; //stack overflow
	}
	bracket_int_stack* new_bracket = (bracket_int_stack*)calloc(1, sizeof(bracket_int_stack));
	if (new_bracket == NULL) {
		return -2; //allocation error
	}
	new_bracket->content = to_be_pushed;
	new_bracket->next = my_stack->top;
	my_stack->top = new_bracket;
	++my_stack->size;
	return 0;
}
int pop_int(stack_int* my_stack) {
	if (my_stack == NULL) {
		return 0; //passed stack pointer is null
	}
	if (!my_stack->size) {
		return 0; //stack is empty
	}
	int to_be_returned = my_stack->top->content;
	bracket_int_stack* to_be_deleted = my_stack->top;
	my_stack->top = my_stack->top->next;
	free(to_be_deleted);
	--my_stack->size;
	return to_be_returned;
}
int reset_stack(stack_int* my_stack) {
	if (my_stack == NULL) {
		return -1; //error, success
	}

	bracket_int_stack* scout = my_stack->top;
	while (my_stack->top != NULL) {
		scout = my_stack->top;
		if (scout->next == NULL) {
			free(scout);
			my_stack->top = NULL;
		}
		else {
			while (scout->next->next != NULL) {
				scout = scout->next;
			}
			free(scout->next);
			scout->next = NULL;
		}
	}
	free(my_stack);
	my_stack = NULL;
	return 0;
}
int full_stack(stack_int* my_stack) {
	if (my_stack == NULL) {
		return -1; //passed pointer is NULL
	}
	return my_stack->max_size - my_stack->size + 1; //returns true when stack is full
}
int empty_stack(stack_int* my_stack) {
	if (my_stack == NULL) {
		return -1; //well it doesn't exist so it's technically empty, right?
	}
	return my_stack->size + 1; //returns true when empty or jibberish otherwise
}

bst* initialise_bst() {
	return (bst*)calloc(1, sizeof(bst));
}
int insert_bst(bst* tree, int id, char* info) {
	if (tree == NULL) {
		return -1; //passed tree pointer invalid
	}

	bracket_bst* scout = tree->root;
	if (tree->size) {
		while (1) {
			if (id < scout->identifier) {
				if (scout->left != NULL) {
					scout = scout->left;
				}
				else {
					bracket_bst* bracket_new = (bracket_bst*)calloc(1, sizeof(bracket_bst));
					if (bracket_new == NULL) {
						return -3; //allocation error
					}
					bracket_new->identifier = id;
					bracket_new->info = info;
					bracket_new->parent = scout;
					scout->left = bracket_new;
					++tree->size;
					break; //found spot for given id
				}
			}

			else if (id > scout->identifier) {
				if (scout->right != NULL) {
					scout = scout->right;
				}
				else {
					bracket_bst* bracket_new = (bracket_bst*)calloc(1, sizeof(bracket_bst));
					if (bracket_new == NULL) {
						return -3; //allocation error
					}
					bracket_new->identifier = id;
					bracket_new->info = info;
					bracket_new->parent = scout;
					scout->right = bracket_new;
					++tree->size;
					break; //found spot for given id
				}
			}
			else {
				return -2; //bracked with specified id already exists; can't have duplicates in a binary search tree
			}
		}
	}
	else {
		bracket_bst* bracket_new = (bracket_bst*)calloc(1, sizeof(bracket_bst));
		if (bracket_new == NULL) {
			return -3; //allocation error
		}
		bracket_new->identifier = id;
		bracket_new->info = info;
		tree->root = bracket_new;
		++tree->size;
	}
	return 0;
}
int destroy_bst(bst* tree) {
	if (tree == NULL) {
		return -1; //passed tree pointer invalid
	}
	bracket_bst* scout = tree->root;
	bracket_bst* garbage;
	if (scout != NULL) {
		do {
			if (scout->left) {
				scout = scout->left;
			}
			else if (scout->right) {
				scout = scout->right;
			}
			else if (scout->parent) {
				garbage = scout;
				scout = scout->parent;
				free(garbage);
				if (scout->left == garbage) {
					scout->left = NULL;
				}
				else {
					scout->right = NULL;
				}
				--tree->size;
			}
		} while (scout->parent != NULL || scout->left != NULL || scout->right != NULL);
		free(scout);
	}
	free(tree);
	return 0;
}
int inordine_iterativ(bst* tree) {
	char last_back = 0, last_left = 0, last_right = 0, last_jump = 0, root_hits = 0;
	if (tree == NULL) {
		return -1; //passed tree pointer invalid
	}
	bracket_bst* scout = tree->root;
	if (scout != NULL) {
		do {

			if (!(scout->left || scout->right)) {
				printf("%d ", scout->identifier);
			}

			if (scout->left && !last_back) {
				scout = scout->left;
				last_left = 1;
				last_right = 0;
				last_back = 0;
			}
			else if (scout->right && (!last_back || !last_right)) {
				printf("%d ", scout->identifier);
				scout = scout->right;
				last_left = 0;
				last_right = 1;
				last_back = 0;
			}
			else if (scout->parent) {
				scout = scout->parent;
				last_left = 0;
				last_back = 1;
			}
			else {
				last_back = 0;
				printf("%d ", scout->identifier);
				scout = scout->right;
			}

			if (scout == tree->root) {
				++root_hits;
			}

		} while (root_hits < 2);
	}
	return 0;
}
int inordine(bracket_bst* root) {
	if (root == NULL) {
		return -1;
	}
	inordine(root->left);
	printf("%d ", root->identifier); //I "processed" the id but usually you'd process the "info"
	inordine(root->right);
	return 0;
}
int preordine(bracket_bst* root) {
	if (root == NULL) {
		return -1;
	}
	printf("%d ", root->identifier); //I "processed" the id but usually you'd process the "info"
	inordine(root->left);
	inordine(root->right);
	return 0;
}
int postordine(bracket_bst* root) {
	if (root == NULL) {
		return -1;
	}
	inordine(root->left);
	inordine(root->right);
	printf("%d ", root->identifier); //I "processed" the id but usually you'd process the "info"
	return 0;
}
bracket_bst* search_bst(bracket_bst* root, int id) {
	if (root == NULL) {
		return NULL; //passed root was null
	}
	if (root->identifier == id) {
		return root;
	}
	else if (root->identifier > id) {
		return search_bst(root->left, id);
	}
	else if (root->identifier < id) {
		return search_bst(root->right, id);
	}
	else {
		return NULL; //unknown error
	}
}
int remove_from_bst(bracket_bst* root, int id) {
	bracket_bst* garbage;
	garbage = search_bst(root, id);
	if (garbage == NULL) {
		return -1; //missing item
	}
	if (!garbage->left && !garbage->right) { //case 1
		if (garbage->parent->left == garbage) {
			garbage->parent->left = NULL;
		}
		else {
			garbage->parent->right = NULL;
		}
		free(garbage);
	}
	else if (!garbage->left ^ !garbage->right) { //case 2
		if (garbage->parent->left == garbage) {
			if (garbage->left == NULL) {
				garbage->parent->left = garbage->right;
			}
			else {
				garbage->parent = garbage->left;
			}
		}
		else {
			if (garbage->right == NULL) {
				garbage->parent->right = garbage->left;
			}
			else {
				garbage->parent->right = garbage->left;
			}
		}
		free(garbage);
	}
	else { //case 3
		bracket_bst* garbage1;
		garbage1 = garbage->left;
		garbage->parent = garbage1;
		while (garbage1->right != NULL) {
			garbage->parent = garbage1;
			garbage1 = garbage1->right;
		}
		garbage->identifier = garbage1->identifier;
		garbage->info = garbage1->info;
		garbage->parent->right = garbage1->left;
		free(garbage1);
	}
	return 0;
}
bst* generate_bst(const unsigned int size) {
	//safety checks
	bst* tree = initialise_bst();
	if (tree == NULL) {
		return NULL; //allocation error
	}
	if (size == 0) {
		return tree;
	}

	unsigned int height = 0;
	int random;
	int last;

	//first and second insertion
	insert_bst(tree, rand(), (char*)"generated info");
	if (size == 1) {
		return tree;
	}
	++height;
	random = rand();
	last = random;
	insert_bst(tree, random, (char*)"generated info");
	if (size == 2) {
		return tree;
	}
	++height;

	//rest of insertions
	if (random < last) {
		while (height < size) {
			random = rand();
			if (random < last) {
				insert_bst(tree, random, (char*)"generated info");
				last = random;
				++height;
			}
		}
	}
	else {
		while (height < size) {
			random = rand();
			if (random > last) {
				insert_bst(tree, random, (char*)"generated info");
				last = random;
				++height;
			}
		}
	}
	return tree;
}
int measure_and_destroy_bst(bst* tree) {
	if (tree == NULL) {
		return -1; //passed tree pointer invalid
	}
	bracket_bst* scout = tree->root;
	bracket_bst* garbage;
	unsigned int height;
	unsigned int max_height;
	if (tree->root) {
		height = max_height = 1;
	}
	else {
		height = max_height = 0;
	}
	if (scout != NULL) {
		do {
			if (scout->left) {
				scout = scout->left;
				++height;
			}
			else if (scout->right) {
				scout = scout->right;
				++height;
			}
			else if (scout->parent) {
				garbage = scout;
				scout = scout->parent;
				--height;
				free(garbage);
				if (scout->left == garbage) {
					scout->left = NULL;
				}
				else {
					scout->right = NULL;
				}
				--tree->size;
			}
			if (height > max_height) max_height = height;
		} while (scout->parent != NULL || scout->left != NULL || scout->right != NULL);
		free(scout);
	}
	free(tree);
	return max_height;
}
int* read_bst_inordine(bracket_bst* root, int* my_array, int& array_size) {
	int* temp_array = (int*)calloc(array_size, sizeof(int));
	if (root == NULL) {
		return my_array;
	}
	my_array = read_bst_inordine(root->left, my_array, array_size);
	for (int i = 0; i < array_size; ++i) {
		temp_array[i] = my_array[i];
	}
	++array_size;
	my_array = (int*)realloc(my_array, array_size);
	my_array[array_size - 1] = root->identifier;
	for (int i = 0; i < array_size - 1; ++i) {
		my_array[i] = temp_array[i];
	}
	my_array = read_bst_inordine(root->right, my_array, array_size);
	return my_array;
}
int read_bst_inordine_stack(bracket_bst* root, stack_int* stack) {
	if (root == NULL) {
		return -1;
	}
	push_int(stack, root->identifier);
	read_bst_inordine_stack(root->left, stack);
	read_bst_inordine_stack(root->right, stack);
	pop_int(stack);
	return 0;
}
int read_bst_level_queue(bracket_bst* root, queue_int* queue) {
	boolean left_check = 0;
	boolean right_check = 0;
	if (root == NULL) {
		return -1;
	}
	if (root->left != NULL) {
		enqueue_with_priority_int(queue, root->left->identifier, 2);
		left_check = 1;
	}
	if (root->right != NULL) {
		enqueue_with_priority_int(queue, root->right->identifier, 2);
		right_check = 1;
	}
	if (!(left_check || right_check)) {
		dequeue_highest_priority_int(queue);
	}
	read_bst_level_queue(root->left, queue);
	read_bst_level_queue(root->right, queue);
	return 0;
}
bracket_bst* search_by_info(bracket_bst* root, char* info, bracket_bst& find) {
	if (!strcmp(root->info, info)) {
		find = *root;
	}
	if (root->left != NULL) {
		search_by_info(root->left, info, find);
	}
	if (root->right != NULL) {
		search_by_info(root->right, info, find);
	}
	return 0;
}

int main() {
	bst* tree = initialise_bst();
	queue_int* queue = initialise_queue(0);
	stack_int* stack = initialise_stack(0);
	bracket_bst find = { 0 };

	insert_bst(tree, 50, (char*)"Rares");
	insert_bst(tree, 10, (char*)"Andrei");
	insert_bst(tree, 44, (char*)"Anto");
	insert_bst(tree, 60, (char*)"Banca");
	insert_bst(tree, 5, (char*)"Barni");
	search_by_info(tree->root, (char*)"Barni", find);

	(void)getchar();
	return 0;
}