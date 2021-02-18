#include "Backgroung.h"
#include "GameConfig.h"

std::vector <CellVO> Backgroung::render()
{
	std::vector<CellVO> cells;

	//cells.push_back(getCellVO('A', FOREGROUND_BLUE, 5, 3));
	//line(cells, '*', FOREGROUND_GREEN, 1, 1, 1, 10);
	//border(cells, '+', '+', '+', '+', '+', '+', FOREGROUND_RED, 5, 5, 5, 5);
	//box(cells, '^', FOREGROUND_RED, 6, 6, 4, 4);
	border(cells, L'\u2550', L'\u2551', L'\u2554', L'\u2557', L'\u255D', L'\u255A', FOREGROUND_RED, 0, 0, GameConfig::WIDTH, GameConfig::HEIGHT);
	border(cells, L'\u2550', L'\u2551', L'\u2554', L'\u2557', L'\u255D', L'\u255A', FOREGROUND_RED, 10, 3, 12, 22);
	cells.push_back(getCellVO(' ', BACKGROUND_RED | BACKGROUND_GREEN, 5, 3));
	cells.push_back(getCellVO(' ', BACKGROUND_RED | BACKGROUND_GREEN, 5, 4));
	cells.push_back(getCellVO(' ', BACKGROUND_RED | BACKGROUND_GREEN, 5, 5));
	cells.push_back(getCellVO(' ', BACKGROUND_RED | BACKGROUND_GREEN, 5, 6));

	return cells;
}