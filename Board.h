#ifndef _Board_
#define _Board_
#include "Piece.h"
#include <vector>
#include "Figur.h"

class Board 
{
private:
	std::vector<std::vector<Figur*>> figur;
	bool game_color;
public:
	Board();
	void Start(Coordinates coordinates, Coordinates new_coordinates, bool color);
};
#endif _Board_