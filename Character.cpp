#include "Character.h"

#include <string>
#include <sstream>
#include <ctime>

Player::Player(int key, int HP, int F){

	this->keyNum = key;
	this->HP = HP;
	this->floorNum = F;
}


void Player::Pmove_to(int inputX, int inputY, Floor &map){

	symbol = map.check_map(inputX, inputY);

	switch(symbol){
		case '#':	// tile: no move
			map.set_player(0,0, false);
			break;

		case 'K':	// get a key
			if(keyNum<3)
				keyNum++;
			map.set_player(inputX,inputY, true);
			if(HP>0)
			HP--;
			break;

		case 'C':	// get a cherry
			HP=20;
			map.set_player(inputX,inputY, true);	
			break;

		case 'D':	// open a door
			if(keyNum>0){
				keyNum--;
				map.set_player(inputX,inputY, true);
				if(HP>0)
				HP--;
			}
			else
				map.set_player(0,0, false);
			break;

		case 'G':
			if(HP>0){	// met the ghost
				map.set_player(inputX,inputY, true);
				HP--;
				if(map.ex_ghost() == false)
					HP=0;
			}
			else
				map.set_player(inputX,inputY, false);
			break;

		case 'X':
			floorNum = 0;
			break;

		case 'A':	// next level: A
			if(floorNum == 1){
				cout << "\nGoing Up?[y/n]: ";
				cin >> floor_choice;
				if(floor_choice == 'y')
					floorNum = 2;
			}else if(floorNum == 2){
				cout << "\nGoing Down?[y/n]: ";
				cin >> floor_choice;
				if(floor_choice == 'y')
					floorNum = 1;
			}
			
			break;

		case 'B':	// next level: B
			if(floorNum == 2){
				cout << "\nGoing Up?[y/n]: ";
				cin >> floor_choice;
				if(floor_choice == 'y')
					floorNum = 3;
			}
			
			else if(floorNum == 3){
				cout << "\nGoing Down?[y/n]: ";
				cin >> floor_choice;
				if(floor_choice == 'y')
					floorNum = 2;
			}
			break;

		default:
			map.set_player(inputX,inputY, true);
			if(HP>0)
				HP--;
			break;
		}
}



void Player::move(Floor &P_floor){
	
	//set the area that is visible by player
	P_floor.set_playerarea();		
	P_floor.print();

	cout << "\n---------- LEVEL." << floorNum << " -----------";
	cout << "\n  KEY#: " << keyNum << "           Cherry: " << HP;
	cout << "\n\nAction(Steps<5): ";

	string input;
	char action;
	int stepNum;	

	getline(cin,input);
	stringstream ss;
	ss << input;
	ss >> action >> stepNum;

	if(!(stepNum > 1 && stepNum < 6 ))
	{
		switch (action){
			case 'w':
	            Pmove_to(-1, 0, P_floor);
	        break;

	        case 'a':
	            Pmove_to(0, -1, P_floor);
	        break;

	        case 's':
	            Pmove_to(1, 0, P_floor);
	        break;

	        case 'd':
	            Pmove_to(0, 1, P_floor);
	        break;

	        case 'q':
	            exit (EXIT_SUCCESS);
	        break;
		}
	}

	if(stepNum > 1 && stepNum < 6)
	{
		for(int i=0; i<stepNum; i++ )
		{
			switch (action){
				case 'w':
					Pmove_to(-1, 0, P_floor);			
				break;

			    case 'a':
			        Pmove_to(0, -1, P_floor);				
				break;

				case 's':
					Pmove_to(1, 0, P_floor);
				break;

				case 'd':
					Pmove_to(0, 1, P_floor);	
				break;

				case 'q':
	            	exit (EXIT_SUCCESS);
	           	break;
			}
		}
	}
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void Ghost::move(Floor &G_floor){

	//check if the ghost is exist
	if(G_floor.ex_ghost()==0){
		cout << "\n     The ghost is dead!!!\n" << endl;
		return;
	}

	else
	srand ((unsigned int)time(NULL));
		int rand_dir = rand() % 4;
		int rand_step = rand()% 5 + 1;	
		int X_d = G_floor.return_X();
		int Y_d = G_floor.return_Y();

	if( G_floor.near_player() == true ){
		cout << "\n     She is watching you!!!\n" << endl;

		if(X_d > 0)			// go up
			G_floor.set_ghost(-1,0);

		else if(X_d < 0)	// go down
			G_floor.set_ghost(1,0);
	

		if(X_d == 0)
		{
			if(Y_d > 0)		// go left
				G_floor.set_ghost(0,-1);

			else if(Y_d < 0)	// go right
				G_floor.set_ghost(0,1);
		}
	}

	else{
		cout << "\n                           \n" << endl;

		for(int i=0; i<rand_step; i++){
			switch (rand_dir){ 
				case 0:
			      G_floor.set_ghost(0,1);
					break;

				case 1:
					G_floor.set_ghost(-1,0);
					break;

				case 2:
			       G_floor.set_ghost(0,-1);
					break;

				case 3:
				    G_floor.set_ghost(1,0);
					break;

				case 4:
					G_floor.set_ghost(-1,0);
					break;

			 	default:
				    G_floor.set_ghost(-1,0);
					break;    
			}
		}	
	}
}