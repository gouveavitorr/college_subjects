#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gym.h"

trainer *gymArrayPointer = NULL;
int gymCount = 0;
int arraySize = 5;

int gymAmount();
pokemon* getGymByIndex(int index);

bool createGym(trainer t);
bool updateGym(int index, trainer newTrainerData);
bool deleteGym(int index);

bool initializeGyms();
bool finishGyms();
