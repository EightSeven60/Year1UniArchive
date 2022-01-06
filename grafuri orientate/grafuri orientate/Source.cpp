#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#define ESCAPE 27
#define ENTER 13

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

typedef const unsigned char c_u_char;
typedef unsigned char u_char;
typedef const char c_char;

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

void check_for_keystroke(char& fkeystroke) {
	while (!_kbhit()) {
		Sleep(1);
	}
	if (_kbhit()) {
		fkeystroke = _getch();
		//fprintf(stdout, "keystroke: %c\n", fkeystroke);
	}
}
int clear() {
	COORD cursor_position;
	cursor_position.X = 0;
	cursor_position.Y = 0;
	SetConsoleCursorPosition(hConsole, cursor_position);
	printf(
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
		"                                                                                                                                                    "
	);
	SetConsoleCursorPosition(hConsole, cursor_position);
	return 0;
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
			delete_this = NULL;
		}
		free(scout);
		scout = NULL;
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
boolean isInQueue(queue_int* queue, int target) {
	bracket_int_queue* scout = queue->front;
	if (scout == NULL) {
		return false;
	}
	if (scout->content == target) {
		return true;
	}
	while (scout->next != NULL) {
		scout = scout->next;
		if (scout->content == target) {
			return true;
		}
	}
	return false;
}
int removeFromQueue(queue_int* queue, int target) {
	bracket_int_queue* scout = queue->front;
	bracket_int_queue* scoutParent = NULL;
	if (scout == NULL) {
		return -1; //queue is empty
	}
	if (scout->content == target) {
		queue->front = queue->front->next;
		free(scout);
		while (!removeFromQueue(queue, target));
		return 0; //success
	}
	while (scout->next != NULL && scout->content != target) {
		scoutParent = scout;
		scout = scout->next;
	}
	if (scout->content == target && scoutParent != NULL) {
		scoutParent->next = scout->next;
		free(scout);
		while (!removeFromQueue(queue, target));
		return 0; //success
	}
	else {
		return -2; //could not find target
	}
}
int printQueue(queue_int* queue) {
	if (queue == NULL) {
		return -1; //passed queue is null
	}
	bracket_int_queue* scout = queue->front;
	do {
		printf("%d ", scout->content);
		scout = scout->next;
	} while (scout != NULL);
	return 0;
}

class Muchie {
public:

	int origin;
	int destination;

	Muchie(int origin, int destination) {
		this->origin = origin;
		this->destination = destination;
	}
};

int gasesteNodMaxim(Muchie* muchii, int nrMuchii) {
	int max = 0;
	for (int i = 0; i < nrMuchii; ++i) {
		if (muchii[i].origin > max) {
			max = muchii[i].origin;
		}
		if (muchii[i].destination > max) {
			max = muchii[i].destination;
		}
	}
	return max;
}
void generareAdiacenta(Muchie* muchii, int nrMuchii, boolean** matriceAdiacenta) {
	for (int i = 0; i < nrMuchii; ++i) {
		matriceAdiacenta[muchii[i].origin - 1][muchii[i].destination - 1] = 1;
		matriceAdiacenta[muchii[i].origin - 1][muchii[i].origin - 1] = 1;
		matriceAdiacenta[muchii[i].destination - 1][muchii[i].destination - 1] = 1;
	}
}
boolean ver_ex_muchie(Muchie* muchii, int nrMuchii, int origin, int destination) {
	for (int i = 0; i < nrMuchii; ++i) {
		if ((muchii[i].origin == origin && muchii[i].destination == destination) || (muchii[i].origin == destination && muchii[i].destination == origin)) {
			return true;
		}
	}
	return false;
}
Muchie* regenerareMuchii(boolean** matriceAdiacenta, int matrixSize, Muchie* muchiiRezultate, int nrMuchii) {
	muchiiRezultate = (Muchie*)calloc(nrMuchii, sizeof(Muchie));
	int index_muchii = 0;
	for (int i = 0; i < matrixSize; ++i) {
		for (int j = 0; j < matrixSize; ++j) {
			if (matriceAdiacenta[i][j] == 1 && i != j) {
				if (!ver_ex_muchie(muchiiRezultate, nrMuchii, i + 1, j + 1)) {
					muchiiRezultate[index_muchii].origin = i + 1;
					muchiiRezultate[index_muchii++].destination = j + 1;
				}
			}
		}
	}
	return muchiiRezultate;
}
int gradulNodului(boolean** matriceAdiacenta, int matrixSize, int nodIntrodus) {
	int grad = 0;
	for (int i = 0; i < matrixSize; ++i) {
		for (int j = 0; j < matrixSize; ++j) {
			if (i != j && matriceAdiacenta[i][j] == 1) {
				if (i + 1 == nodIntrodus) {
					++grad;
				}
			}
		}
	}
	return grad;
}
queue_int* parcurgereAdancime2(boolean** matriceAdiacenta, int marimeMatrice, int nodCurent, queue_int* resultQueue) {
	if (matriceAdiacenta == NULL || marimeMatrice < 1) {
		return NULL;
	}
	if (!isInQueue(resultQueue, nodCurent)) {
		enqueue_with_priority_int(resultQueue, nodCurent, 2);
	}
	for (int i = 0; i < marimeMatrice; ++i) {
		if (matriceAdiacenta[nodCurent - 1][i] == 1 && nodCurent - 1 != i && !isInQueue(resultQueue, i + 1)) {
			parcurgereAdancime2(matriceAdiacenta, marimeMatrice, i + 1, resultQueue);
		}
	}
	return resultQueue;
}
queue_int* parcurgereLatime2(boolean** matriceAdiacenta, int marimeMatrice, int nodCurent, queue_int* resultQueue) {
	if (matriceAdiacenta == NULL || marimeMatrice < 1) {
		return NULL;
	}
	queue_int* coada = initialise_queue(0);
	enqueue_with_priority_int(coada, nodCurent, 2);
	enqueue_with_priority_int(resultQueue, nodCurent, 2);
	while (coada->front != NULL) {
		nodCurent = dequeue_highest_priority_int(coada);
		for (int i = 0; i < marimeMatrice; ++i) {
			if (matriceAdiacenta[nodCurent - 1][i] == 1 && !isInQueue(resultQueue, i + 1) && nodCurent != i + 1) {
				enqueue_with_priority_int(coada, i + 1, 2);
				enqueue_with_priority_int(resultQueue, i + 1, 2);
			}
		}
	}
	return resultQueue;
}
boolean verificareConex(Muchie* muchii, int nrMuchii, queue_int* resultQueue) {
	for (int i = 0; i < nrMuchii; ++i) {
		if (!isInQueue(resultQueue, muchii[i].origin) || !isInQueue(resultQueue, muchii[i].destination)) {
			return false;
		}
	}
	return true;
}
int nrComponenteConexe(boolean** matriceAdiacenta, int marimeMatrice, Muchie* muchii, int nrMuchii, queue_int* rezultateParcurgere) {
	int nrComponente = 0;
	int current = 1;
	queue_int* noduriRamase = initialise_queue(0);

	//inserare in coada a tuturor nodurilor
	for (int i = 0; i < nrMuchii; ++i) {
		if (!isInQueue(noduriRamase, muchii[i].origin)) {
			enqueue_with_priority_int(noduriRamase, muchii[i].origin, 2);
		}
		if (!isInQueue(noduriRamase, muchii[i].destination)) {
			enqueue_with_priority_int(noduriRamase, muchii[i].destination, 2);
		}
	}

	do {
		current = dequeue_highest_priority_int(noduriRamase);
		reset_queue_int(rezultateParcurgere);
		rezultateParcurgere = initialise_queue(0);
		if (current < 1) { break; }
		rezultateParcurgere = parcurgereAdancime2(matriceAdiacenta, marimeMatrice, current, rezultateParcurgere);
		printf("\nComponenta: ");
		printQueue(rezultateParcurgere);
		++nrComponente;
		for (int i = 0; i < nrMuchii; ++i) {
			if (isInQueue(rezultateParcurgere, muchii[i].origin)) {
				removeFromQueue(noduriRamase, muchii[i].origin);
			}
			if (isInQueue(rezultateParcurgere, muchii[i].destination)) {
				removeFromQueue(noduriRamase, muchii[i].destination);
			}
		}
	} while (noduriRamase->front != NULL);

	//verificare noduri neconectate
	boolean neconectat = true;
	boolean prezent = false;
	for (int i = 0; i < marimeMatrice; ++i) {
		prezent = false;
		for (int j = 0; j < marimeMatrice; ++j) {
			if (i != j) {
				if (matriceAdiacenta[i][j] == 1 || matriceAdiacenta[j][i] == 1) {
					neconectat = false;
				}
			}
			else if (i == j && matriceAdiacenta[i][j] == 1) {
				prezent = true;
			}
		}
		if (neconectat && prezent) {
			++nrComponente;
			printf("\nComponenta: %d", i + 1);

		}
		neconectat = true;
	}

	return nrComponente;
}
Muchie* conectare(boolean** matriceAdiacenta, int marimeMatrice, Muchie* muchii, int& nrMuchii) {
	queue_int* rezultatParcurgere = initialise_queue(0);
	queue_int* reprezentanti = initialise_queue(0);
	queue_int* total = initialise_queue(0);
	bracket_int_queue* scout = NULL;
	bracket_int_queue* scout2 = NULL;
	int nodeToCheck = 1, totalSize = 0, nrOfAddedPaths = 0, i = 0;
	boolean connectionToNode = false;

	if (verificareConex(muchii, nrMuchii, rezultatParcurgere)) {
		return NULL; //graf-ul e conex deja
	}

	for (int i = 0; i < nrMuchii; ++i) {
		if (!isInQueue(total, muchii[i].origin)) {
			enqueue_with_priority_int(total, muchii[i].origin, 2);
		}
		if (!isInQueue(total, muchii[i].destination)) {
			enqueue_with_priority_int(total, muchii[i].destination, 2);
		}
	}
	totalSize = total->size;
	reset_queue_int(total);
	total = initialise_queue(0);

	while (total->size < totalSize) {
		do {
			rezultatParcurgere = parcurgereAdancime2(matriceAdiacenta, marimeMatrice, nodeToCheck, rezultatParcurgere);
			scout = rezultatParcurgere->front;
			while (scout != NULL) {
				if (!isInQueue(total, scout->content)) {
					for (int i = 0; i < marimeMatrice; ++i) {
						if (matriceAdiacenta[scout->content - 1][i] == 1) {
							enqueue_with_priority_int(total, scout->content, 2);
							break;
						}
					}
				}
				scout = scout->next;
			}
			++nodeToCheck;
		} while (rezultatParcurgere->front == NULL);
		if (!isInQueue(reprezentanti, nodeToCheck - 1)) {
			scout = reprezentanti->front;
			while (scout != NULL) {
				reset_queue_int(rezultatParcurgere);
				rezultatParcurgere = initialise_queue(0);
				rezultatParcurgere = parcurgereAdancime2(matriceAdiacenta, marimeMatrice, scout->content, rezultatParcurgere);
				scout2 = rezultatParcurgere->front;
				while (scout2 != NULL) {
					if (scout2->content == nodeToCheck - 1) {
						connectionToNode = true;
					}
					scout2 = scout2->next;
				}
				scout = scout->next;
			}
			if (!connectionToNode) {
				for (int i = 0; i < marimeMatrice; ++i) {
					if (matriceAdiacenta[nodeToCheck - 2][i] == 1) {
						enqueue_with_priority_int(reprezentanti, nodeToCheck - 1, 2);
						break;
					}
				}
			}
			connectionToNode = false;
		}
		reset_queue_int(rezultatParcurgere);
		rezultatParcurgere = initialise_queue(0);
	}

	scout2 = reprezentanti->front;
	nrOfAddedPaths = reprezentanti->size - 1;
	if (scout2 == NULL) {
		return NULL; //graph is empty
	}
	scout = scout2->next;
	if (scout == NULL) {
		return NULL; //graph is already fully connected
	}
	free(muchii);
	muchii = regenerareMuchii(matriceAdiacenta, marimeMatrice, muchii, nrMuchii + nrOfAddedPaths);
	i = nrMuchii;
	nrMuchii += nrOfAddedPaths;
	while (i < nrMuchii && scout != NULL) {
		muchii[i].origin = scout->content;
		muchii[i].destination = scout2->content;
		++i;
		scout = scout->next;
	}
	return muchii;
}
int determinareSubgraf(boolean** matriceAdiacenta, int marimeMatrice, Muchie* muchii, int& nrMuchii, queue_int* rezultateParcurgere) {
	reset_queue_int(rezultateParcurgere);
	rezultateParcurgere = initialise_queue(0);
	for (int i = 1; rezultateParcurgere->size == 0; ++i) {
		rezultateParcurgere = parcurgereAdancime2(matriceAdiacenta, marimeMatrice, i, rezultateParcurgere);
	}

	bracket_int_queue* scout = NULL;
	bracket_int_queue* previous1 = NULL;
	bracket_int_queue* previous2 = NULL;
	scout = rezultateParcurgere->front;
	if (scout == NULL) {
		return -1;
	}
	while (scout != NULL) {
		previous2 = previous1;
		previous1 = scout;
		scout = scout->next;
	}
	printf("\nSe sterge nodul %d.\n", previous2->content);
	int muchiiScoase = 0;
	for (int i = 0; i < marimeMatrice; ++i) {
		if (matriceAdiacenta[previous2->content - 1][i] == 1) {
			matriceAdiacenta[previous2->content - 1][i] = 0;
			matriceAdiacenta[i][previous2->content - 1] = 0;
			++muchiiScoase;
		}
	}
	nrMuchii -= muchiiScoase - 1;
	return 0;
}
boolean** generareMatriceDrumuri(boolean** matriceAdiacenta, int marimeMatrice) {
	boolean** matriceDrumuri = (boolean**)calloc(marimeMatrice, sizeof(boolean*));
	for (int i = 0; i < marimeMatrice; ++i) {
		matriceDrumuri[i] = (boolean*)calloc(marimeMatrice, sizeof(boolean));
	}
	for (int i = 0; i < marimeMatrice; ++i) {
		for (int j = 0; j < marimeMatrice; ++j) {
			if (i != j) {
				matriceDrumuri[i][j] = matriceAdiacenta[i][j];
			}
		}
	}

	for (int k = 0; k < marimeMatrice; ++k)
		for (int i = 0; i < marimeMatrice; ++i)
			for (int j = 0; j < marimeMatrice; ++j)
				if (i != j && matriceDrumuri[i][j] == 0 && matriceDrumuri[i][k] == 1 && matriceDrumuri[k][j] == 1)
					matriceDrumuri[i][j] = 1;
	return matriceDrumuri;
}
boolean verificareTareConexitate(boolean** matriceAdiacenta, boolean** matriceDrumuri, int marimeMatrice) {
	for (int i = 0; i < marimeMatrice; ++i) {
		for (int j = 0; j < marimeMatrice; ++j) {
			if (i != j) {
				if (matriceDrumuri[i][j] == 0) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	char keystroke = 0;
	Muchie* muchii = NULL;
	int origin = 0, destination = 0, nrMuchii = 0;
	int max = 0;
	boolean** matriceAdiacenta = NULL, **matriceDrumuri = NULL;
	Muchie* muchiiRezultate = NULL;
	int nodIntrodus = 0;
	int gradNodIntrodus = 0;
	queue_int* rezultateParcurgere = initialise_queue(0);
	int ret = 0;

	//citire de la tastatura
	printf("Introduceti muchiile formate din cate doua numere naturale separate de spatiu.\n"
		"Muchiile individuale se separa folosind Enter\n"
		"Cate muchii doriti sa introduceti?\n"
		"Muchii: ");
	keystroke = 0;
	while (keystroke != ENTER) {
		check_for_keystroke(keystroke);
		if (keystroke > 47 && keystroke < 58) {
			nrMuchii = keystroke - '0' + nrMuchii * 10;
			printf("%c", keystroke);
		}
	}
	printf("\n");
	muchii = (Muchie*)calloc(nrMuchii, sizeof(Muchie));
	for (int i = 0; i < nrMuchii; ++i) {
		printf("Introduceti muchia %d: ", i);
		keystroke = 0;
		while (keystroke != ENTER) {
			check_for_keystroke(keystroke);
			if (keystroke > 47 && keystroke < 58) {
				origin = keystroke - '0' + origin * 10;
				printf("%c", keystroke);
			}
		}
		printf(" ");
		keystroke = 0;
		while (keystroke != ENTER) {
			check_for_keystroke(keystroke);
			if (keystroke > 47 && keystroke < 58) {
				destination = keystroke - '0' + destination * 10;
				printf("%c", keystroke);
			}
		}
		printf("\n");
		muchii[i].origin = origin;
		muchii[i].destination = destination;
		origin = 0;
		destination = 0;
	}

	//generare matrice
	max = gasesteNodMaxim(muchii, nrMuchii);
	matriceAdiacenta = (boolean**)calloc(max, sizeof(boolean*));
	for (int i = 0; i < max; ++i) {
		matriceAdiacenta[i] = (boolean*)calloc(max, sizeof(boolean));
	}
	generareAdiacenta(muchii, nrMuchii, matriceAdiacenta);

	//printare matrice adiacenta
	printf("\nMatrice adiacenta:\n     ");
	for (int i = 0; i < max; ++i) {
		printf("%4d ", i + 1);
	}
	printf("\n");
	for (int i = 0; i < max; ++i) {
		printf("%4d ", i + 1);
		for (int j = 0; j < max; ++j) {
			printf("%4d ", matriceAdiacenta[i][j]);
		}
		printf("\n");
	}
	
	//generare matrice drumuri
	matriceDrumuri = generareMatriceDrumuri(matriceAdiacenta, max);

	//printare matrice drumuri
	printf("\nMatricea drumurilor:\n     ");
	for (int i = 0; i < max; ++i) {
		printf("%4d ", i + 1);
	}
	printf("\n");
	for (int i = 0; i < max; ++i) {
		printf("%4d ", i + 1);
		for (int j = 0; j < max; ++j) {
			printf("%4d ", matriceDrumuri[i][j]);
		}
		printf("\n");
	}

	//verificare tare conexitate
	if (verificareTareConexitate(matriceAdiacenta, matriceDrumuri, max)) {
		printf("\nGraful este tare conex!\n");
	}
	else {
		printf("\nGraful nu este tare conex!\n");
	}

	(void)getchar();
	return 0;
}