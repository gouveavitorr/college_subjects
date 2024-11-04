#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "battle.h"

trainer *battleArrayPointer = NULL;
int battleCount = 0;
int arraySize = 5;


int battleAmount();
pokemon* getBattleByIndex(int index);

bool createBattle(trainer t);
bool updateBattle(int index, trainer newTrainerData);
bool deleteBattle(int index);

bool initializeBattles();
bool finishBattles();
