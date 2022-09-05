#ifndef BOARD
#define BOARD

#include <vector> 

#include "Piece.h"
#include "Figur.h"

class Board 
{
public:
	Board();
	void Start(Coordinates coord);
private:
	std::vector<std::vector<Figur*>> figur;
	//bool game_color;
};
#endif BOARD