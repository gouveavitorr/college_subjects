#define MAX_SIZE 50;
#include <stdbool.h>

struct stack {
    int size;
    int top;
    int* vector;
};

typedef struct stack Stack;

Stack* create_stack(int size);
bool push(Stack* stack, int value);
bool pop(Stack* stack, int* value);
bool empty(Stack* stack);
bool full(Stack* stack);
