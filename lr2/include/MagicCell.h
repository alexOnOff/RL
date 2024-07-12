#pragma once
#include <iostream>
#include "Cell.h"
#include "Agent.h"

namespace GridWorld
{
    class MagicCell : public Cell
    {
    public:
        MagicCell(uint16_t x, uint16_t y, uint16_t xDest, uint16_t yDest, int16_t reward);
        ~MagicCell();

        uint16_t GetXDest();
        uint16_t GetYDest();
        int16_t GetReward();

        bool operator == (Agent* agent) ;

    private:
        Cell* _destination;
        int16_t _reward;
    };
}