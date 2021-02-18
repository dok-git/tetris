#pragma once
#include "GameConfig.h"
#include "vector"
#include "BaseFigure.h"
#include "GameData.h"

enum class Direction { RIGHT, LEFT, UP, DOWN };

class GameController
{

public:
	GameController();
	GameData* gameData;

	void move(Direction dir);

private:
	DataVO moveDataVO;
	DataVO staticDataVO;

	std::vector < BaseFigure > figures;
	int figureId = 0;

	void updateGameData();
	void nextFigure();
	void drawFigure();
};


