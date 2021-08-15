#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define W 120
#define H 35
#define ALIVE "\u25c9"	//◉
#define LIVE_PERCENT 20
#define DELAY 400

void clear_screen();
void draw();
void evolve();
void delay(int);
void print_info();

void set_randoms();
void set_heart();
void set_glider();
void set_pentadecathlon();


#endif // GAME_OF_LIFE_H
