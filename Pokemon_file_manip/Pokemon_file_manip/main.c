#include "trainer.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"
#include "gym.h"
#include "battle.h"

void subMenuTrainers()
{

	int internalMenuCode = 1;
	while (internalMenuCode != 0) {
		printf("\nTrainer menu: \n0. Exit \n1. List trainers \n2. Register a new "
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
						printf("Trainer updated successfully.\n");
					} else printf("Problem updating the trainer.\n");
				} else {
					printf("Invalid trainer code.\n");
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
					printf("Trainer deleted successfully.\n");
				} else {
					printf("Invalid trainer code.\n");
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
        printf("\nPokemon menu: \n0. Exit \n1. List pokemon \n2. Register pokemon by trainer code \n3. Search pokemon by name \n4. Delete pokemon by code \n");
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
                printf("There was a problem when creating this pokemon. Try again later.\n");
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
            printf("Code --- Name --- HP --- Atk --- Def --- TrainerCode\n");
            printf("%d --- %s --- %d --- %d --- %d --- %d\n", tempPokemon->pokeCode, tempPokemon->name, tempPokemon->life, tempPokemon->atk, tempPokemon->def, tempPokemon->trainerCode);
          } else {
            printf("This pokemon has not been found.\n");
          }
          free(tempPokemon);
          break;
        }


        case 4: {
        	int pokemonTestCode;
          	printf("Type the code of the pokemon you want to delete.\n");
          	scanf("%d", &pokemonTestCode);
          	if (!pokeCodeVerifier(pokemonTestCode)) {
				printf("This code is not related to any pokemon.\n");
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
        printf("\nGym menu:\n0. Exit\n1. List gyms\n2. Register gym by code\n3. "
               "Search gym by neighborhood\n4. Delete gym by code\n");
        scanf("%d", &internalMenuCode);
        switch(internalMenuCode){

            case 1: {
                printf("Code --- Name --- Capacity --- Neighborhood\n");
                int i;
                for(i = 0; i < gymAmount(); i++){
                    gym* tempGym = getGymByIndex(i);
                    printf("%d --- %s --- %d --- %s\n", tempGym->gymCode, tempGym->name, tempGym->capacity, tempGym->neighborhood);
                }
                break;
            }
            case 2: {
                int gymTestCode;
                gym* tempGym = (gym*) malloc(sizeof(gym));
                printf("Type the code of the gym you want to add.\n");
                scanf("%d", &gymTestCode);
                if(!gymCodeVerifier(gymTestCode)){
                    tempGym->gymCode = gymTestCode;
                    printf("The code is valid. Now, type the info of the gym you want to register in this order: Name, Capacity, and Neighborhood\n");
                    scanf("%s %d %s", tempGym->name, &tempGym->capacity, tempGym->neighborhood);
                    if(createGym(tempGym)){
                        printf("Gym successfully created!\n");
                    } else {
                        printf("There was a problem when creating this gym. Try again later.\n");
                    }
                } else {
                    printf("This gym code already exists.\n");
                }
                free(tempGym);
                break;
            }
            case 3: {
                char gymTestName[20];
                gym* tempGym = (gym*) malloc(sizeof(gym));
                printf("Type the neighborhood of the gym you want to search:\n");
                scanf("%s", gymTestName);
                if(gymNbhoodVerifier(gymTestName) != -1){
                    tempGym = getGymByIndex(gymNbhoodVerifier(gymTestName));
                    printf("Gym found!\n");
                    printf("Code --- Name --- Capacity --- Neighborhood\n");
                    printf("%d --- %s --- %d --- %s", tempGym->gymCode, tempGym->name, tempGym->capacity, tempGym->neighborhood);
                } else {
                    printf("This gym has not been found.\n");
                }
                free(tempGym);
                break;
            }
            case 4: {
                int gymTestCode;
                printf("Type the code of the gym you want to delete:\n");
                scanf("%d", &gymTestCode);
                if(!gymCodeVerifier(gymTestCode)){
                    printf("This code is not related to any gym from our database.\n");
                } else {
                    deleteGym(gymTestCode);
                }
                break;
            }
        }
      }
}

void subMenuBattles()
{
	int internalMenuCode = -1;
	while (internalMenuCode != 0) {
        printf("\nBattle menu:\n0. Exit\n1. List trainer battles\n2. List gym battles\n3. Battle\n4. Search for a trainer's victories and defeats\n");
        scanf("%d", &internalMenuCode);
        switch(internalMenuCode){
            case 1: {
                printf("Code ----- Name ----- bAtk ----- bDef\n");
				int i;
				for (i = 0; i < trainerAmount(); i++) {
					trainer* tempPointer = getTrainerByIndex(i);
					printf("%d ----- %s ----- %d ----- %d\n", tempPointer->trainerCode, tempPointer->name,
					tempPointer->bonusAtk, tempPointer->bonusDef);
				}
                printf("Choose between one of these trainers by their code.\n");
                int chosenTrainerCode;
                scanf("%d", &chosenTrainerCode);
                int j;
                for(j = 0; j < battleAmount(); j++){
                    battle* tempBattle = getBattleByIndex(j);
                    if(tempBattle->trainerCodes[0] == chosenTrainerCode || tempBattle->trainerCodes[1] == chosenTrainerCode){
                        printf("\nBattle code: %d\n"
                               "Gym code: %d\n"
                               "Fist poke code: %d\n"
                               "Second poke code: %d\n"
                               "First trainer code: %d\n"
                               "Second trainer code: %d\n"
                               "Winner code: %d\n", tempBattle->battleCode, tempBattle->gymCode, tempBattle->pokeCodes[0], tempBattle->pokeCodes[1], tempBattle->trainerCodes[0], tempBattle->trainerCodes[1], tempBattle->winnerCode);
                    }
                }
                break;
            }
            case 2: {
                printf("Code --- Name --- Capacity --- Neighborhood\n");
                int i;
                for(i = 0; i < gymAmount(); i++){
                    gym* tempGym = getGymByIndex(i);
                    printf("%d --- %s --- %d --- %s\n", tempGym->gymCode, tempGym->name, tempGym->capacity, tempGym->neighborhood);
                }
                printf("Choose between one of these gyms by their code.\n");
                int chosenGymCode;
                scanf("%d", &chosenGymCode);
                int j;
                for(j = 0; j < battleAmount(); j++){
                    battle* tempBattle = getBattleByIndex(j);
                    if(tempBattle->gymCode == chosenGymCode){
                        printf("\nBattle code: %d\n"
                               "Gym code: %d\n"
                               "Fist poke code: %d\n"
                               "Second poke code: %d\n"
                               "First trainer code: %d\n"
                               "Second trainer code: %d\n"
                               "Winner code: %d\n", tempBattle->battleCode, tempBattle->gymCode, tempBattle->pokeCodes[0], tempBattle->pokeCodes[1], tempBattle->trainerCodes[0], tempBattle->trainerCodes[1], tempBattle->winnerCode);
                    }
                }
                break;
            }
            case 3: {
                //battle a pokemon
                pokemon* tempPokemon = (pokemon*) malloc(sizeof(pokemon));
                trainer* tempTrainer = (trainer*) malloc(sizeof(trainer));
                gym* tempGym = (gym*) malloc(sizeof(gym));
                int i,j,k,l,chosenGymCode;
                printf("First, choose the code of the gym where the battle will take place.\n");
                printf("Code --- Name --- Capacity --- Neighborhood\n");
                for(l = 0; l < gymAmount(); l++){
                    tempGym = getGymByIndex(l);
                    printf("%d --- %s --- %d --- %s\n", tempGym->gymCode, tempGym->name, tempGym->capacity, tempGym->neighborhood);
                }
                scanf("%d", &chosenGymCode);
                printf("Now choose the pokemons.\n\nCode --- Name --- HP --- Atk --- Def --- TrainerCode\n");
                for(i = 0; i < pokemonAmount(); i++){
                    tempPokemon = getPokemonByIndex(i);
                    printf("%d --- %s --- %d --- %d --- %d --- %d\n", tempPokemon->pokeCode, tempPokemon->name, tempPokemon->life, tempPokemon->atk, tempPokemon->def, tempPokemon->trainerCode);
                }
                int chosenPokeCodes[2];
                int chosenTrainerCodes[2];
                int chosenPokemonStats[4]; //p1Atk, p1Def, p2Atk, p2Def
                printf("Choose the first pokemon by their code:\n");
                scanf("%d", &chosenPokeCodes[0]);
                printf("Now choose the second:\n");
                scanf("%d", &chosenPokeCodes[1]);
                for(j = 0; j < pokemonAmount(); j++){
                    tempPokemon = getPokemonByIndex(j);
                    if(tempPokemon->pokeCode == chosenPokeCodes[0]){
                        chosenPokemonStats[0] = tempPokemon->atk;
                        chosenPokemonStats[1] = tempPokemon->def;
                        chosenTrainerCodes[0] = tempPokemon->trainerCode;
                    }
                    if(tempPokemon->pokeCode == chosenPokeCodes[1]){
                        chosenPokemonStats[2] = tempPokemon->atk;
                        chosenPokemonStats[3] = tempPokemon->def;
                        chosenTrainerCodes[1] = tempPokemon->trainerCode;
                    }
                }
                for(k = 0; k < trainerAmount(); k++) {
                    tempTrainer = getTrainerByIndex(k);
                    if(tempTrainer->trainerCode == chosenTrainerCodes[0]){
                        chosenPokemonStats[0] += tempTrainer->bonusAtk;
                        chosenPokemonStats[1] += tempTrainer->bonusDef;
                    }
                    if(tempTrainer->trainerCode == chosenTrainerCodes[1]){
                        chosenPokemonStats[2] += tempTrainer->bonusAtk;
                        chosenPokemonStats[3] += tempTrainer->bonusDef;
                    }
                }
                printf("Let's begin the battle!\n\n");
                int winnerCode;
                int damageToP1 = chosenPokemonStats[2] - chosenPokemonStats[1];
                int damageToP2 = chosenPokemonStats[0] - chosenPokemonStats[3];
                damageToP1 += rand() % 10;
                damageToP2 += rand() % 10;

                if (damageToP1 <= 0 && damageToP2 <= 0) {
                    printf("It's a draw! Both Pokémon are too evenly matched.\n");
                    winnerCode = -1;
                } else if (damageToP1 > damageToP2) {
                    winnerCode = chosenTrainerCodes[1];
                    printf("The second Pokémon's trainer (code: %d) wins the battle!\n", winnerCode);
                } else {
                    winnerCode = chosenTrainerCodes[0];
                    printf("The first Pokémon's trainer (code: %d) wins the battle!\n", winnerCode);
                }
                battle* newBattle = (battle*) malloc(sizeof(battle));
                newBattle->battleCode = battleAmount() + 1;
                newBattle->gymCode = chosenGymCode;
                newBattle->pokeCodes[0] = chosenPokeCodes[0];
                newBattle->pokeCodes[1] = chosenPokeCodes[1];
                newBattle->trainerCodes[0] = chosenTrainerCodes[0];
                newBattle->trainerCodes[1] = chosenTrainerCodes[1];
                newBattle->winnerCode = winnerCode;
                registerBattle(newBattle);

                free(tempTrainer);
                free(tempGym);
                free(tempPokemon);
                free(newBattle);
                break;
            }
            case 4: {
                printf("Code ----- Name ----- bAtk ----- bDef\n");
				int i;
				for (i = 0; i < trainerAmount(); i++) {
					trainer* tempPointer = getTrainerByIndex(i);
					printf("%d ----- %s ----- %d ----- %d\n", tempPointer->trainerCode, tempPointer->name,
					tempPointer->bonusAtk, tempPointer->bonusDef);
				}
                printf("Choose between one of these trainers by their code.\n");
                int chosenTrainerCode;
                scanf("%d", &chosenTrainerCode);
                int* victDefeats = listTrainerVictDefeats(chosenTrainerCode);
                printf("Victories: %d\n Defeats: %d\n", victDefeats[0], victDefeats[1]);
                break;
            }
        }
		}
}

int main() {
  int i;

  initializeTrainers();
  initializePokemons();
  initializeGyms();
  initializeBattles();

  int menuCode = -1;
  while (menuCode != 0) {
    printf("\nMain menu: \n0. Exit \n1. Trainer \n2. Pokemon \n3. Gym \n4.Battle \n");
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
   finishGyms();
   finishBattles();
  return 0;
}
