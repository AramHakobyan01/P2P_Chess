#pragma once
#include "Board.h"
#include "Halper.h"
class Bishops : public Board
{
public:
	Halper halper;
	void MoveBishop(Coordinates coordinates, Coordinates new_coordinates);
};

