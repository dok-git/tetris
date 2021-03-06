#pragma once
#include "Layer.h"
#include "GameConfig.h"
#include <string>
class MenuLayer :
    public Layer
{
public:
    MenuLayer();
    const int widthMsg = 34;
    const int heightMsg = 10;
    std::vector<CellVO> render() override;
    WORD getTextColor(int i);
    COORD getLayerPos() override;
    std::vector <std::string> gamesName;
    int itemSelected = 1;
};

