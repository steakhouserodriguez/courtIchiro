#include "Point.h"

Point::Point() {
	current = NULL;
	playersSpawned = false;
}

Point::~Point(){
	delete current;
}

void Point::playStep(){

	//TODO consider a switch statement here

	// Spawn players if not spawned yet
	if (!playersSpawned){
		spawnPlayers();
	} else if (!this->isEnded()){ //Normal mode, play game

		Round* toPlay = getCurrentRound();
		toPlay->playStep();

	} else { // 1 player left:

		// Point::isEnded() = true, 
		// this point will be deconstructed by the GM
	}


}

Round* Point::getCurrentRound(){

	if(current->isEnded()){
		delete current;
		current = new Round();
	}

	return current;
}

void Point::spawnPlayers(){

	//called once playerSpawn is complete
	playersSpawned = true;

}

bool Point::isEnded(){
	return !(physics->numAlivePlayers() > 1); 
}