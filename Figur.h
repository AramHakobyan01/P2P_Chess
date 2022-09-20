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
	Piece getP() {
		return piece;
	}
	virtual std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>&  figur, Coordinates c, Coordinates king_c) = 0;
	virtual ~Figur() = default;
protected:
	Piece piece;
	bool AreChacking(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates new_c, Coordinates king_c);
};

class Pawn : public Figur
{
public:
	Pawn(Color color) {
		piece = { color, PieceName::Pawn };
		//coord = { c.x,c.y };
			p = false;
	}
	bool get() {
		return p;
	}
	void set() {
		p = true;

	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
private:
	bool p;
};

class Knight : public Figur
{
public:
	Knight( Color color) {
		piece = { color, PieceName::Knight };
		//coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
};

class Bishop : virtual public Figur
{
public:
	Bishop() {}
	Bishop(Color color) {
		piece = { color, PieceName::Bishop };
		//coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
};

class Rook : virtual public Figur
{
public:
	Rook() {}
	Rook(Color color) {
		piece = { color, PieceName::Rook };
		//coord = { c.x,c.y };
	}
	bool get() {
		return r;
	}
	void set() {
		r = false;

	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
	virtual ~Rook() {};
private:
	bool r = true;
};

class Queen : public Bishop, public Rook
{
public:
	Queen(Color color)  {
		piece = { color, PieceName::Queen };
		//coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
};

class King : public Figur
{
public:
	King(Color color) {
		piece = { color, PieceName::King };
		//coord = { c.x,c.y };
	}
	bool get() {
		return k;
	}
	void set() {
		k = false;

	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
private:
	bool k = true;
};

class None : public Figur 
{
public:
	None(Coordinates c) {
		piece = { Color::None,PieceName::None };
		//coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override {
		return {};
	}
};

#endif //FIGUR
