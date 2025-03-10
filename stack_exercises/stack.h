#define MAX_SIZE 50;

struct stack {
    int size;
    int* vector;
};

typedef struct stack Stack;

int create_stack(int size);
void push(Stack* stack, int item);
int pop(Stack* stack);
