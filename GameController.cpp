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
	if (checkCollisionL(moveDataVO, staticDataVO) || checkLeftCol(moveDataVO)) {
		return false;
	}
	gameData->posFigure.X--;
	return true;
}

bool GameController::moveRight() {
	if (checkCollisionR(moveDataVO, staticDataVO) || checkRightCol(moveDataVO)) {
		return false;
	}
	gameData->posFigure.X++;
	return true;
}

bool GameController::moveDown() {
	
	if (checkCollision(moveDataVO, staticDataVO) || checkLastRow(moveDataVO)) {
		copyData(staticDataVO, moveDataVO);
		return false;
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

void GameController::copyData(DataVO &dataTo , DataVO& dataFrom) {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
			if (dataFrom.data[i][j] != 0) {
				dataTo.data[i][j] = dataFrom.data[i][j];
			}
		}
	}
}

bool GameController::checkCollision(DataVO& moveData, DataVO& staticData) {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 1; j < GameConfig::GAME_HEIGHT; j++) {
			if (staticData.data[i][j] == moveData.data[i][j-1] && staticData.data[i][j] == 1) {
				return true;
			}
		}
	}
	return false;
}

bool GameController::checkCollisionL(DataVO& moveData, DataVO& staticData) {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 1; j < GameConfig::GAME_HEIGHT; j++) {
			if (staticData.data[i][j] == moveData.data[i+1][j] && staticData.data[i][j] == 1) {
				int ii = staticData.data[i][j];
				int jj = moveData.data[i + 1][j];
				return true;
			}
		}
	}
	return false;
}

bool GameController::checkCollisionR(DataVO& moveData, DataVO& staticData) {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		for (int j = 1; j < GameConfig::GAME_HEIGHT; j++) {
			if (staticData.data[i][j] == moveData.data[i-1][j] && staticData.data[i][j] == 1) {
				return true;
			}
		}
	}
	return false;
}

bool GameController::checkLastRow(DataVO& moveData) {
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++) {
		if (moveData.data[i][GameConfig::GAME_HEIGHT - 1] == 1) {
			return true;
		}
	}
	return false;
}

bool GameController::checkLeftCol(DataVO& moveData) {
	for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
		if (moveDataVO.data[0][j] == 1) {
			return true;
		}
	}
	return false;
}

bool GameController::checkRightCol(DataVO& moveData) {
	for (int j = 0; j < GameConfig::GAME_HEIGHT; j++) {
		if (moveDataVO.data[GameConfig::GAME_WIDTH - 1][j] == 1) {
			return true;
		}
	}
	return false;
}