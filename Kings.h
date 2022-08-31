#pragma once
#include "Board.h"
#include "Halper.h"
class Kings : Board
{
public:
	Halper halper;
	bool CanKingCastling(Coordinates coordinates, Coordinates new_coordinates);
	void MoveKing(Coordinates coordinates, Coordinates new_coordinates);
};

