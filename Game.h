/****************************************
				game.h
****************************************/
#ifndef GAME_H_
#define GAME_H_
#include "Character.h"

class Game{

	private:
		Floor floor[4];
		Character *character[2];
		int n;

	public:
		Game();
		~Game();
		void read();
		void play();	
};



#endif