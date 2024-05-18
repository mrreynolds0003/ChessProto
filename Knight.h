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

	vector<bool> move(vector<Piece*>& map, int loc, int newloc) {
		possiblemoves.clear();
		possiblemoves.resize(64, false);
		/*TO DO KNIGHT MOVES
		* 1. loc - (vectorX * 2) - 1
		* 2. loc - (vectorX * 2) + 1
		* 3. loc - vectorX - 2
		* 4. loc - vectorX + 2
		* 5. loc + vectorX - 2
		* 6. loc + vectorX + 2
		* 7. loc + (vectorX * 2) - 1
		* 8. loc + (vectorX * 2) + 1
		*/
		return possiblemoves;
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