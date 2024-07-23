#include "Office.h"

using namespace Parking;

Office::Office(uint16_t queryLambda, uint16_t returnLambda)
{
    _carNumber = 20;

    _queryDistribution = std::poisson_distribution<uint16_t>(queryLambda);
    _returnDistribution = std::poisson_distribution<uint16_t>(returnLambda);
    gen = std::mt19937(time(NULL));
}

Office::~Office()
{
}

bool Office::CanTake()
{
    return (bool)_carNumber;
}

bool Parking::Office::CanReturn()
{
    return _carNumber < _Capacity;
}

uint16_t Office::ClientsForDay()
{
    auto wantToTake = TodayTake();

    if (wantToTake < _carNumber)
    {
        //Take(wantToTake);
        return wantToTake;
    }
    else
    {
        auto temp = _carNumber;
        //Take(_carNumber);
        return temp;
    }
}

uint16_t Parking::Office::ReturnCarsForDay()
{
    auto wantToReturn = TodayReturn();

    if (wantToReturn + _carNumber > _Capacity)
    {
        auto canReturn = _Capacity - _carNumber;
        //Take(canReturn);
        return canReturn;
    }
    else
    {
        //Return(wantToReturn);
        return wantToReturn;
    }
}

uint16_t Office::MaxCanTake()
{
    return _carNumber;
}

uint16_t Parking::Office::MaxCanReturn()
{
    return _Capacity - _carNumber;
}

uint16_t Office::GetCarNumber()
{
    return _carNumber;
}

uint16_t Parking::Office::GetCapacity()
{
    return _Capacity;
}

void Office::Take()
{
    _carNumber--;
}

void Office::Return()
{
    _carNumber++;
}

void Office::Take(uint16_t num)
{
    _carNumber -= num;
    if (_carNumber < 0) throw new std::exception("Car number can be less than 0!");
}

void Office::Return(uint16_t num)
{
    _carNumber += num;
    if (_carNumber > _Capacity) throw new std::exception("Car number can be more than Capacity!");
}

void Parking::Office::SetCarNumber(uint16_t state)
{
    _carNumber = state;
}

uint16_t Office::TodayTake()
{
    return _queryDistribution(gen);
}

uint16_t Parking::Office::TodayReturn()
{
    return _returnDistribution(gen);
}
