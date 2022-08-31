#pragma once
#include "Piece.h"
#include <vector>
class Coordinates
{
public:
	int x;
	int y;
};

extern std::vector<Piece> figur[8];
extern bool game_color;

class Board 
{
public:
	Board() {
		if (figur[0].empty()) {
			for (int j = 0; j < 8; j++) {
				for (int i = 0; i < 8; i++) {
					switch (j)
					{
					case 0:
						switch (i)
						{
						case 0:
							figur[j].push_back({ true,Rook});
							break;
						case 1:
							figur[j].push_back({ NULL,None });
							//figur[j].push_back({true,Knight});
							break;
						case 2:
							figur[j].push_back({ NULL,None });
							//figur[j].push_back({true,Bishop});
							break;
						case 3:
							figur[j].push_back({true,King});
							break;
						case 4:
							figur[j].push_back({true,Queen});
							break;
						case 5:
							figur[j].push_back({true,Bishop});
							break;
						case 6:
							figur[j].push_back({true,Knight});
							break;
						case 7:
							figur[j].push_back({true,Rook});
							break;
						}
						break;
					case 1:
						figur[j].push_back({true,Pawn});
						break;
					case 6:
						figur[j].push_back({false,Pawn});
						break;
					case 7:
						switch (i)
						{
						case 0:
							figur[j].push_back({false,Rook});
							break;
						case 1:
							figur[j].push_back({false,Knight});
							break;
						case 2:
							figur[j].push_back({false,Bishop});
							break;
						case 3:
							figur[j].push_back({false,King});
							break;
						case 4:
							figur[j].push_back({false,Queen});
							break;
						case 5:
							figur[j].push_back({false,Bishop});
							break;
						case 6:
							figur[j].push_back({false,Knight});
							break;
						case 7:
							figur[j].push_back({false,Rook});
							break;
						}
						break;
					default:
						figur[j].push_back({NULL,None});
						break;
					}
				}
			}
		}
	}
	void Start(Coordinates coordinates, Coordinates new_coordinates, bool color);
	void Erase(auto figur) {
		if (!(*figur).piece.color) {
			//Black.erase(figur);
		}
		else {
			//White.erase(figur);
		}
	}
	void NotErase(auto figur) {
		if ((*figur).piece.color) {
			//Black.push_back(*figur);
		}
		else {
			//White.push_back(*figur);
		}
	}
	~Board(){}
};