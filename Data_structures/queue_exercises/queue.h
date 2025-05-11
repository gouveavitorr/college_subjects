#include "stdlib.h"
#include <stdio.h>
#include <stdlib.h>

struct queue {
    int* item;
    int quantity;
    int start;
    int size;
}

typedef struct queue Queue;

Queue* createQueue(int size);
bool push(Queue* queue, int item);
bool shift(Queue* queue);
bool empty(Queue* queue);
bool full(Queue* queue);
