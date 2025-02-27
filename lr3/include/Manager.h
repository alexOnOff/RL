#pragma once
#include <iostream>
#include "Office.h"
#include "Jack.h"
#include "Service.h"
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
        void PrintLastPolitics();
        void PrintProbabilities();
        void Study();
        

    private:
        Office* _firstOffice;
        Office* _secondOffice;
        Jack* _jack;

        vector<vector<vector<int16_t>>> _politics;
        vector<vector<vector<float>>> _stateValues;
        vector<vector<vector<int16_t>>> _rewards;

        const float _Gamma = 0.9f;
        uint16_t _dayNumber = 0;
        const uint16_t _Reward = 10;
        uint16_t _dayCash = 0;
        uint16_t _argMax;
        float _Theta = 0.004f; 

        float NewStateValue(int16_t, int16_t, int16_t);

    };
}


