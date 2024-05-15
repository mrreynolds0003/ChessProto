
#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
private:
	bool moved = false;
	int vectorX = 8;
public:
	vector<bool> move(vector<Piece*>& map, int loc) {
		possiblemoves.clear();
		possiblemoves.resize(64, false);
		int index = 1 ;
		bool flag = true;
		/*
		for(int i = loc, i < vectorX  ; i++){
			
		}
		
		*/
		while (flag || (map.at(loc + ((vectorX)*index))->team == map.at(loc)->team)) {
			if (map.at(loc + ((vectorX)*index))->team == 0) {
				possiblemoves.at(loc + ((vectorX)*index) * team) = true;
			}
			if (map.at(loc + ((vectorX)*index))->team != map.at(loc)->team) {
				possiblemoves.at(loc + ((vectorX)*index) * team) = true;
				flag = false;
			}
			index++;
		}
		return possiblemoves;
	}


	Rook(int pieceTeam) {
		possiblemoves.resize(64, false);
		pieceInt = 1;
		team = pieceTeam;
		if (team == 1) {
			figure = 'R';
		}
		else {
			figure = 'r';
		}
	}
	vector<bool>  move(vector<Piece> map) {
		cout << "hello";
	}

};

#endif