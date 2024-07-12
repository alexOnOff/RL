#include "MagicCell.h"

using namespace GridWorld;

MagicCell::MagicCell(uint16_t x, uint16_t y, uint16_t xDest, uint16_t yDest, int16_t reward) : Cell(x, y)
{
    _destination = new Cell(xDest, yDest);
    _reward = reward;
}

MagicCell::~MagicCell()
{
    _destination->~Cell();
}

uint16_t MagicCell::GetXDest()
{
    return _destination->GetX();
}

uint16_t MagicCell::GetYDest()
{
    return _destination->GetY();;
}

int16_t MagicCell::GetReward()
{
    return _reward;
}

bool MagicCell::operator==(Agent* agent) 
{
    return agent->GetX() == _x && agent->GetY() == _y;
}