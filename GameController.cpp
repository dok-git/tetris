#include "GameController.h"
#include "Zoro.h"
#include "Triangle.h"
#include "Sqeare.h"
#include "AngleD.h"
#include "Angle.h"
#include "Straight.h"

int random(int max) {
	int min = 0;
	return min + rand() % (max - min + 1);
}

GameController::GameController()
{
	Zoro zoro;
	Triangle triangle;
	Straight straight;
	Angle angle;
	AngleD angleD;
	Sqeare sqeare;

	figures.push_back(zoro);
	figures.push_back(triangle);
	figures.push_back(straight);
	figures.push_back(angle);
	figures.push_back(angleD);
	figures.push_back(sqeare);

	nextFigure();
	
}

void GameController::move(Direction dir)
{

	switch (dir)
	{
	case Direction::RIGHT:

		break;
	case Direction::LEFT:

		break;
	case Direction::DOWN:

		break;
	case Direction::UP:
		nextFigure();
		drawFigure();
		updateGameData();
		break;
	default:
		break;
	}

}

void GameController::nextFigure()
{
	figureId = random(5);
}

void GameController::drawFigure()
{
	moveDataVO.clear();
	BaseFigure currentFigure = figures[figureId];
	vector<COORD> state = currentFigure.getState();
	for (int i = 0; i < state.size(); i++) {
		moveDataVO.data[state[i].X][state[i].Y] = 1;
	}
}

void GameController::updateGameData() {
	gameData->dataVO.clear();
	for (int i = 0; i < GameConfig::WIDTH; i++) {
		for (int j = 0; j < GameConfig::HEIGHT; j++) {
			if (moveDataVO.data[i][j] != 0) {
				gameData->dataVO.data[i][j] = moveDataVO.data[i][j];
			}

			if (staticDataVO.data[i][j] != 0) {
				gameData->dataVO.data[i][j] = staticDataVO.data[i][j];
			}

		}
	}
}