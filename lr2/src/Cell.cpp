#include "Cell.h"

using namespace GridWorld;

Cell::Cell(uint16_t x, uint16_t y)
{
    _x = x;
    _y = y;
}

Cell::~Cell(){}

uint16_t Cell::GetX()
{
    return _x;
}

uint16_t Cell::GetY()
{
    return _y;
}
