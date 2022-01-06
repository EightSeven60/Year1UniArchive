#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>

typedef struct bracket_int {
	int content; //storage
	struct bracket_int* next; //next bracket
}bracket_int;

typedef struct stack_int {
	struct bracket_int* top; //top of stack
	size_t size; //current size
	size_t max_size; //can be 0 indicating that there is no max size
}stack_int;

typedef struct bracket_int {
	int content; //storage
	char priority; //higher values represent higher priorities that are taken out first
	struct bracket_int* next; //next bracket
}bracket_int;

typedef struct queue_int {
	struct bracket_int* front;
	size_t size;
	size_t max_size;
	size_t priority_presence[5]; //indexes represent priority levels; values represent the amount of brackets that have said priority
	struct bracket_int* back; //back isn't used anywhere but I let it be
}queue_int;

stack_int* initialise_stack(const size_t size_max);
int push_int(stack_int* my_stack, int to_be_pushed);
int pop_int(stack_int* my_stack);
int reset_stack(stack_int* my_stack);
int full_stack(stack_int* my_stack);
int empty_stack(stack_int* my_stack);

queue_int* initialise_queue(const size_t max_size);
int enqueue_with_priority_int(queue_int* my_queue, const int value, const int priority);
int dequeue_int(queue_int* my_queue); //dequeues front of queue regardless of priority
int reset_queue_int(queue_int* my_queue); //deallocates all brackets in queue and the queue itself
int dequeue_highest_priority_int(queue_int* my_queue);
int peek_int(queue_int* my_queue); //assumed peek needed to return without removing returned item from queue

void check_for_keystroke(char& fkeystroke) {
	while (!_kbhit()) {
		Sleep(1);
	}
	if (_kbhit()) {
		fkeystroke = _getch();
		//fprintf(stdout, "keystroke: %c\n", fkeystroke);
	}
}

int main() {
	char keystroke = 0;
	stack_int* stack = initialise_stack(0);
	queue_int* queue = initialise_queue(0);
	printf("Introduceti un cuvant.\n");
	do {
		check_for_keystroke(keystroke);
		if ((keystroke > 64 && keystroke < 91) || keystroke > 96 && keystroke < 123) {
			push_int(stack, keystroke);
			enqueue_with_priority_int(queue, keystroke, 1);
		}
	} while (keystroke != 10);
	(void)getchar();
	return 0;
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
	bracket_int* new_bracket = (bracket_int*)calloc(1, sizeof(bracket_int));
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
	bracket_int* to_be_deleted = my_stack->top;
	my_stack->top = my_stack->top->next;
	free(to_be_deleted);
	--my_stack->size;
	return to_be_returned;
}
int reset_stack(stack_int* my_stack) {
	if (my_stack == NULL) {
		return -1; //error, success
	}

	bracket_int* scout = my_stack->top;
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
	bracket_int* new_data = (bracket_int*)calloc(1, sizeof(bracket_int));
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
		bracket_int* old_front = my_queue->front;
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
			bracket_int* scout = my_queue->front;
			bracket_int* previous_scout = NULL;
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
		bracket_int* scout = my_queue->front;
		bracket_int* delete_this;
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
			bracket_int* scout = my_queue->front;
			while (scout->priority != priority_index) {
				scout = scout->next;
			}
			int return_this = scout->content;
			return return_this;
		}
	}
}