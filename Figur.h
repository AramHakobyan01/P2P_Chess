#pragma once
#include "Piece.h"
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
	Coordinates coord;
	virtual void Move() = 0;
};


class Pawn : public Figur
{
public:
	void Move();
};
class Knight : public Figur
{
public:
	void Move();
};
class Bishop : public Figur
{
public:
	void Move();
};
class Rook : public Figur
{
public:
	void Move();
};
class Queen : public Figur
{
public:
	void Move();
};
class King : public Figur
{
public:
	void Move();
};
