#include "Board.h"
#include "Piece.h"

#include <iostream>
#include <QApplication>

Board::Board(MainWindow** w) {
	piece_l.insert({ PieceName::Pawn, &Board::CreatePawn });
	piece_l.insert({ PieceName::Knight, &Board::CreateKnight });
	piece_l.insert({ PieceName::Bishop, &Board::CreateBishop });
	piece_l.insert({ PieceName::Rook, &Board::CreateRook });
	piece_l.insert({ PieceName::Queen, &Board::CreateQueen });
	piece_l.insert({ PieceName::King, &Board::CreateKing });
	piece_l.insert({ PieceName::None, &Board::CreateNone });
	Color color = Color::White;
	for (int i = 0, j = 0; i < 2; i++) {
        (this->*piece_l[PieceName::Rook])({ j,0 }, color, w);
        (this->*piece_l[PieceName::Knight])({ j,1 }, color, w);
        (this->*piece_l[PieceName::Bishop])({ j,2 }, color, w);
        (this->*piece_l[PieceName::King])({ j,3 }, color, w);
        (this->*piece_l[PieceName::Queen])({ j,4 }, color, w);
        (this->*piece_l[PieceName::Bishop])({ j,5 }, color, w);
        (this->*piece_l[PieceName::Knight])({ j,6 }, color, w);
        (this->*piece_l[PieceName::Rook])({ j,7 }, color, w);
		king_c[i] = { j,3 };
		j = 7;
		color = Color::Black;
	}
	color = Color::White;
	for (int i = 1, j = 0, l = 0; l < 16; l++) {
        (this->*piece_l[PieceName::Pawn])({ i,j }, color, w);
		if (l == 7) {
			j = 0;
			i = 6;
			color = Color::Black;
		}
		else {
			j++;
		}
	}
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
            (this->*piece_l[PieceName::None])({ i,j }, color, w);
		}
    }
   // widget->show();
    //w->Butten(figur);
}

void Board::Move(Coordinates c, Coordinates new_c, MainWindow** w) {
    delete figur[new_c.x][new_c.y];
    (this->*piece_l[figur[c.x][c.y]->getP().name])({new_c.x,new_c.y}, figur[c.x][c.y]->getP().color, w);
    if(figur[c.x][c.y]->getP().name == PieceName::Pawn){
        if (new_c.y + 1 < 8 && figur[new_c.x][new_c.y + 1]->getP().name == PieceName::Pawn) {
            Pawn* p = &dynamic_cast<Pawn&>(*figur[new_c.x][new_c.y]);
            if (abs(c.x - new_c.x) == 2) {
                p->set();
            }
        }else if (new_c.y - 1 >= 0 && figur[new_c.x][new_c.y - 1]->getP().name == PieceName::Pawn) {
            Pawn* p = &dynamic_cast<Pawn&>(*figur[new_c.x][new_c.y]);
            if (abs(c.x - new_c.x) == 2) {
                p->set();
            }
        }
        if (abs(c.x - new_c.x) == 1 && abs(c.y - new_c.y) == 1 && figur[c.x][new_c.y]->getP().name == PieceName::Pawn) {
            if(figur[c.x][c.y + 1]->getP().color != figur[c.x][new_c.y]->getP().color){
                delete figur[c.x][new_c.y];
                (this->*piece_l[PieceName::None])({ c.x,new_c.y }, Color::None, w);
            }
        }

    }
    if (figur[c.x][c.y]->getP().name == PieceName::King) {
        if (c.y - new_c.y == 2 && (&dynamic_cast<King&>(*figur[c.x][c.y]))->get() && (&dynamic_cast<Rook&>(*figur[c.x][c.y - 3]))->get()) {
            delete figur[c.x][c.y - 1];
            (this->*piece_l[PieceName::Rook])({ c.x,c.y - 1 }, figur[c.x][c.y]->getP().color, w);
            delete figur[c.x][c.y - 3];
            (this->*piece_l[PieceName::None])({ c.x,c.y - 3 }, Color::None, w);
        }
        else if (c.y - new_c.y == -2 && (&dynamic_cast<King&>(*figur[c.x][c.y]))->get() && (&dynamic_cast<Rook&>(*figur[c.x][c.y + 4]))->get()) {
            delete figur[c.x][c.y + 1];
            (this->*piece_l[PieceName::Rook])({ c.x,c.y + 1 }, figur[c.x][c.y]->getP().color, w);
            delete figur[c.x][c.y + 4];
            (this->*piece_l[PieceName::None])({ c.x,c.y + 4 }, Color::None, w);
        }
        (&dynamic_cast<King&>(*figur[new_c.x][new_c.y]))->set();
        if (c.x == king_c[0].x) {
            king_c[0] = new_c;
        }
        else {
            king_c[1] = new_c;
        }
    }
    if (figur[c.x][c.y]->getP().name == PieceName::Rook) {
        (&dynamic_cast<Rook&>(*figur[new_c.x][new_c.y]))->set();
    }
    delete figur[c.x][c.y];
    (this->*piece_l[PieceName::None])({ c.x,c.y }, Color::None, w);
}

void Board::Start(MainWindow** w) {
    while (!ChackMate()) {
    //wid->show();
        QApplication::sync();
        Coordinates coord = (*w)->get();
        while(coord.x == -1){
           //QApplication::sync();
           coord = (*w)->get();
        }
        (*w)->set();
		if (coord.x < 8 && coord.x >= 0 && game_color == figur[coord.x][coord.y]->getP().color) {
			if (coord.y < 8 && coord.y >= 0 && figur[coord.x][coord.y]->getP().name != PieceName::None) {
				if (figur[coord.x][coord.y]->getP().color == Color::White) {
					move = figur[coord.x][coord.y]->WhereCanMove(figur, coord, king_c[0]);
 				}
				else {
					move = figur[coord.x][coord.y]->WhereCanMove(figur, coord, king_c[1]);
				}
                for (size_t i = 0; i < move.size(); i++) {
                    std::cout << move[i].x << move[i].y << std::endl;
                }
                //(*w)->ShowMoive(move);
                Coordinates new_coord = {10,10};(*w)->get();
                //std::cout << move[0].x << move[0].y << std::endl;
//                while(new_coord.x == -1){
//                    QApplication::sync();
//                    new_coord = (*w)->get();
//                }
//                for (int i = 0; i < (int)move.size(); i++) {
//                    if ((move[i].x == new_coord.x && move[i].y == new_coord.y)) {
//                        Move(coord, new_coord, w);
//                        (*w)->set();
//                        if (game_color == Color::White) {
//                            game_color = Color::Black;
//                        }
//                        else {
//                            game_color = Color::White;
//                        }
//                        break;
//                    }
//                }
			}
        }
    }
}
void Board::Continue(Coordinates coord, Coordinates new_coord){

}


