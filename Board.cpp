#include <iostream>
#include <QApplication>

#include "Board.h"
#include "Piece.h"

Board::Board() {
    game_color = Color::White;
    piece_l.insert({ PieceName::Pawn, &Board::CreatePawn });
    piece_l.insert({ PieceName::Knight, &Board::CreateKnight });
    piece_l.insert({ PieceName::Bishop, &Board::CreateBishop });
    piece_l.insert({ PieceName::Rook, &Board::CreateRook });
    piece_l.insert({ PieceName::Queen, &Board::CreateQueen });
    piece_l.insert({ PieceName::King, &Board::CreateKing });
    piece_l.insert({ PieceName::None, &Board::CreateNone });
}

void Board::CreateFigur() {
    Color figur_color = Color::White;
    for (int i = 0, j = 0; i < 2; i++) {
        (this->*piece_l[PieceName::Rook])({ j,0 }, figur_color);
        (this->*piece_l[PieceName::Knight])({ j,1 }, figur_color);
        (this->*piece_l[PieceName::Bishop])({ j,2 }, figur_color);
        (this->*piece_l[PieceName::Queen])({ j,3 }, figur_color);
        (this->*piece_l[PieceName::King])({ j,4 }, figur_color);
        (this->*piece_l[PieceName::Bishop])({ j,5 }, figur_color);
        (this->*piece_l[PieceName::Knight])({ j,6 }, figur_color);
        (this->*piece_l[PieceName::Rook])({ j,7 }, figur_color);
        king_c[i] = { j,4 };
        j = 7;
        figur_color = Color::Black;
    }
    figur_color = Color::White;
    for (int i = 1, j = 0, l = 0; l < 16; l++) {
        (this->*piece_l[PieceName::Pawn])({ i,j }, figur_color);
        if (l == 7) {
            j = 0;
            i = 6;
            figur_color = Color::Black;
        }
        else {
            j++;
        }
    }
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            (this->*piece_l[PieceName::None])({ i,j }, figur_color);
        }
    }
}

void Board::ChangeFigur(Coordinates widget, int name) {
    Color c = figur[widget.x][widget.y]->GetPiece().color;
    delete figur[widget.x][widget.y];
    switch(name) {
    case 1:
        (this->*piece_l[PieceName::Bishop])({ widget.x, widget.y }, c);
        break;
    case 2:
        (this->*piece_l[PieceName::Queen])({ widget.x, widget.y }, c);
        break;
    case 3:
        (this->*piece_l[PieceName::Rook])({ widget.x, widget.y }, c);
        break;
    case 4:
        (this->*piece_l[PieceName::Knight])({ widget.x, widget.y }, c);
        break;
    }
    QList<QPushButton*> b = wid->findChildren<QPushButton*>();
    for (auto k = b.begin(); k != b.end(); k++) {
        if ((*k)->pos().x() == widget.y * 50 && (*k)->pos().y() == abs(rev - widget.x) * 50) {
            (*k)->setIcon(QIcon(QString(figur[widget.x][widget.y]->GetPath())));
            (*k)->setIconSize((*k)->size());
        }
    }
}

void Board::ReadSocket() {
    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_6_3);
    socketStream.startTransaction();
    if (first) {
        socketStream >> temp;
        qDebug() << temp;
        socketStream.abortTransaction();
        CreateFigur();
        AddWindowStyle();
        MainWindow::show();
        first = false;
        return;
    }
    if (temp == PAUSE) {
        socketStream >> temp;
        qDebug() << temp;
        delete startWid;
        socketStream.abortTransaction();
        return;
    }
    if (firstClick) {
        socketStream >> buttonCoord.x;
        if(buttonCoord.x == PAUSE) {
            socketStream >> buttonCoord.y;
            Coordinates widget;
            socketStream >> widget.x >> widget.y;
            ChangeFigur(widget, buttonCoord.y);
            socketStream.abortTransaction();
            return;
        }
        socketStream >> buttonCoord.y;
        qDebug() << buttonCoord.x << buttonCoord.y;
        socketStream.abortTransaction();
        prev_buttonCoord = buttonCoord;
        Start(buttonCoord);
        CanMove(move, prev_buttonCoord);
    } else {
        CanMove(move, prev_buttonCoord);
        socketStream >> buttonCoord.x >> buttonCoord.y;
        qDebug() << buttonCoord.x << buttonCoord.y;
        socketStream.abortTransaction();
        Continue(prev_buttonCoord, buttonCoord);
    }
}

void Board::Move(Coordinates c, Coordinates new_c) {
    delete figur[new_c.x][new_c.y];
    (this->*piece_l[figur[c.x][c.y]->GetPiece().name])({new_c.x,new_c.y}, figur[c.x][c.y]->GetPiece().color);
    if (figur[c.x][c.y]->GetPiece().name == PieceName::Pawn){
        if (new_c.y + 1 < 8 && figur[new_c.x][new_c.y + 1]->GetPiece().name == PieceName::Pawn) {
            Pawn* p = &dynamic_cast<Pawn&>(*figur[new_c.x][new_c.y]);
            if (abs(c.x - new_c.x) == 2) {
                p->Set();
            }
        } else if (new_c.y - 1 >= 0 && figur[new_c.x][new_c.y - 1]->GetPiece().name == PieceName::Pawn) {
            Pawn* p = &dynamic_cast<Pawn&>(*figur[new_c.x][new_c.y]);
            if (abs(c.x - new_c.x) == 2) {
                p->Set();
            }
        }
        if (abs(c.x - new_c.x) == 1 && abs(c.y - new_c.y) == 1 && figur[c.x][new_c.y]->GetPiece().name == PieceName::Pawn && (&dynamic_cast<Pawn&>(*figur[c.x][new_c.y]))->Get()) {
            if(figur[c.x][new_c.y]->GetPiece().color != figur[c.x][c.y]->GetPiece().color){
                DeletePawn({ c.x,new_c.y }, figur[c.x][new_c.y]->GetPiece().color);
                delete figur[c.x][new_c.y];
                (this->*piece_l[PieceName::None])({ c.x,new_c.y }, Color::None);
            }
        }

    }
    if (figur[c.x][c.y]->GetPiece().name == PieceName::King) {
        if (c.y - new_c.y == -2) {
            delete figur[c.x][c.y + 1];
            (this->*piece_l[PieceName::Rook])({ c.x,c.y + 1 }, figur[c.x][c.y]->GetPiece().color);
            delete figur[c.x][c.y + 3];
            (this->*piece_l[PieceName::None])({ c.x,c.y + 3 }, Color::None);
            MoveTo({ c.x,c.y + 3 }, { c.x,c.y + 1 }, Color::None);
        } else if (c.y - new_c.y == 2) {
            delete figur[c.x][c.y - 1];
            (this->*piece_l[PieceName::Rook])({ c.x,c.y - 1 }, figur[c.x][c.y]->GetPiece().color);
            delete figur[c.x][c.y - 4];
            (this->*piece_l[PieceName::None])({ c.x,c.y - 4 }, Color::None);
            MoveTo({ c.x,c.y - 4 }, { c.x,c.y - 1 }, Color::None);
        }
        (&dynamic_cast<King&>(*figur[new_c.x][new_c.y]))->Set();
        if (c.x == king_c[0].x) {
            king_c[0] = new_c;
        } else {
            king_c[1] = new_c;
        }
    }
    if (figur[c.x][c.y]->GetPiece().name == PieceName::Rook) {
        (&dynamic_cast<Rook&>(*figur[new_c.x][new_c.y]))->Set();
    }
    delete figur[c.x][c.y];
    (this->*piece_l[PieceName::None])({ c.x,c.y }, Color::None);
    ++temp;
}

void Board::Start(Coordinates coord) {
    move.clear();
    if (ChackMate()) {
        GameOver();
    }
    if (coord.x < 8 && coord.x >= 0 && game_color == figur[coord.x][coord.y]->GetPiece().color) {
        if (coord.y < 8 && coord.y >= 0 && figur[coord.x][coord.y]->GetPiece().name != PieceName::None) {
            if (figur[coord.x][coord.y]->GetPiece().color == Color::White) {
                move = figur[coord.x][coord.y]->WhereCanMove(figur, coord, king_c[0]);
            } else {
                move = figur[coord.x][coord.y]->WhereCanMove(figur, coord, king_c[1]);
            }
            for (uint i = 0; i < move.size(); i++) {
                std::cout << move[i].x << move[i].y << std::endl;
            }

        }
    }
}

void Board::Continue(Coordinates coord, Coordinates new_coord) {
    for (uint i = 0; i < move.size(); i++) {
        if ((move[i].x == new_coord.x && move[i].y == new_coord.y)) {
            MoveTo(coord, new_coord, figur[new_coord.x][new_coord.y]->GetPiece().color);
            Move(coord, new_coord);
            if (figur[new_coord.x][new_coord.y]->GetPiece().name == PieceName::Pawn) {
                if(new_coord.x == 7 || new_coord.x == 0){
                    if(temp % 2 != 1){
                        ChangePawn(new_coord, figur[new_coord.x][new_coord.y]->GetPiece().color);
                    }
                }
            }
            if (game_color == Color::White) {
                game_color = Color::Black;
            } else {
                game_color = Color::White;
            }
            break;
        }
    }
}


