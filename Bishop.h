#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
class Bishop : public Piece {
private:
	
public:
	vector<bool>  move(vector<Piece> map) {

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