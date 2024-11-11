#include "trainer.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initial array pointer and counters
trainer *trainerArrayPointer = NULL;
int trainerCount = 0;
int trainerArraySize = 5;

bool initializeTrainers() {
  trainerArrayPointer = (trainer*) malloc(trainerArraySize * sizeof(trainer));

  if(trainerArrayPointer != NULL){

    trainer t0 = {11, "Ash", 10, 12};
    trainer t1 = {12, "Brock", 8, 8};
    trainer t2 = {13, "Misty", 9, 15};
    trainer t3 = {14, "Mili", 15, 9};

    trainerArrayPointer[0] = t0;
    trainerArrayPointer[1] = t1;
    trainerArrayPointer[2] = t2;
    trainerArrayPointer[3] = t3;

    trainerCount = 4;

    return true;

  } else return false;
}

bool finishTrainers() {
  if (trainerArrayPointer != NULL) {
    free(trainerArrayPointer);
    trainerArrayPointer = NULL;
    trainerCount = 0;
    trainerArraySize = 5;
    return true;
  }
  return false;
}

int trainerAmount() { return trainerCount; }

trainer *getTrainerByIndex(int index) {
  if (index >= 0 && index <= trainerCount) {
    trainer* tempTrainer = (trainer*) malloc(sizeof(trainer));
    if (tempTrainer) {
      *tempTrainer = trainerArrayPointer[index];
      return tempTrainer;
    }
  }
  return false;
}

bool codeVerifier(int code) {
  int i;
  for (i = 0; i < trainerCount; i++) {
    if (code == trainerArrayPointer[i].trainerCode) {
      return true;
    }
  }
  return false;
}

bool createTrainer(trainer* t) {
  if (trainerCount == trainerArraySize) {
    trainerArraySize *= 2;
    trainer* newArray = (trainer*) realloc(trainerArrayPointer, trainerArraySize * sizeof(trainer));
    if (newArray == NULL){
        return false;
    } else trainerArrayPointer = newArray;
  }

  trainerArrayPointer[trainerCount] = *t;
  trainerCount++;
  return true;
}

bool updateTrainer(trainer* newTrainerData) {
  int i;
  for (i = 0; i < trainerCount; i++) {
    if (newTrainerData->trainerCode == trainerArrayPointer[i].trainerCode) {
      trainerArrayPointer[i] = *newTrainerData;
      return true;
    }
  }
  return false;
}

bool deleteTrainer(int code) {
     int i;
  for (i = 0; i < trainerCount - 1; i++) {

    if (trainerArrayPointer[i].trainerCode == code) {
       int j;
      for (j = i; j < trainerCount - 1; j++) {
        trainerArrayPointer[j] = trainerArrayPointer[j + 1];
      }
      trainerCount--;
    }
  }

  if (trainerCount < trainerArraySize / 2 && trainerArraySize > 5) {
    trainerArraySize /= 2;
    trainer *newArray = (trainer*) realloc(trainerArrayPointer, trainerArraySize * sizeof(trainer));
    if (newArray != NULL) {
      trainerArrayPointer = newArray;
    }
  }
}
