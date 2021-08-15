gameoflife : main.o game_of_life.o
	g++ game_of_life.o main.o -o gameoflife

game_of_life.o : game_of_life.cpp
	g++ game_of_life.cpp -c

main.o : main.cpp
	g++ main.cpp -c

clean :
	rm *.o gameoflife
