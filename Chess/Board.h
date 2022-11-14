#ifndef BOARD
#define BOARD

#include <vector> 
#include <unordered_map>

#include "Piece.h"
#include "Figur.h"
#include "mainwindow.h"

class Board : MainWindow
{
public:
    Board();
    ~Board() = default;
private slots:
    void ReadSocket() override;
private:
    std::vector<Coordinates> move;
    std::unordered_map<PieceName, void (Board::*)(Coordinates c, Color color)> piece_l;
    std::vector<std::vector<Figur*>> figur{ 8 };
    Color game_color;
	Coordinates king_c[2];
private:
    void Move(Coordinates c, Coordinates new_c);
    void Start(Coordinates coord);
    void Continue(Coordinates coord, Coordinates new_coord);
    void CreatePawn(Coordinates c, Color color);
    void CreateKnight(Coordinates c, Color color);
    void CreateBishop(Coordinates c, Color color);
    void CreateRook(Coordinates c, Color color);
    void CreateKing(Coordinates c, Color color);
    void CreateQueen(Coordinates c, Color color);
    void CreateNone(Coordinates c, Color);
    void ChangeFigur(Coordinates widget, int name);
	bool ChackMate();
    void CreateFigur();
	
};
#endif //BOARD
