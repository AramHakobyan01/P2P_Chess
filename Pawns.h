#pragma once
#include "Board.h"
#include "Halper.h"
class Pawns : Board
{
public:
	Pawns(){}
	Halper halper;
	void MovePawn(Coordinates coordinates, Coordinates new_coordinates);
};

