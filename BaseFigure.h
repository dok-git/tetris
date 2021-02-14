#pragma once
#include <windows.h>
#include <vector>
#include <wincontypes.h>

using namespace std;
class BaseFigure
{
public:
	BaseFigure();
	vector<vector<COORD>> states;
	int stateId  = 0;
	void nextState();
	vector<COORD> getState();
};

