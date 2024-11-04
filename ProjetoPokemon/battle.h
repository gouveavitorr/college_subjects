struct Battle {
	int gymCode
	int firstPokeCode
	int secondPokeCode
	int winnerCode
	int battleCount
};

typedef struct Battle battle;

int battleAmount();
pokemon* getBattleByIndex(int index);

bool createBattle(trainer t);
bool updateBattle(int index, trainer newTrainerData);
bool deleteBattle(int index);

bool initializeBattles();
bool finishBattles();

//battle* listTrainerBattles();
//battle* listGymBattles();
//int battle();
//int listTrainerVictDefeats(); 
