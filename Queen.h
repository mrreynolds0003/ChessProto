#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
class Queen : public Piece {
private:
	int vectorX = 8;
public:

	/*vector<bool> move(vector<piece*>& map, int loc) {
		possiblemoves.clear();
		possiblemoves.resize(64, false);
		if (abs(map.at(loc + ((vectorX)*team))->team) == 0) {
			
		return possiblemoves;
	}*/

	Queen(int pieceTeam) {
		possiblemoves.resize(64, false);
		pieceInt = 5;
		team = pieceTeam;
		if (team == 1) {
			figure = 'Q';
		}
		else {
			figure = 'q';
		}
	}
}; 





#endif