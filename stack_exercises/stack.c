#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* stackArrayPointer = NULL;
int* intStackPointer = NULL;

int create_stack(int size){
    stackArrayPointer = (Stack*) malloc(1 * sizeof(Stack));
    intStackPointer = (int) malloc(size * sizeof(int));
    stackArrayPointer.vector = intStackPointer;

    if(stackArrayPointer){
      return 1;
    }else{
        return 0;
    }
}

void push(Stack* stack, int item){

}

int pop(Stack* stack){

}
