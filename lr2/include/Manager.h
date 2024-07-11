#pragma once
#include <iostream>
#include "Agent.h"
#include "Environment.h"

namespace GridWorld
{
    class Manager
    {
    public:
        Manager();
        ~Manager();

        void TryMoveAgent();
        void TryConcreteMoveAgent(MoveType type);
        void PrintCurrentState();

    private:
        Agent* _agent;
        Environment* _env;

        bool CheckNewCoordinates(int xIncr, int yIncr);
    };

}
