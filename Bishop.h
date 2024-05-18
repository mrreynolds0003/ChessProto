#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
class Bishop : public Piece {
private:
	
public:
	vector<bool> move(vector<Piece*>& map, int loc, int newloc) {
		possiblemoves.clear();
		possiblemoves.resize(64, false);
		/*TO DO BISHOP MOVES
		* 1. loc - vectorX - 1 up/left
		* 2. loc - vectorX + 1 up/right
		* 3. loc + vectorX - 1 down/left
		* 4. loc + vectorX + 1 down/right
		*/
		return possiblemoves;
	}

	Bishop(int pieceTeam) {
		possiblemoves.resize(64, false);
		pieceInt = 3;
		team = pieceTeam;
		if (team == 1) {
			figure = 'B';
		}
		else {
			figure = 'b';
		}
	}
};
#endif