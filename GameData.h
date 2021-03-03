#pragma once
#include "GameConfig.h"
#include <vcruntime_string.h>
#include "BaseFigure.h"
#include <array>

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
		int score = 0;
		int level = 0;
		void setNewFigure();
		COORD posFigure{};
		void rotateFigure();
		int getSpeed();
		

	private:
		int figureId = 0;
		int nextfigureId = 0;
		std::vector <BaseFigure> figures{};
		const std::array < int, 5 > levelSpeed{ 12000 , 10000 , 8000 , 7000 , 5000 };
};

