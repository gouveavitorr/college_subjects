#include "trainer.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "trainers.bin"

// Initial array pointer and counters
FILE* file = NULL;

bool initializeTrainers() {
    file = fopen(FILE_NAME, "a+b");
    return file != NULL;
}

bool finishTrainers() {
    if (file) {
        fclose(file);
        file = NULL;
        return true;
    }
    return false;
}

int trainerAmount() {
    if (!file) return 0;
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);

    return fileSize / sizeof(trainer);
}

trainer *getTrainerByIndex(int index) {
  if (!file) return NULL;

  trainer* tempTrainer = (trainer*) malloc(sizeof(trainer));
  if (!tempTrainer) return NULL;

  fseek(file, index * sizeof(trainer), SEEK_SET);
  if (fread(tempTrainer, sizeof(trainer), 1, file) != 1) {
    free(tempTrainer);
    return NULL;
  }
  return tempTrainer;
}

bool codeVerifier(int code) {
    if (!file) return false;
    trainer tempTrainer;
    rewind(file);
    while (fread(&tempTrainer, sizeof(trainer), 1, file) == 1) {
        if (tempTrainer.trainerCode == code) {
        return true;
        }
    }
    return false;
}

bool createTrainer(trainer* t) {
  if (!file) return false;
  return fwrite(t, sizeof(trainer), 1, file) == 1;
}

bool updateTrainer(trainer* newTrainerData) {
  if (!file) return false;
  trainer tempTrainer;
  rewind(file);
  while (fread(&tempTrainer, sizeof(trainer), 1, file) == 1) {
    if (tempTrainer.trainerCode == newTrainerData->trainerCode) {
      fseek(file, -sizeof(trainer), SEEK_CUR);
      return fwrite(newTrainerData, sizeof(trainer), 1, file) == 1;
    }
  }
  return false;
}

bool deleteTrainer(int code) {
    if (!file) return false;
    FILE* tempFile = fopen("temp.bin", "wb");

    if (!tempFile) return false;
    trainer tempTrainer;
    bool found = false;
    rewind(file);

    while (fread(&tempTrainer, sizeof(trainer), 1, file) == 1) {
        if (tempTrainer.trainerCode != code) {
            fwrite(&tempTrainer, sizeof(trainer), 1, tempFile);
        } else {
            found = true;
        }
    }

    fclose(tempFile);
    if (found) {
        remove(FILE_NAME);
        rename("temp.bin", FILE_NAME);
        file = fopen(FILE_NAME, "a+b");
    } else {
        remove("temp.bin");
    }
    return found;
}
