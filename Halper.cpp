#include "Halper.h"
vector<Figur>::iterator Halper::CheckCoordinates(Coordinates coordinates) {
	for (vector<Figur>::iterator a = White.begin(); a != White.end(); a++) {
		if ((*a).coordinates.x == coordinates.x && (*a).coordinates.y == coordinates.y) {
			return a;
		}
	}
	for (vector<Figur>::iterator a = Black.begin(); a != Black.end(); a++) {
		if ((*a).coordinates.x == coordinates.x && (*a).coordinates.y == coordinates.y) {
			return a;
		}
	}
	return none.begin();
}
bool Halper::CanPawnMove(vector<Figur>::iterator pawn, Coordinates new_coordinates) {
	if ((*pawn).coordinates.y == new_coordinates.y) {
		if ((*pawn).piece.color == true) {
			if ((*pawn).coordinates.x - new_coordinates.x == -1) {
				return true;
			}
			else if ((*pawn).coordinates.x - new_coordinates.x == -2) {
				if ((*pawn).coordinates.x == 1) {
					return true;
				}
			}
		}
		else {
			if ((*pawn).coordinates.x - new_coordinates.x == 1) {
				return true;
			}
			else if ((*pawn).coordinates.x - new_coordinates.x == 2) {
				if ((*pawn).coordinates.x == 6) {
					return true;
				}
			}
		}
	}
	return false;
}
bool Halper::CanPawnEat(vector<Figur>::iterator pawn, Coordinates new_coordinates) {
	if ((*CheckCoordinates(new_coordinates)).piece.name != None) {
		if ((*pawn).coordinates.x - new_coordinates.x == -1) {
			if ((*pawn).piece.color == true) {
				if (abs((*pawn).coordinates.y - new_coordinates.y) == 1) {
					return true;
				}
			}
		}
		else if ((*pawn).coordinates.x - new_coordinates.x == 1) {
			if ((*pawn).piece.color == false) {
				if (abs((*pawn).coordinates.y - new_coordinates.y) == 1) {
					return true;
				}
			}
		}
	}
	return false;
}
bool Halper::CanKnightMove(vector<Figur>::iterator knight, Coordinates new_coordinates) {
	if (abs((*knight).coordinates.x - new_coordinates.x) == 1) {
		if (abs((*knight).coordinates.y - new_coordinates.y) == 2)
			return true;
	}
	else if (abs((*knight).coordinates.x - new_coordinates.x) == 2) {
		if (abs((*knight).coordinates.y - new_coordinates.y) == 1)
			return true;
	}
	return false;
}
bool Halper::CanBishopMove(vector<Figur>::iterator bishop, Coordinates new_coordinates) {
	if (abs((*bishop).coordinates.x - new_coordinates.x) == abs((*bishop).coordinates.y - new_coordinates.y)) {
		int count = 0;

		if ((*bishop).coordinates.x > new_coordinates.x) {
			if ((*bishop).coordinates.y > new_coordinates.y) {
				for (int i = (*bishop).coordinates.x - 1, j = (*bishop).coordinates.y - 1; i > new_coordinates.x; i--, j--) {
					if ((*CheckCoordinates({ i,j })).piece.name != None) {
						count++;
						break;
					}
				}
			}
			else {
				for (int i = (*bishop).coordinates.x - 1, j = (*bishop).coordinates.y + 1; i > new_coordinates.x; i--, j++) {
					if ((*CheckCoordinates({ i,j })).piece.name != None) {
						count++;
						break;
					}
				}
			}
		}
		else {
			if ((*bishop).coordinates.y > new_coordinates.y) {
				for (int i = (*bishop).coordinates.x + 1, j = (*bishop).coordinates.y - 1; i < new_coordinates.x; i++, j--) {
					if ((*CheckCoordinates({ i,j })).piece.name != None) {
						count++;
						break;
					}
				}
			}
			else {
				for (int i = (*bishop).coordinates.x + 1, j = (*bishop).coordinates.y + 1; i < new_coordinates.x; i++, j++) {
					if ((*CheckCoordinates({ i,j })).piece.name != None) {
						count++;
						break;
					}
				}
			}
		}
		if (count == 0)
			return true;
	}
	return false;
}
bool Halper::CanRookMove(vector<Figur>::iterator rook, Coordinates new_coordinates) {
	int count = 0;
	if ((*rook).coordinates.y == new_coordinates.y) {
		if ((*rook).coordinates.x > new_coordinates.x) {
			for (int i = (*rook).coordinates.x - 1, j = (*rook).coordinates.y; i > new_coordinates.x; i--) {
				if ((*CheckCoordinates({ i,j })).piece.name != None) {
					count++;
					break;
				}
			}
		}
		else {
			for (int i = (*rook).coordinates.x + 1, j = (*rook).coordinates.y; i < new_coordinates.x; i++) {
				if ((*CheckCoordinates({ i,j })).piece.name != None) {
					count++;
					break;
				}
			}
		}
	}
	else {
		if ((*rook).coordinates.y > new_coordinates.y) {
			for (int i = (*rook).coordinates.x, j = (*rook).coordinates.y - 1; j > new_coordinates.y; j--) {
				if ((*CheckCoordinates({ i,j })).piece.name != None) {
					count++;
					break;
				}
			}
		}
		else {
			for (int i = (*rook).coordinates.x, j = (*rook).coordinates.y + 1; j < new_coordinates.x; j++) {
				if ((*CheckCoordinates({ i,j })).piece.name != None) {
					count++;
					break;
				}
			}
		}
	}
	if (count == 0)
		return true;
	else
		return false;
}
bool Halper::CanQueenMove(vector<Figur>::iterator queen, Coordinates new_coordinates) {
	if (CanBishopMove(queen, new_coordinates) || CanRookMove(queen, new_coordinates)) {
		return true;
	}
	else {
		return false;
	}
}
bool Halper::CanKingMove(vector<Figur>::iterator king, Coordinates new_coordinates) {
	if (abs((*king).coordinates.x - new_coordinates.x) == 1 && (*king).coordinates.y == new_coordinates.y) {
		return true;
	}
	else if (abs((*king).coordinates.y - new_coordinates.y) == 1 && (*king).coordinates.x == new_coordinates.x) {
		return true;
	}
	else if (abs((*king).coordinates.x - new_coordinates.x) == 1 && abs((*king).coordinates.y - new_coordinates.y) == 1) {
		return true;
	}
	return false;
}
bool Halper::Check(vector<Figur>::iterator king, Coordinates coordinates) {
	for (int i = coordinates.x + 1, j = coordinates.y; i < 8; i++) {
		auto piece = CheckCoordinates({ i,j });
		if ((*piece).piece.name == Queen || (*piece).piece.name == Rook) {
			if ((*piece).piece.color != (*king).piece.color) {
				return true;
			}
			else
				break;
		}
		else if ((*piece).piece.name != None) {
			break;
		}
	}
	for (int i = coordinates.x - 1, j = coordinates.y; i >= 0; i--) {
		auto piece = CheckCoordinates({ i,j });
		if ((*piece).piece.name == Queen || (*piece).piece.name == Rook) {
			if ((*piece).piece.color != (*king).piece.color) {
				return true;
			}
			else
				break;
		}
		else if ((*piece).piece.name != None) {
			break;
		}
	}
	for (int i = coordinates.x, j = coordinates.y + 1; j < 8; j++) {
		auto piece = CheckCoordinates({ i,j });
		if ((*piece).piece.name == Queen || (*piece).piece.name == Rook) {
			if ((*piece).piece.color != (*king).piece.color) {
				return true;
			}
			else
				break;
		}
		else if ((*piece).piece.name != None) {
			break;
		}
	}
	for (int i = coordinates.x, j = coordinates.y - 1; j >= 0; j--) {
		auto piece = CheckCoordinates({ i,j });
		if ((*piece).piece.name == Queen || (*piece).piece.name == Rook) {
			if ((*piece).piece.color != (*king).piece.color) {
				return true;
			}
			else
				break;
		}
		else if ((*piece).piece.name != None) {
			break;
		}
	}
	for (int i = coordinates.x - 1, j = coordinates.y - 1; j >= 0; j--, i--) {
		auto piece = CheckCoordinates({ i,j });
		if ((*piece).piece.name == Queen || (*piece).piece.name == Bishop) {
			if ((*piece).piece.color != (*king).piece.color) {
				return true;
			}
			else
				break;
		}
		else if ((*piece).piece.name != None) {
			break;
		}
	}
	for (int i = coordinates.x + 1, j = coordinates.y + 1; j < 8; j++, i++) {
		auto piece = CheckCoordinates({ i,j });
		if ((*piece).piece.name == Queen || (*piece).piece.name == Bishop) {
			if ((*piece).piece.color != (*king).piece.color) {
				return true;
			}
			else
				break;
		}
		else if ((*piece).piece.name != None) {
			break;
		}
	}
	for (int i = coordinates.x + 1, j = coordinates.y - 1; j >= 0; j--, i++) {
		auto piece = CheckCoordinates({ i,j });
		if ((*piece).piece.name == Queen || (*piece).piece.name == Bishop) {
			if ((*piece).piece.color != (*king).piece.color) {
				return true;
			}
			else
				break;
		}
		else if ((*piece).piece.name != None) {
			break;
		}
	}
	for (int i = coordinates.x - 1, j = coordinates.y + 1; i >= 0; j++, i--) {
		auto piece = CheckCoordinates({ i,j });
		if ((*piece).piece.name == Queen || (*piece).piece.name == Bishop) {
			if ((*piece).piece.color != (*king).piece.color) {
				return true;
			}
			else
				break;
		}
		else if ((*piece).piece.name != None) {
			break;
		}
	}
	auto piece = CheckCoordinates({ coordinates.x + 2,coordinates.y + 1 });
	if ((*piece).piece.name == Knight) {
		if ((*piece).piece.color != (*king).piece.color) {
			return true;
		}
	}
	piece = CheckCoordinates({ coordinates.x + 2,coordinates.y - 1 });
	if ((*piece).piece.name == Knight) {
		if ((*piece).piece.color != (*king).piece.color) {
			return true;
		}
	}
	piece = CheckCoordinates({ coordinates.x + 1,coordinates.y + 2 });
	if ((*piece).piece.name == Knight) {
		if ((*piece).piece.color != (*king).piece.color) {
			return true;
		}
	}
	piece = CheckCoordinates({ coordinates.x + 1,coordinates.y - 2 });
	if ((*piece).piece.name == Knight) {
		if ((*piece).piece.color != (*king).piece.color) {
			return true;
		}
	}
	piece = CheckCoordinates({ coordinates.x - 1,coordinates.y + 2 });
	if ((*piece).piece.name == Knight) {
		if ((*piece).piece.color != (*king).piece.color) {
			return true;
		}
	}
	piece = CheckCoordinates({ coordinates.x - 1,coordinates.y - 2 });
	if ((*piece).piece.name == Knight) {
		if ((*piece).piece.color != (*king).piece.color) {
			return true;
		}
	}
	piece = CheckCoordinates({ coordinates.x - 2,coordinates.y - 1 });
	if ((*piece).piece.name == Knight) {
		if ((*piece).piece.color != (*king).piece.color) {
			return true;
		}
	}
	piece = CheckCoordinates({ coordinates.x - 2,coordinates.y + 1 });
	if ((*piece).piece.name == Knight) {
		if ((*piece).piece.color != (*king).piece.color) {
			return true;
		}
	}
	return false;
}
bool Halper::AreChacking(bool game_color) {
	if (game_color) {
		auto king = White.begin();
		for (; king != White.end(); king++) {
			if ((*king).piece.name == King) {
				return Check(king, (*king).coordinates);
			}
		}
	}
	else {
		auto king = Black.begin();
		for (; king != Black.end(); king++) {
			if ((*king).piece.name == King) {
				return Check(king, (*king).coordinates);
			}
		}
	}
	return false;

}
vector<Coordinates> Halper::WhereCanMove(Coordinates coordinates, bool game_color) {
	vector<Coordinates> move;
	vector<Figur>::iterator figur = CheckCoordinates(coordinates);
	vector<Figur>::iterator count;
	switch ((*figur).piece.name)
	{
	case Pawn:
		if (!AreChacking(game_color)) {
			*figur = { {game_color,Pawn},{coordinates.x,coordinates.y + 1} };
			if (!AreChacking(game_color)) {
				*figur = { {game_color,Pawn},{coordinates.x,coordinates.y } };
				if (game_color) {
					for (int i = coordinates.x + 1, j = coordinates.y; i < coordinates.x + 3; i++) {
						if (CanPawnMove(figur, { i,j }))
							move.push_back({ i,j });
					}
					if (!(*CheckCoordinates({ coordinates.x + 1,coordinates.y + 1 })).piece.color) {
						move.push_back({ coordinates.x + 1,coordinates.y + 1 });
					}
					else if (!(*CheckCoordinates({ coordinates.x + 1,coordinates.y - 1 })).piece.color) {
						move.push_back({ coordinates.x + 1,coordinates.y - 1 });
					}
				}
				else {
					for (int i = coordinates.x - 1, j = coordinates.y; i > coordinates.x - 3; i--) {
						if (CanPawnMove(figur, { i,j }))
							move.push_back({ i,j });
					}
					if ((*CheckCoordinates({ coordinates.x - 1,coordinates.y + 1 })).piece.color) {
						move.push_back({ coordinates.x - 1,coordinates.y + 1 });
					}
					else if ((*CheckCoordinates({ coordinates.x - 1,coordinates.y - 1 })).piece.color) {
						move.push_back({ coordinates.x - 1,coordinates.y - 1 });
					}
				}
			}
		}
		break;
	case Knight:
		count = CheckCoordinates({ coordinates.x + 2,coordinates.y + 1 });
		if ((*count).piece.name == None) {
			*figur = { {game_color,Knight},{coordinates.x + 2,coordinates.y + 1} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x + 2,coordinates.y + 1 });
			}
		}
		else {
			Erase(count);
			*figur = { {game_color,Knight},{coordinates.x + 2,coordinates.y + 1} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x + 2,coordinates.y + 1 });
			}
			NotErase(count);
		}
		count = CheckCoordinates({ coordinates.x + 2,coordinates.y - 1 });
		if ((*count).piece.name == None) {
			*figur = { {game_color,Knight},{coordinates.x + 2,coordinates.y - 1} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x + 2,coordinates.y - 1 });
			}
		}
		else {
			Erase(count);
			*figur = { {game_color,Knight},{coordinates.x + 2,coordinates.y - 1} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x + 2,coordinates.y - 1 });
			}
			NotErase(count);
		}
		count = CheckCoordinates({ coordinates.x + 1,coordinates.y + 2 });
		if ((*count).piece.name == None) {
			*figur = { {game_color,Knight},{coordinates.x + 1,coordinates.y + 2} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x + 1,coordinates.y + 2 });
			}
		}
		else {
			Erase(count);
			*figur = { {game_color,Knight},{coordinates.x + 1,coordinates.y + 2} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x + 1,coordinates.y + 2 });
			}
			NotErase(count);
		}
		count = CheckCoordinates({ coordinates.x + 1,coordinates.y - 2 });
		if ((*count).piece.name == None) {
			*figur = { {game_color,Knight},{coordinates.x + 1,coordinates.y - 2} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x + 1,coordinates.y - 2 });
			}
		}
		else {
			Erase(count);
			*figur = { {game_color,Knight},{coordinates.x + 1,coordinates.y - 2} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x + 1,coordinates.y - 2 });
			}
			NotErase(count);
		}
		count = CheckCoordinates({ coordinates.x - 1,coordinates.y - 2 });
		if ((*count).piece.name == None) {
			*figur = { {game_color,Knight},{coordinates.x - 1,coordinates.y - 2} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x - 1,coordinates.y - 2 });
			}
		}
		else {
			Erase(count);
			*figur = { {game_color,Knight},{coordinates.x - 1,coordinates.y - 2} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x - 1,coordinates.y - 2 });
			}
			NotErase(count);
		}
		count = CheckCoordinates({ coordinates.x - 1,coordinates.y + 2 });
		if ((*count).piece.name == None) {
			*figur = { {game_color,Knight},{coordinates.x - 1,coordinates.y + 2} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x - 1,coordinates.y + 2 });
			}
		}
		else {
			Erase(count);
			*figur = { {game_color,Knight},{coordinates.x - 1,coordinates.y + 2} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x - 1,coordinates.y + 2 });
			}
			NotErase(count);
		}
		count = CheckCoordinates({ coordinates.x - 2,coordinates.y - 1 });
		if ((*count).piece.name == None) {
			*figur = { {game_color,Knight},{coordinates.x - 2,coordinates.y - 1} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x - 2,coordinates.y - 1 });
			}
		}
		else {
			Erase(count);
			*figur = { {game_color,Knight},{coordinates.x - 2,coordinates.y - 1} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x - 2,coordinates.y - 1 });
			}
			NotErase(count);
		}
		count = CheckCoordinates({ coordinates.x - 2,coordinates.y + 1 });
		if ((*count).piece.name == None) {
			*figur = { {game_color,Knight},{coordinates.x - 2,coordinates.y + 1} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x - 2,coordinates.y + 1 });
			}
		}
		else {
			Erase(count);
			*figur = { {game_color,Knight},{coordinates.x - 2,coordinates.y + 1} };
			if (!AreChacking(game_color)) {
				move.push_back({ coordinates.x - 2,coordinates.y + 1 });
			}
			NotErase(count);
		}
		*figur = { {game_color,Knight},{coordinates.x ,coordinates.y } };
		break;
	case Bishop:
		for (int i = coordinates.x + 1, j = coordinates.y + 1; i < 8; i++, j++) {
			if (CanBishopMove(figur, { i,j })) {
				*figur = { {game_color,Bishop},{i,j} };
				if (!AreChacking(game_color)) {
					move.push_back({ i,j });
				}
				*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
			}
			else {
				count = CheckCoordinates({ i,j });
				if ((*count).piece.color == (*figur).piece.color) {
					break;
				}
				else {
					Erase(count);
					*figur = { {game_color,Bishop},{i,j} };
					if (!AreChacking(game_color)) {
						move.push_back({ i,j });
					}
					NotErase(count);
					*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
				}
			}
		}
		for (int i = coordinates.x + 1, j = coordinates.y - 1; i < 8; i++, j--) {
			if (CanBishopMove(figur, { i,j })) {
				*figur = { {game_color,Bishop},{i,j} };
				if (!AreChacking(game_color)) {
					move.push_back({ i,j });
				}
				*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
			}
			else {
				count = CheckCoordinates({ i,j });
				if ((*count).piece.color == (*figur).piece.color) {
					break;
				}
				else {
					Erase(count);
					*figur = { {game_color,Bishop},{i,j} };
					if (!AreChacking(game_color)) {
						move.push_back({ i,j });
					}
					NotErase(count);
					*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
				}
			}
		}
		for (int i = coordinates.x - 1, j = coordinates.y + 1; j < 8; i--, j++) {
			if (CanBishopMove(figur, { i,j })) {
				*figur = { {game_color,Bishop},{i,j} };
				if (!AreChacking(game_color)) {
					move.push_back({ i,j });
				}
				*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
			}
			else {
				count = CheckCoordinates({ i,j });
				if ((*count).piece.color == (*figur).piece.color) {
					break;
				}
				else {
					Erase(count);
					*figur = { {game_color,Bishop},{i,j} };
					if (!AreChacking(game_color)) {
						move.push_back({ i,j });
					}
					NotErase(count);
					*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
				}
			}
		}
		for (int i = coordinates.x - 1, j = coordinates.y - 1; i >= 0; i--, j--) {
			if (CanBishopMove(figur, { i,j })) {
				*figur = { {game_color,Bishop},{i,j} };
				if (!AreChacking(game_color)) {
					move.push_back({ i,j });
				}
				*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
			}
			else {
				count = CheckCoordinates({ i,j });
				if ((*count).piece.color == (*figur).piece.color) {
					break;
				}
				else {
					Erase(count);
					*figur = { {game_color,Bishop},{i,j} };
					if (!AreChacking(game_color)) {
						move.push_back({ i,j });
					}
					NotErase(count);
					*figur = { {game_color,Bishop},{coordinates.x ,coordinates.y } };
				}
			}
		}
		break;
	case Rook:
	case Queen:
	case King:
	default:
		break;
	}
	return move;
}