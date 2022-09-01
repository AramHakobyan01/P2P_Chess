#pragma once
#include "Piece.h"
#include <vector>
#include "Figur.h"
class Board 
{
public:
	std::vector<Figur*> figur[8];
	bool game_color;
};