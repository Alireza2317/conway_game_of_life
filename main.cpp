#include <iostream>
#include "game_of_life.h"


int main() {
	clear_screen();
	srand(time(0));

	set_randoms();
	//set_heart();
	//set_glider();
	//set_pentadecathlon();

	draw();
	print_info();
	delay(500);
	while (true) {
		evolve();
		draw();
		print_info();
		delay(DELAY);
	}
	return 0;
}
