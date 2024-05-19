
#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
private:
	bool moved = false;
public:
	vector<bool> move(vector<Piece*>& map, int loc) {
		possiblemoves.clear();
		possiblemoves.resize(64, false);

		int curRow = loc / vectorX;
		int curCol = loc %  vectorX;
		int index = 1;
		while (flag && index < 8) {
			if ((loc + (vectorX)*index) < 64) { //move down
				if (map.at(loc + (vectorX)*index)->team == 0) {
					possiblemoves.at(loc + ((vectorX)*index)) = true;
				}
				else if (map.at(loc + ((vectorX)*index))->team != map.at(loc)->team) {
					possiblemoves.at(loc + ((vectorX)*index)) = true;
					flag = false;
				}
				if ((map.at(loc + (vectorX)*index)->team == map.at(loc)->team)) {
					flag = false;
				}

			}
			index++;
		}
		index = 1;
		flag = true;
 		while (flag && index < 8) {
			if ((loc - (vectorX)*index) > -1) { //move up
 				if (map.at(loc - (vectorX)*index)->team == 0) {
					possiblemoves.at(loc - ((vectorX)*index)) = true;
				}
				else if (map.at(loc - ((vectorX)*index))->team != map.at(loc)->team) {
					possiblemoves.at(loc - ((vectorX)*index)) = true;
					flag = false;
				}
				if ((map.at(loc - (vectorX)*index)->team == map.at(loc)->team)) {
					flag = false;
				}
			}
			index++;
		}
 		index = 1;
		flag = true;
		while (flag && index < 8) {
 			if (curCol != 7) { // move right
				if (map.at(loc + index)->team == 0) {
 					possiblemoves.at(loc + index) = true;
				}
				else if (map.at(loc + index)->team != map.at(loc)->team) {
					possiblemoves.at(loc + index) = true;
					flag = false;
				}
				if ((map.at(loc + index)->team == map.at(loc)->team)) {
					flag = false;
				}
				curCol++;
			}
			
			index++;
		}
		curCol = loc % vectorX;
		index = 1;
		flag = true;
		while (flag && index < 8) {
		 	if (curCol != 0) { // move left
				if (map.at(loc - index)->team == 0) {
					possiblemoves.at(loc - index) = true;
				}
				else if (map.at(loc - index)->team != map.at(loc)->team) {
					possiblemoves.at(loc - index) = true;
					flag = false;
				}
				if ((map.at(loc - index)->team == map.at(loc)->team)) {
					flag = false;
				}
				curCol--;
			}
			
			index++;
		}
		return possiblemoves;
		// write to check <vector> all possible moves
	}


	Rook(int pieceTeam) {
		possiblemoves.resize(64, false);
		pieceInt = 1;
		team = pieceTeam;
		if (team == 1) {
			figure = L'♖';
		}
		else {
			figure = L'♜';
		}
	}
	

};/*
♔♖♕♘♗♙♚♛♜♝♞♟
white 
*/

#endif