struct list {
    int data;
    struct list* previous;
    struct list* next;
}

typedef struct list List;

List* insert(List* L, int value){
    List* newKnot = (List*) malloc(sizeof(List));
    newKnot->data = value;
    newKnot->next = L;
    newKnot->previous = NULL;
    if(L != NULL) L->previous = newKnot;

    return newKnot;
}

List* findPrevious(List* L, int value){
    List* current = L;
    if(current == NULL) return NULL;
    while(current->next != NULL && current->next->data < value){
        current = current->next;
    }
    if(current->data > value) return current->previous;
    return current;
}

int main(){
    List myList = NULL;
}