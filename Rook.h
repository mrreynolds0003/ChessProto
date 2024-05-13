#pragma once
#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook  {
private:	
	bool team = true;
public:
	vector <int> possiblemovelocation; 
	Rook();
	void move() {
		
	}
};

Rook::Rook() {
	int pieceInt = 1;
}
#endif