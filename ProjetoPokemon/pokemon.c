#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pokemon.h"

pokemon *pokemonArrayPointer = NULL;
int pokemonCount = 0;
int pokemonArraySize = 6;

bool initializePokemons() {
    pokemonArrayPointer = (pokemon*) malloc(pokemonArraySize * sizeof(pokemon));

    if (pokemonArrayPointer != NULL) {
        pokemon p0 = {"Chikorita", 109, 12, 12, 11};
        pokemon p1 = {"Togepi", 81, 8, 8, 14};
        pokemon p2 = {"Totodyle", 91, 15, 11, 11};
        pokemon p3 = {"Treecko", 110, 9, 9, 13};
        pokemon p4 = {"Chingling", 78, 9, 12, 13};

        pokemonArrayPointer[0] = p0;
        pokemonArrayPointer[1] = p1;
        pokemonArrayPointer[2] = p2;
        pokemonArrayPointer[3] = p3;
        pokemonArrayPointer[4] = p4;

        pokemonCount = 5;
        return true;
    }
    return false;
}

bool finishPokemons() {
    if (pokemonArrayPointer != NULL) {
        free(pokemonArrayPointer);
        pokemonArrayPointer = NULL;
        pokemonCount = 0;
        pokemonArraySize = 6;
        return true;
    }
    return false;
}

int pokemonAmount() {
    return pokemonCount;
}

int pokemonNameVerifier(char pokeName[]){
    int i;
    char namePlaceholder[20]; //fiz isso por conta do strlwr
    for(i = 0; i < pokemonCount; i++){
        strcpy(namePlaceholder, pokemonArrayPointer[i].name);
        if(!strcmp(strlwr(namePlaceholder), strlwr(pokeName))){
            return i;
        }
    }
    return -1;
}

pokemon* getPokemonByIndex(int index) {
    if (index >= 0 && index < pokemonCount) {
        pokemon* tempPokemon = (pokemon*) malloc(sizeof(pokemon));
        if (tempPokemon) {
            *tempPokemon = pokemonArrayPointer[index];
            return tempPokemon;
        }
    }
    return NULL;
}

bool createPokemon(pokemon* p) {
    if (pokemonCount == pokemonArraySize) {
        pokemonArraySize *= 2;
        pokemon* newArray = (pokemon*) realloc(pokemonArrayPointer, pokemonArraySize * sizeof(pokemon));
        if (newArray == NULL) {
            return false;
        }
        pokemonArrayPointer = newArray;
    }

    pokemonArrayPointer[pokemonCount] = *p;
    pokemonCount++;
    return true;
}

bool deletePokemon(int code) {
    int i;
    for (i = 0; i < pokemonCount - 1; i++) {
        if (pokemonArrayPointer[i].trainerCode == code) {
            int j;
            for (j = i; j < pokemonCount - 1; j++) {
                pokemonArrayPointer[j] = pokemonArrayPointer[j + 1];
            }
            pokemonCount--;
            break;
        }
    }

    if (pokemonCount < pokemonArraySize / 2 && pokemonArraySize > 6) {
        pokemonArraySize /= 2;
        pokemon* newArray = (pokemon*) realloc(pokemonArrayPointer, pokemonArraySize * sizeof(pokemon));
        if (newArray != NULL) {
            pokemonArrayPointer = newArray;
        }
    }

    return true;
}
