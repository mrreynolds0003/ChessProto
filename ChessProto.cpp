#include <iostream>
#include "windows.h"
#include <io.h>
#include <fcntl.h>
#include "Aboard.h"
#include "Piece.h"
#include "ACursor.h"
using namespace std;
int main()
{	
	int time = 100;
	_setmode(_fileno(stdout), _O_U16TEXT);
	bool game_running = true;
	board myBoard(SIZEX, SIZEY);
	thread thread_obj(&board::c_update, &myBoard, time);  //thread for cursor update
	thread clock(&board::clock, &myBoard);

	//vector <string> scoreFile = readFile("HighScoresDB.txt");
	
	do {
		myBoard.draw();
		system("pause>nul");  //wait for key
		this_thread::sleep_for(chrono::milliseconds(100));

		if (GetAsyncKeyState(VK_DOWN)) {
			myBoard.move_down();
		}
		else if (GetAsyncKeyState(VK_UP)) {
			myBoard.move_up();

		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			myBoard.move_right();

		}
		else if (GetAsyncKeyState(VK_LEFT)) {
			myBoard.move_left();
		}
		else if (GetAsyncKeyState(VK_SPACE)) { 
			bool pressed = false;
			
			myBoard.identifyMoves(pressed);// location
		}
		else if (GetAsyncKeyState(0x4D)) {
			//Forfeit game

		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			game_running = false;
 			myBoard.game_over = true;
 		};

	} while (game_running);
	
	myBoard.clock();
	myBoard.draw();
	clock.join();
	thread_obj.join();
}