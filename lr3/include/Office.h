#pragma once
#include <iostream>
#include <random>
#include "Service.h"

namespace Parking
{
    class Office
    {
    public:
        Office(uint16_t queryLambda, uint16_t returnLambda);
        ~Office();

        void Take();
        void Return();
        void Take(uint16_t);
        void Return(uint16_t);
        void SetCarNumber(uint16_t);

        bool CanTake();
        bool CanReturn();

        uint16_t ClientsForDay();
        uint16_t ReturnCarsForDay();

        uint16_t TodayTake();
        uint16_t TodayReturn();
        uint16_t MaxCanTake();
        uint16_t MaxCanReturn();

        uint16_t GetCarNumber();
        uint16_t GetCapacity();

        float GetProbabilityRent(uint16_t i);
        float GetProbabilityReturn(uint16_t i);

    private:
        std::mt19937 gen;
        std::poisson_distribution<uint16_t> _queryDistribution;
        std::poisson_distribution<uint16_t> _returnDistribution;

        std::vector<float> _probabilityRent;
        std::vector<float> _probabilityReturn;

        uint16_t _carNumber;
        const uint16_t _Capacity = 20;

        std::vector<float> GenerateProbability(uint16_t);
    };
}