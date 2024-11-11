#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Pokemon pokemon;

struct Pokemon {
	char name[20];
	int life;
	int atk;
	int def;
	int trainerCode;
};

bool initializePokemons();
bool finishPokemons();

int pokemonAmount();
int pokemonNameVerifier(char pokeName[]);
pokemon* getPokemonByIndex(int index);


bool createPokemon(pokemon* p);
bool deletePokemon(int code);



