#include "GameData.h"
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

GameData::GameData()
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

	setNewFigure();
}


void GameData::setNewFigure()
{
	posFigure = { 5,0 };
	figureId = nextfigureId;
	nextfigureId = random(figures.size() - 1);
	nextFigure = &figures[nextfigureId];
	nextFigure->clearState();

	currentFigure = &figures[figureId];
	currentFigure->clearState();
}

void GameData::rotateFigure() {
	currentFigure->rotate();
}
