#include "AngleD.h"

AngleD::AngleD()
{
	states.push_back({ {0,0},{0,1},{0,2},{1,0} });
	states.push_back({ {0,0},{1,0},{2,0},{1,2} });
	states.push_back({ {1,0},{1,1},{1,2},{0,2} });
	states.push_back({ {0,0},{0,1},{1,1},{2,1} });
}
