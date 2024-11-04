struct Pokemon {
	char name[20]
	int life
	int atk
	int def
	int trainerCode
};

typedef struct Pokemon pokemon;

int pokemonAmount();
pokemon* getPokemonByIndex(int index);

bool createPokemon(trainer t);
bool updatePokemon(int index, trainer newTrainerData);
bool deletePokemon(int index);

bool initializePokemons();
bool finishPokemons();

