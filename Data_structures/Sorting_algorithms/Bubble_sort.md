Basically, the heaviest bubbles go down.

#Code
```
void BubbleSort(int* input, int size){
    
    int i, j, aux;

    for(i = size - 1; i >= 1; i--){

        for(j = 0; j < i; j++){

            if(input[j] > input[j + 1]){

                aux = input[j];
                input[j] = input[j + 1];
                input[j + 1] = aux;
            }
        }
    }
}

```

Input example: [500,300,100,400,700,200,600]

