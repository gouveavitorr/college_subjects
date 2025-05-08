Goes through the array from left to right, picks an element, and then goes from right to left, to check where to insert the current element.

#Code
```
void InsertionSort(int* input, int length){

    int i, j, currentElement;

    for(i=1;i<length;i++){

        currentElement = input[i]; 

        j = i - 1; 

        while((j>=0) && (currentElement < input[j])){ 

            input[j+1] = input[j]; 

            j--;
        }
        input[j+1] = currentElement; 

    }
}
```

Input example: [500,300,100,400,700,200,600]
i progression: [1,2,3,4,5,6]
j progression: [0,-1,1,0,-1,2,1,0,-1,3,2,1,0,-1,4,3,2,1,0,-1,5,4,3,2,1,0,-1,6,5,4,3,2,1,0,-1]
currentElement progression: [300,100,400,700,200,600]

Line 11: i always goes to the left, and the space behind it gets bigger (j continually has a bigger space to run)
Line 13: j starts as one less than i and goes down
Line 15: we run towards the left and we check if currentElement is smaller than anything to its left
Line 17: it assigns the item to the right with the value of the one to the left
Line 19: always goes towards zero to end this ever-growing loop
Line 21: if the j loop is over or currentElement is bigger than input[j], we assign input[j+1] to the value inside currentElement
Line 22 (before ending i loop): in the first iteration, j is -1, so we assign 300 to input[0]

Observations:
- Shortsighted: creates a new array to the left, which has to be rechecked every time we pick a new element.
- We change the original array as we run this algorithm. There are no parallel/extra/temporary arrays being created.
- Using this specific input, this algorithm take 35 j iterations to sort the array
