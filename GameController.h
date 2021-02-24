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

	bool moveLeft();

	bool moveRight();

	bool moveDown();

private:
	DataVO moveDataVO;
	DataVO staticDataVO;

	void updateGameData();
	void copyData(DataVO& dataTo, DataVO& dataFrom);
	bool checkCollision(DataVO& moveData, DataVO& staticData);
	void drawFigure();
	bool checkLastRow(DataVO& moveData);
	bool checkCollisionL(DataVO& moveData, DataVO& staticData);
	bool checkCollisionR(DataVO& moveData, DataVO& staticData);
	bool checkRightCol(DataVO& moveData);
	bool checkLeftCol(DataVO& moveData);
};


