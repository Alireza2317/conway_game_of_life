# Conway's Game of Life

A lightweight, zero-dependency C++ implementation of Conway's Game of Life for the terminal.

The **Game of Life** is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. It is Turing complete and can simulate a universal constructor or any other Turing machine.

[More information on Wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

## Demo
<p align="center">
	<img src="https://github.com/user-attachments/assets/393eefdd-533e-4512-8d6b-154f1b225f24" alt="Game of Life Demo" width=600>
</p>

## How to Run

First, ensure `g++` and `make` are installed.

```bash
git clone https://github.com/alireza2317/conway_game_of_life.git
cd conway_game_of_life
make
./gameoflife
```

## Customize
- Map Size: Edit `W` (width) and `H` (height) in `game_of_life.h`.
- Speed: Edit the `DELAY` value in `game_of_life.h` (in milliseconds). Lower values = faster evolution.

## Patterns
By default, the game starts with a random map. You can enable specific patterns by uncommenting lines in `main.cpp`:

```C++
// set_randoms();
// set_heart();
set_glider(); // Example: Glider is now active
// set_pentadecathlon();
```

After any customization, recompile and run:

```Bash
make
./gameoflife
```
