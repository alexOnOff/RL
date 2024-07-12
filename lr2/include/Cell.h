#pragma once
#include <iostream>

namespace GridWorld
{
    class Cell
    {
    public:
        Cell();
        Cell(uint16_t x, uint16_t y);
        ~Cell();

        uint16_t GetX();
        uint16_t GetY();
    protected:
        uint16_t _x;
        uint16_t _y;
    };
}