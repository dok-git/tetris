#pragma once
#include "GameConfig.h"
#include "vector"
#include "BaseFigure.h"

enum class Direction { RIGHT, LEFT, UP, DOWN };

class GameController
{

public:
	GameController();
	void move(Direction dir);
	int getGameLayer();

	void nextFigure();

	void drawFigure();

private:
	int moveLayer[GameConfig::GAME_WIDTH][GameConfig::GAME_HEIGHT];
	int staticLayer[GameConfig::GAME_WIDTH][GameConfig::GAME_HEIGHT];
	int gameLayer[GameConfig::GAME_WIDTH][GameConfig::GAME_HEIGHT];
	//std:: vector <std :: vector <int>> gameLayer;
	std::vector < BaseFigure > figures;
	int figureId = 0;
};


