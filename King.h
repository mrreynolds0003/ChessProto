#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public Piece {
private:

	bool check = false;
	bool checkMate = false;

public:
	vector<bool>  move(vector<Piece> map) {

	}

	King( int pieceTeam) {
		possiblemoves.resize(64, false);
		pieceInt = 4;
		team = pieceTeam;
		if (team == 1) {
			figure = 'K';
		}
		else {
			figure = 'k';
		}
	}
};

#endif