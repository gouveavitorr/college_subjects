#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trainer.h"

// Initial array pointer and counters
trainer *trainerArrayPointer = NULL;
int trainerCount = 0;
int arraySize = 5;

bool initializeTrainers() {
    trainerArrayPointer = (trainer*) malloc(arraySize * sizeof(trainer));
    
    //populate the array for better tests
    
    return trainerArrayPointer != NULL;
}

bool finishTrainers() {
    if (trainerArrayPointer != NULL) {
        free(trainerArrayPointer);
        trainerArrayPointer = NULL;
        trainerCount = 0;
        arraySize = 5;
        return true;
    }
    return false;
}

int trainerAmount() {
    return trainerCount;
}

trainer* getTrainerByIndex(int index) {
    if (index >= 0 && index < trainerCount) {
        trainer *tempTrainer = (trainer*) malloc(sizeof(trainer));
        if (tempTrainer) {
            *tempTrainer = trainerArrayPointer[index];
            return tempTrainer;
        }
    }
    return NULL;
}

bool createTrainer(trainer t) {
    if (trainerCount == arraySize) {
        arraySize *= 2;
        trainer *newArray = (trainer*) realloc(trainerArrayPointer, arraySize * sizeof(trainer));
        if (newArray == NULL) return false;
        trainerArrayPointer = newArray;
    }
    
    trainerArrayPointer[trainerCount] = t;
    //isn't this putting the trainer on the last spot, cause the index starts with 0?
    trainerCount++;
    return true;
}

bool updateTrainer(int index, trainer newTrainerData) {
    if (index >= 0 && index < trainerCount) {
        trainerArrayPointer[index] = newTrainerData;
        return true;
    }
    return false;
}

bool deleteTrainer(int index) {
    if (index >= 0 && index < trainerCount) {
        for (int i = index; i < trainerCount - 1; i++) {
            trainerArrayPointer[i] = trainerArrayPointer[i + 1];
        }
        trainerCount--;
        
        if (trainerCount < arraySize / 2 && arraySize > 5) {
            arraySize /= 2;
            trainer *newArray = (trainer*) realloc(trainerArrayPointer, arraySize * sizeof(trainer));
            if (newArray != NULL) {
                trainerArrayPointer = newArray;
            }
        }
        return true;
    }
    return false;
}
