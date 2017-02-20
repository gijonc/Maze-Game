/****************************************
				character.h
****************************************/
#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Floor.h"

using namespace std;

class Character{

	public:
		Character(){};
		~Character(){};

		virtual void move(Floor&)=0;
		virtual int get_floor()=0;
};


class Ghost : public Character{
	public:
		int get_floor(){return 0;}
		void move(Floor&);
};


class Player : public Character{
	public:
		Player(int key, int HP, int F);
		void move(Floor&);
		void Pmove_to(int, int, Floor&);
		int get_floor(){return floorNum;}	//return current floor number

	private:
		char floor_choice;
		char symbol;
		int HP;
		int keyNum;
		int floorNum;
		
};

#endif

