#pragma once
#include <iostream>
#include "Office.h"
#include "Jack.h"

namespace Parking
{
    class Manager
    {
    public:
        Manager();
        ~Manager();

        void GoDay();
        void GoNight();

    private:

        std::poisson_distribution<uint16_t> _queryDistributionFirstOffice();
        std::poisson_distribution<uint16_t> _returnDistribution;
        Office* _firstOffice;
        Office* _secondOffice;
        Jack* _jack;

        const float _Gamma = 0.9f;
        
        const uint16_t _Reward = 10;

    };
}


