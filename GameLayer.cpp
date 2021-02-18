#include "GameLayer.h"
#include "GameConfig.h"
COORD GameLayer::getLayerPos()
{
	return layerPos;
}

std::vector <CellVO> GameLayer::render()
{
	std::vector<CellVO> cells;

	box(cells, ' ', BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, 0, 0, 10, 20);
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
			if (gameData->dataVO.data[i][j] == 1) {
				cells.push_back(getCellVO('*', FOREGROUND_GREEN, i, j));
			}
		}
	}
	return cells;
}