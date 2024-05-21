#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Windows.h"
class King : public Piece {
private:

	bool check = false;
	bool checkMate = false;

public:
	vector<bool> move(vector<Piece*>& map, int loc) {
		possiblemoves.clear();
		possiblemoves.resize(64, false);
		int curCol = loc % vectorX;

		if (loc > 7) { //checks up
			if (map.at(loc - vectorX)->team != map.at(loc)->team) { //up
				possiblemoves.at(loc - vectorX) = true;
			}
			if (curCol <= 6 && map.at(loc - vectorX + 1)->team != map.at(loc)->team) { //up right
				possiblemoves.at(loc - vectorX + 1) = true;
			}
		}
		if (curCol >= 1) { //checks left
			if (map.at(loc - 1)->team != map.at(loc)->team) { //left
				possiblemoves.at(loc - 1) = true;
			}
			if (loc > 8 && map.at(loc - vectorX - 1)->team != map.at(loc)->team) { //up left
				possiblemoves.at(loc - vectorX - 1) = true;
			}
		}
		if (curCol <=6) { //checks right
			if (map.at(loc + 1)->team != map.at(loc)->team) { //right
				possiblemoves.at(loc + 1) = true;
			}
			if (loc < 55 && map.at(loc + vectorX + 1)->team != map.at(loc)->team) { //down right
				possiblemoves.at(loc + vectorX + 1) = true;
			}
		}
		if (loc < 56) { //checks down
			if (map.at(loc + vectorX)->team != map.at(loc)->team) { //down
				possiblemoves.at(loc + vectorX) = true;
			}
			if (curCol >= 1 && map.at(loc + vectorX - 1)->team != map.at(loc)->team) { //down left
				possiblemoves.at(loc + vectorX - 1) = true;
			}
		}
		return possiblemoves;
	}

	King( int pieceTeam) {
		possiblemoves.resize(64, false);
		pieceInt = 4;
		team = pieceTeam;
		if (team == 1) {
			figure = L'♔';
		}
		else {
			figure = L'♚';
		}
	}
};


#endif