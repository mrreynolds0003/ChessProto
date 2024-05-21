#ifndef CURSOR_H
#define CURSOR_H
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <thread>
#include <random>
#include <mutex>
#include "windows.h"
using namespace std;

class cursor
{ //{L'\u25b5', L'\u25b9', L'\u25bf', L'\u25c3'};
private:
	static int CURSOR_LOCATION;
	vector <wchar_t> cursorPhase = {L'\u25b4', L'\u25b8', L'\u25be', L'\u25c2'};
	static int shapelocation;

public:
	int get_c_location() {
		return  CURSOR_LOCATION;
	}

	void set_c_location(int loc) {
		CURSOR_LOCATION = loc;
	}

	wchar_t cursor_update() {
		shapelocation = ++shapelocation % cursorPhase.size();
		return cursorPhase.at(shapelocation);
	}
};

int cursor::CURSOR_LOCATION = 0;
int cursor::shapelocation = 0;
#endif
