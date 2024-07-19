#pragma once
#include <iostream>
#include "Office.h"
#include "Jack.h"
#include <vector>

using namespace std;

namespace Parking
{
    class Manager
    {
    public:
        Manager();
        ~Manager();

        void GoDay();
        void GoNight();
        void PrintLastStateValues();

    private:
        Office* _firstOffice;
        Office* _secondOffice;
        Jack* _jack;

        vector<vector<vector<int16_t>>> _stateValues;

        const float _Gamma = 0.9f;
        
        const uint16_t _Reward = 10;

    };
}


