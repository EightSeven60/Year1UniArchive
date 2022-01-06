#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

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

queue_int* initialise_queue(const size_t max_size);
int enqueue_with_priority_int(queue_int* my_queue, const int value, const int priority);
int dequeue_int(queue_int* my_queue); //dequeues front of queue regardless of priority
int reset_queue_int(queue_int* my_queue); //deallocates all brackets in queue and the queue itself
int dequeue_highest_priority_int(queue_int* my_queue);
int peek_int(queue_int* my_queue); //assumed peek needed to return without removing returned item from queue

int main()
{
	int number;

	queue_int* my_queue = initialise_queue(10);
	enqueue_with_priority_int(my_queue, 10, 3);
	enqueue_with_priority_int(my_queue, 20, 0);
	enqueue_with_priority_int(my_queue, 0, 1);
	enqueue_with_priority_int(my_queue, -10, 2);
	enqueue_with_priority_int(my_queue, -2450, 6);
	dequeue_int(my_queue);
	dequeue_int(my_queue);
	dequeue_int(my_queue);
	enqueue_with_priority_int(my_queue, 28, 2);
	enqueue_with_priority_int(my_queue, 2, 2);
	enqueue_with_priority_int(my_queue, 8, 1);
	enqueue_with_priority_int(my_queue, -2, 4);
	enqueue_with_priority_int(my_queue, -253, 4);
	enqueue_with_priority_int(my_queue, 6, 2);
	enqueue_with_priority_int(my_queue, 1000, 3);
	enqueue_with_priority_int(my_queue, 'd', 1);
	enqueue_with_priority_int(my_queue, 'A', 2); //returns error code
	enqueue_with_priority_int(my_queue, '0', 3); //returns error code
	reset_queue_int(my_queue);

	my_queue = initialise_queue(0);
	dequeue_int(my_queue);
	enqueue_with_priority_int(my_queue, -2, 4);
	enqueue_with_priority_int(my_queue, 23, 3);
	dequeue_int(my_queue);
	dequeue_int(my_queue);
	dequeue_int(my_queue); //returns error code
	reset_queue_int(my_queue);

	my_queue = initialise_queue(0);
	enqueue_with_priority_int(my_queue, 10, 5);
	enqueue_with_priority_int(my_queue, 2, 4);
	enqueue_with_priority_int(my_queue, 12, 2);
	enqueue_with_priority_int(my_queue, 125, 2);
	enqueue_with_priority_int(my_queue, 21, 4);
	enqueue_with_priority_int(my_queue, -214, 2);
	enqueue_with_priority_int(my_queue, 0, 2);
	enqueue_with_priority_int(my_queue, 25, 3);
	number = peek_int(my_queue);
	number = dequeue_highest_priority_int(my_queue);
	number = peek_int(my_queue);
	number = dequeue_highest_priority_int(my_queue);
	number = dequeue_highest_priority_int(my_queue);
	number = dequeue_highest_priority_int(my_queue);
	number = dequeue_highest_priority_int(my_queue);
	number = dequeue_highest_priority_int(my_queue);
	number = dequeue_highest_priority_int(my_queue);
	number = dequeue_highest_priority_int(my_queue);
	number = dequeue_highest_priority_int(my_queue);
	number = dequeue_highest_priority_int(my_queue);
	reset_queue_int(my_queue);

	printf("%c\n", 3);
	(void)getchar();
	return 0;
}

queue_int* initialise_queue(const size_t max_size) {
	queue_int* new_q = calloc(1, sizeof(queue_int));
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
	bracket_int* new_data = calloc(1, sizeof(bracket_int));
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