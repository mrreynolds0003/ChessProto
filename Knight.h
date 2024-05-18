#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <vector>
#include <iostream>
#include "windows.h"
#include <io.h>
#include <fcntl.h>
#include "Aboard.h"
#include "ACursor.h"

class Knight : public Piece {
private:

	
public:
	
	vector<bool> move(vector<Piece*>& map, int loc) {
		possiblemoves.clear();
		possiblemoves.resize(64, false);
		
		int curRow = loc / vectorX;
		int curCol = loc % vectorX;

		/*TO DO KNIGHT MOVES
		* 1. loc - (vectorX * 2) - 1	UUL
		* 2. loc - vectorX - 2			ULL
		* 3. loc - (vectorX * 2) + 1	UUR
		* 4. loc - vectorX + 2			URR
		* 5. loc + vectorX - 2			DLL
		* 6. loc + vectorX + 2			DRR
		* 7. loc + (vectorX * 2) - 1	DDL	
		* 8. loc + (vectorX * 2) + 1	DDR
		* 
		* if (curCol != 7 && (loc - (vectorX - 1) * index) > 0) {
		* if (curCol != 0 && (loc - (vectorX + 1) * index) > 0) {
		*/
		
		if (curCol >= 1 && (loc  > 9)) {
			
			//move 2 ULL
			if (curCol >= 2 && map.at(loc - vectorX - 2)->team != map.at(loc)->team) {
				possiblemoves.at(loc - vectorX - 2) = true;

			}//move 1 UUL
			if (loc > 16 && map.at(loc - (vectorX * 2) - 1)->team != map.at(loc)->team) {
				possiblemoves.at(loc - (vectorX * 2) - 1) = true;
			}
		}
		if (curCol <= 6 && (loc  > 8)) {
			
			//move 4 URR
			if (curCol <= 5 && map.at(loc - vectorX + 2)->team != map.at(loc)->team) {
				possiblemoves.at(loc - vectorX + 2) = true;

			}//move 3 UUR
			if (loc > 15 && map.at(loc - (vectorX * 2) + 1)->team != map.at(loc)->team) {
				possiblemoves.at(loc - (vectorX * 2) + 1) = true;
			}
		}

		if (curCol >= 1 && (loc < 56)) {
			//move 5 DLL
			if (curCol >= 2 &&  map.at(loc + vectorX - 2)->team != map.at(loc)->team) {
				possiblemoves.at(loc + vectorX - 2) = true;
			}
			//move 7 DDL
			if ( loc < 48 && map.at(loc + (vectorX * 2) - 1)->team != map.at(loc)->team) {
				possiblemoves.at(loc + (vectorX * 2) - 1) = true;
			}
		}
		if (curCol <= 6 && (loc < 54)) {
			//move 6 DRR
			if (curCol <= 5 && map.at(loc + vectorX + 2)->team != map.at(loc)->team) {
				possiblemoves.at(loc + vectorX + 2) = true;
			}
			//move 8 DDR
			if (loc < 47 && map.at(loc + (vectorX * 2) + 1)->team != map.at(loc)->team) {
				possiblemoves.at(loc + (vectorX * 2) + 1) = true;
			}
		}
		 	
			return possiblemoves;
	}

	Knight(int pieceTeam) {
		possiblemoves.resize(64, false);
		pieceInt = 2;
		team = pieceTeam;
		if (team == 1) {
			figure = 'N';
		}
		else {
			figure = 'n';
		}
	}
};

#endif