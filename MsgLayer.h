#pragma once
#include "Layer.h"
class MsgLayer :
    public Layer
{
public:
    std::vector<CellVO> render() override;

};

