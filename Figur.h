#ifndef FIGUR
#define FIGUR

#include <vector>
#include <iostream>
#include <QString>

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
    QString getPath() {
        return path;
    }
	virtual std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>&  figur, Coordinates c, Coordinates king_c) = 0;
    virtual ~Figur() {};
protected:
    QString path;
	Piece piece;
	bool AreChacking(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates new_c, Coordinates king_c);
};

class Pawn : public Figur
{
public:
    Pawn(Color color) {
        piece = { color, PieceName::Pawn };
        if(color == Color::White){
            path = ":/image/Pawn1.png";
        }else{
           path = ":/image/Pawn.png";
        }
//        QPushButton* button_ = new QPushButton(*w);
//        button_->resize(50,50);
//        button_->move(c.y*50, c.x*50);
//        if(((c.x + c.y)%2) == 0){
//            button_->setStyleSheet(QString("border: 0 ;background-color: rgb(0,0,0);"));
//        }else{
//            button_->setStyleSheet(QString("border: 0 ;background-color: rgb(255,255,255);"));
//        }
//        MainWindow::connect(button_, &QPushButton::clicked, *w, &MainWindow::ClickedSlot);
        p = false;
	}
	bool get() {
		return p;
	}
	void set() {
		p = true;

	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
    virtual ~Pawn() {};
private:
	bool p;
};

class Knight : public Figur
{
public:
    Knight( Color color) {
		piece = { color, PieceName::Knight };
        if(color == Color::White){
            path = ":/image/Knight1.png";
        }else{
           path = ":/image/Knight.png";
        }
		//coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
    virtual ~Knight() {};
};

class Bishop : virtual public Figur
{
public:
	Bishop() {}
    Bishop(Color color) {
		piece = { color, PieceName::Bishop };
        if(color == Color::White){
            path = ":/image/Bishop1.png";
        }else{
           path = ":/image/Bishop.png";
        }
		//coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
    virtual ~Bishop() {};
};

class Rook : virtual public Figur
{
public:
	Rook() {}
    Rook(Color color) {
		piece = { color, PieceName::Rook };
        if(color == Color::White){
            path = ":/image/Rook1.png";
        }else{
           path = ":/image/Rook.png";
        }

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
        if(color == Color::White){
            path = ":/image/Queen1.png";
        }else{
           path = ":/image/Queen.png";
        }
		//coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
    virtual ~Queen() {};
};

class King : public Figur
{
public:
    King(Color color) {
		piece = { color, PieceName::King };
        if(color == Color::White){
            path = ":/image/King1.png";
        }else{
           path = ":/image/King.png";
        }
		//coord = { c.x,c.y };
	}
	bool get() {
		return k;
	}
	void set() {
		k = false;

	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
    virtual ~King   () {};
private:
	bool k = true;
};

class None : public Figur 
{
public:
    None() {
        piece = { Color::None, PieceName::None };
        //path = ":/image/None.png";
		//coord = { c.x,c.y };
	}
	std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override {
		return {};
	}
    virtual ~None() {};

};

#endif //FIGUR
