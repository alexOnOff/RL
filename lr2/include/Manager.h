#pragma once
#include <iostream>
#include "Agent.h"
#include "MagicCell.h"
#include "Environment.h"
#include <math.h>
#include <vector>
#include <iomanip>
#include <ios>

namespace GridWorld
{
    class Manager
    {
    public:
        Manager();
        ~Manager();

        int16_t TryMoveAgent();
        int16_t TryConcreteMoveAgent(MoveType type);
        void PrintCurrentState();
        void PrintCurrentReward();
        void PrintCurrentStateValues();
        void Study(int iters);
        void StudyOnce();
        void SetStateValues5x5();
        void StudyOptimalOnce();
        void StudyOptimal(int iters);

        vector<MagicCell> MagicCells;

    private:
        Agent* _agent;
        Environment* _env;
        Cell* _tempCell;
        int16_t _currentReward = 0;
        const int16_t _Punishment = -1;
        const float _Gamma = 0.9f;


        vector<vector<float>> _stateValues;
        vector<vector<float>> _nextStateValues;
        
        bool CheckNewCoordinates(int xIncr, int yIncr);
        int16_t CheckMagicCells();
    };

}
