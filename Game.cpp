#include "Game.h"

Game::Game(){
	character[0] = new Player(0,0,1);	//initialize key, HP and current floor number
	character[1] = new Ghost;
}

Game::~Game(){}

void Game::read(){

	floor[1].read_maps("Maps/FloorA.txt");
	floor[2].read_maps("Maps/FloorB.txt");
	floor[3].read_maps("Maps/FloorC.txt");
	floor[1].ini_location(1);
	floor[2].ini_location(2);
	floor[3].ini_location(3);	
}


void Game::play(){

	read();
	do{
		n = character[0]->get_floor();
		character[1]->move(floor[n]);
		character[0]->move(floor[n]);
		system("clear");
		
	}while(character[0]->get_floor()!=0);
}