#pragma once
#include <iostream>
#include <random>

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

    private:
        std::mt19937 gen;
        std::poisson_distribution<uint16_t> _queryDistribution;
        std::poisson_distribution<uint16_t> _returnDistribution;

        uint16_t _carNumber;
        const uint16_t _Capacity = 20;
    };
}