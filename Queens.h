#pragma once
#include "Board.h"
#include "Halper.h"
class Queens : Board
{
public:
	Halper halper;
	void MoveQueen(Coordinates coordinates, Coordinates new_coordinates);
};

