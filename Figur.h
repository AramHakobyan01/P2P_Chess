#pragma once
#include "Piece.h"
using namespace std;
class Coordinates
{
public:
	int x;
	int y;
};
class Figur 
{
public:
	Piece piece;
	Coordinates coordinates;
};