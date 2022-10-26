#include <vector>

#include "Figur.h"

Piece Figur::GetPiece() {
    return piece;
}

QString Figur::GetPath() {
    return path;
}

Pawn::Pawn(Color color) {
    piece = { color, PieceName::Pawn };
    if (color == Color::White) {
        path = ":/image/Pawn1.png";
    } else {
        path = ":/image/Pawn.png";
    }
    first = false;
}

bool Pawn::Get() {
    return first;
}

void Pawn::Set() {
    first = true;

}

Knight::Knight(Color color) {
    piece = { color, PieceName::Knight };
    if (color == Color::White) {
        path = ":/image/Knight1.png";
    } else {
        path = ":/image/Knight.png";
    }
}

Bishop::Bishop(Color color) {
    piece = { color, PieceName::Bishop };
    if (color == Color::White) {
        path = ":/image/Bishop1.png";
    } else {
        path = ":/image/Bishop.png";
    }
}

Rook::Rook(Color color) {
    piece = { color, PieceName::Rook };
    if (color == Color::White) {
        path = ":/image/Rook1.png";
    } else {
        path = ":/image/Rook.png";
    }
    move = true;
}
bool Rook::Get() {
    return move;
}

void Rook::Set() {
    move = false;

}

Queen::Queen(Color color) {
    piece = { color, PieceName::Queen };
    if(color == Color::White){
        path = ":/image/Queen1.png";
    }else{
        path = ":/image/Queen.png";
    }
}

King::King(Color color) {
    piece = { color, PieceName::King };
    if(color == Color::White){
        path = ":/image/King1.png";
    }else{
        path = ":/image/King.png";
    }
    move = true;
}

bool King::Get() {
    return move;
}

void King::Set() {
    move = false;
}

None::None() {
    piece = { Color::None, PieceName::None };
}

std::vector<Coordinates> None::WhereCanMove(std::vector<std::vector<Figur*>>&, Coordinates, Coordinates) {
    return {};
}

std::vector<Coordinates> Pawn::WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) {
    std::vector<Coordinates> pawnMove;
    if (figur[c.x][c.y]->GetPiece().color == Color::White) {
        if (c.x == 1) {
            if (figur[c.x + 2][c.y]->GetPiece().name == PieceName::None && figur[c.x + 1][c.y]->GetPiece().name == PieceName::None) {
                if (!AreChacking(figur, c, { c.x + 2,c.y }, king_c)) {

                    pawnMove.push_back({ c.x + 2,c.y });
                }
            }
        }
        if (c.x + 1 < 8 && figur[c.x + 1][c.y]->GetPiece().name == PieceName::None) {
            if (!AreChacking(figur, c, { c.x + 1,c.y }, king_c)) {
                pawnMove.push_back({ c.x + 1,c.y });
            }
        }
        if (c.y - 1 >= 0 && c.x + 1 < 8 && figur[c.x + 1][c.y - 1]->GetPiece().name != PieceName::None && figur[c.x + 1][c.y - 1]->GetPiece().color == Color::Black) {
            if (!AreChacking(figur, c, { c.x + 1,c.y - 1 }, king_c)) {
                pawnMove.push_back({ c.x + 1,c.y - 1 });
            }
        }
        if (c.y + 1 < 8 && c.x + 1 < 8 && figur[c.x + 1][c.y + 1]->GetPiece().name != PieceName::None && figur[c.x + 1][c.y + 1]->GetPiece().color == Color::Black) {
            if (!AreChacking(figur, c, { c.x + 1,c.y + 1 }, king_c)) {
                pawnMove.push_back({ c.x + 1,c.y + 1 });
            }
        }
    } else if (figur[c.x][c.y]->GetPiece().color == Color::Black) {
        if (c.x == 6) {
            if (figur[c.x - 2][c.y]->GetPiece().name == PieceName::None && figur[c.x - 1][c.y]->GetPiece().name == PieceName::None) {
                if (!AreChacking(figur, c, { c.x - 2,c.y }, king_c)) {
                    pawnMove.push_back({ c.x - 2,c.y });
                }
            }
        }
        if (c.x - 1 >= 0 && figur[c.x - 1][c.y]->GetPiece().name == PieceName::None) {
            if (!AreChacking(figur, c, { c.x - 1,c.y }, king_c)) {
                pawnMove.push_back({ c.x - 1,c.y });
            }
        }
        if (c.x - 1 >= 0 && c.y - 1 >= 0 && figur[c.x - 1][c.y - 1]->GetPiece().name != PieceName::None && figur[c.x - 1][c.y - 1]->GetPiece().color == Color::White) {
            if (!AreChacking(figur, c, { c.x - 1,c.y - 1 }, king_c)) {
                pawnMove.push_back({ c.x - 1,c.y - 1 });
            }
        }
        if (c.x - 1 >= 0 && c.y + 1 < 8 && figur[c.x - 1][c.y + 1]->GetPiece().name != PieceName::None && figur[c.x - 1][c.y + 1]->GetPiece().color == Color::White) {
            if (!AreChacking(figur, c, { c.x - 1,c.y + 1 }, king_c)) {
                pawnMove.push_back({ c.x - 1,c.y + 1 });
            }
        }
    }
    if (figur[c.x][c.y]->GetPiece().color == Color::White) {
        if (c.y + 1 < 8 &&
                figur[c.x][c.y + 1]->GetPiece().name == PieceName::Pawn &&
                figur[c.x][c.y + 1]->GetPiece().color != figur[c.x][c.y]->GetPiece().color &&
                (&dynamic_cast<Pawn&>(*figur[c.x][c.y + 1]))->Get()) {
            pawnMove.push_back({ c.x + 1, c.y + 1 });
        }
        if (c.y - 1 >= 0 &&
                figur[c.x][c.y - 1]->GetPiece().name == PieceName::Pawn &&
                figur[c.x][c.y - 1]->GetPiece().color != figur[c.x][c.y]->GetPiece().color &&
                (&dynamic_cast<Pawn&>(*figur[c.x][c.y - 1]))->Get()) {
            pawnMove.push_back({ c.x + 1, c.y - 1 });
        }
    } else if (figur[c.x][c.y]->GetPiece().color == Color::Black) {
        if (c.y + 1 < 8 &&
                figur[c.x][c.y + 1]->GetPiece().name == PieceName::Pawn &&
                figur[c.x][c.y + 1]->GetPiece().color != figur[c.x][c.y]->GetPiece().color && (&dynamic_cast<Pawn&>(*figur[c.x][c.y + 1]))->Get()) {
            pawnMove.push_back({ c.x - 1, c.y + 1 });
        } else if (c.y - 1 >= 0 &&
                 figur[c.x][c.y - 1]->GetPiece().name == PieceName::Pawn &&
                 figur[c.x][c.y - 1]->GetPiece().color != figur[c.x][c.y]->GetPiece().color && (&dynamic_cast<Pawn&>(*figur[c.x][c.y - 1]))->Get()) {
            pawnMove.push_back({ c.x - 1, c.y - 1 });
        }
    }
    return pawnMove;
}

std::vector<Coordinates> Knight::WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) {
    std::vector<Coordinates> knightMove;
    if(c.x + 1 < 8 && c.y + 2 < 8 && figur[c.x][c.y]->GetPiece().color != figur[c.x + 1][c.y + 2]->GetPiece().color){
        if (!AreChacking(figur, c, { c.x + 1,c.y + 2 }, king_c)) {
            knightMove.push_back({ c.x + 1,c.y + 2 });
        }
    }
    if (c.x + 1 < 8 && c.y - 2 >= 0 && figur[c.x][c.y]->GetPiece().color != figur[c.x + 1][c.y - 2]->GetPiece().color ) {
        if (!AreChacking(figur, c, { c.x + 1,c.y - 2 }, king_c)) {
            knightMove.push_back({ c.x + 1,c.y - 2 });
        }
    }
    if (c.x - 1 >= 0 && c.y + 2 < 8 && figur[c.x][c.y]->GetPiece().color != figur[c.x - 1][c.y + 2]->GetPiece().color ) {
        if (!AreChacking(figur, c, { c.x - 1,c.y + 2 }, king_c)) {
            knightMove.push_back({ c.x - 1,c.y + 2 });
        }
    }
    if (c.x - 1 >= 0 && c.y - 2 >= 0 && figur[c.x][c.y]->GetPiece().color != figur[c.x - 1][c.y - 2]->GetPiece().color) {
        if (!AreChacking(figur, c, { c.x - 1,c.y - 2 }, king_c)) {
            knightMove.push_back({ c.x - 1,c.y - 2 });
        }
    }
    if (c.x + 2 < 8 && c.y + 1 < 8 && figur[c.x][c.y]->GetPiece().color != figur[c.x + 2][c.y + 1]->GetPiece().color ) {
        if (!AreChacking(figur, c, { c.x + 2,c.y + 1 }, king_c)) {
            knightMove.push_back({ c.x + 2,c.y + 1 });
        }
    }
    if (c.x + 2 < 8 && c.y - 1 >= 0 && figur[c.x][c.y]->GetPiece().color != figur[c.x + 2][c.y - 1]->GetPiece().color ) {
        if (!AreChacking(figur, c, { c.x + 2,c.y - 1 }, king_c)) {
            knightMove.push_back({ c.x + 2,c.y - 1 });
        }
    }
    if (c.x - 2 >= 0 && c.y + 1 < 8 && figur[c.x][c.y]->GetPiece().color != figur[c.x - 2][c.y + 1]->GetPiece().color) {
        if (!AreChacking(figur, c, { c.x - 2,c.y + 1 }, king_c)) {
            knightMove.push_back({ c.x - 2,c.y + 1 });
        }
    }
    if (c.x - 2 >= 0 && c.y - 1 >= 0 && figur[c.x][c.y]->GetPiece().color != figur[c.x - 2][c.y - 1]->GetPiece().color ) {
        if (!AreChacking(figur, c, { c.x - 2,c.y - 1 }, king_c)) {
            knightMove.push_back({ c.x - 2,c.y - 1 });
        }
    }
    return knightMove;
}

std::vector<Coordinates> Bishop::WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) {
    std::vector<Coordinates> bishopMove;
    for (int i = c.x + 1, j = c.y + 1; i < 8 && j < 8; i++, j++) {
        if (figur[c.x][c.y]->GetPiece().color != figur[i][j]->GetPiece().color) {
            if(!AreChacking(figur, c, { i,j }, king_c)){
                if (figur[i][j]->GetPiece().color != Color::None) {
                    bishopMove.push_back({ i,j });
                    break;
                } else {
                    bishopMove.push_back({ i,j });
                }
            }
        } else {
            break;
        }
    }
    for (int i = c.x + 1, j = c.y - 1; i < 8 && j >= 0; i++, j--) {
        if (figur[c.x][c.y]->GetPiece().color != figur[i][j]->GetPiece().color) {
            if (!AreChacking(figur, c, { i,j }, king_c)) {
                if (figur[i][j]->GetPiece().color != Color::None) {
                    bishopMove.push_back({ i,j });
                    break;
                } else {
                    bishopMove.push_back({ i,j });
                }
            }
        } else {
            break;
        }
    }
    for (int i = c.x - 1, j = c.y + 1; i >= 0 && j < 8; i--, j++) {
        if (figur[c.x][c.y]->GetPiece().color != figur[i][j]->GetPiece().color) {
            if (!AreChacking(figur, c, { i,j }, king_c)) {
                if (figur[i][j]->GetPiece().color != Color::None) {
                    bishopMove.push_back({ i,j });
                    break;
                } else {
                    bishopMove.push_back({ i,j });
                }
            }
        } else {
            break;
        }
    }
    for (int i = c.x - 1, j = c.y - 1; i >= 0 && j >= 0; i--, j--) {
        if (figur[c.x][c.y]->GetPiece().color != figur[i][j]->GetPiece().color) {
            if (!AreChacking(figur, c, { i,j }, king_c)) {
                if (figur[i][j]->GetPiece().color != Color::None) {
                    bishopMove.push_back({ i,j });
                    break;
                } else {
                    bishopMove.push_back({ i,j });
                }
            }
        } else {
            break;
        }
    }
    return bishopMove;
}

std::vector<Coordinates> Rook::WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) {
    std::vector<Coordinates> rookMove;
    for (int i = c.x + 1, j = c.y; i < 8; i++) {
        if (figur[c.x][c.y]->GetPiece().color != figur[i][j]->GetPiece().color) {
            if (!AreChacking(figur, c, { i,j }, king_c)) {
                if (figur[i][j]->GetPiece().color != Color::None) {
                    rookMove.push_back({ i,j });
                    break;
                } else {
                    rookMove.push_back({ i,j });
                }
            }
        } else {
            break;
        }
    }
    for (int i = c.x - 1, j = c.y; i >= 0; i--) {
        if (figur[c.x][c.y]->GetPiece().color != figur[i][j]->GetPiece().color) {
            if (!AreChacking(figur, c, { i,j }, king_c)) {
                if (figur[i][j]->GetPiece().color != Color::None) {
                    rookMove.push_back({ i,j });
                    break;
                } else {
                    rookMove.push_back({ i,j });
                }
            }
        } else {
            break;
        }
    }
    for (int i = c.x, j = c.y + 1; j < 8; j++) {
        if (figur[c.x][c.y]->GetPiece().color != figur[i][j]->GetPiece().color) {
            if (!AreChacking(figur, c, { i,j }, king_c)) {
                if (figur[i][j]->GetPiece().color != Color::None) {
                    rookMove.push_back({ i,j });
                    break;
                } else {
                    rookMove.push_back({ i,j });
                }
            }
        } else {
            break;
        }
    }
    for (int i = c.x, j = c.y - 1; j >= 0; j--) {
        if (figur[c.x][c.y]->GetPiece().color != figur[i][j]->GetPiece().color) {
            if (!AreChacking(figur, c, { i,j }, king_c)) {
                if (figur[i][j]->GetPiece().color != Color::None) {
                    rookMove.push_back({ i,j });
                    break;
                } else {
                    rookMove.push_back({ i,j });
                }
            }
        } else {
            break;
        }
    }
    return rookMove;
}

std::vector<Coordinates> Queen::WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates king_c) {
    std::vector<Coordinates> queenMove = Rook::WhereCanMove(figur, c, king_c);
    std::vector<Coordinates> bishop = Bishop::WhereCanMove(figur, c, king_c);
    queenMove.insert(queenMove.end(), bishop.begin(), bishop.end());
    return queenMove;
}

std::vector<Coordinates> King::WhereCanMove(std::vector<std::vector<Figur*>>& figur, Coordinates c, Coordinates) {
    std::vector<Coordinates> kingMove;
    if (c.x + 1 < 8 && figur[c.x][c.y]->GetPiece().color != figur[c.x + 1][c.y]->GetPiece().color) {
        if (!AreChacking(figur, c, { c.x + 1,c.y }, { c.x + 1,c.y })) {
            kingMove.push_back({ c.x + 1,c.y });
        }
    }
    if (c.y + 1 < 8 && figur[c.x][c.y]->GetPiece().color != figur[c.x][c.y + 1]->GetPiece().color) {
        if (!AreChacking(figur, c, { c.x,c.y + 1 }, { c.x,c.y + 1 })) {
            kingMove.push_back({ c.x,c.y + 1 });
        }
    }
    if (c.x - 1 >= 0 && figur[c.x][c.y]->GetPiece().color != figur[c.x - 1][c.y]->GetPiece().color ) {
        if (!AreChacking(figur, c, { c.x - 1,c.y }, { c.x - 1,c.y })) {
            kingMove.push_back({ c.x - 1,c.y });
        }
    }
    if (c.y - 1 >= 0 && figur[c.x][c.y]->GetPiece().color != figur[c.x][c.y - 1]->GetPiece().color ) {
        if (!AreChacking(figur, c, { c.x,c.y - 1 }, { c.x,c.y - 1 })) {
            kingMove.push_back({ c.x,c.y - 1 });
        }
    }
    if (c.x + 1 < 8 && c.y + 1 < 8 && figur[c.x][c.y]->GetPiece().color != figur[c.x + 1][c.y + 1]->GetPiece().color) {
        if (!AreChacking(figur, c, { c.x + 1,c.y + 1 }, { c.x + 1,c.y + 1 })) {
            kingMove.push_back({ c.x + 1,c.y + 1 });
        }
    }
    if (c.x + 1 < 8 && c.y - 1 >= 0 && figur[c.x][c.y]->GetPiece().color != figur[c.x + 1][c.y - 1]->GetPiece().color ) {
        if (!AreChacking(figur, c, { c.x + 1,c.y - 1 }, { c.x + 1,c.y - 1 })) {
            kingMove.push_back({ c.x + 1,c.y - 1 });
        }
    }
    if (c.x - 1 >= 0 && c.y + 1 < 8 && figur[c.x][c.y]->GetPiece().color != figur[c.x - 1][c.y + 1]->GetPiece().color ) {
        if (!AreChacking(figur, c, { c.x - 1,c.y + 1 }, { c.x - 1,c.y + 1 })) {
            kingMove.push_back({ c.x - 1,c.y + 1 });
        }
    }
    if (c.x - 1 >= 0 && c.y - 1 >= 0 && figur[c.x][c.y]->GetPiece().color != figur[c.x - 1][c.y - 1]->GetPiece().color) {
        if (!AreChacking(figur, c, { c.x - 1,c.y - 1 }, { c.x - 1,c.y - 1 })) {
            kingMove.push_back({ c.x - 1,c.y - 1 });
        }
    }
    if ((c.x == 0 || c.x == 7) && c.y == 4 && (&dynamic_cast<King&>(*figur[c.x][c.y]))->Get()) {
        if (figur[c.x][c.y - 1]->GetPiece().name == PieceName::None && figur[c.x][c.y - 2]->GetPiece().name == PieceName::None && figur[c.x][c.y - 3]->GetPiece().name == PieceName::None) {
            if (figur[c.x][c.y - 4]->GetPiece().name == PieceName::Rook && (&dynamic_cast<Rook&>(*figur[c.x][c.y - 4]))->Get()) {
                if (!AreChacking(figur, c, { c.x,c.y - 1 }, { c.x,c.y - 1 }) && !AreChacking(figur, c, { c.x,c.y - 2 }, { c.x,c.y - 2 })) {
                    kingMove.push_back({ c.x ,c.y - 2 });
                }
            }
        }
        if (figur[c.x][c.y + 1]->GetPiece().name == PieceName::None && figur[c.x][c.y + 2]->GetPiece().name == PieceName::None) {
            if (figur[c.x][c.y + 3]->GetPiece().name == PieceName::Rook && (&dynamic_cast<Rook&>(*figur[c.x][c.y + 3]))->Get()) {
                if (!AreChacking(figur, c, { c.x,c.y + 1 }, { c.x,c.y + 1 }) && !AreChacking(figur, c, { c.x,c.y + 2 }, { c.x,c.y + 2 })) {
                    kingMove.push_back({ c.x ,c.y + 2 });
                }
            }
        }
    }
    return kingMove;
}
