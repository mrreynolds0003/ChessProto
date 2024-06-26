﻿
#ifndef PIECE_H
#define PIECE_H
#include "ACursor.h"
#include <vector>
#include <string>

using namespace std;

class Piece : public cursor{
private:
	int location = 0;

public:
	int team;
	int pieceInt = 0;
	int vectorX = 8;
	int index = 1;
	bool flag = true;
	vector <bool> possiblemoves;
	virtual vector<bool> move(vector<Piece*>& map, int loc) {
		possiblemoves.clear();
		possiblemoves.resize(64, false);
		return possiblemoves;
	}
    wstring figure = L" ";
    bool color = true;
	Piece(int);
	Piece();
    wstring getFigure(int loc) {
		wstring temp = figure;
			if (loc == get_c_location()) {
				temp = cursor_update();
			}
			return temp;
	}

};
Piece::Piece() {
	team = 0;
}
Piece::Piece(int pieceTeam) {
	possiblemoves.resize(64, false);
	team = pieceTeam;
}
#endif