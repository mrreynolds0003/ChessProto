#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
class Bishop : public Piece {
private:
	
public:
	vector<bool> move(vector<Piece*>& map, int loc) {
		possiblemoves.clear();
		possiblemoves.resize(64, false);		
		int curRow = loc / vectorX;
		int curCol = loc % vectorX;
		int index = 1;
		while (flag && index < 8) {
			if (curCol != 7 && (loc + (vectorX + 1) * index) < 64) { // move right and down
				if (map.at(loc + (vectorX + 1) * index)->team == 0) {
					possiblemoves.at(loc + (vectorX + 1) * index) = true;
				}
				else if (map.at(loc + (vectorX + 1) * index)->team != map.at(loc)->team) {
					possiblemoves.at(loc + (vectorX + 1) * index) = true;
					flag = false;
				}
				if ((map.at(loc + (vectorX + 1) * index)->team == map.at(loc)->team)) {
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
			if (curCol != 0 && (loc + (vectorX - 1) * index) < 64) { // move left and down
				if (map.at(loc + (vectorX - 1) * index)->team == 0) {
					possiblemoves.at(loc + (vectorX - 1) * index) = true;
				}
				else if (map.at(loc + (vectorX - 1) * index)->team != map.at(loc)->team) {
					possiblemoves.at(loc + (vectorX - 1) * index) = true;
					flag = false;
				}
				if ((map.at(loc + (vectorX - 1) * index)->team == map.at(loc)->team)) {
					flag = false;
				}
				curCol--;
			}

			index++;
		}
		curCol = loc % vectorX;
		index = 1;
		flag = true;

		while (flag && index < 8) {
			if (curCol != 0 && (loc - (vectorX + 1) * index) > 0) { // move left and up
				if (map.at(loc - (vectorX + 1) * index)->team == 0) {
					possiblemoves.at(loc - (vectorX + 1) * index) = true;
				}
				else if (map.at(loc - (vectorX + 1) * index)->team != map.at(loc)->team) {
					possiblemoves.at(loc - (vectorX + 1) * index) = true;
					flag = false;
				}
				if ((map.at(loc - (vectorX + 1) * index)->team == map.at(loc)->team)) {
					flag = false;
				}
				curCol--;
			}

			index++;
		}
		curCol = loc % vectorX;
		index = 1;
		flag = true;
		while (flag && index < 8) {
			if (curCol != 7 && (loc - (vectorX - 1) * index) > 0) { // move right and up
				if (map.at(loc - (vectorX - 1) * index)->team == 0) {
					possiblemoves.at(loc - (vectorX - 1) * index) = true;
				}
				else if (map.at(loc - (vectorX - 1) * index)->team != map.at(loc)->team) {
					possiblemoves.at(loc - (vectorX - 1) * index) = true;
					flag = false;
				}
				if ((map.at(loc - (vectorX - 1) * index)->team == map.at(loc)->team)) {
					flag = false;
				}
				curCol++;
			}

			index++;
		}

		return possiblemoves;
	}

	Bishop(int pieceTeam) {
		possiblemoves.resize(64, false);
		pieceInt = 3;
		team = pieceTeam;
		if (team == 1) {
			figure = L'♗';
		}
		else {
			figure = L'♝';
		}
	}
};

/*
♔♖♕♘♗♙♚♛♜♝♞♟
white
*/
#endif