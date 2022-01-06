#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef struct bracket {
	int identifier;
	char* info; //info is optional to functionality so I didn't write code to handle it at all
	struct bracket* parent;
	struct bracket* left;
	struct bracket* right;
}bracket;

typedef struct bst {
	bracket* root;
	size_t size;
}bst;

bst* initialise_bst();
int insert_bst(bst* tree, int id);
int destroy_bst(bst* tree);
int inordine_iterativ(bst* tree); //fail, couldn't get it to work
int inordine(bracket* root);
int preordine(bracket* root);
int postordine(bracket* root);
bracket* search_bst(bracket* root, int id);
int remove_from_bst(bracket* root, int id);
bst* generate_bst(const unsigned int size); //you didn't mention HOW I should do it :-D
int measure_and_destroy_bst(bst* tree); //you didn't mention that the tree must survive :-D

int main()
{
	srand(time(NULL));
	bst* tree = initialise_bst();
	bst* random_tree = generate_bst(7);
	insert_bst(tree, 2);
	insert_bst(tree, -1);
	insert_bst(tree, 0);
	insert_bst(tree, 6);
	insert_bst(tree, 10);
	insert_bst(tree, 11);
	insert_bst(tree, 7);
	insert_bst(tree, 1);
	insert_bst(tree, 5);
	insert_bst(tree, -5);
	insert_bst(tree, 3);
	insert_bst(tree, 4);
	inordine(tree->root);
	printf("\n");
	preordine(tree->root);
	printf("\n");
	postordine(tree->root);
	printf("\n");
	printf("%d ", search_bst(tree->root, 7)->identifier);
	remove_from_bst(tree->root, -1);
	//destroy_bst(tree);
	int measurement = measure_and_destroy_bst(random_tree);
	

	printf("%c\n", 3);
	(void)getchar();
	return 0;
}

bst* initialise_bst() {
	return calloc(1, sizeof(bst));
}
int insert_bst(bst* tree, int id) {
	if (tree == NULL) {
		return -1; //passed tree pointer invalid
	}

	bracket* scout = tree->root;
	if (tree->size) {
		while (1) {
			if (id < scout->identifier) {
				if (scout->left != NULL) {
					scout = scout->left;
				}
				else {
					bracket* bracket_new = calloc(1, sizeof(bracket));
					if (bracket_new == NULL) {
						return -3; //allocation error
					}
					bracket_new->identifier = id;
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
					bracket* bracket_new = calloc(1, sizeof(bracket));
					if (bracket_new == NULL) {
						return -3; //allocation error
					}
					bracket_new->identifier = id;
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
		bracket* bracket_new = calloc(1, sizeof(bracket));
		if (bracket_new == NULL) {
			return -3; //allocation error
		}
		bracket_new->identifier = id;
		tree->root = bracket_new;
		++tree->size;
	}
	return 0;
}
int destroy_bst(bst* tree) {
	if (tree == NULL) {
		return -1; //passed tree pointer invalid
	}
	bracket* scout = tree->root;
	bracket* garbage;
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
	bracket* scout = tree->root;
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
int inordine(bracket* root) {
	if (root == NULL) {
		return -1;
	}
	inordine(root->left);
	printf("%d ", root->identifier); //I "processed" the id but usually you'd process the "info"
	inordine(root->right);
	return 0;
}
int preordine(bracket* root) {
	if (root == NULL) {
		return -1;
	}
	printf("%d ", root->identifier); //I "processed" the id but usually you'd process the "info"
	inordine(root->left);
	inordine(root->right);
	return 0;
}
int postordine(bracket* root) {
	if (root == NULL) {
		return -1;
	}
	inordine(root->left);
	inordine(root->right);
	printf("%d ", root->identifier); //I "processed" the id but usually you'd process the "info"
	return 0;
}
bracket* search_bst(bracket* root, int id) {
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
int remove_from_bst(bracket* root, int id) {
	bracket* garbage;
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
		bracket* garbage1;
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
	insert_bst(tree, rand());
	if (size == 1) {
		return tree;
	}
	++height;
	random = rand();
	last = random;
	insert_bst(tree, random);
	if (size == 2) {
		return tree;
	}
	++height;

	//rest of insertions
	if (random < last) {
		while (height < size) {
			random = rand();
			if (random < last) {
				insert_bst(tree, random);
				last = random;
				++height;
			}			
		}
	}
	else {
		while (height < size) {
			random = rand();
			if (random > last) {
				insert_bst(tree, random);
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
	bracket* scout = tree->root;
	bracket* garbage;
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