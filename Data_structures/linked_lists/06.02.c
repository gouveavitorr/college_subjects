struct list {
    int data;
    struct list* next;
}

typedef struct list List;

List* insert(List* L, int value){
    List* knot = (List*) malloc (sizeof(List));
    knot->data = value;
    knot->next = L;
    return knot;
}

List* find(List* L, int value){
    List* currentList = L;
    List* previousKnot = NULL;

    while(currentList != NULL && current->data < value){
        previousKnot = currentList;
        currentList = currentList->next;
    }
    return previousKnot;
}

int main(){
    List myList = NULL;
    myList = insert(myList, 5);
    myList = insert(myList, 8);
}