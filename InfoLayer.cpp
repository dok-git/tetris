#include "InfoLayer.h"
#include <string>
using namespace std;

COORD InfoLayer::getLayerPos()
{
	return layerPos;
}

std::vector<CellVO> InfoLayer::render()
{
	std::vector<CellVO> cells;
	drawString(cells, "Next Figure", FOREGROUND_RED, {3, 18});
	drawString(cells, "Points ", FOREGROUND_GREEN | FOREGROUND_INTENSITY, { 1, 3 });
	drawString(cells, "Level ", FOREGROUND_GREEN | FOREGROUND_INTENSITY, { 1, 4 });
	drawString(cells, "Destroyed rows ", FOREGROUND_GREEN | FOREGROUND_INTENSITY, { 1, 5 });
	drawString(cells, "Time ", FOREGROUND_GREEN | FOREGROUND_INTENSITY, { 1, 6 });
	
	vector < COORD > figure = gameData->nextFigure->getInitState();
	for (int i = 0; i < figure.size(); i++) {
		cells.push_back(getCellVO(L'\u00A4', FOREGROUND_RED | FOREGROUND_INTENSITY , figure[i].X+7, figure[i].Y+20));
	}
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
