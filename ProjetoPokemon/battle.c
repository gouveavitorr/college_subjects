#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "battle.h"

battle *battleArrayPointer = NULL;
int battleCount = 0;
int battleArraySize = 5;

bool initializeBattles(){
    battleArrayPointer = (battle*) malloc(battleArraySize * sizeof(battle));

    if(battleArrayPointer != NULL) {
        battle b1 = {1, 1, {1, 2}, {11,12}, 12};
        battle b2 = {2, 2, {2, 3}, {13, 14}, 14};

        battleArrayPointer[0] = b1;
        battleArrayPointer[1] = b2;

        battleCount = 2;
        return true;
    }
    return false;
}

bool finishBattles(){
    if(battleArrayPointer != NULL){
        free(battleArrayPointer);
        battleArrayPointer = NULL;
        battleCount = 0;
        battleArraySize = 5;
        return true;
    }
    return false;
}

int battleAmount(){
    return battleCount;
}

battle* getBattleByIndex(int index){
    if (index >= 0 && index < battleCount) {
        battle* tempBattle = (battle*) malloc(sizeof(battle));
        if (tempBattle) {
            *tempBattle = battleArrayPointer[index];
            return tempBattle;
        }
    }
    return NULL;
}

int registerBattle(battle* b){
    if (battleCount == battleArraySize) {
        battleArraySize *= 2;
        battle* newArray = (battle*) realloc(battleArrayPointer, battleArraySize * sizeof(battle));
        if (newArray == NULL) {
            return false;
        }
        battleArrayPointer = newArray;
    }

    battleArrayPointer[battleCount] = *b;
    battleCount++;
    return true;
}

int* listTrainerVictDefeats(int code) {
    int* victDefeats = malloc(2 * sizeof(int));
    victDefeats[0] = 0;
    victDefeats[1] = 0;
    for (int i = 0; i < battleCount; i++) {
        if (battleArrayPointer[i].winnerCode == code) {
            victDefeats[0]++;
        }
        if (battleArrayPointer[i].winnerCode != code &&
            (battleArrayPointer[i].trainerCodes[0] == code ||
             battleArrayPointer[i].trainerCodes[1] == code)) {
            victDefeats[1]++;
        }
    }
    return victDefeats;
}



