#pragma once
#include <iostream>

using namespace std;

namespace GridWorld
{
    enum class MoveType {Up, Down, Left, Right, Undefined};

    class Agent
    {
    public:
        Agent();
        Agent(int16_t x, int16_t y);
        ~Agent();

        void Move();
        MoveType RandomMove();

        int16_t GetX();
        int16_t GetY();

        void PrintCoordinates();
        void SetCoordinates(int16_t x, int16_t y);

    private:
        int16_t _x;
        int16_t _y;
    };
}



