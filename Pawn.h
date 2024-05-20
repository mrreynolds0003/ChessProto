#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include <iomanip>
class Pawn : public Piece {
private:

	bool moved = false;

public:
	vector<bool> move(vector<Piece*>& map, int loc) {
		possiblemoves.clear();
		possiblemoves.resize(64, false);
		if (abs(map.at(loc + ((vectorX)*team))->team) == 0) {			// verifies nothing is there
			if (moved == false) {										// verifies piece hasnt moved for this entry loop 
				possiblemoves.at(loc + ((2 * vectorX) * team)) = true;  // move if not moved
				possiblemoves.at(loc + ((vectorX)*team)) = true;

			}
			else {
				possiblemoves.at(loc + ((vectorX)*team)) = true;
			}
		}
		if (((map.at(loc + ((vectorX - 1) * team))->team * map.at(loc)->team < 0))) {
			possiblemoves.at(loc + ((vectorX - 1) * team)) = true;
		}
		if (map.at(loc + ((vectorX + 1) * team))->team * map.at(loc)->team < 0) {
			possiblemoves.at(loc + ((vectorX + 1) * team)) = true;
		}


		moved = true;
		return possiblemoves;
	}

	Pawn(int pieceTeam) {
		possiblemoves.resize(64, false);
		moved = false;
		pieceInt = 6;
		team = pieceTeam;
		if (team == 1) {
			figure = L'♙';
		}
		else {
			figure = L'♟';
		}
	}
};

/*
♔♖♕♘♗♙♚♛♜♝♞♟
white
*/
#endif