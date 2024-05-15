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

class Knight : public Piece {
private:

	
public:

	

	vector<bool>  move(vector<Piece> map) {

	}

	Knight(int pieceTeam) {
		possiblemoves.resize(64, false);
		pieceInt = 2;
		team = pieceTeam;
		if (team == 1) {
			figure = 'N';
		}
		else {
			figure = 'n';
		}
	}
};

#endif