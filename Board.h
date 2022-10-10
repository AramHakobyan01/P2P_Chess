#ifndef BOARD
#define BOARD

#include <vector> 
#include <unordered_map>

#include "Piece.h"
#include "Figur.h"
#include "mainwindow.h"

class Board
{
public:
    Board(){}
    Board(MainWindow* w);
    void Move(Coordinates c, Coordinates new_c, MainWindow* w);
    void Start(MainWindow* w);
    void Continue(Coordinates coord, Coordinates new_coord);
    std::vector<Coordinates> get(){
        return move;
    }
    //~Board() {};
private:
    QTcpSocket* socket;
    std::vector<Coordinates> move;
    std::unordered_map<PieceName, void (Board::*)(Coordinates c, Color color, MainWindow* w)> piece_l;
    std::vector<std::vector<Figur*>> figur{ 8 };
    Color game_color = Color::White;
	Coordinates king_c[2];
    void CreatePawn(Coordinates c, Color color, MainWindow* w);
    void CreateKnight(Coordinates c, Color color, MainWindow* w);
    void CreateBishop(Coordinates c, Color color, MainWindow* w);
    void CreateRook(Coordinates c, Color color, MainWindow* w);
    void CreateKing(Coordinates c, Color color, MainWindow* w);
    void CreateQueen(Coordinates c, Color color, MainWindow* w);
    void CreateNone(Coordinates c, Color color, MainWindow* w);
	bool ChackMate();
	
};
#endif //BOARD
