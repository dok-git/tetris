#pragma once
#include "GameConfig.h"
#include "vector"
#include "BaseFigure.h"
#include "GameData.h"

enum class Direction { RIGHT, LEFT, UP, DOWN };
enum class MoveResult {
	NONE,
	MOVE,
	GAME_OVER,
};
class GameController
{

public:
	GameData *gameData;
	void startGame();
	MoveResult move(Direction dir);
	bool moveLeft();
	bool moveRight();
	bool moveDown();
private:
	DataVO moveDataVO;
	DataVO staticDataVO;
	int litchGoal=0;
	void updateGameData();
	void copyData(DataVO& dataTo, DataVO& dataFrom);
	bool checkCollision(DataVO& moveData, DataVO& staticData);
	void drawFigure();
	bool checkLastRow(DataVO& moveData);
	bool checkCollisionL(DataVO& moveData, DataVO& staticData);
	bool checkCollisionR(DataVO& moveData, DataVO& staticData);
	bool checkRightCol(DataVO& moveData);
	bool checkLeftCol(DataVO& moveData);
	void checkWidth();
	void clearRow(int row);
	void moveDownStatic(int row);
};


