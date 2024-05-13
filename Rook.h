
#ifndef CROOK_H
#define CROOK_H

#include "Piece.h"

class Rook : public piece {
private:
	int team = 1;
public:
	vector <bool> possiblemoves;

	Rook(int type, int pieceTeam) {
		possiblemoves.resize(64, false);
		pieceInt = type;
		team = pieceTeam;
	}
	vector<bool>  move(vector<piece> map) {

	}
};

#endif