#pragma once
#include "Layer.h"
#include <string>
#include "GameData.h"
class InfoLayer :
    public Layer
{
public:
    COORD getLayerPos() override;
    std::vector<CellVO> render() override;
    GameData* gameData{};
    COORD layerPos{ 20,1 };

private:
    std::string formatTime(int second);
};

