#include "queue.h"

Queue* createQueue(int size){
	Queue* pointer = (Queue*)malloc(sizeof(Queue));
	pointer->beginning = 0;
	pointer->size = size;
	pointer->quantity = 0;
	pointer->vector = (int*)malloc(sizeof(int));
	
	return pointer;
}

bool push(Queue* q, int item);
bool shift(Queue* q, int item);

bool empty(Queue* q);
bool full(Queue* q);
