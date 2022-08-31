#pragma once
#include <iostream>
#include "Board.h"
class Halper
{
public:
	Halper(){}
	bool CanPawnMove(Coordinates coordinates, Coordinates new_coordinates);
	bool CanPawnEat(Coordinates coordinates, Coordinates new_coordinates);
	bool CanKnightMove(Coordinates coordinates, Coordinates new_coordinates);
	bool CanBishopMove(Coordinates coordinates, Coordinates new_coordinates);
	bool CanRookMove(Coordinates coordinates, Coordinates new_coordinates);
	bool CanQueenMove(Coordinates coordinates, Coordinates new_coordinates);
	bool CanKingMove(Coordinates coordinates, Coordinates new_coordinates);
	bool Check(Coordinates coordinates, Coordinates new_coordinates);
	bool AreChacking(bool game_color);
	//vector<Coordinates> WhereCanMove(Coordinates coordinates, bool game_color);
};