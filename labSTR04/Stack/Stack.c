#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

typedef struct bracket_int {
	int content; //storage
	struct bracket_int* next; //next bracket
}bracket_int;

typedef struct stack_int {
	struct bracket_int* top; //top of stack
	size_t size; //current size
	size_t max_size; //can be 0 indicating that there is no max size
}stack_int;

stack_int* initialise_stack(const size_t size_max);
int push_int(stack_int* my_stack, int to_be_pushed);
int pop_int(stack_int* my_stack);
int reset_stack(stack_int* my_stack);
int full_stack(stack_int* my_stack);
int empty_stack(stack_int* my_stack);

int main()
{
	//example usage
	int popped;
	stack_int* my_stack = initialise_stack(0);
	printf("Popped number: %d\n", push_int(my_stack, 1));
	push_int(my_stack, -346);
	push_int(my_stack, 0);
	popped = pop_int(my_stack);
	popped = pop_int(my_stack);
	popped = pop_int(my_stack);
	popped = pop_int(my_stack);
	push_int(my_stack, 10);
	push_int(my_stack, -2);
	push_int(my_stack, -3563);
	push_int(my_stack, 123530);
	reset_stack(my_stack);

	//ADDING NUMBERS USING STACKS
	int number1 = 5;
	int number2 = 10;

	//filling stacks with the numbers
	stack_int* stack1 = initialise_stack(0);
	stack_int* stack2 = initialise_stack(0);
	int i = 1000000000;
	boolean found_first_digit1 = 0;
	boolean found_first_digit2 = 0;
	while (i) {
		if (found_first_digit1 || number1 / i) {
			push_int(stack1, number1 / i);
			number1 %= i;
			found_first_digit1 = 1;
		}
		if (found_first_digit2 || number2 / i) {
			push_int(stack2, number2 / i);
			number2 %= i;
			found_first_digit2 = 1;
		}
		i /= 10;
	}
	int digit_sum = 0, transfer = 0, final_sum = 0; //addition
	boolean not_empty_stacks = 1; //0 when both stacks are empty
	i = 1;
	do {
		digit_sum = pop_int(stack1) + pop_int(stack2) + transfer;
		transfer = 0;
		not_empty_stacks = stack1->size + stack2->size;
		if (digit_sum > 9) {
			++transfer;
			digit_sum -= 10;
		}
		else if (digit_sum < 0 && not_empty_stacks) {
			transfer = -1;
			digit_sum += 10;
		}
		final_sum += digit_sum * i;
		i *= 10;
	} while (not_empty_stacks || transfer);
	printf("Sum is %d.\n", final_sum);

	printf("%c", 3);
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
