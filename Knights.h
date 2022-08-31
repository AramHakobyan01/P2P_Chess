#pragma once
#include "Board.h"
#include "Halper.h"
class Knights : Board
{
public:
	Halper halper;
	void MoveKnight(Coordinates coordinates, Coordinates new_coordinates);
};

