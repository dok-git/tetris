#pragma once
#include "Layer.h"
#include "GameConfig.h"
class GameLayer : public Layer
{
public:
    COORD getLayerPos() override;
    std::vector<CellVO> render() override;

    void updateGameLayer(int gameLayer);

    COORD layerPos{ 11,4 };
private:
    //std::vector <std::vector <int>> layerDate;
    int layerDate[GameConfig::GAME_WIDTH][GameConfig::GAME_HEIGHT];
};

