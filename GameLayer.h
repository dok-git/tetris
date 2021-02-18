#pragma once
#include "Layer.h"
#include "GameConfig.h"
#include "GameData.h"
class GameLayer : public Layer
{
public:
    COORD getLayerPos() override;
    std::vector<CellVO> render() override;
    COORD layerPos{ 11,4 };

    GameData* gameData;

private:
   

};

