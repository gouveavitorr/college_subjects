struct list {
    int data;
    struct list* next;
}

typedef struct list List;

//new implementation strategy
List* insert(List* L, int value){
    List* currentList = L;
    List* previousKnot = NULL;

    while(currentList != NULL && current->data < value){
        previousKnot = currentList;
        currentList = currentList->next;
    }
    
    List* knot = (List*) malloc (sizeof(List));
    knot->data = value;
    knot->next = current;
    if(previousKnot == NULL){
        return previousKnot;
    }
    else {
        previousKnot->next = knot;
        return knot;
    }
}

int main(){
    List myList = NULL;
    myList = insert(myList, 5);
    myList = insert(myList, 8);
}