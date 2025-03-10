#include <stdbool.h>

struct queue {
	int size;
	int quantity;
	int beginning;
	int* vector;
};

typedef struct queue Queue;

Queue* createQueue(int size);

bool push(Queue* q, int item);
bool shift(Queue* q, int item);

bool empty(Queue* q);
bool full(Queue* q);
