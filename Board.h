#ifndef BOARD
#define BOARD

#include <vector> 

#include "Piece.h"
#include "Figur.h"

class Board 
{
public:
	Board();
	void Move(Coordinates c, Coordinates new_c);
	void Start(Coordinates coord);
private:
	std::vector<std::vector<Figur*>> figur{8};
	//bool game_color;
};
#endif //BOARD