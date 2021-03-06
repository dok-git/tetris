#include "MenuLayer.h"

COORD MenuLayer::getLayerPos()
{
	COORD pos;
	pos.X = GameConfig::WIDTH / 2 - widthMsg / 2;
	pos.Y = GameConfig::HEIGHT / 2 - heightMsg / 2;
	return pos;
}

MenuLayer::MenuLayer()
{
	gamesName.push_back("1. Tetris game");
	gamesName.push_back("2. Snake game");
	gamesName.push_back("3. RocketSrocketsRockets");
}

std::vector<CellVO> MenuLayer::render()
{
	WORD background = BACKGROUND_BLUE | BACKGROUND_RED;
	WORD textColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	std::vector<CellVO> cells;

	box(cells, ' ', background, 0, 0, widthMsg, heightMsg);
	border(cells, L'\u2550', L'\u2551', L'\u2554', L'\u2557', L'\u255D', L'\u255A', background | textColor, 0, 0, widthMsg, heightMsg);

	drawString(cells, "MENU", background | textColor, { 15 , 1 });
	for (SHORT i = 0; i < gamesName.size(); i++) {
		drawString(cells, gamesName[i], background | getTextColor(i), { 3, 3 + i*2 });
	}
	
	return cells;
}

WORD MenuLayer::getTextColor(int id) {
	if (id == itemSelected) {
		return  FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	}
	else {
		return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	}
}