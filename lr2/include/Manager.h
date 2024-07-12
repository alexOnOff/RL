#pragma once
#include <iostream>
#include "Agent.h"
#include "MagicCell.h"
#include "Environment.h"
#include <vector>

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
        void PrintCurrentReward();

        vector<MagicCell> MagicCells;

    private:
        Agent* _agent;
        Environment* _env;
        int16_t _currentReward = 0;
        const int16_t _punishment = -1;
        
        bool CheckNewCoordinates(int xIncr, int yIncr);
        bool CheckMagicCells();
    };

}
