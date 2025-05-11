#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* create_stack(int size){
    Stack* stackArrayPointer = (Stack*)malloc(sizeof(Stack));
    stackArrayPointer->top = 0;
    stackArrayPointer->size = size;
    stackArrayPointer->vector = (int*) malloc(size * sizeof(int));

    return stackArrayPointer;
}

bool push(Stack* stack, int value){
    if(full(stack)){
        return false;
    }else{
        stack->top++;
        stack->vector[stack->top] = value;
        return true;
    }
}

bool pop(Stack* stack, int* value){
    if(empty(stack)){
        return false;
    }else{
        *value = stack->vector[stack->top];
        stack->top--;
        return true;
    }
}

bool empty(Stack* stack){
    if(stack->top == 0){
        return true;
    }return false;

}

bool full(Stack* stack){
    if(stack->top == (stack->size)){
        return true;
    }return false;
}
