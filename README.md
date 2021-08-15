# Conway's Game of Life
The Game of Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. It is Turing complete and can simulate a universal constructor or any other Turing machine.

More information in [Wikipedia](https://en.wikipedia.org/wiki/Conway's_Game_of_Life).

## How to run
First make sure `g++` is installed. Then:
```bash
git clone htts://github.com/alireza2317/conway_game_of_life
cd conway_game_of_life
make
./gameoflife
```

## Customize
You can change the size of the map in `game_of_life.h`, by changing the `W`(width) and `H`(height) values.

You can also change the speed of evolving by changing the `DELAY` value. It's a number in miliseconds. The less the `DELAY`, the faster the evolution.

### Patterns
By default the game starts in a random map. You can use different patterns provided in the code. In `main.cpp` file, uncomment the desired pattern:
```c++
	//set_randoms();
	//set_heart();
	//set_glider();
	//set_pentadecathlon();
```

After any customizaiton, run:
```bash
make
./gameoflife
```

Enjoy :)