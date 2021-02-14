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

	//for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
	//	std::vector<int> a;
	//	for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {	
	//		if (j >= GameConfig::GAME_HEIGHT - 2) {
	//			a.push_back(1);
	//		}
	//		else {
	//			a.push_back(0);
	//		}
	//	}
	//	gameLayer.push_back(a);
	//}
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
	drawFigure();
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

		break;
	default:
		break;
	}
	

}

int GameController::getGameLayer()
{
	return gameLayer[GameConfig::GAME_WIDTH][GameConfig::GAME_HEIGHT];
}

void GameController::nextFigure()
{
	figureId = random(5);
}

void GameController:: drawFigure()
{
	BaseFigure currentFigure = figures[figureId];
	vector<COORD> state = currentFigure.getState();
	for (int i = 0; i < state.size(); i++) {
		gameLayer[state[i].X][state[i].Y] = 1;
	}
}