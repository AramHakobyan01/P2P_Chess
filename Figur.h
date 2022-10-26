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
    Piece GetPiece();
    QString GetPath();
    virtual std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>&  figur, Coordinates c, Coordinates king_c) = 0;
    virtual ~Figur() = default;
protected:
    QString path;
    Piece piece;
    bool AreChacking(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates new_c, Coordinates king_c);
};

class Pawn : public Figur
{
public:
    Pawn(Color color);
    bool Get();
    void Set();
    std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
    virtual ~Pawn() = default;
private:
    bool first;
};

class Knight : public Figur
{
public:
    Knight(Color color);
    std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
    virtual ~Knight() = default;
};

class Bishop : virtual public Figur
{
public:
    Bishop() = default;
    Bishop(Color color);
    std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
    virtual ~Bishop() = default;
};

class Rook : virtual public Figur
{
public:
    Rook() = default;
    Rook(Color color);
    bool Get();
    void Set();
    std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
    virtual ~Rook() = default;
private:
    bool move;
};

class Queen : public Bishop, public Rook
{
public:
    Queen(Color color);
    std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) override;
    virtual ~Queen() = default;
};

class King : public Figur
{
public:
    King(Color color);
    bool Get();
    void Set();
    bool ArePawnChacking(std::vector<std::vector<Figur*>>& figur, Coordinates new_c, Coordinates king_c);
    bool AreKnightChacking(std::vector<std::vector<Figur*>>& figur, Coordinates new_c, Coordinates king_c);
    bool AreBishopChacking(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates new_c, Coordinates king_c);
    bool AreRookChacking(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates new_c, Coordinates king_c);
    bool AreKingChacking(std::vector<std::vector<Figur*>>& figur, Coordinates new_c, Coordinates king_c);
    std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates) override;
    virtual ~King() = default;
private:
    bool move;
};

class None : public Figur 
{
public:
    None();
    std::vector<Coordinates> WhereCanMove(std::vector<std::vector<Figur*>>&, Coordinates, Coordinates) override;
    virtual ~None() = default;
};

#endif //FIGUR
