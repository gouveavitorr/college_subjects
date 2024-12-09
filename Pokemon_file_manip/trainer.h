#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Trainer trainer;

struct Trainer {
	int trainerCode;
	char name[20];
	int bonusAtk;
	int bonusDef;	
};

int trainerAmount();
trainer* getTrainerByIndex(int index);
bool codeVerifier(int code);

bool createTrainer(trainer* t);
bool updateTrainer(trainer* newTrainerData);
bool deleteTrainer(int code);

bool initializeTrainers();
bool finishTrainers();

