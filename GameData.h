#pragma once
#include "GameConfig.h"
#include <vcruntime_string.h>

class DataVO
{
	public:
		int data[GameConfig::WIDTH][GameConfig::HEIGHT] = {};
		void clear() {
			memset(data, 0, sizeof(data));
		}

};

class GameData
{
	public:
		DataVO dataVO;
};

