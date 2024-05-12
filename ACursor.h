#pragma once
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
{
private:
	static int CURSOR_LOCATION;
	vector <char> cursorPhase = { '/', '-', '\\', '|' };
	static int shapelocation;

public:
	int get_c_location() {
		return  CURSOR_LOCATION;
	}

	void set_c_location(int loc) {
		CURSOR_LOCATION = loc;
	}

	char cursor_update() {
		shapelocation = ++shapelocation % cursorPhase.size();
		return cursorPhase.at(shapelocation);
	}
};

int cursor::CURSOR_LOCATION = 0;
int cursor::shapelocation = 0;
#endif
