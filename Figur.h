#ifndef FIGUR
#define FIGUR

#include <vector>
#include <iostream>

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
	virtual std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) = 0;
};

class Pawn : public Figur
{
public:
	Pawn(Figur* figur, Color color , Coordinates c) {
		std::cout << "mmmm" << std::endl;
		if (color == Color::White) {
			std::cout << "mmmm" << std::endl;
			figur->piece = { Color::White, PieceName::Rook };
			figur->coord = { c.x,c.y };
		}
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) override;
};

class Knight : public Figur
{
public:
	Knight(Figur* figur, Color color, Coordinates c) {
		if (color == Color::White) {
			figur->piece = { Color::White, PieceName::Rook };
			figur->coord = { c.x,c.y };
		}
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) override;
};

class Bishop : virtual public Figur
{
public:
	Bishop() {}
	Bishop(Figur* figur, Color color, Coordinates c) {
		if (color == Color::White) {
			figur->piece = { Color::White, PieceName::Rook };
			figur->coord = { c.x,c.y };
		}
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) override;
};

class Rook : virtual public Figur
{
public:
	Rook() {}
	//Rook(Figur* figur) {
	//	std::cout << "mmmm" << std::endl;
	//	//if (color == Color::White) {
	//		figur->piece = {Color::White, PieceName::Rook};
	//		figur->coord = {0,0};
	//	//}
	//}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) override {
		std::vector<Coordinates> rookMove;
		return rookMove;
	};
};

class Queen : public Bishop, public Rook
{
public:
	Queen(Figur* figur, Color color, Coordinates c) {
		if (color == Color::White) {
			figur->piece = { Color::White, PieceName::Rook };
			figur->coord = { c.x,c.y };
		}
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) override;
};

class King : public Figur
{
public:
	King(Figur* figur, Color color, Coordinates c) {
		if (color == Color::White) {
			figur->piece = { Color::White, PieceName::Rook };
			figur->coord = { c.x,c.y };
		}
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>> figur, Coordinates c) override;
};

#endif FIGUR
