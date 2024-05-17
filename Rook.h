
#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
private:
	bool moved = false;
	int vectorX = 8;
public:
	vector<bool> move(vector<Piece*>& map, int loc, int newloc) {
		possiblemoves.clear();
		possiblemoves.resize(64, false);
		int index = 1;
		bool flag = true;
		int currentRow = loc / vectorX;
		
 		 while (flag == true && index < 8) {			
			if ((loc + (vectorX)*index) < 64 ) { //move down
 				if (map.at(loc + (vectorX)*index)->team == 0) {
					possiblemoves.at(loc + ((vectorX)*index)) = true;
				}
				else if (map.at(loc + ((vectorX)*index))->team != map.at(loc)->team) {
					possiblemoves.at(loc + ((vectorX)*index) ) = true;
					flag = false;
 				}
				if ((map.at(loc + (vectorX)*index)->team == map.at(loc)->team)) {
					flag = false;
				}
			}
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
			if ((currentRow - (newloc / vectorX)) == 0 ) { //move left & right
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
			}
			if ((currentRow - (newloc / vectorX)) != 0) {
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
	

};

#endif