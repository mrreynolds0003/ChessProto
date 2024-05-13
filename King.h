#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public piece {
private:
	//int pieceInt = 4;
	int team = 1;
	bool check = false;
	bool checkMate = false;
	vector <bool> possiblemoves;

public:
	vector<bool>  move(vector<piece> map) {

	}
	King(int type, int pieceTeam) {
		possiblemoves.resize(64, false);
		pieceInt = type;
		team = pieceTeam;
	}
};

#endif