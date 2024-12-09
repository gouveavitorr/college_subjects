#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pokemon.h"

#define FILE_NAME "pokemons.bin"

FILE* file = NULL;

bool initializePokemons() {
    file = fopen(FILE_NAME, "a+b");
    return file != NULL;
}

bool finishPokemons() {
    if (file) {
        fclose(file);
        file = NULL;
        return true;
    }
    return false;
}

int pokemonAmount() {
    if (!file) return 0;
    fseek(file, 0, SEEK_END);
    return ftell(file) / sizeof(pokemon);
}

bool pokeCodeVerifier(int code) {
    if (!file) return false;
    pokemon tempPokemon;
    rewind(file);
    while (fread(&tempPokemon, sizeof(pokemon), 1, file) == 1) {
        if (tempPokemon.pokeCode == code) {
            return true;
        }
    }
    return false;
}

int pokemonNameVerifier(char pokeName[]) {
    if (!file) return -1;
    pokemon tempPokemon;
    char namePlaceholder[20];
    rewind(file);
    while (fread(&tempPokemon, sizeof(pokemon), 1, file) == 1) {
        strcpy(namePlaceholder, tempPokemon.name);
        if (!strcmp(strlwr(namePlaceholder), strlwr(pokeName))) {
            return ftell(file) / sizeof(pokemon) - 1;
        }
    }
    return -1;
}

pokemon* getPokemonByIndex(int index) {
    if (!file) return NULL;
    pokemon* tempPokemon = (pokemon*) malloc(sizeof(pokemon));
    if (!tempPokemon) return NULL;
    fseek(file, index * sizeof(pokemon), SEEK_SET);
    if (fread(tempPokemon, sizeof(pokemon), 1, file) != 1) {
        free(tempPokemon);
        return NULL;
    }
    return tempPokemon;
}

bool createPokemon(pokemon* p) {
    if (!file) return false;
    fseek(file, 0, SEEK_END);
    return fwrite(p, sizeof(pokemon), 1, file) == 1;
}

bool deletePokemon(int code) {
    if (!file) return false;
    FILE* tempFile = fopen("temp.bin", "wb");
    if (!tempFile) return false;
    pokemon tempPokemon;
    bool found = false;
    rewind(file);
    while (fread(&tempPokemon, sizeof(pokemon), 1, file) == 1) {
        if (tempPokemon.pokeCode != code) {
            fwrite(&tempPokemon, sizeof(pokemon), 1, tempFile);
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
