#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <vector>
#include <iostream>
#include "windows.h"
#include <io.h>
#include <fcntl.h>
#include "Aboard.h"
#include "ACursor.h"

class Knight : public piece {
private:
	//int pieceInt = 2;
	int team = 1;
	
public:

	vector <bool> possiblemoves;

	vector<bool>  move(vector<piece> map) {

	}

	Knight(int type, int pieceTeam) {
		possiblemoves.resize(64, false);
		pieceInt = type;
		team = pieceTeam;
	}
};

#endif