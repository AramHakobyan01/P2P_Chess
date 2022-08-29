#pragma once
#include "Figur.h"
#include "Halper.h"
#include <iostream>
class Logic : ConstructPieceList
{
public:
	Logic(){}
	bool game_color = false;
	Halper halper;
	void Start(Coordinates coordinates, Coordinates new_coordinates, bool color);
	bool CanKingCastling(vector<Figur>::iterator king, Coordinates new_coordinates);
	void MovePawn(Coordinates coordinates, Coordinates new_coordinates);
	void MoveKnight(Coordinates coordinates, Coordinates new_coordinates);
	void MoveBishop(Coordinates coordinates, Coordinates new_coordinates);
	void MoveRook(Coordinates coordinates, Coordinates new_coordinates);
	void MoveQueen(Coordinates coordinates, Coordinates new_coordinates);
	void MoveKing(Coordinates coordinates, Coordinates new_coordinates);
};