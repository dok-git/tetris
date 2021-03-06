﻿// tetris.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <conio.h>
#include "GameController.h"
#include "Scene.h"
#include "Backgroung.h"
#include "GameLayer.h"
#include "ctime"
#include <fcntl.h>
#include <io.h>
#include "GameData.h"
#include "InfoLayer.h"
#include <iostream>
#include "MsgLayer.h"

using namespace std;

#define KEY_ARROW_UP 72
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_DOWN 80
#define KEY_ARROW_LEFT 75

void SetWindowSize(int Width, int Height)
{
	_COORD coord{};
	coord.X = Width+10;
	coord.Y = Height;

	_SMALL_RECT Rect{};
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}

void SetWindowPosition() {
	HWND hwd = GetDesktopWindow();
	HWND hwc = GetConsoleWindow();
	RECT rd, rc;
	GetWindowRect(hwd, &rd);
	GetWindowRect(hwc, &rc);
	MoveWindow(hwc, (rd.right - rc.right) / 2, (rd.bottom - rc.bottom) / 2, 500, 600, TRUE);
	SetWindowLong(hwc, GWL_STYLE, GetWindowLong(hwc, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

void initWindow() {
	SetConsoleTitle(L"TETRIS");// вывод заголовка окна
	SetWindowSize(GameConfig::WIDTH, GameConfig::HEIGHT + 3);
	SetWindowPosition();
}

int main()
{

	initWindow();
	srand((unsigned)time(0));

	bool isStart = false;

	GameData gameData;
	GameController gController;
	Scene scene;
	Backgroung backgroung;
	GameLayer gameLayer;
	InfoLayer infoLayer;
	MsgLayer msgLayer;

	scene.addLayer(&backgroung);
	scene.addLayer(&gameLayer);
	scene.addLayer(&infoLayer);
	scene.addLayer(&msgLayer);

	gController.gameData = &gameData;
	gameLayer.gameData = &gameData;
	infoLayer.gameData = &gameData;
	msgLayer.showStartMsg();

	scene.draw();
	Direction direction = Direction::DOWN;
	MoveResult result = MoveResult::NONE;
	int iKey = 67;
	int a = 0;
	while (iKey != 27) // Выход по клавише ESC
	{
		if (_kbhit())
		{
			iKey = _getch();
			result = MoveResult::NONE;
			if (isStart) {
				switch (iKey)
				{
				case KEY_ARROW_UP:
					direction = Direction::UP;
					break;
				case KEY_ARROW_RIGHT:
					direction = Direction::RIGHT;
					break;
				case KEY_ARROW_DOWN:
					direction = Direction::DOWN;
					break;
				case KEY_ARROW_LEFT:
					direction = Direction::LEFT;
					break;
				case 120: //клавиша x
				case 88: //клавиша X
					exit(0); //завершение программы
				}
				if (iKey == KEY_ARROW_UP || iKey == KEY_ARROW_RIGHT || iKey == KEY_ARROW_DOWN || iKey == KEY_ARROW_LEFT) {
					result = gController.move(direction);
					scene.draw();
				}
			}
			else {
				isStart = true;
				msgLayer.hideMsg();
				gController.startGame();
			}
		}
		if (isStart) {
			if (a == gameData.getSpeed()) {
				result = gController.move(Direction::DOWN);
				scene.draw();
				a = 0;
			}
			if (result == MoveResult::GAME_OVER) {
				msgLayer.gameOver();
				scene.draw();
				iKey = 27;
			}
			a++;
		}
	}
 }