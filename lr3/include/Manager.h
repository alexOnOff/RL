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
        

    private:
        Office* _firstOffice;
        Office* _secondOffice;
        Jack* _jack;

        vector<vector<vector<int16_t>>> _politics;
        vector<vector<vector<float>>> _stateValues;

        const float _Gamma = 0.9f;
        uint16_t _dayNumber = 0;
        const uint16_t _Reward = 10;

    };
}


