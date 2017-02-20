/***********************************************************************
				MAIN FILE
************************************************************************
** Incluing files: FloorA.txt, FloorB.txt, FloorC.txt
		   game.h, character.h, floor.h

** Author: Jiongcheng Luo
** Date: 3/14/2015
** Assignment: Final project
** Description: More about Maze game base on assignment #4
** Input: directions, step number
** Output: current motion in the map
***********************************************************************/


#include "Game.h"

using namespace std;

int main(){    

Game game;
	system("clear");
	cout << "\n---------------------------------- Game Guideline ----------------------------------\n";
	cout << "\n1) 'W,S,A,D' keys for directions, you can put one step number (no more than '5')";
	cout << "\n after direction keys, default step# is '1';\n";
	cout << "\n2) Ghost moves before you, if you are within her one step (and you have no cherry)";
	cout << "\n you will be sent back to start location;\n";
	cout << "\n3) If the Ghost detects you are within her '5' steps distance, she will move forward";
	cout << "\n to you, her every move is '1' step;\n";	
	cout << "\n------------------------------------------------------------------------------------\n";

	game.play();

	cout << "\nCongradulations!!! YOU WIN!!!\n" << endl;
	
return 0;
}
