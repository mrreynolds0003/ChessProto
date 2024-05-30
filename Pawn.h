#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <vector>
#include <cmath>

class Pawn : public Piece {
private:

public:

    bool moved = false;

    vector<bool> move(vector<Piece*>& map, int loc) {
        int curRow = loc / vectorX;
        int curCol = loc % vectorX;
        possiblemoves.clear();
        possiblemoves.resize(64, false);

        if (loc > 7 && loc < 56) {
            // Forward move
            int forwardLoc = loc + (vectorX * team);
            if (abs(map.at(forwardLoc)->team) == 0) {
                possiblemoves.at(forwardLoc) = true;

                // Initial double move
                if ((curRow == 1 && team == 1) || (curRow == 6 && team == -1)) {
                    int doubleForwardLoc = loc + (2 * vectorX * team);
                    if (abs(map.at(doubleForwardLoc)->team) == 0) {
                        possiblemoves.at(doubleForwardLoc) = true;
                    }
                }
            }

            // Capture moves
            int captureLeft = loc + (vectorX - 1) * team;
            int captureRight = loc + (vectorX + 1) * team;
            if (curCol > 0 && map.at(captureLeft)->team * map.at(loc)->team < 0) {
                possiblemoves.at(captureLeft) = true;
            }
            if (curCol < vectorX - 1 && map.at(captureRight)->team * map.at(loc)->team < 0) {
                possiblemoves.at(captureRight) = true;
            }
        }

        return possiblemoves;
    }

    vector<bool> captureMoves(vector<Piece*>& map, int loc) {
        int curRow = loc / vectorX;
        int curCol = loc % vectorX;
        vector<bool> captureMoves(64, false);

        if (loc > 7 && loc < 56) {
            // Capture moves
            int captureLeft = loc + (vectorX - 1) * team;
            int captureRight = loc + (vectorX + 1) * team;
            if (curCol > 0 && map.at(captureLeft)->team * map.at(loc)->team < 0) {
                captureMoves.at(captureLeft) = true;
            }
            if (curCol < vectorX - 1 && map.at(captureRight)->team * map.at(loc)->team < 0) {
                captureMoves.at(captureRight) = true;
            }
        }

        return captureMoves;
    }

    Pawn(int pieceTeam) {
        possiblemoves.resize(64, false);
        moved = false;
        pieceInt = 6;
        team = pieceTeam;
        if (team == 1) {
            figure = L'♙';
        }
        else {
            figure = L'P'; // L'♟';
        }
    }
};

#endif



/*#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include <iomanip>
class Pawn : public Piece {
private:

public:

	bool moved = false;

	vector<bool> move(vector<Piece*>& map, int loc) {
		int curRow = loc / vectorX;
		possiblemoves.clear();
		possiblemoves.resize(64, false);
		if (loc > 7 && loc < 56) {
			if (abs(map.at(loc + ((vectorX)*team))->team) == 0) {
				possiblemoves.at(loc + ((vectorX)*team)) = true;			// verifies nothing is there
				if ((curRow == 1  && team == 1)|| (curRow == 6 && team == -1)) {							// verifies piece hasnt moved for this entry loop 
					if (!(possiblemoves.at(loc + ((2 * vectorX) * team)) > 63 || possiblemoves.at(loc + ((2 * vectorX) * team)) < 0)) {

						possiblemoves.at(loc + ((2 * vectorX) * team)) = true;  // move if not moved
					}
				}
			}
			if (((map.at(loc + ((vectorX - 1) * team))->team * map.at(loc)->team < 0))) {
				possiblemoves.at(loc + ((vectorX - 1) * team)) = true;
			}
			if (map.at(loc + ((vectorX + 1) * team))->team * map.at(loc)->team < 0) {
				possiblemoves.at(loc + ((vectorX + 1) * team)) = true;
			}
		}

		return possiblemoves;
	}

	Pawn(int pieceTeam) {
		possiblemoves.resize(64, false);
		moved = false;
		pieceInt = 6;
		team = pieceTeam;
		if (team == 1) {
			figure = L'♙';
		}
		else {
			figure = L'P';//L'♟';
		}
	}
};


#endif*/