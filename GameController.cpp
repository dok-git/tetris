#include "GameController.h"

void GameController::startGame(){

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
		gameData->rotateFigure();
		break;
	default:
		break;
	}

	drawFigure();
	updateGameData();

}

void GameController::drawFigure()
{
	moveDataVO.clear();
	vector<COORD> state = gameData->currentFigure->getState();
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