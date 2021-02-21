#pragma once
#include "GameConfig.h"
#include <vcruntime_string.h>
#include "BaseFigure.h"

class DataVO
{
	public:
		int data[GameConfig::GAME_WIDTH][GameConfig::GAME_HEIGHT] = {};
		void clear() {
			memset(data, 0, sizeof(data));
		}

};

class GameData
{
	public:
		GameData();
		DataVO dataVO;
		BaseFigure *nextFigure;
		BaseFigure *currentFigure;
		void setNewFigure();
		COORD posFigure{};
		void rotateFigure();

	private:
		int figureId = 0;
		int nextfigureId = 0;
		std::vector <BaseFigure> figures{};

};

