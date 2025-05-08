Runs through the array searching for the lowest value, and puts this value into the leftmost position of the array.

#Code
```
void SelecionSort(int* input, int tam){

    int i, j, min, aux;

    for(i = 0; i < (tam - 1); i++){

        min = i;

        for(j = (i + 1); j < tam; j++){
            if(input[j] < input[min])
                min = j;
        }

        if(i != min){
            aux = input[i];
            input[i] = input[min];
            input[min] = aux;
        }
    }
}

```

Input example: [500,300,100,400,700,200,600]