
struct Trainer {
	int trainerCode
	char name[20]
	int bonusAtk
	int bonusDef	
};

typedef struct Trainer trainer;

int trainerAmount();
trainer* getTrainerByIndex(int index);

bool createTrainer(trainer t);
bool updateTrainer(int code, trainer newTrainerData);
bool deleteTrainer(int code);

bool initializeTrainers();
bool finishTrainers();

