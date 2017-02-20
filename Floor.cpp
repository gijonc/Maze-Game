#include "Floor.h"

Floor::Floor(){}

Floor::~Floor(){}

void Floor::read_maps(const char *txtfile){
	
	inputfile.open(txtfile);

	for(int row = 0; row < ROW; row++){
		for(int col = 0; col < COL; col++){   
			inputfile >> noskipws >> tile[row][col];
		}   
	}

	inputfile.close();
}

void Floor::print(){

	for(int row=0; row<ROW; row++){
		for(int col=0; col<COL; col++){
			cout << darkmap[row][col];
		}
	cout << endl;
	}
}

void Floor::set_darkmap(bool set){
	if(set){
		for(int row=0; row<ROW; row++){
			for(int col=0; col<COL; col++){
				darkmap[row][col] = '/';
			}
		}
	}
}

void Floor::set_playerarea(){

	x_u=pX-5;
	if(pX<5)
		x_u=0;

	x_d=pX+6;
	if(pX>15)
		x_d=ROW;

	y_l=pY-5;
	if(pY<5)
		y_l=0;

	y_r=pY+6;
	if(pY>25)
		y_r=COL;

	for(int i=x_u; i<x_d; i++){
		for(int j=(y_l); j<(y_r); j++){			
			darkmap[i][j]=tile[i][j];	
		}
	}
	
	for(int row=0; row<ROW; row++){
		for(int col=0; col<COL; col++){
			if(darkmap[row][col] != '/')
				darkmap[row][col] = tile[row][col];
		}
	}

}


void Floor::ini_location(int n){

	find_ghost();			// this will make find ghost first when the function is called
	set_darkmap(false);		// initialize the dark map

	// following will find the player's position depends on which floor he is in
	for (int x = 0; x < ROW; x++){
        for (int y = 0; y < COL; y++){
			if(n==1){
				if (tile[x][y]=='E'){
					tile[x][y] = 'P';
					record_start();
					track_player();
				}
			}else if(n==2){
				if (tile[x][y]=='A'){
					tile[x-1][y] = 'P';
					record_start();
					track_player();
				}
			}else if(n==3){
				if (tile[x][y]=='B'){
					tile[x+1][y] = 'P';
					record_start();
					track_player();
				}
			}
		}
	}
}

void Floor::track_player(){
	for(int row=0; row<ROW; row++){
		for(int col=0; col<COL; col++){
			if(tile[row][col]=='P'){
				pX=row;
				pY=col;
			}
		}
	}
}

void Floor::record_start(){
	for(int row=0; row<ROW; row++){
		for(int col=0; col<COL; col++){
			if(tile[row][col]=='P'){
				startX=row;
				startY=col;
			}
		}
	}
}

bool Floor::ex_ghost(){
	if(ghost==1)
		return true;
	else
		return false;
}

void Floor::find_ghost(){
	for (int x = 0; x < ROW; x++){
        for (int y = 0; y < COL; y++){
            if (tile[x][y] == 'G'){
				track_ghost(x,y);
				ghost=1;		//initialize ghost;
				pre_item = ' ';
				return;
            }	
        }
    }
}

void Floor::track_ghost(int inputX, int inputY){
	gX=inputX;
	gY=inputY;
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////


bool Floor::check_Gmove(int x, int y) const{
    return (x >= 0 && x < ROW && y >= 0 && y < COL) && tile[x][y] != 'P';
}

bool Floor::near_player(){
	if( abs(gX-pX) + abs(gY-pY) <= 5 )
		return true;
	else
		return false;
}

void Floor::set_ghost(int inputX, int inputY){
		if(tile[gX+inputX][gY+inputY] != 'G'  ){
			if( !check_Gmove(gX+inputX,gY+inputY) ){
				return;
			}
			item = tile[gX+inputX][gY+inputY];
			tile[gX][gY] = pre_item;
			tile[gX+inputX][gY+inputY] = 'G';
			track_ghost(gX+inputX,gY+inputY);
			pre_item = item;
		}
}


char Floor::check_map(int inputX, int inputY){
	
	if( (tile[pX+inputX][pY+inputY]=='#') || (pX+inputX < 0) || (pX+inputX>=ROW) || (pY+inputY<0) || (pY+inputY>=COL) )
		return '#';

	else if(tile[pX+inputX][pY+inputY]=='K')
		return 'K';

	else if(tile[pX+inputX][pY+inputY]=='D')
		return 'D';

	else if(tile[pX+inputX][pY+inputY]=='C')
		return 'C';	

	else if( (tile[pX+1][pY]=='G') || (tile[pX-1][pY]=='G') || (tile[pX][pY+1]=='G') || (tile[pX][pY-1]=='G') )
	//else if( (abs(pX-gX) + abs(pY-gY)) <= 1 ) 
	//else if( (tile[pX+inputX][pY]=='G') || (tile[pX-inputX][pY]=='G') || (tile[pX][pY+inputY]=='G') || (tile[pX][pY-inputY]=='G') )
		return 'G';	
	
	else if(tile[pX+inputX][pY+inputY]=='A')
		return 'A';

	else if(tile[pX+inputX][pY+inputY]=='B')
		return 'B';

	else if(tile[pX+inputX][pY+inputY]=='X')
		return 'X';

	else
		return '0';
}


void Floor::set_player(int inputX, int inputY, bool safe){

	if(safe==true){
		if(tile[pX+inputX][pY+inputY] == 'G'){	
			ghost = 0;
			track_ghost(100,100);
		}
		tile[pX+inputX][pY+inputY] = 'P';
		tile[pX][pY]=' ';
		track_player();		
	}else if(inputX==inputY){
		tile[pX][pY] = 'P';
		track_player();
	}else if(safe==false){	
		tile[startX][startY] = 'P';
		tile[pX][pY]=' ';
		track_player();
	}
}








