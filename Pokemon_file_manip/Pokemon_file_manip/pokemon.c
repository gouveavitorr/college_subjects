#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pokemon.h"

#define FILE_NAME "pokemons.bin"

FILE* pokemonFile = NULL;

bool initializePokemons() {
    pokemonFile = fopen(FILE_NAME, "a+b");
    return pokemonFile != NULL;
}

bool finishPokemons() {
    if (pokemonFile) {
        fclose(pokemonFile);
        pokemonFile = NULL;
        return true;
    }
    return false;
}

int pokemonAmount() {

    long fileSize;

    if (!pokemonFile) return 0;
    fseek(pokemonFile, 0, SEEK_END);

    fileSize = ftell(pokemonFile);
    return fileSize / sizeof(pokemon);
}

bool pokeCodeVerifier(int code) {

    pokemon tempPokemon;
    fseek(pokemonFile, 0, SEEK_SET);

    while (fread(&tempPokemon, sizeof(pokemon), 1, pokemonFile) == 1) {
        if (tempPokemon.pokeCode == code) {
            return true;
        }
    }
    return false;
}

int pokemonNameVerifier(char pokeName[]) {

    pokemon tempPokemon;
    char namePlaceholder[20];
    fseek(pokemonFile, 0, SEEK_SET);

    while (fread(&tempPokemon, sizeof(pokemon), 1, pokemonFile) == 1) {
        strcpy(namePlaceholder, tempPokemon.name);
        if (!strcmp(strlwr(namePlaceholder), strlwr(pokeName))) {
            return ftell(pokemonFile) / sizeof(pokemon) - 1;
        }
    }
    return -1;
}

pokemon* getPokemonByIndex(int index) {

    pokemon* tempPokemon = (pokemon*) malloc(sizeof(pokemon));

    fseek(pokemonFile, index * sizeof(pokemon), SEEK_SET);
    if (fread(tempPokemon, sizeof(pokemon), 1, pokemonFile) != 1) {
        free(tempPokemon);
        return NULL;
    }
    return tempPokemon;
}

bool createPokemon(pokemon* p) {

    fseek(pokemonFile, 0, SEEK_END);
    return fwrite(p, sizeof(pokemon), 1, pokemonFile) == 1;
}

bool deletePokemon(int code) {

    FILE* tempFile = fopen("temp.bin", "wb");

    pokemon tempPokemon;
    bool found = false;
    fseek(pokemonFile, 0, SEEK_SET);

    while (fread(&tempPokemon, sizeof(pokemon), 1, pokemonFile) == 1) {
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
        pokemonFile = fopen(FILE_NAME, "a+b");
    } else {
        remove("temp.bin");
    }
    return found;
}
