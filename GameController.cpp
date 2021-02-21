#include "GameController.h"

void GameController::startGame(){
	gameData->setNewFigure();
	drawFigure();
	updateGameData();
}

void GameController::move(Direction dir)
{
	bool needToUpdate = true;
	switch (dir)
	{
	case Direction::RIGHT:
		needToUpdate = moveRight();
		break;
	case Direction::LEFT:
		needToUpdate = moveLeft();
		break;
	case Direction::DOWN:
		needToUpdate = moveDown();
		if (!needToUpdate) {
			gameData->setNewFigure();
			needToUpdate = true;
		}
		break;
	case Direction::UP:
		gameData->rotateFigure();
		break;
	default:
		break;
	}
	if (needToUpdate) {
		drawFigure();
		updateGameData();
	}
}

bool GameController::moveLeft() {
	for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
		if (moveDataVO.data[0][j]==1) {
			return false;
		}	
	}
	gameData->posFigure.X--;
	return true;
}

bool GameController::moveRight() {
	for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
		if (moveDataVO.data[GameConfig::GAME_WIDTH -1][j] == 1) {
			return false;
		}
	}
	gameData->posFigure.X++;
	return true;
}

bool GameController::moveDown() {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		if (moveDataVO.data[i][GameConfig::GAME_HEIGHT - 1] == 1) {
			return false;
		}
	}
	gameData->posFigure.Y++;
	return true;
}


void GameController::drawFigure()
{
	moveDataVO.clear();
	vector<COORD> state = gameData->currentFigure->getState();
	for (int i = 0; i < state.size(); i++) {
		moveDataVO.data[state[i].X + gameData->posFigure.X][state[i].Y + gameData->posFigure.Y] = 1;
	}
}

void GameController::updateGameData() {
	gameData->dataVO.clear();
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
			if (moveDataVO.data[i][j] != 0) {
				gameData->dataVO.data[i][j] = moveDataVO.data[i][j];
			}

			if (staticDataVO.data[i][j] != 0) {
				gameData->dataVO.data[i][j] = staticDataVO.data[i][j];
			}

		}
	}
}