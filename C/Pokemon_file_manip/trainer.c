#include "trainer.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "trainers.bin"

// Initial array pointer and counters
FILE* trainerFile = NULL;
int trainerCount;

bool initializeTrainers() {

    trainerFile = fopen(FILE_NAME, "a+b");
    if(trainerFile != NULL){
        fseek(trainerFile, 0, SEEK_SET);
        trainerCount = ftell(trainerFile) / sizeof(trainer);
        return true;
    }
    return false;
}

bool finishTrainers() {

    if (trainerFile) {
        fclose(trainerFile);
        trainerFile = NULL;
        return true;
    }
    return false;
}

int trainerAmount() {

    long fileSize;
    fseek(trainerFile, 0, SEEK_END);
    fileSize = ftell(trainerFile);
    trainerCount = fileSize / sizeof(trainer);

    return trainerCount;
}

trainer *getTrainerByIndex(int index) {

  trainer* tempTrainer = (trainer*) malloc(sizeof(trainer));

  fseek(trainerFile, index * sizeof(trainer), SEEK_SET);

  int result = fread(tempTrainer, sizeof(trainer), 1, trainerFile);
  //se eu colocasse um arquivo aleat�rio no lugar, desde que
  //ele tivesse um tamanho similar, retornaria 1?

  if (result != 1) {
    free(tempTrainer);
    return NULL;
  }
  return tempTrainer;
}

bool codeVerifier(int code) {

    trainer tempTrainer;
    fseek(trainerFile, 0, SEEK_SET);

    int i;
    for(i = 0; i < trainerCount; i++){
        if(fread(&tempTrainer, i * sizeof(trainer), 1, trainerFile) == 1){
            if(tempTrainer.trainerCode == code){
                return true;
            }
        }
    }
//    while (fread(&tempTrainer, sizeof(trainer), 1, file) == 1) {
//        if (tempTrainer.trainerCode == code) {
//        return true;
//        }
//    }
    return false;
}

bool createTrainer(trainer* t) {
    bool result;

    fseek(trainerFile, 0, SEEK_END);
    result = fwrite(t, sizeof(trainer), 1, trainerFile);
    trainerCount++;
    return result;
}

bool updateTrainer(trainer* newTrainerData) {

  trainer tempTrainer;
  fseek(trainerFile, 0, SEEK_SET);

  while (fread(&tempTrainer, sizeof(trainer), 1, trainerFile) == 1) {
    if (tempTrainer.trainerCode == newTrainerData->trainerCode) {
      fseek(trainerFile, -sizeof(trainer), SEEK_CUR);
      return fwrite(newTrainerData, sizeof(trainer), 1, trainerFile) == 1;
    }
  }
  return false;
}

bool deleteTrainer(int code) {

    FILE* tempFile = fopen("temp.bin", "wb");

    trainer tempTrainer;
    bool found = false;
    fseek(trainerFile, 0, SEEK_SET);

    while (fread(&tempTrainer, sizeof(trainer), 1, trainerFile) == 1) {
        if (tempTrainer.trainerCode != code) {
            fwrite(&tempTrainer, sizeof(trainer), 1, tempFile);
        } else if (tempTrainer.trainerCode == code) {
            found = true;
        }
    }

    fclose(tempFile);
    if (found) {
        trainerCount--;
        remove(FILE_NAME);
        rename("temp.bin", FILE_NAME);
        trainerFile = fopen(FILE_NAME, "a+b");
    } else {
        remove("temp.bin");
    }
    return found;
}
