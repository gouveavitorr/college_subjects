#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Gym {
    int gymCode;
	char name[30];
	int capacity;
	char neighborhood[30];
};

typedef struct Gym gym;

int gymAmount();
bool gymCodeVerifier(int code);
int gymNbhoodVerifier(char nbhood[]);

gym* getGymByIndex(int index);

bool createGym(gym* g);
bool deleteGym(int code);

bool initializeGyms();
bool finishGyms();
