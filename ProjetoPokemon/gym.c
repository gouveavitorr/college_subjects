#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "gym.h"

gym* gymArrayPointer = NULL;
int gymCount = 0;
int gymArraySize = 5;

bool initializeGyms(){
    gymArrayPointer = (gym*) malloc(gymArraySize * sizeof(gym));

    if(gymArrayPointer != NULL) {
        gym g1 = {1, "FireGym", 30, "Lavaridge"};
        gym g2 = {2, "WaterGym", 30, "Violet"};
        gym g3 = {3, "FairyGym", 30, "Azalea"};
        gym g4 = {4, "DragonGym", 30, "Goldenrod"};

        gymArrayPointer[0] = g1;
        gymArrayPointer[1] = g2;
        gymArrayPointer[2] = g3;
        gymArrayPointer[3] = g4;

        gymCount = 4;
        return true;
    }
    return false;
}

bool finishGyms(){
    if(gymArrayPointer != NULL){
        free(gymArrayPointer);
        gymArrayPointer = NULL;
        gymCount = 0;
        gymArraySize = 5;
        return true;
    }
    return false;
}

int gymAmount(){
    return gymCount;
}

bool gymCodeVerifier(int code){
    int i;
    for(i = 0; i < gymCount; i++){
        if(gymArrayPointer[i].gymCode == code){
            return true;
        }
    }
    return false;
}

int gymNbhoodVerifier(char nbhood[]){
    int i;
    char namePlaceholder[20];
    for(i = 0; i < gymCount; i++){
        strcpy(namePlaceholder, gymArrayPointer[i].neighborhood);
        if(!strcmp(strlwr(namePlaceholder), strlwr(nbhood))){
            return i;
        }
    }
    return -1;
}

gym* getGymByIndex(int index){
    if(index >= 0 && index < gymCount){
        gym* tempGym = (gym*) malloc(sizeof(gym));
        if(tempGym){
            *tempGym = gymArrayPointer[index];
            return tempGym;
        }
    }
    return NULL;
}

bool createGym(gym* g){
    if(gymCount == gymArraySize){
        gymArraySize *= 2;
        gym* newArray = (gym*) realloc(gymArrayPointer, gymArraySize * sizeof(gym));
        if(newArray == NULL){
            return false;
        }
        gymArrayPointer = newArray;
    }

    gymArrayPointer[gymCount] = *g;
    gymCount++;
    return true;
}

bool deleteGym(int code){
    int i;
    for (i = 0; i < gymCount; i++) {
        if (gymArrayPointer[i].gymCode == code) {
            int j;
            for (j = i; j < gymCount; j++) {
                gymArrayPointer[j] = gymArrayPointer[j + 1];
            }
            gymCount--;
            break;
        }
    }

    if (gymCount < gymArraySize / 2 && gymArraySize > 6) {
        gymArraySize /= 2;
        gym* newArray = (gym*) realloc(gymArrayPointer, gymArraySize * sizeof(gym));
        if (newArray != NULL) {
            gymArrayPointer = newArray;
        }
    }

    return true;
}


