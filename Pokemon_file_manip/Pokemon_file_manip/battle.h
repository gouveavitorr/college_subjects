#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Battle {
    int battleCode;
	int gymCode;
	int pokeCodes[2];
	int trainerCodes[2];
	int winnerCode;
};

typedef struct Battle battle;

bool initializeBattles();
bool finishBattles();

int battleAmount();
battle* getBattleByIndex(int index);

int registerBattle(battle* b);
int* listTrainerVictDefeats(int code);
