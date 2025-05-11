#include "queue.h"

Queue* createQueue(int size){
    Queue* q = (Queue*) malloc(sizeof(queue));
    q->item = (int*) malloc(size * sizeof(int));
    q->start = 0;
    q->quantity = 0;
    q->size = size;

    return q;
}

bool push(Queue* queue, int item){
    if(full()){
       return false;
    } else {
        int position = (queue->start + queue->quantity) % queue->size;
        queue[position] = item;
        queue->quantity++;
        return true;
    }
}

bool shift(Queue* queue){
    if(empty()){
        return false;
    } else {
        queue->start = (queue->start + 1) % queue->size;
        queue->quantity--;
        return true;
    }
}

bool empty(Queue* queue){
    return queue->quantity == 0;
}

bool full(Queue* queue){
    return queue->size == queue->quantity;
}
