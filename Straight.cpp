#include "Straight.h"

Straight::Straight()
{
	states.push_back({ {0,0},{0,1},{0,2},{0,3} });
	states.push_back({ {0,0},{1,0},{2,0},{3,0} });
	states.push_back({ {0,0},{0,1},{0,2},{0,3} });
	states.push_back({ {0,0},{1,0},{2,0},{3,0} });
}
