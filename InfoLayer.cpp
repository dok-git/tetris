#include "InfoLayer.h"
#include <string>
using namespace std;

std::vector<CellVO> InfoLayer::render()
{
	std::vector<CellVO> cells;
	drawString(cells, FOREGROUND_GREEN, {5, 1});

	return cells;
}
std::string InfoLayer::formatTime(int second)
{
	int h = 0, m = 0, s = 0;
	string time, sec, min, hour;
	h = second / 3600;
	m = (second % 3600) / 60;
	s = second % 60;
	if (s < 10) {
		sec = "0" + to_string(s);
	}
	else {
		sec = to_string(s);
	}
	//	
	if (m < 10) {
		min = "0" + to_string(m);
	}
	else {
		min = to_string(m);
	}
	//	
	if (h < 10) {
		hour = "0" + to_string(h);
	}
	else {
		hour = to_string(h);
	}
	time = hour + ":" + min + ":" + sec;
	return time;
}
