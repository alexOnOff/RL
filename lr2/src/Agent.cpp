#include "Agent.h"

using namespace GridWorld;

Agent::Agent()
{
    _x = 0;
    _y = 0;
}

Agent::Agent(int16_t x, int16_t y)
{
    _x = x;
    _y = y;
}

Agent::~Agent()
{
}

void Agent::Move()
{
    // TODO: WHERE???
}

MoveType Agent::RandomMove()
{
    return (MoveType)(rand() % 4);
}

int16_t Agent::GetX()
{
    return _x;
}

int16_t Agent::GetY()
{
    return _y;
}

void Agent::PrintCoordinates()
{
    cout << "x: " << _x << endl;
    cout << "y: " << _x << endl;
}

void Agent::SetCoordinates(int16_t x, int16_t y)
{
    _x = x;
    _y = y;
}
