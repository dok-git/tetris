#pragma once
#include "GameConfig.h"

class DataVO
{
	public:
		int data[GameConfig::WIDTH][GameConfig::HEIGHT] = {};
};

class GameData
{
	public:
		DataVO dataVO;

		void clearDataVO() {
			DataVO newDataVO;
			dataVO = newDataVO;
		}
};

