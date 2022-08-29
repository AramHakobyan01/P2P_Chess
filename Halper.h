#pragma once
#include "ConstructPieceList.h"
#include "Figur.h"
#include <iostream>
class Halper : ConstructPieceList
{
public:
	Halper(){}
	
	vector<Figur>::iterator CheckCoordinates(Coordinates coordinates);
	bool CanPawnMove(vector<Figur>::iterator pawn, Coordinates new_coordinates);
	bool CanPawnEat(vector<Figur>::iterator pawn, Coordinates new_coordinates);
	bool CanKnightMove(vector<Figur>::iterator knight, Coordinates new_coordinates);
	bool CanBishopMove(vector<Figur>::iterator bishop, Coordinates new_coordinates);
	bool CanRookMove(vector<Figur>::iterator rook, Coordinates new_coordinates);
	bool CanQueenMove(vector<Figur>::iterator queen, Coordinates new_coordinates);
	bool CanKingMove(vector<Figur>::iterator king, Coordinates new_coordinates);
	bool Check(vector<Figur>::iterator king, Coordinates coordinates);
	bool AreChacking(bool game_color);
	vector<Coordinates> WhereCanMove(Coordinates coordinates, bool game_color);
};