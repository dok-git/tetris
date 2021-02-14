#include "BaseFigure.h"

BaseFigure::BaseFigure()
{
	
}

void BaseFigure::nextState()
{
	if (stateId == states.size()-1) {
		stateId = 0;
	}
	else{
		stateId++;
	}
}

vector<COORD> BaseFigure::getState()
{
	return states[stateId];
}
	
