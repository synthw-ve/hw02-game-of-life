#include "game_of_life.h"
#include <ctime>
using namespace std;

bool game_of_life::random_value() {
	// Random number 0-100, if <PROBABILITY return true (PROBABILITY%)
	return (rand() % 100) < PROBABILITY;
}

game_of_life::game_of_life() {
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			_generation[i][j] = random_value();
}

void game_of_life::next_generation() {
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++) {
			int alive_neighs = 0;
			for (int k = -1; k <= 1; k++)
				for (int l = -1; l <= 1; l++) {
					if (   !((i == 0)    && (k == -1)) // OOB check rows
						&& !((i == ROWS) && (k == 1))
						&& !((j == 0)    && (l == -1)) // OOB check cols
						&& !((j == COLS) && (l == 1)))
							if (_generation[i+l][j+k])
								alive_neighs++;
				}
			if (_generation[i][j]) {
				alive_neighs--; // 0,0 is alive but not a neighbour
				if (alive_neighs == 2 || alive_neighs == 3)
					_next_generation[i][j] = true;
				else _next_generation[i][j] = false;
			}
			else
				if (alive_neighs == 3)
					_next_generation[i][j] = true;
				else _next_generation[i][j] = false;
		}

	copy(&_next_generation[0][0], &_next_generation[0][0]+ROWS*COLS, &_generation[0][0]);
}

void game_of_life::draw() {
	system("cls");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++)
			if (_generation[i][j])
				cout << '*';
			else
				cout << '-';
		cout << endl;
	}
}