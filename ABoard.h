
#ifndef ABOARD_H
#define ABOARD_H
using namespace std;

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <thread>
#include <random>
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
#include <random>
/*
todo:
clean out unneeded code
assemble basic constructors
draw board with moving cursor
*/
const int SIZEX = 8;
const int SIZEY = 8;
const int WHITE = 240;
const int BLACK = 7;
//extern vector <piece> map;
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
	vector <Piece*> map;
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
	void SmalltoBig(int& x, int& y) {
		x = 5 * x + 1;
		y = 3 * y + 1;

	}
	void oneDtotwoD(int pos, int &x, int &y) {
		x = pos % vectorX;
		y = pos / vectorX;
	}
	void identifyMoves(bool pressed) { 
		//identify which was clicked map.at(cursorlocation)
		// send the map to the piece class in question
		// gets back a vector of possible moves
		// restricts cursor to only move in indexes that align with the possible moves vector
		// if space is pressed, if the cursor location has not changed, "let go" of the piece
		//else, move the piece to new location
		int currPieceLoc = myCursor.get_c_location();
		int nextPieceLocation;
		int index = 0;
		//wcout << "CPL" << currentPieceLocation << endl;

		do {
			index++;
			//myBoard.draw();
			this_thread::sleep_for(chrono::milliseconds(100));

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
				//vector <bool> test(map.at(currPieceLoc)->move(map, currPieceLoc));
				pressed = true;
				if (currPieceLoc != nextPieceLocation) {
					if (map.at(currPieceLoc)->move(map, currPieceLoc).at(nextPieceLocation)) {
						map.at(nextPieceLocation) = map.at(currPieceLoc);
						map.at(currPieceLoc) = new Piece(0);
					}
				}
			}
				
		}while (!pressed);

	}
	void draw( ) {
		secure.lock();
		gotoxy(0, 0);
		int start = 0;
		int index = 0;
		for (int rowIndex = 0; rowIndex < vectorY; rowIndex++) {
			//first row type even, start at 0
			//for (int temp = 0; temp < 3; temp++) {
				for (int colIndex = start; colIndex < (vectorX + start); colIndex++) {
					if (colIndex % 2 == 0) {
						SetConsoleTextAttribute(console_color, WHITE);
						wcout  << map.at(index) -> getFigure(index) << ' ';
					}
					else {
						SetConsoleTextAttribute(console_color, BLACK);
						wcout  << map.at(index) -> getFigure(index) << ' ';
					}
					index++;
				}
			    SetConsoleTextAttribute(console_color, BLACK);
				wcout << endl;
			//}
			//flop start
			start++;
		}
		
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
	map.resize(absoluteSize/2 , new Piece());
	ShowConsoleCursor(false);
	map.insert(map.begin(), { new Rook(1), new Knight(1), new Bishop(1), new King(1), new Queen( 1), new Bishop( 1), new Knight( 1), new Rook(1) });
	//map.insert(map.begin() + 8, { new Pawn(1), new Pawn(1), new Pawn( 1), new Pawn( 1), new Pawn( 1), new Pawn( 1), new Pawn( 1), new Pawn( 1) });
	//map.insert(map.begin() + 48, { new Pawn(-1), new Pawn( -1),new Pawn(-1), new Pawn(-1), new Pawn(-1), new Pawn(-1), new Pawn(-1), new Pawn(-1) });
	map.insert(map.begin() + 8, { new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0) });
	map.insert(map.begin() + 48, { new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0), new Piece(0) });
	map.insert(map.begin() + 56, { new Rook( -1), new Knight( -1), new Bishop(-1), new King(-1), new Queen(-1), new Bishop( -1), new Knight(-1), new Rook(-1) });

 
 	


}

#endif
