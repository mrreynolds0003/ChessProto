﻿#pragma once
#ifndef PIECE_H
#define PIECE_H
#include "ACursor.h"
#include "Rook.h"
#include <vector>
#include <string>


using namespace std;

class piece : public cursor{
private:
	int location = 0;
	int team = 0;
	vector <int> possibleMoves;
	string pieceName = " ";

    //const char WHITE = 0xDB;
    //const char BLACK = 0xFF;
public:
	int pieceInt = 0;
	virtual void move(){

	}
    char figure = ' ';
    bool color = true;
	piece(int type, int);
	piece();
    char getFigure(int loc) {
			if (loc == get_c_location()) {
				figure = cursor_update();
			}
			else if (pieceInt == 1) {
				figure = 'R';
			}
			else if (pieceInt == 2) {
				figure = 'N';
			}
			else if (pieceInt == 3) {
				figure = 'B';
			}
			else if (pieceInt == 4) {
				figure = 'Q';
			}
			else if (pieceInt == 5) {
				figure = 'K';
			}
			else if (pieceInt == 6) {
				figure = 'P';
			}
			else {
				figure = ' ';
			}
			return figure;
		}
};
piece::piece() {
	pieceInt = 0;
	team = 0;
}
piece::piece(int type, int pieceTeam) {
	pieceInt = type;
	team = pieceTeam;
}
#endif