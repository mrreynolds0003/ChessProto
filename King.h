#pragma once
#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public piece {
private:
	int pieceInt = 4;
	int team = 1;
	bool check = false;
	bool checkMate = false;

};

#endif