/****************************************
				floor.h
****************************************/
#ifndef FLOOR_H_
#define FLOOR_H_

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Floor{

	public:
		Floor();
		~Floor();
		void read_maps(const char *txtfile);
		void print();
		char check_map(int inputX, int inputY);
		bool check_Gmove(int x, int y) const;
		void track_player();
		void track_ghost(int inputX, int inputY);
		void ini_location(int n);
		void find_ghost();
		bool ex_ghost();		//check if ghost exist
		void set_player(int, int, bool);
		void set_ghost(int, int);
		void record_start();
		bool near_player();
		int return_X(){return gX-pX;}
		int return_Y(){return gY-pY;}
		void set_darkmap(bool set);
		void set_playerarea();

	private:
		char ghost;		
		char item;
		char pre_item;
		int pX;
		int pY;
		int gX;		//previous step
		int gY;		//previous step
		int startX;
		int startY;
		int x_u,x_d;
		int y_l,y_r;
		const static int ROW=20;
		const static int COL=30;
		char tile[ROW][COL];
		char darkmap[ROW][COL];
		fstream inputfile;
};


#endif
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////







