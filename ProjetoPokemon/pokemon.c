#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

trainer *pokemonArrayPointer = NULL;
int pokemonCount = 0;
int arraySize = 5;


int pokemonAmount();
pokemon* getPokemonByIndex(int index);

bool createPokemon(trainer t);
bool updatePokemon(int index, trainer newTrainerData);
bool deletePokemon(int index);

bool initializePokemons();
bool finishPokemons();

