#include <iostream>
#include <thread>
#include <chrono>
#include "game_of_life.h"
using std::cout;
using std::endl;


bool world[H][W]={0};

void clear_screen() {
	cout << "\033[H";
}

void draw() {
	clear_screen();
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			if (world[i][j] == true)
				cout << ALIVE;
			else
				cout << " " ;
			cout << " ";
		}
		cout << endl;
	}
}

void print_info() {
	static int gen=1;
	cout << "Generation : " << gen++ << endl;
	int count_lives=0, whole_space=0;
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			if (world[i][j]==true)
				count_lives++;
			whole_space++;
		}
	}
	cout << "Alive cells : " << count_lives << endl;
	cout << "Whole spaces : " << whole_space << endl;
	cout << "Lives percent : " << 1.0*count_lives/whole_space*100.0 << "%" << endl;
}


void evolve() {
	bool new_world[H][W];
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			int lives = 0;
			for (int ii=i-1; ii<=i+1; ii++) {
				for (int jj=j-1; jj<=j+1; jj++) {
					if (world[(ii+H)%H][(jj+W)%W])
						lives++;
				}
			}
			if (world[i][j]) lives--;


			//------------RULES-----------------

			if (lives==3)
				new_world[i][j] = true;
			else if (lives==2 && world[i][j]==true)
				new_world[i][j] = true;
			else
				new_world[i][j] = false;

			//----------------------------------
		}
	}
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			world[i][j] = new_world[i][j];
		}
	}
}

void delay(unsigned long long ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}



void set_randoms() {
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			int rnd = rand()%100 + 1;
			world[i][j] = rnd < LIVE_PERCENT ? true : false ;
		}
	}
}


// some cool patterns

void set_heart() {
	// 9 * 13
	int indexes[][2] = {{0,2}, {0,3}, {0, 4}, {0,8}, {0,9}, {0,10},
       			    	{1,1}, {1,2}, {1,4}, {1,8}, {1,10}, {1,11},
			    		{2,0}, {2,1}, {2,3}, {2,9}, {2,11}, {2,12},
			    		{3,1}, {3,3}, {3,4}, {3,6}, {3,8}, {3,9}, {3,11},
			    		{4,2}, {4,3}, {4,5}, {4,6}, {4,7}, {4,9}, {4,10},
			    		{5,4}, {5,6}, {5,8},
			    		{6,4}, {6,6}, {6,8},
			    		{7,5}, {7,6}, {7,7},
			    		{8,6}

	};
	int size = sizeof(indexes)/sizeof(indexes[0]);
	int m_h = (H/2)-4;
	int m_w = (W/2)-6;
	for (int i=0; i<size; i++) {
		world[m_h+indexes[i][0]][m_w+indexes[i][1]] = true;
	}
}

void set_glider() {
	// 3 * 3
	int indexes[][2] = {{0,1}, {0,2},
			    {1,0}, {1,1},
			    {2,2}

	};
	int size = sizeof(indexes)/sizeof(indexes[0]);
	int m_h = (H/2)-1;
	int m_w = (W/2)-1;
	for (int i=0; i<size; i++) {
		world[m_h+indexes[i][0]][m_w+indexes[i][1]] = true;
	}
}

void set_pentadecathlon() {
	// 8 * 3

	int indexes[][2] = {{0,0}, {0,1}, {0,2},
			    {1,0}, {1,2},
			    {2,0}, {2,1}, {2,2},
			    {3,0}, {3,1}, {3,2},
			    {4,0}, {4,1}, {4,2},
			    {5,0}, {5,1}, {5,2},
			    {6,0}, {6,2},
			    {7,0}, {7,1}, {7,2}

	};

	int size = sizeof(indexes)/sizeof(indexes[0]);
	int m_h = (H/2)-4;
	int m_w = (W/2)-1;
	for (int i=0; i<size; i++) {
		world[m_h+indexes[i][0]][m_w+indexes[i][1]] = true;
	}

}
