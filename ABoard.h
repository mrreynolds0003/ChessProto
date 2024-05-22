
#ifndef ABOARD_H
#define ABOARD_H
using namespace std;

#include <iostream>
#include <random>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <thread>
#include <mutex>
#include <chrono>
#include "windows.h"
#include "ACursor.h"
#include "Piece.h"
#include "Rook.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"
#include "Pawn.h"
#include "Bishop.h"


const int SIZEX = 8;
const int SIZEY = 8;
const int WHITE_COLOR = 240;
const int BLACK_COLOR = 7;
const int BLACK_TEAM = -1;
const int WHITE_TEAM = 1;

class board {
private:
	int vectorX;
	HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	int vectorY;
	int absoluteSize = vectorX * vectorY;
	mutex secure;
	int timer = 0;

	void ShowConsoleCursor(bool showFlag)
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO     cursorInfo;
		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = showFlag;
		SetConsoleCursorInfo(out, &cursorInfo);
	}

	BOOL gotoxy(const WORD x, const WORD y) {
		COORD xy;
		xy.X = x;
		xy.Y = y;
		return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
	}
public:
	bool game_over = false;
	bool turn = true;
	int flip = -1;
	//bool mate;
	vector <Piece*> map;
	vector <Piece*> futuremap;
	vector<bool> kingVec;
	cursor myCursor;
	board(int sizeX, int sizeY);
	void clock() {

		while (!game_over) {

			this_thread::sleep_for(chrono::seconds(1));
			secure.lock();
			timer++;
			secure.unlock();

			draw();
		}

	}

	vector<bool> checkVector(vector<Piece*>& map, bool turn) {
		vector <bool> checkVec;
		checkVec.clear();
		checkVec.resize(64, false);

		turn ? flip = BLACK_TEAM : flip = WHITE_TEAM;
		// white team check vector (filled with black pieces)	
		for (int pieceIndex = 0; pieceIndex < absoluteSize; pieceIndex++) {
			if (map.at(pieceIndex)->team == flip) {
				vector<bool> tempVec = map.at(pieceIndex)->move(map, pieceIndex);
				for (int i = 0; i < absoluteSize; i++) {
					if (tempVec.at(i) == true) {
						checkVec.at(i) = true;
					}
				}
			}
		}
		return checkVec;
	}
	bool nomoves() {
		bool moves = true;
		for (int i = 0; i < kingVec.size(); i++) {
			if (kingVec.at(i) == true) {
				moves = false;
			}
		}
		return moves;
	}
	bool checkmate() {
		kingcheck(map, turn);
		if (!nomoves()) {
			game_over = true;
		}
		return game_over;
	}// status(bool/vector?) for check to check for checkmate
	bool kingcheck(vector<Piece*>& map, bool turn) {
		bool kingCheck = false;

		turn ? flip = WHITE_TEAM : flip = BLACK_TEAM;
		// white team check vector (filled with black pieces)	
		for (int pieceIndex = 0; pieceIndex < absoluteSize; pieceIndex++) {
			if (map.at(pieceIndex)->team == flip && map.at(pieceIndex)->pieceInt == 4) {
				kingVec = map.at(pieceIndex)->move(map, pieceIndex); //king's possible moves
				kingVec.at(pieceIndex) = true;

				if (checkVector(map, turn).at(pieceIndex) == true && kingVec.at(pieceIndex)) {
					kingCheck = true;
					kingVec.at(pieceIndex) = false;

				}
			}
		}
		return kingCheck;
	}
	bool futurecheck(int currPieceLoc, int nextPieceLocation) {
		futuremap = map;
		bool proceed = true;

		if (map.at(currPieceLoc)->team == WHITE_TEAM) { //white team
			if (futuremap.at(currPieceLoc)->move(futuremap, currPieceLoc).at(nextPieceLocation)) {
				futuremap.at(nextPieceLocation) = futuremap.at(currPieceLoc);
				futuremap.at(currPieceLoc) = new Piece(0);

			}
		}

		if (map.at(currPieceLoc)->team == BLACK_TEAM) {	///black team						
			if (futuremap.at(currPieceLoc)->move(futuremap, currPieceLoc).at(nextPieceLocation)) {
				futuremap.at(nextPieceLocation) = futuremap.at(currPieceLoc);
				futuremap.at(currPieceLoc) = new Piece(0);
			}
		}

		if (kingcheck(futuremap, turn)) {
			proceed = false;
		}

		return proceed;

	}

	void identifyMoves(bool pressed) {

		int currPieceLoc = myCursor.get_c_location();
		int nextPieceLocation;
		

		do {
			//myBoard.draw();
			this_thread::sleep_for(chrono::milliseconds(100));
			checkVector(map, turn);
			checkmate();
			if (GetAsyncKeyState(VK_DOWN)) {
				move_down();
			}
			else if (GetAsyncKeyState(VK_UP)) {
				move_up();

			}
			else if (GetAsyncKeyState(VK_RIGHT)) {
				move_right();

			}
			else if (GetAsyncKeyState(VK_LEFT)) {
				move_left();
			}
			else if (GetAsyncKeyState(VK_SPACE)) {

				nextPieceLocation = myCursor.get_c_location();
				pressed = true;
				if (currPieceLoc != nextPieceLocation || map.at(currPieceLoc)->team != 0) {

					if (turn == true && map.at(currPieceLoc)->team == WHITE_TEAM) { ///white team
						if (map.at(currPieceLoc)->move(map, currPieceLoc).at(nextPieceLocation)) {
							if (futurecheck(currPieceLoc, nextPieceLocation) == true) {
								map.at(nextPieceLocation) = map.at(currPieceLoc);
								map.at(currPieceLoc) = new Piece(0);
								turn = false;
							}
						}
					}
					if (turn == false && map.at(currPieceLoc)->team == BLACK_TEAM) {	///black team						
						if (map.at(currPieceLoc)->move(map, currPieceLoc).at(nextPieceLocation)) {
							if (futurecheck(currPieceLoc, nextPieceLocation)) {
								map.at(nextPieceLocation) = map.at(currPieceLoc);
								map.at(currPieceLoc) = new Piece(0);
								turn = true;
							}
						}
					}
				}
			}

		} while (!pressed);

	}

	void draw() {
		secure.lock();
		gotoxy(0, 0);
		int start = 0;
		int index = 0;
		for (int rowIndex = 0; rowIndex < vectorY; rowIndex++) {
			for (int colIndex = start; colIndex < (vectorX + start); colIndex++) {
				if (colIndex % 2 == 0) {
					SetConsoleTextAttribute(console_color, WHITE_COLOR);
					wcout << map.at(index)->getFigure(index) << ' ';
				}
				else {
					SetConsoleTextAttribute(console_color, BLACK_COLOR);
					wcout << map.at(index)->getFigure(index) << ' ';
				}
				index++;
			}
			SetConsoleTextAttribute(console_color, BLACK_COLOR);
			wcout << endl;
			
			start++;
		}
		if (turn == 1) wcout << "white turn";
		if (turn == 0) wcout << "black turn";
		if (game_over) wcout << "Checkmate!";

		secure.unlock();

	}

	void c_update(int time) {
		while (!game_over) {

			this_thread::sleep_for(chrono::milliseconds(time));
			draw();
		}
	}

	void move_down() {
		secure.lock();
		if (!(myCursor.get_c_location() >= absoluteSize - 1) && !(myCursor.get_c_location() + vectorX >= absoluteSize)) {
			myCursor.set_c_location(myCursor.get_c_location() + vectorX);
		}
		secure.unlock();
	}
	void move_up() {
		secure.lock();
		if (!(myCursor.get_c_location() <= 0) && !(myCursor.get_c_location() - vectorX < 0)) {
			myCursor.set_c_location(myCursor.get_c_location() - vectorX);
		}
		secure.unlock();
	}
	void move_left() {
		secure.lock();
		if (!(myCursor.get_c_location() <= 0) && (abs((myCursor.get_c_location() / vectorX) - ((myCursor.get_c_location() - 1) / vectorX)) == 0)) {
			myCursor.set_c_location(myCursor.get_c_location() - 1);
		}
		secure.unlock();

	}
	void move_right() {
		secure.lock();
		if (!(myCursor.get_c_location() >= absoluteSize - 1) && (abs((myCursor.get_c_location() / vectorX) - ((myCursor.get_c_location() + 1) / vectorX)) == 0)) {
			myCursor.set_c_location(myCursor.get_c_location() + 1);
		}
		secure.unlock();
	}
};

board::board(int sizeX, int sizeY) {
	vectorX = sizeX;
	vectorY = sizeY;
	absoluteSize = sizeX * sizeY;
	map.resize(absoluteSize / 2, new Piece());
	ShowConsoleCursor(false);
	map.insert(map.begin(), { new Rook(1), new Knight(1), new Bishop(1), new King(1), new Queen(1), new Bishop(1), new Knight(1), new Rook(1) });
	map.insert(map.begin() + 8, { new Pawn(1), new Pawn(1), new Pawn(1), new Pawn(1), new Pawn(1), new Pawn(1), new Pawn(1), new Pawn(1) });
	map.insert(map.begin() + 48, { new Pawn(-1), new Pawn(-1),new Pawn(-1), new Pawn(-1), new Pawn(-1), new Pawn(-1), new Pawn(-1), new Pawn(-1) });
	//map.insert(map.begin() + 8, { new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0) }); // tests without pawns
	//map.insert(map.begin() + 48, { new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0) }); // tests without pawns
	map.insert(map.begin() + 56, { new Rook(-1), new Knight(-1), new Bishop(-1), new King(-1), new Queen(-1), new Bishop(-1), new Knight(-1), new Rook(-1) });

}

#endif
