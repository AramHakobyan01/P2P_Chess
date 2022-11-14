#include <vector>

#include "Figur.h"
#include "Board.h"
#include "mainwindow.h"

bool Figur::AreRookChacking(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates new_c, Coordinates king_c) {
    int count = 0;
    Color color = figur[c.x][c.y]->GetPiece().color;
    for (int i = king_c.x + 1, j = king_c.y; i < 8; i++) {
        if (i == c.x && j == c.y) {
            continue;
        }
        else if (i == new_c.x && j == new_c.y) {
            break;
        }
        if (figur[i][j]->GetPiece().color != color) {
            if (figur[i][j]->GetPiece().name == PieceName::Queen || figur[i][j]->GetPiece().name == PieceName::Rook) {
                count++;
                break;
            }else if(figur[i][j]->GetPiece().name != PieceName::None){
                break;
            }
        }else if(figur[i][j]->GetPiece().color == color) {
            break;
        }
    }
    for (int i = king_c.x - 1, j = king_c.y; i >= 0; i--) {
        if (i == c.x && j == c.y) {
            continue;
        }
        else if (i == new_c.x && j == new_c.y) {
            break;
        }
        if (figur[i][j]->GetPiece().color != color) {
            if (figur[i][j]->GetPiece().name == PieceName::Queen || figur[i][j]->GetPiece().name == PieceName::Rook) {
                count++;
                break;
            }else if(figur[i][j]->GetPiece().name != PieceName::None){
                break;
            }
        }else if(figur[i][j]->GetPiece().color == color) {
            break;
        }
    }
    for (int i = king_c.x, j = king_c.y + 1; j < 8; j++) {
        if (i == c.x && j == c.y) {
            continue;
        }
        else if (i == new_c.x && j == new_c.y) {
            break;
        }
        if (figur[i][j]->GetPiece().color != color) {
            if (figur[i][j]->GetPiece().name == PieceName::Queen || figur[i][j]->GetPiece().name == PieceName::Rook) {
                count++;
                break;
            }else if(figur[i][j]->GetPiece().name != PieceName::None){
                break;
            }
        }else if(figur[i][j]->GetPiece().color == color) {
            break;
        }
    }
    for (int i = king_c.x, j = king_c.y - 1; j >= 0; j--) {
        if (i == c.x && j == c.y) {
            continue;
        }
        else if (i == new_c.x && j == new_c.y) {
            break;
        }
        if (figur[i][j]->GetPiece().color != color) {
            if (figur[i][j]->GetPiece().name == PieceName::Queen || figur[i][j]->GetPiece().name == PieceName::Rook) {
                count++;
                break;
            }else if(figur[i][j]->GetPiece().name != PieceName::None){
                break;
            }
        }else if(figur[i][j]->GetPiece().color == color) {
            break;
        }

    }
    if (count == 0) {
        return false;
    } else {
        return true;
    }
}

bool Figur::AreBishopChacking(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates new_c, Coordinates king_c) {
    int count = 0;
    Color color = figur[c.x][c.y]->GetPiece().color;
    for (int i = king_c.x + 1, j = king_c.y + 1; j < 8 && i < 8; j++, i++) {
        if (i == c.x && j == c.y) {
            continue;
        } else if (i == new_c.x && j == new_c.y) {
            break;
        }
        if (figur[i][j]->GetPiece().color != color) {
            if (figur[i][j]->GetPiece().name == PieceName::Queen || figur[i][j]->GetPiece().name == PieceName::Bishop) {
                count++;
                break;
            }
        }
        if (figur[i][j]->GetPiece().color == color || figur[i][j]->GetPiece().name != PieceName::None) {
            break;
        }
    }
    for (int i = king_c.x - 1, j = king_c.y + 1; j < 8 && i >= 0; j++, i--) {
        if (i == c.x && j == c.y) {
            continue;
        } else if (i == new_c.x && j == new_c.y) {
            break;
        }
        if (figur[i][j]->GetPiece().color != color) {
            if (figur[i][j]->GetPiece().name == PieceName::Queen || figur[i][j]->GetPiece().name == PieceName::Bishop) {
                count++;
                break;
            }
        }
        if (figur[i][j]->GetPiece().color == color || figur[i][j]->GetPiece().name != PieceName::None) {
            break;
        }
    }
    for (int i = king_c.x + 1, j = king_c.y - 1; j >= 0 && i < 8; j--, i++) {
        if (i == c.x && j == c.y) {
            continue;
        } else if (i == new_c.x && j == new_c.y) {
            break;
        }
        if (figur[i][j]->GetPiece().color != color) {
            if (figur[i][j]->GetPiece().name == PieceName::Queen || figur[i][j]->GetPiece().name == PieceName::Bishop) {
                count++;
                break;
            }
        }
        if (figur[i][j]->GetPiece().color == color || figur[i][j]->GetPiece().name != PieceName::None) {
            break;
        }
    }
    for (int i = king_c.x - 1, j = king_c.y - 1; j >= 0 && i >= 0; j--, i--) {
        if (i == c.x && j == c.y) {
            continue;
        } else if (i == new_c.x && j == new_c.y) {
            break;
        }
        if (figur[i][j]->GetPiece().color != color) {
            if (figur[i][j]->GetPiece().name == PieceName::Queen || figur[i][j]->GetPiece().name == PieceName::Bishop) {
                count++;
                break;
            }
        }
        if (figur[i][j]->GetPiece().color == color || figur[i][j]->GetPiece().name != PieceName::None) {
            break;
        }
    }
    if (count == 0) {
        return false;
    } else {
        return true;
    }
}

bool Figur::AreKnightChacking(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates new_c, Coordinates king_c) {
    int count = 0;
    Color color = figur[c.x][c.y]->GetPiece().color;
    if (king_c.x + 1 < 8 && king_c.y + 2 < 8 && figur[king_c.x + 1][king_c.y + 2]->GetPiece().color != color && figur[king_c.x + 1][king_c.y + 2]->GetPiece().name == PieceName::Knight) {
        if (!(new_c.x == king_c.x + 1 && new_c.y == king_c.y + 2))  {
            count++;
        }
    }
    if (king_c.x - 1 >= 0 && king_c.y + 2 < 8 && figur[king_c.x - 1][king_c.y + 2]->GetPiece().color != color && figur[king_c.x - 1][king_c.y + 2]->GetPiece().name == PieceName::Knight) {
        if (!(new_c.x == king_c.x - 1 && new_c.y == king_c.y + 2)) {
            count++;
        }
    }
    if (king_c.x - 1 >= 0 && king_c.y - 2 >= 0 && figur[king_c.x - 1][king_c.y - 2]->GetPiece().color != color && figur[king_c.x - 1][king_c.y - 2]->GetPiece().name == PieceName::Knight) {
        if (!(new_c.x == king_c.x - 1 && new_c.y == king_c.y - 2)) {
            count++;
        }
    }
    if (king_c.x + 1 < 8 && king_c.y - 2 >= 0 && figur[king_c.x + 1][king_c.y - 2]->GetPiece().color != color && figur[king_c.x + 1][king_c.y - 2]->GetPiece().name == PieceName::Knight) {
        if (!(new_c.x == king_c.x + 1 && new_c.y == king_c.y - 2)) {
            count++;
        }
    }

    if (king_c.x + 2 < 8 && king_c.y + 1 < 8 && figur[king_c.x + 2][king_c.y + 1]->GetPiece().color != color && figur[king_c.x + 2][king_c.y + 1]->GetPiece().name == PieceName::Knight) {
        if (!(new_c.x == king_c.x + 2 && new_c.y == king_c.y + 1)) {
            count++;
        }
    }
    if (king_c.x - 2 >= 0 && king_c.y + 1 < 8 && figur[king_c.x - 2][king_c.y + 1]->GetPiece().color != color && figur[king_c.x - 2][king_c.y + 1]->GetPiece().name == PieceName::Knight) {
        if (!(new_c.x == king_c.x - 2 && new_c.y == king_c.y + 1)) {
            count++;
        }
    }
    if (king_c.x - 2 >= 0 && king_c.y - 1 >= 0 && figur[king_c.x - 2][king_c.y - 1]->GetPiece().color != color && figur[king_c.x - 2][king_c.y - 1]->GetPiece().name == PieceName::Knight) {
        if (!(new_c.x == king_c.x - 2 && new_c.y == king_c.y - 1)) {
            count++;
        }
    }
    if (king_c.x + 2 < 8 && king_c.y - 1 >= 0 && figur[king_c.x + 2][king_c.y - 1]->GetPiece().color != color && figur[king_c.x + 2][king_c.y - 1]->GetPiece().name == PieceName::Knight) {
        if (!(new_c.x == king_c.x + 2 && new_c.y == king_c.y - 1)) {
            count++;
        }
    }
    if (count == 0) {
        return false;
    } else {
        return true;
    }
}

bool Figur::ArePawnChacking(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates new_c, Coordinates king_c) {
    int count = 0;
    Color color = figur[c.x][c.y]->GetPiece().color;
    if (color == Color::White) {
        if (king_c.x + 1 < 8 && king_c.y + 1 < 8 && figur[king_c.x + 1][king_c.y + 1]->GetPiece().color != color && figur[king_c.x + 1][king_c.y + 1]->GetPiece().name == PieceName::Pawn) {
            if (!(new_c.x == king_c.x + 1 && new_c.y == king_c.y + 1)) {
                count++;
            }
        }
        if (king_c.x + 1 < 8 && king_c.y - 1 >= 0 && figur[king_c.x + 1][king_c.y - 1]->GetPiece().color != color && figur[king_c.x + 1][king_c.y - 1]->GetPiece().name == PieceName::Pawn) {
            if (!(new_c.x == king_c.x + 1 && new_c.y == king_c.y - 1)) {
                count++;
            }
        }

    } else if(color == Color::Black){
        if (king_c.x - 1 >= 0 && king_c.y + 1 < 8 && figur[king_c.x - 1][king_c.y + 1]->GetPiece().color != color && figur[king_c.x - 1][king_c.y + 1]->GetPiece().name == PieceName::Pawn) {
            if (!(new_c.x == king_c.x - 1 && new_c.y == king_c.y + 1)) {
                count++;
            }
        }
        if (king_c.x - 1 >= 0 && king_c.y - 1 >= 0 && figur[king_c.x - 1][king_c.y - 1]->GetPiece().color != color && figur[king_c.x - 1][king_c.y - 1]->GetPiece().name == PieceName::Pawn) {
            if (!(new_c.x == king_c.x - 1 && new_c.y == king_c.y - 1)) {
                count++;
            }
        }
    }
    if (count == 0) {
        return false;
    } else {
        return true;
    }
}

bool Figur::AreKingChacking(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates new_c, Coordinates king_c) {
    int count = 0;
    Color color = figur[c.x][c.y]->GetPiece().color;
    if (king_c.x + 1 < 8 && king_c.y + 1 < 8 && figur[king_c.x + 1][king_c.y + 1]->GetPiece().color != color && figur[king_c.x + 1][king_c.y + 1]->GetPiece().name == PieceName::King) {
        if (!(new_c.x == king_c.x + 1 && new_c.y == king_c.y + 1)) {
            count++;
        }
    }
    if (king_c.x + 1 < 8 && king_c.y - 1 >= 0 && figur[king_c.x + 1][king_c.y - 1]->GetPiece().color != color && figur[king_c.x + 1][king_c.y - 1]->GetPiece().name == PieceName::King) {
        if (!(new_c.x == king_c.x + 1 && new_c.y == king_c.y - 1)) {
            count++;
        }
    }

    if (king_c.x - 1 >= 0 && king_c.y + 1 < 8 && figur[king_c.x - 1][king_c.y + 1]->GetPiece().color != color && figur[king_c.x - 1][king_c.y + 1]->GetPiece().name == PieceName::King) {
        if (!(new_c.x == king_c.x - 1 && new_c.y == king_c.y + 1)) {
            count++;
        }
    }
    if (king_c.x - 1 >= 0 && king_c.y - 1 >= 0 && figur[king_c.x - 1][king_c.y - 1]->GetPiece().color != color && figur[king_c.x - 1][king_c.y - 1]->GetPiece().name == PieceName::King) {
        if (!(new_c.x == king_c.x - 1 && new_c.y == king_c.y - 1)) {
            count++;
        }
    }
    if (king_c.x + 1 < 8 && figur[king_c.x + 1][king_c.y]->GetPiece().color != color && figur[king_c.x + 1][king_c.y]->GetPiece().name == PieceName::King) {
        if (!(new_c.x == king_c.x + 1)) {
            count++;
        }
    }
    if (king_c.y - 1 >= 0 && figur[king_c.x][king_c.y - 1]->GetPiece().color != color && figur[king_c.x][king_c.y - 1]->GetPiece().name == PieceName::King) {
        if (!(new_c.y == king_c.y - 1)) {
            count++;
        }
    }

    if (king_c.x - 1 >= 0 && figur[king_c.x - 1][king_c.y]->GetPiece().color != color && figur[king_c.x - 1][king_c.y]->GetPiece().name == PieceName::King) {
        if (!(new_c.x == king_c.x - 1)) {
            count++;
        }
    }
    if (king_c.y - 1 >= 0 && figur[king_c.x][king_c.y - 1]->GetPiece().color != color && figur[king_c.x][king_c.y - 1]->GetPiece().name == PieceName::King) {
        if (!(new_c.y == king_c.y - 1)) {
            count++;
        }
    }
    if (count == 0) {
        return false;
    } else {
        return true;
    }
}

bool Figur::AreChacking(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates new_c, Coordinates king_c) {
    if (AreRookChacking(figur, c, new_c, king_c)) {
        return true;
    }
    if (AreBishopChacking(figur, c, new_c, king_c)) {
        return true;
    }
    if (AreKnightChacking(figur, c, new_c, king_c)) {
        return true;
    }
    if (ArePawnChacking(figur, c, new_c, king_c)) {
        return true;
    }
    if (AreKingChacking(figur, c, new_c, king_c)) {
        return true;
    }
    return false;
}

void Board::CreatePawn(Coordinates c, Color color) {
    if (figur[c.x].size() < 8) {
        figur[c.x].push_back(new Pawn(color));
        CreateButton(figur, c);
    }
    else {
        figur[c.x][c.y] = new Pawn(color);
    }
}

void Board::CreateKnight(Coordinates c, Color color) {
    if (figur[c.x].size() < 8) {
        figur[c.x].push_back(new Knight(color));
        CreateButton(figur, c);
    }
    else {
        figur[c.x][c.y] = new Knight(color);
    }
}

void Board::CreateBishop(Coordinates c, Color color) {
    if (figur[c.x].size() < 8) {
        figur[c.x].push_back(new Bishop(color));
        CreateButton(figur, c);
    }
    else {
        figur[c.x][c.y] = new Bishop(color);
    }
}

void Board::CreateRook(Coordinates c, Color color) {
    if (figur[c.x].size() < 8) {
        figur[c.x].push_back(new Rook(color));
        CreateButton(figur, c);
    }
    else {
        figur[c.x][c.y] = new Rook(color);
    }
}

void Board::CreateKing(Coordinates c, Color color) {
    if (figur[c.x].size() < 8) {
        figur[c.x].push_back(new King(color));
        CreateButton(figur, c);
    }
    else {
        figur[c.x][c.y] = new King(color);
    }
}
void Board::CreateQueen(Coordinates c, Color color) {
    if (figur[c.x].size() < 8) {
        figur[c.x].push_back(new Queen(color));
        CreateButton(figur, c);
    }
    else {
        figur[c.x][c.y] = new Queen(color);
    }
}

void Board::CreateNone(Coordinates c, Color) {
    if (figur[c.x].size() < 8) {
        figur[c.x].push_back(new None());
        CreateButton(figur, c);
    }
    else {
        figur[c.x][c.y] = new None();
    }
}

bool Board::ChackMate() {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (figur[i][j]->GetPiece().color == Color::White && game_color == Color::White) {
                if (!figur[i][j]->WhereCanMove(figur, { i,j }, king_c[0]).empty()) {
                    count++;
                }
            } else if (figur[i][j]->GetPiece().color == Color::Black && game_color == Color::Black) {
                if (!figur[i][j]->WhereCanMove(figur, { i,j }, king_c[1]).empty()) {
                    count++;
                }
            }
        }
    }
    if (count == 0) {
        return true;
    }
    else {
        return false;
    }
}
