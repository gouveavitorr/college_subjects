Goes through the array from left to right, picks an element, and then goes from right to left, to check where to insert the current element.

#Code
```
void InsertionSort(int* input, int length){
    int i, j, currentElement;
    for(i=1;i<length;i++){
        currentElement = input[i];
        j = i -1;
        while((j>=0) && (currentElement < input[j])){
            input[j+1] = input[j];
            j = j - 1;
        }
        input[j+1] = currentElement;
    }
}
```
