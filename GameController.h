#pragma once
#include "GameConfig.h"
#include "vector"
#include "BaseFigure.h"
#include "GameData.h"

enum class Direction { RIGHT, LEFT, UP, DOWN };

class GameController
{

public:
	GameData *gameData;

	void startGame();

	void move(Direction dir);

private:
	DataVO moveDataVO;
	DataVO staticDataVO;

	void updateGameData();
	void drawFigure();
};


