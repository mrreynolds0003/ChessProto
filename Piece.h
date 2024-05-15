
#ifndef PIECE_H
#define PIECE_H
#include "ACursor.h"
#include <vector>
#include <string>


using namespace std;

class Piece : public cursor{
private:
	int location = 0;
	
	//string pieceName = " ";

    //const char WHITE = 0xDB;
    //const char BLACK = 0xFF;

public:
	int team;
	int pieceInt = 0;
	vector <bool> possiblemoves;
	virtual vector<bool> move(vector<Piece*>& map, int loc) {
		return  possiblemoves;
	}
    char figure = ' ';
    bool color = true;
	Piece(int);
	Piece();
    char getFigure(int loc) {
		char temp = figure;
			if (loc == get_c_location()) {
				temp = cursor_update();
			}
			return temp;
	}
};
Piece::Piece() {
	pieceInt = 0;
	team = 0;
}
Piece::Piece(int pieceTeam) {
	pieceInt = 0;
	team = pieceTeam;
}
#endif