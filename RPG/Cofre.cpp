#include "Cofre.h"
#include <random>

char Cofre::spawnRandomObject() {

	char item;
	int i = rand() % 20;

	consoleControl.LockMutex();

	consoleControl.SetPosition(x, y);
	if (i < 15) {
		item = 'M';
		std::cout << 'M';
	}
	else if(i >=15 && i <19){
		item = 'P';
		std::cout << 'P';
	}
	else {
		item = 'A';
		std::cout << 'A';
	}
	consoleControl.UnlockMutex();

	return item;
}
