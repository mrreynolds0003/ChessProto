#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
class Bishop : public piece {
private:
	//int pieceInt = 3;
	int team = 1;
	vector <bool> possiblemoves;
public:
	vector<bool>  move(vector<piece> map) {

	}
	Bishop(int type, int pieceTeam) {
		possiblemoves.resize(64, false);
		pieceInt = type;
		team = pieceTeam;
	}
};
#endif