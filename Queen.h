#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
class Queen : public piece {
private:
	//int pieceInt = 5;
	int team = 1;
	vector <bool> possiblemoves;
public:

	vector<bool>  move(vector<piece> map) {

	}
Queen(int type, int pieceTeam) {
	possiblemoves.resize(64, false);
	pieceInt = type;
	team = pieceTeam;
}


}; 





#endif