#include <iostream>
#include "windows.h"
#include <io.h>
#include <fcntl.h>
#include "Aboard.h"
#include "Piece.h"
#include "ACursor.h"

/*
♔♖♕♘♗♙♚♛♜♝♞♟

*/

using namespace std;
//const char WHITE = 0xDB;
//const char BLACK = 0xFF;


int main()
{	
	int time = 100;
    //HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    //TO DO MANUALLY :  set your console output to "MS GOTHIC"
    // you can run program  charmap.exe  on windows to see the characters in a font set.

    _setmode(_fileno(stdout), _O_U16TEXT);

    wstring s = L"♕";
    wchar_t t1 = L'\u2658';
    wchar_t t2 = L'\u265B';
    wstring t3 = L"\u265C";
    wcout << L"♕" << endl << s << endl << t1 << endl << t2 << endl << t3 << endl << endl;
	//wcout << L"Test" << endl;
    

	bool game_running = true;
	board myBoard(SIZEX, SIZEY);
	thread thread_obj(&board::c_update, &myBoard, time);  //thread for cursor update
	thread clock(&board::clock, &myBoard);

	//vector <string> scoreFile = readFile("HighScoresDB.txt");
	
	do {
		myBoard.draw();
		//system("pause>nul");  //wait for key
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
			//Note: store peice selection, wich will remain the same, until they move or exit move state by pressing space on other square
			//Cases:
			//	Move Piece valid
			//	Exit by pressing space on select piece
			//Call Board Function to show avaiable with cursor location
				//In board move, waiting for cursor to move, and select new location
				//Unless they press space on non valid LOC,we are in move state
		}
		else if (GetAsyncKeyState(0x4D)) {


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
        
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}