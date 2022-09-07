#ifndef FIGUR
#define FIGUR

#include <vector>
#include <iostream>

#include "Piece.h"

struct  Coordinates
{
	int x;
	int y;
};

class Figur
{
public:
	Piece piece;
	Coordinates coord;
	virtual std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>&  figur, Coordinates c) = 0;
	virtual ~Figur() = default;
};

class Pawn : public Figur
{
public:
	Pawn(Color color , Coordinates c) {
		piece = { color, PieceName::Pawn };
		coord = { c.x,c.y };
		//std::cout << c.x << c.y << std::endl;
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c) override;
};

class Knight : public Figur
{
public:
	Knight(Color color, Coordinates c) {
		piece = { color, PieceName::Knight };
		coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c) override;
};

class Bishop : virtual public Figur
{
public:
	Bishop() {}
	Bishop(Color color, Coordinates c) {
		piece = { color, PieceName::Bishop };
		coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c) override;
};

class Rook : virtual public Figur
{
public:
	Rook() {}
	Rook(Color color , Coordinates c) {
		piece = { color, PieceName::Rook };
		coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c) override;
	virtual ~Rook() {};
};

class Queen : public Bishop, public Rook
{
public:
	Queen(Color color, Coordinates c)  {
		piece = { color, PieceName::Queen };
		coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c) override;
};

class King : public Figur
{
public:
	King(Color color, Coordinates c) {
		piece = { color, PieceName::King };
		coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c) override;
};

class None : public Figur 
{
public:
	None(Coordinates c) {
		piece = { Color::None,PieceName::None };
		coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c) override {
		std::vector<Coordinates> none;
		return none;
	}
};

#endif //FIGUR
