Divide and conquer sorting. The strategy is to create a pivot point, and recursively break the array in halves until the last level, which has the pivot with only one (or none) element to each side.

#Code

```
void QuickSort(int* input, int left, int right){
    if(left < right){
        int q = slice(input, left, right);
        QuickSort(input, left, q - 1);
        QuickSort(input, q + 1, right);
    }
}

int slice(int* input, int left, int right){
    int pivotPoint = left;
    int i, j, aux;

    for(i = (left + 1); i <= right; i++){
        if(input[i] < input[pivotPoint]){
            aux = input[i];

            for(j = i - 1; j >= pivotPoint; j--){
                input[j + 1] = input[j];
            }

            input[pivotPoint] = aux;
            pivotPoint++;
        }
    }
    return pivotPoint;
}
```