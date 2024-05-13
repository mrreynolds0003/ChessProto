#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include <iomanip>
class Pawn : public piece {
private:
	//int pieceInt = 6;
	int team = 1;
	bool moved = false;
	int vectorX = 8;
	
	vector <bool> possiblemoves;
public:
	vector<bool>  move(vector<piece> map, int loc) {
		if(moved == false){
		 possiblemoves.at(loc + (2 * vectorX) * team) = true;
		 possiblemoves.at(loc + (vectorX) * team) = true;
		 moved = true;
		}
		 else{
		possiblemoves.at(loc + (vectorX) * team) = true;
		}
		 if(((map.at(loc + (vectorX -1 * team )).team * map.at(loc).team < 0|| map.at(loc + (vectorX + 1 * team)).team * map.at(loc).team < 0))){
			possiblemoves.at(loc + (2 * vectorX) * team) = true;
		}
		 return possiblemoves;
	}
	Pawn(int type, int pieceTeam) {
		possiblemoves.resize(64, false);
		moved = false;
		pieceInt = type;
		team = pieceTeam;
	}
};
#endif