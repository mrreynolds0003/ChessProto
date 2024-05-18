#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
class Queen : public Piece {
private:

public:
	vector<bool> move(vector<Piece*>& map, int loc) {
		possiblemoves.clear();
		possiblemoves.resize(64, false);
		int curRow = loc / vectorX;
		int curCol = loc % vectorX;

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
		curCol = loc % vectorX;
		index = 1;
		flag = true;

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