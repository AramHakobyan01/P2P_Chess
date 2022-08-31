#pragma once
#include "Halper.h"
#include "Board.h"
class Rooks : Board
{
public:
	Halper halper;
	void MoveRook(Coordinates coordinates, Coordinates new_coordinates);
};

