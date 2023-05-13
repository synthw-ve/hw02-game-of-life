#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int COLS = 40;
	static const unsigned int ROWS = 20;
	static const unsigned int PROBABILITY = 15;
	bool _generation[ROWS][COLS];
	bool _next_generation[ROWS][COLS];
	bool random_value();

public:
	game_of_life();
	void next_generation();
	void draw();
};

#endif