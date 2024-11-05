#include <stdio.h>
#include <stdlib.h>
#include "treinador.h"
#include "pokemon.h"
#include "gym.h"
#include "battle.h"


int main(int argc, char *argv[]) {
	int i;
	
	initializeTrainer();
	
	int menuCode, internalMenuCode;
	while (menuCode != 0){
		printf("Main menu: /n0. Exit \n1. Trainer \n2. Pokemon \n3. Gym \n4. Battle \n");
		scanf("%d", &menuCode);
		switch(menuCode){
			case 1:
				while(internalMenuCode != 0){
					printf("Trainer menu: /n0. Exit \n1. List trainers \n2. Register a new trainer by their code \n3. Update a trainer by their code \n4. Delete trainer by their code \n");
					scanf("%d", &internalMenuCode);
					switch(internalMenuCode){
						case 1:
							for(i = 0; i < trainerAmount() - 1; i++){
								trainer *tempPointer = getTrainerByIndex(i);
								printf("%s \n%d \n%d \n", tempPointer->name, tempPointer->bonusAtk, tempPointer->bonusDef);
							}
							break;
						
						case 2:
							printf("Type the info of the trainer you want to register, in this order: name, bonus attack, bonus defense, and the code");
							trainer *tempTrainer;
							scanf("%s %d %d %d", &tempTrainer->name, &tempTrainer->bonusAtk, &tempTrainer->bonusDef, &tempTrainer->trainerCode);
							createTrainer(tempTrainer);
							break;
						
						case 3:
							printf("Type the code of the trainer you want to update\n");
							scanf("%d", );
							trainer *tempTrainer;
							scanf("%s %d %d", &tempTrainer->name, &tempTrainer->bonusAtk, &tempTrainer->bonusDef);
							createTrainer(tempTrainer);
							break;
						
						case 4:
							//code
							break;
					}
				}
				break;
			
			case 2:
				while(internalMenuCode != 0){
					printf("Pokemon menu: /n0. Exit \n1. List pokemon \n2. Register pokemon by name \n3. Search pokemon by name \n4. Delete pokemon by code \n");
					scanf("%d", &internalMenuCode);
					switch(internalMenuCode){ 
						case 1:
							//code
							break;
						
						case 2:
							//code
							break;
						
						case 3:
							//code
							break;
						
						case 4:
							//code
							break;
					}
				}
				break;
			
			case 3:
				while(internalMenuCode != 0){
					printf("Gym menu:\n0. Exit\n1. List gyms\n2. Register gym by code\n3. Search gym by neighborhood\n4. Delete gym by code\n");
					scanf("%d", &internalMenuCode);
					switch(internalMenuCode){
						case 1:
							//code
							break;
						
						case 2:
							//code
							break;
						
						case 3:
							//code
							break;
						
						case 4:
							//code
							break;
					}
				}
				break;
			
			case 4:
				while(internalMenuCode != 0){
					printf("Battle menu:\n0. Exit\n1. List trainer battles\n2. List gym battles\n3. Battle\n4. Search for a trainer's victories and defeats\n");
					scanf("%d", &internalMenuCode);
					switch(internalMenuCode){
						case 1:
							//code
							break;
						
						case 2:
							//code
							break;
						
						case 3:
							//code
							break;
						
						case 4:
							//code
							break;
					}
				}
				break;
		}
		
	}
	
	
	
	
	//chama a finalização dos arrays das entidades
	return 0;
}
