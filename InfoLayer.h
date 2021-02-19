#pragma once
#include "Layer.h"
#include <string>
class InfoLayer :
    public Layer
{
public:
    std::vector<CellVO> render() override;
    
private:
    std::string formatTime(int second);
};

