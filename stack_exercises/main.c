#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Stack* myStack = Create(3);
    int total, i;

    for(i=1; i< 5; i++){
        if(push(myStack, i)){
            printf("\n Inseri %d", i);
        } else {
            printf("Falha na insercao %d", i);
        }
    }

    return 0;
}
