#include "trainer.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"
//#include "gym.h"
//#include "battle.h"

void subMenuTrainers()
{
	
	int internalMenuCode = 1;
	while (internalMenuCode != 0) {
		printf("Trainer menu: \n0. Exit \n1. List trainers \n2. Register a new "
		"trainer by their code \n3. Update a trainer by their code \n4. "
		"Delete trainer by their code \n");
		scanf("%d", &internalMenuCode);
		switch (internalMenuCode) {
			case 1: {
				printf("Code ----- Name ----- bAtk ----- bDef\n");
				int i;
				for (i = 0; i < trainerAmount(); i++) {
					trainer* tempPointer = getTrainerByIndex(i);
					printf("%d ----- %s ----- %d ----- %d\n", tempPointer->trainerCode, tempPointer->name,
					tempPointer->bonusAtk, tempPointer->bonusDef);
				}
				break;
			}
	
			case 2: {
				printf("Type the info of the trainer you want to register, in this "
					"order: code, name, bAttack, and bDefense\n");
				trainer *tempTrainer = (trainer*) malloc(sizeof(trainer));
				scanf("%d %s %d %d", &tempTrainer->trainerCode, tempTrainer->name, &tempTrainer->bonusAtk,
					&tempTrainer->bonusDef);
				if (codeVerifier(tempTrainer->trainerCode)) {
					printf("Code already exists.\n");
				} else {
					if(createTrainer(tempTrainer)){
						printf("Trainer successfully registered.\n");
					} else printf("There was a problem registering. Try again later.\n");
				}
				free(tempTrainer);
				break;
			}
	
			case 3: {
				int trainerTestCode;
				trainer *tempTrainer = (trainer*) malloc(sizeof(trainer));
				printf("Type the code of the trainer you want to update\n");
				scanf("%d", &trainerTestCode);
				if (codeVerifier(trainerTestCode)) {
					printf("Type the info you want to update, in this "
					"order: code, name, bonus attack, bonus defense\n");
					
					scanf("%d %s %d %d", &tempTrainer->trainerCode, tempTrainer->name, &tempTrainer->bonusAtk, &tempTrainer->bonusDef);
					if(updateTrainer(tempTrainer)){
						printf("Trainer updated successfully.");
					} else printf("Problem updating the trainer.");
				} else {
					printf("Invalid trainer code.");
				}
				free(tempTrainer);
				break;
			}
			case 4: {
				printf("Type the code of the trainer you want to delete\n");
				int code;
				scanf("%d", &code);
				if (codeVerifier(code)) {
					deleteTrainer(code);
					printf("Trainer deleted successfully.");
				} else {
					printf("Invalid trainer code.");
				}
				break;
			}
		}
	}
}

void subMenuPokemons()
{
	int internalMenuCode = -1;
      while (internalMenuCode != 0) {
        printf("Pokemon menu: \n0. Exit \n1. List pokemon \n2. Register pokemon by trainer code \n3. Search pokemon by name \n4. Delete pokemon by code \n");
        scanf("%d", &internalMenuCode);
        switch (internalMenuCode) {
        case 1: {
            printf("Code --- Name --- HP --- Atk --- Def --- TrainerCode\n");
            int i;
            for(i = 0; i < pokemonAmount(); i++){
                pokemon* tempPokemon = getPokemonByIndex(i);
                printf("%d --- %s --- %d --- %d --- %d --- %d\n", tempPokemon->pokeCode, tempPokemon->name, tempPokemon->life, tempPokemon->atk, tempPokemon->def, tempPokemon->trainerCode);
            }
            break;
        }

        case 2: {
          int pokemonTestCode;
          pokemon *tempPokemon = (pokemon*) malloc(sizeof(pokemon));
          printf("Type the code of the pokemon you want to add.\n");
          scanf("%d", &pokemonTestCode);
          if (!pokeCodeVerifier(pokemonTestCode)) {
            tempPokemon->pokeCode = pokemonTestCode;
            printf("The code is valid. Now, type the info of the pokemon you want to register, in this order: Name, HP, Attack, Defense, and Trainer Code \n");
            scanf("%s %d %d %d %d", tempPokemon->name, &tempPokemon->life, &tempPokemon->atk, &tempPokemon->def, &tempPokemon->trainerCode);
            if(createPokemon(tempPokemon)){
                printf("Pokemon successfully created!\n");
            } else {
                printf("There was a problem when creating this pokemon. Try again later.");
            }
          } else {
              printf("This pokemon code already exists.\n");
          }
          free(tempPokemon);
          break;
        }

        case 3: {
          char pokeTestName[20];
          pokemon *tempPokemon = (pokemon*) malloc(sizeof(pokemon));
          printf("Type the name of the pokemon you want to search:\n");
          scanf("%s", pokeTestName);
          if(pokemonNameVerifier(pokeTestName) != -1){
            tempPokemon = getPokemonByIndex(pokemonNameVerifier(pokeTestName));
            printf("Pokemon found!\n");
            printf("Name --- HP --- Atk --- Def --- TrainerCode\n");
            printf("%s --- %d --- %d --- %d --- %d\n", tempPokemon->name, tempPokemon->life, tempPokemon->atk, tempPokemon->def, tempPokemon->trainerCode);
          } else {
            printf("Pokemon name not found in out database.\n");
          }
          free(tempPokemon);
          break;
        }


        case 4: {
        	int pokemonTestCode;
          	printf("Type the code of the pokemon you want to delete.\n");
          	scanf("%d", &pokemonTestCode);
          	if (!pokeCodeVerifier(pokemonTestCode)) {
				printf("This code is not related to any pokemon.");  
			} else {
				deletePokemon(pokemonTestCode);
			}
			break;
		}
    }		
}
}

void subMenuGyms()
{
	int internalMenuCode = -1;
	while (internalMenuCode != 0) {
        printf("Gym menu:\n0. Exit\n1. List gyms\n2. Register gym by code\n3. "
               "Search gym by neighborhood\n4. Delete gym by code\n");
        scanf("%d", &internalMenuCode);
      }	
}

void subMenuBattles()
{
	int internalMenuCode = -1;
	while (internalMenuCode != 0) {
        printf("Battle menu:\n0. Exit\n1. List trainer battles\n2. List gym battles\n3. Battle\n4. Search for a trainer's victories and defeats\n");
        scanf("%d", &internalMenuCode);
		}
}

int main() {
  int i;

  initializeTrainers();
  initializePokemons();

  int menuCode = -1;
  while (menuCode != 0) {
    printf("Main menu: \n0. Exit \n1. Trainer \n2. Pokemon \n3. Gym \n4.Battle \n");
    scanf("%d", &menuCode);
    switch (menuCode) {
    case 1:
      	subMenuTrainers();
      break;

    case 2:
    	subMenuPokemons();
      break;

    case 3:
    	subMenuGyms();
      break;

    case 4:
    	subMenuBattles();
	}
  }
   finishTrainers();
   finishPokemons();
  // chama a finalizacao dos arrays das entidades
  return 0;
}
